
#define MIN 0
#define MAX 1
#define ODD 2
#define EVEN 3
#define MINMAX 4
#define ODDEVEN 5
#define MAXVAL 1000000

#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "memory.h"
#include "buffer.h"

int *inputBuffer = NULL;
int *outputBuffer = NULL;

// two functions provided to you (defined in io.h and io.c) are:

// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer

// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)

int reading()
{

    int i;
    int id = get_value();
    if (id == -1)
    {
        return -1;
    }
    int size = get_value();
    //  memory for input buffer
    printf("Allocating memory for input buffer\n");
    inputBuffer = (int *)my_malloc((size + 2) * sizeof(int));

    inputBuffer[0] = id;
    inputBuffer[1] = size;
    for (i = 2; i < size + 2; i++)
    {
        inputBuffer[i] = get_value();
    }
    return size;
}

void transferringTOlocal(int *localBuffer)
{
    int i;
    // copy the contents of input to local buffer
    for (i = 0; i < inputBuffer[1] + 2; i++)
    {
        localBuffer[i] = inputBuffer[i];
    }
    // Free input buffer
    printf("Freeing input buffer\n");
    my_free(inputBuffer);
}

void processing(int *localBuffer)
{


    int i;
    int min = MAXVAL;
    int max = 0;
    int odd = 0;
    int even = 0;
    int size = localBuffer[1];
    int id = localBuffer[0];

    // Find min, max, odd, even
    for (i = 2; i < 2 + size; i++)
    {
        if (localBuffer[i] < min)
        {
            min = localBuffer[i];
        }
        if (localBuffer[i] > max)
        {
            max = localBuffer[i];
        }
        if (localBuffer[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    // Replace localBuffer
    if (id == MIN)
    {
        localBuffer[2] = min;
        localBuffer[1] = 1;
    }
    else if (id == MAX)
    {
        localBuffer[2] = max;
        localBuffer[1] = 1;
    }
    else if (id == ODD)
    {
        localBuffer[2] = odd;
        localBuffer[1] = 1;
    }
    else if (id == EVEN)
    {
        localBuffer[2] = even;
        localBuffer[1] = 1;
    }
    else if (id == MINMAX)
    {
        localBuffer[2] = min;
        localBuffer[3] = max;
        localBuffer[1] = 2;
    }
    else if (id == ODDEVEN)
    {
        localBuffer[2] = odd;
        localBuffer[3] = even;
        localBuffer[1] = 2;
    }
}

void transferringFROMlocal(int *localBuffer)
{
    //  memory for output buffer
    printf("Allocating memory for output buffer\n");
    outputBuffer = (int *)my_malloc((localBuffer[1] + 2) * sizeof(int));
    //  local to output buffer
    int i;
    for (i = 0; i < localBuffer[1] + 2; i++)
    {
        outputBuffer[i] = localBuffer[i];
    }
}

void submitting()
{

    submit_results(outputBuffer);
    // Free output buffer
    printf("Freeing output buffer\n");
    my_free(outputBuffer);
    printf("\n");
}
