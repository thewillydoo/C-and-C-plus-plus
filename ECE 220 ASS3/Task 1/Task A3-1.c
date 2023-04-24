#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

struct book {
    char *title;
    char *author;
    struct book *next;
    struct book *previous;
};

int main(void) {

    char *book_title[SIZE] = {"Solaris", "Neuromancer", "Hyperion"};
    char *book_author[SIZE] = {"Stanislaw Lem", "William Gibson", "Dan Simmons"};
    struct book *first;
    struct book *current;
    struct book *new;
    int i, len;

    current = (struct book *)malloc(sizeof(struct book));
    len = (int)strlen(book_title[0]);
    current->title = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->title, book_title[0]);
    len = (int)strlen(book_author[0]);
    current->author = (char *) malloc((len+1) * sizeof(char));
    strcpy(current->author, book_author[0]);
    current->next = NULL;
    current->previous = NULL;
    first = current;

    for (i = 1; i < SIZE; i++) {
        // Allocates memory of a new book
        new = (struct book *)malloc(sizeof(struct book));

        // Length of the book title string
        len = (int)strlen(book_title[i]);

        // Allocates memory for and copies the book title into the new title
        new->title = (char *) malloc((len+1) * sizeof(char));
        strcpy(new->title, book_title[i]);

        // Length of the book title
        len = (int)strlen(book_author[i]);

        // Allocates memory for and copies the book author into the new author
        new->author = (char *) malloc((len+1) * sizeof(char));
        strcpy(new->author, book_author[i]);


        new->next = NULL;


        new->previous = current;


        current->next = new;

        // Sets the current pointer on new
        current = new;
    }
    current = first;
    i = 0;

    while (current != NULL) {
        // Prints the book title and author, and moves to the next part in the list until it reaches NULL
        printf("Author of %s is %s\n", current->title, current->author);
        current = current->next;
    }
    printf("END\n");
    return 0;
}