#include <stdio.h>

//Initialize function
int main(void) {

    //Declare Variables
    int userinput1;
    int userinput2;
    int userinput3;
    int arr[4], temp, i, j;


    //Use do-while loop
    do {
        printf("Enter the first integer:");
        scanf("%d", &arr[0]);
        printf("Enter the second integer:");
        scanf("%d", &arr[1]);
        printf("Enter the third integer:");
        scanf("%d", &arr[2]);
        //use bubblesort
        for (i = 0; i < 3; i++){
            for (j = 0; j<3; j++){
                if (arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        userinput1 = arr[0];
        userinput2 = arr[1];
        userinput3 = arr[2];

    } while (userinput1 <= 0 || userinput1 + 7 > userinput2 || userinput2 + 7 > userinput3);


    printf("Min:%d\nMiddle:%d\nMax:%d\n", userinput1, userinput2, userinput3);

    //Display all the odd numbers
    printf("*** The odd numbers are:\n");

    // Display all odd integers between the minimum and the middle number
    if (userinput1 % 2 == 1) {
        printf("value: %d\n", userinput1);
    }

    for (int i = userinput1 + 1; i < userinput2; i++) {
        if (i % 2 == 1) {
            printf("value: %d\n", i);
        }
    }


    printf("*** The even numbers are:\n");

    // Display all even numbers between the middle number and the maximum
    for (int i = userinput2 + 1; i < userinput3; i++) {
        if (i % 2 == 0) {
            printf("value: %d\n", i);
        }
    }

    if (userinput2 % 2 == 0 && userinput2 < userinput3) {
        printf("value: %d\n", userinput2);
    }

    return 0;

}



