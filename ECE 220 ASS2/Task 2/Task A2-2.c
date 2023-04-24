#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 200
#define ERROR -1

int main(void)
{
    // Pointer to file
    FILE *filePtr;

    // Initialize variables
    char buffer[ARRAY_SIZE] = {0};
    int numLines = 0;
    int shortestLineID = 0, longestLineID = 0;
    int shortestLineLength = ARRAY_SIZE; // First line read from the input file will be considered the shortest
    int longestLineLength = 0;
    char shortestLine[ARRAY_SIZE], longestLine[ARRAY_SIZE];

    // Open the file
    filePtr = fopen("C:\\Coding\\C and C++\\CLionProjects\\ECE 220 ASS2 Task A2-2\\test.txt","r");

    // Check if the file exists
    if (filePtr == NULL)
    {
        printf("Input file not found.\n");
        return ERROR;
    }

    // Read line by line until the end of the file (NULL)
    while (fgets(buffer, ARRAY_SIZE, filePtr) != NULL)
    {

        int lineLength = strlen(buffer);

        // Remove \n from the end of the line
        if (lineLength > 0 && buffer[lineLength - 1] == '\n') // Indexing starts at 0
        {
            buffer[lineLength - 1] = '\0';
            lineLength--;
        }

        // Skip empty lines
        if (lineLength == 0)
        {
            continue; // Go to the next iteration of the loop
        }

        // If the line is shorter than the current shortest line, update the shortest line
        if (lineLength < shortestLineLength)
        {
            shortestLineID = numLines;
            shortestLineLength = lineLength;
            // Copy the line into the shortest line variable
            strcpy(shortestLine, buffer);
        }

        // If the line is longer than the current longest line, update the longest line
        if (lineLength > longestLineLength)
        {
            longestLineID = numLines;
            longestLineLength = lineLength;
            // Copy the line into the longest line variable
            strcpy(longestLine, buffer);
        }

        // Increment the number of lines
        numLines++;
    }

    // Print results
    printf("Number of lines read: %d\n", numLines);
    printf("ID of shortest line: %d\n", shortestLineID);
    printf("ID of longest line: %d\n", longestLineID);
    printf("SHORTEST: length = %d; line = %s\n", shortestLineLength, shortestLine);
    printf("LONGEST: length = %d; line = %s\n", longestLineLength, longestLine);

    fclose(filePtr);
}




