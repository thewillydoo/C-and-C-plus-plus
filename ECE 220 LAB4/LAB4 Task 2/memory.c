/**********************************************************/
/*                       MEMORY.C                         */
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "memory.h"

static long counter=0;


void *my_malloc(int size)
{
    long *ptr;
    long amount;

    amount = (long)((long)size + sizeof(long));

    ptr = (long *)malloc(amount);
    *ptr = amount;
    ptr++;

    counter = counter + amount;
    printf("*** malloc: total #bytes taken from system: %ld\n", counter);

    return (void *)ptr;
}


void my_free(void *ptr)
{
    long amount;
    long *size_ptr;

    size_ptr = (long *)ptr;
    size_ptr--;

    amount = *size_ptr;
    counter = counter - *size_ptr;
    printf("*** free: total #bytes own to system: %ld\n", counter);
    free((void *)size_ptr);
}
