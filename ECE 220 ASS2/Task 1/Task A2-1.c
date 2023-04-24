
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//Declare the variables
    int num_dice1, num_dice2, num_sides1, num_sides2;
    int i, j, sum, rolls;
    double probability[100] = {0};

    srand(time(NULL)); // seed the random number generator with the current time

    // get user input for dice sides and number of dice
    printf("Enter the number of sides for the first custom die: ");
    scanf("%d", &num_sides1);
    printf("Enter the number of dice for the first custom die: ");
    scanf("%d", &num_dice1);
    printf("Enter the number of sides for the second custom die: ");
    scanf("%d", &num_sides2);
    printf("Enter the number of dice for the second custom die: ");
    scanf("%d", &num_dice2);

    // simulate rolling the dice a large number of times (e.g. 1 million)
    rolls = 1000000;
    for (i = 0; i < rolls; i++) {
        sum = 0;
        for (j = 0; j < num_dice1; j++) {
            sum += rand() % num_sides1 + 1; // generate a random value between 1 and num_sides1 for each die
        }
        for (j = 0; j < num_dice2; j++) {
            sum += rand() % num_sides2 + 1; // generate a random value between 1 and num_sides2 for each die
        }
        probability[sum]++; // increment the counter for the corresponding sum
    }

    // calculate the probability of obtaining each possible sum and output the results in a table
    printf("Sum Probability\n");
    for (i = num_dice1 + num_dice2; i <= num_sides1 * num_dice1 + num_sides2 * num_dice2; i++) {
        probability[i] /= rolls;
        printf("%d %f\n", i, probability[i]);
    }

    return 0;
}