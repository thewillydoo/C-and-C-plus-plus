#include <stdio.h>
#include "buffer.h"

// #define _CRT_SECURE_NO_WARNINGS

int main(void)
{

    int isData;
    int localBuffer[Input_Local_BUFFER__SIZE] = {0};

    isData = reading();

    while (isData != -1)
    {
        transferringTOlocal(localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);
        submitting(localBuffer);
        isData = reading();

    }
    return 0.0;
}
