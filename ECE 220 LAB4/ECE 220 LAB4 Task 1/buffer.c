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
#include "buffer.h"

int inputBuffer[Input_Local_BUFFER__SIZE] = {0};
int outputBuffer[Output_BUFFER_SIZE] = {0};

// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)

int reading()
{
    // fill input buffer with values obtained from get_value()
    // first element of the buffer is ID
    // second element of the buffer is the number of elements in the buffer
    // the rest of the elements are the data points, the amount of which is specified by the second element of the buffer

    int i;
    int id = get_value();
    if (id == -1)
    {

        return -1;
    }
    int size = get_value();
    inputBuffer[0] = id;
    inputBuffer[1] = size;
    for (i = 2; i < size + 2; i++)
    {
        inputBuffer[i] = get_value();
    }
    return 0;
}

void transferringTOlocal(int localBuffer[])
{
    int i;
    // copy the contents of input to local buffer
    for (i = 0; i < inputBuffer[1] + 2; i++)
    {
        localBuffer[i] = inputBuffer[i];
    }
}

void processing(int localBuffer[])
{
    // check first element of the buffer as ID
    // Second element of the buffer is the number of elements in the buffer
    // if ID is 0 find min, if 1 find max, if 2 find odd points, if 3 find even points, if 4 find min+max, if 5 find odd+even
    // Replace localBuffer with the proccessed data

    int i;
    int min = MAXVAL;
    int max = 0;
    int odd = 0;
    int even = 0;
    int oddeven = 0;
    int size = localBuffer[1];
    int id = localBuffer[0];

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

void transferringFROMlocal(int localBuffer[])
{
    // copy the contents of local to output buffer
    int i;
    for (i = 0; i < localBuffer[1] + 2; i++)
    {
        outputBuffer[i] = localBuffer[i];
    }
}

void submitting(int localBuffer[])
{
    submit_results(outputBuffer);



    // Clear the output buffer
    for (int i = 0; i < Output_BUFFER_SIZE; i++)
    {
        outputBuffer[i] = 0.0;
    }

    // Clear the input buffer
    for (int i = 0; i < Input_Local_BUFFER__SIZE; i++)
    {
        inputBuffer[i] = 0.0;
    }

    // Clear the local buffer
    for (int i = 0; i < Input_Local_BUFFER__SIZE; i++)
    {
        localBuffer[i] = 0.0;
    }
}
