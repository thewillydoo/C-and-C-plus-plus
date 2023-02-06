#include <stdio.h>

//Initialize function
int main(void) {

    //Declare Variables
    int userinput1;
    int userinput2;
    int sum;

    //Use do-while loop
    do {
        printf("Enter the first integer:");
        scanf("%d", &userinput1);
        printf("Enter the second integer:");
        scanf("%d", &userinput2);

        //Check min and max values
        if (userinput1 > userinput2) {
            printf("The min value is: %d and the max value is: %d\n", userinput2, userinput1);

        } else if (userinput2 > userinput1) {
            printf("The min value is: %d and the max value is: %d\n", userinput1, userinput2);
        } else {
            printf("There is no min or max values");
        }

        //Determine the sum of all integers between the max and min
        sum = ((userinput2 * (userinput2 + 1)) - (userinput1 * (userinput1 - 1))) / 2;
        printf("Result : %d\n", sum);


    } while ((userinput1 > 0) && (userinput2 > 0) && (userinput1 != userinput2));

}