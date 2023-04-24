#include <stdio.h>
#include "io.h"

// this function generates a single value
// you use it to obtain this value and put it
// into an input buffer

int get_value()
{
    static int pointer = 0;
    long long dataX[] = {
        0x804010501030300,
        0x503000102000C05,
        0x106040504030201,
        0x2D0A050605040302,
        0x22000509334E1621,
        0x1010101010A0215,
        0x6401000101010101,
        0x606060606060804,
        0x203040505030606,
        0x3020102010A0501,
        0x401010201020102,
        0x7FF7B7E5A6FF};

    char *data = (char *)dataX;
    return (int)(data[pointer++]);
}

int submit_results(int *answer)
{
    static int pointer = 0;
    static int testCase = 0;
    long long dataX[] = {
        0x1020C0101010100,
        0x601020402010300,
        0xA010204060205,
        0x103060602046401,
        0x401010505020502};

    char *data = (char *)dataX;
    int end = data[pointer + 1] + pointer + 2;
    int index;
    int output = 0;
    int tempPointer = pointer;
    testCase++;
    for (index = 0; pointer < end; pointer++, index++)
    {
        if (answer[index] != ((int)(data[pointer])))
        {
            output = 1;
        }
    }
    if (output == 0)
    {
        printf("Test case %d: Successful\n", testCase);
    }
    else
    {
        printf("\nTest case %d: Failed\n", testCase);
        printf("-----------------------------------\n");
        printf("| %-15s| %-15s|\n", "Correct Answer", "Your Answer");
        printf("-----------------------------------\n");
        for (index = 0; tempPointer < end; tempPointer++, index++)
        {
            printf("| %-15d| %-15d|\n", ((int)(data[tempPointer])), answer[index]);
        }
        printf("-----------------------------------\n");
    }
    return output;
}
