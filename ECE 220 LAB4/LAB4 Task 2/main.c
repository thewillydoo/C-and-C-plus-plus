#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "memory.h"

//#define _CRT_SECURE_NO_WARNINGS

int main(void) {

    int dataSize;
    int *localBuffer = NULL;

    dataSize = reading();

    while (dataSize !=-1) {

        // Allocate memory for local buffer
        printf("Allocating memory for local buffer\n");
        localBuffer = (int *)my_malloc((dataSize + 2) * sizeof(int));

        transferringTOlocal(localBuffer);
        processing(localBuffer);
        transferringFROMlocal(localBuffer);

        // Free local buffer
        printf("Freeing local buffer\n");
        my_free(localBuffer);

        submitting();
        dataSize = reading();
    }
    return 0;
}






