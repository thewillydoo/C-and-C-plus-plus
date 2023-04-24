#include <iostream>
#include <cstring>
#define MAX 40

using namespace std;

class book {
private:
    char publisher[MAX];
    int pub_year;
public:
    book();
    book(char *, int);
    void print();
};

class fiction : public book {
private:
    char author[MAX];
    char title[MAX];
public:
    fiction();
    fiction(char *, char *, char *, int);
    void print();
};

int main() {

    char a1_pub[] = "HarperOne";
    int a1_pub_yr = 2014;
    char a1_title[] = "The Alchemist";
    char a1_author[] = "Paulo Coelho";

    char a2_pub[] = "Bantam";
    int a2_pub_yr = 1988;
    char a2_title[] = "A Brief History of Time";
    char a2_author[] = "Stephen Hawking";

    fiction *library[2];
    library[0] = new fiction(a1_title, a1_author, a1_pub, a1_pub_yr);
    library[1] = new fiction(a2_title, a2_author, a2_pub, a2_pub_yr);

    library[0]->print();
    library[1]->print();

    fiction *copy;
    copy = library[0];
    copy->print();

    library[1]->book::print();

    delete library[1];
    delete library[0];

    return 0;
}

book::book() {
    // Copies content into member
    strcpy(publisher, " ");
    pub_year = 0;
}

book::book(char *pub, int pub_yr) {
    // Copies content into member
    strcpy(publisher, pub);
    pub_year = pub_yr;
}

void book::print() {
    cout << "Publisher: " << publisher << endl;
    cout << "Year: " << pub_year << endl
         << endl;
}

fiction::fiction() {
    strcpy(title, " ");
    strcpy(author, " ");
}

fiction::fiction(char *title, char *author, char *pub, int pub_yr) : book(pub, pub_yr) {
    strcpy(fiction::title, title);
    strcpy(fiction::author, author);
}

void fiction::print() {
    // Prints results
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    book::print();
}