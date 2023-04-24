// define the header file
#include <stdio.h>

//Initialize the main function
int main(void) {

    //Declare variables
    int min, max, counter, userinput, program_guessed_number;

    //Initialization of the variables
    min, max, counter, userinput = 0;

    //User inputs
    do {
        printf("What is your min value?");
        scanf("%d", &min);
        printf("What is your max value?");
        scanf("%d", &max);
    } while (min > max);

    //Display number to the user
    program_guessed_number = (min + max) / 2;
    printf("The guessed value is: %d \n", program_guessed_number);

    //Start for loop
    for (counter; userinput != 3; counter++) {
        //Display menu and ask for user input
        printf("Select one of the options:\n");
        printf("1. TOO LARGE\n");
        printf("2. TOO SMALL\n");
        printf("3. FOUND\n");
        scanf("%d", &userinput);

        //Determine user input
        if (userinput == 1) {
            max = program_guessed_number - 1;
            program_guessed_number = (min + max) / 2;
            printf("The guessed value is: %d \n", program_guessed_number);
        } else if (userinput == 2) {
            min = program_guessed_number + 1;
            program_guessed_number = (min + max) / 2;
            printf("The guessed value is: %d \n", program_guessed_number);
        } else if (userinput == 3) {
            printf("FOUND IT\n");
            printf("The number of guesses is: %d", counter + 1);
        } else {
            printf("Invalid\n");
            counter--;
        }
    }
    return 0;
}

