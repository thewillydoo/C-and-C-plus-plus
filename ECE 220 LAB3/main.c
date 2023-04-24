#include <stdio.h>
#include <io.h>

#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 64

#define MIN 0
#define MAX 1
#define ODD 2
#define EVEN 3
#define MINMAX 4
#define ODDEVEN 5
#define MAXVAL 1000000

// prototypes of your functions you need to write

// this function fills input buffer using values
// obtained with the function get_value()
void reading(int[]);

// this function performs processing of data in local buffer
// and put results back into local buffer
void processing(int[]);

// this function transfers data between two buffers
// it is used to transfer data from input buffer to local buffer
// and to transfer data from local buffer to output buffer
void transferring(int[], int[]);

// this function submit the results stored
// in output buffer for validation
void submitting(int[]);

// two functions provided to you (defined in io.h and io.c) are:
// int get_value(void);
//       this function generates a single value
//       you use it to obtain this value and put it into an input buffer
// int submit_result(int[]);
//       you use this function to submit the data processing results
//       for validation (your results are checked inside this function)

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
        printf("\nTest case %d: Successful\n", testCase);
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

int main(void)
{

    int inputBuffer[BUFFER_SIZE] = {0};
    int localBuffer[BUFFER_SIZE] = {0};
    int outputBuffer[BUFFER_SIZE] = {0};

    reading(inputBuffer);

    while (inputBuffer[0] != -1)
    {
        printf("\n\nNew test case:\n");
        // Print all buffers after with relevant size
        int i;
        printf("Input Buffer: ");
        for (i = 0; i < inputBuffer[1] + 2; i++)
        {
            printf("%d ", inputBuffer[i]);
        }
        printf("\nLocal Buffer: ");
        for (i = 0; i < localBuffer[1] + 2; i++)
        {
            printf("%d ", localBuffer[i]);
        }
        printf("\nOutput Buffer:");
        for (i = 0; i < outputBuffer[1] + 2; i++)
        {
            printf("%d ", outputBuffer[i]);
        }

        transferring(inputBuffer, localBuffer);
        printf("\nInput--->Local:\n");
        // Print all buffers after with relevant size
        printf("Input Buffer: ");
        for (i = 0; i < inputBuffer[1] + 2; i++)
        {
            printf("%d ", inputBuffer[i]);
        }
        printf("\nLocal Buffer: ");
        for (i = 0; i < localBuffer[1] + 2; i++)
        {
            printf("%d ", localBuffer[i]);
        }
        printf("\nOutput Buffer:");
        for (i = 0; i < outputBuffer[1] + 2; i++)
        {
            printf("%d ", outputBuffer[i]);
        }

        processing(localBuffer);
        printf("\nAfter processing:\n");
        // Print all buffers after with relevant size
        printf("Input Buffer: ");
        for (i = 0; i < inputBuffer[1] + 2; i++)
        {
            printf("%d ", inputBuffer[i]);
        }
        printf("\nLocal Buffer: ");
        for (i = 0; i < localBuffer[1] + 2; i++)
        {
            printf("%d ", localBuffer[i]);
        }
        printf("\nOutput Buffer:");
        for (i = 0; i < outputBuffer[1] + 2; i++)
        {
            printf("%d ", outputBuffer[i]);
        }
        transferring(localBuffer, outputBuffer);
        printf("\nAfter local---> output:\n");
        // Print all buffers after with relevant size
        printf("Input Buffer: ");
        for (i = 0; i < inputBuffer[1] + 2; i++)
        {
            printf("%d ", inputBuffer[i]);
        }
        printf("\nLocal Buffer: ");
        for (i = 0; i < localBuffer[1] + 2; i++)
        {
            printf("%d ", localBuffer[i]);
        }
        printf("\nOutput Buffer:");
        for (i = 0; i < outputBuffer[1] + 2; i++)
        {
            printf("%d ", outputBuffer[i]);
        }
        submitting(outputBuffer);
        // set all buffers to 0
        for (i = 0; i < BUFFER_SIZE; i++)
        {
            inputBuffer[i] = 0;
            localBuffer[i] = 0;
            outputBuffer[i] = 0;
        }
        reading(inputBuffer);
        // Print when input buffer is -1 at ID
        if (inputBuffer[0] == -1) {
            printf("\nThis input buffer resulted in the code being terminated:\n");
            for (i = 0; i < 5; i++)
            {
                printf("%d ", inputBuffer[i]);

            }
            printf("\nLocal Buffer: ");
            for (i = 0; i < localBuffer[1] + 2; i++)
            {
                printf("%d ", localBuffer[i]);
            }
            printf("\nOutput Buffer:");
            for (i = 0; i < outputBuffer[1] + 2; i++)
            {
                printf("%d ", outputBuffer[i]);
            }
        }


    }

    return 0;
}

void reading(int inputBuffer[])
{
    // fill input buffer with values obtained from get_value()
    // first element of the buffer is ID
    // second element of the buffer is the number of elements in the buffer
    // the rest of the elements are the data points, the amount of which is specified by the second element of the buffer

    int i;
    int id = get_value();
    int size = get_value();
    inputBuffer[0] = id;
    inputBuffer[1] = size;
    for (i = 2; i < size + 2; i++)
    {
        inputBuffer[i] = get_value();
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

void transferring(int sourceBuffer[], int destinationBuffer[])
{
    // copy the contents of sourceBuffer to destinationBuffer
    int i;
    for (i = 0; i < sourceBuffer[1]+2; i++)
    {
        destinationBuffer[i] = sourceBuffer[i];
    }
}

void submitting(int outputBuffer[])
{
    // Buffer size is 4, first element is ID, second is the size of the processing, third is the result of the processing
    printf("\nAfter submitting:");
    submit_results(outputBuffer);
}
