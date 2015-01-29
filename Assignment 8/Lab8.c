// APS105-F12 Lab 8 Lab8.c
// This program maintains a bookstore inventory database using linked lists.
// The user may add books to database, search by name/rating, list all the books in database
//and delete books.
// Author: Shengyuan Guo


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//**********************************************************************
// Linked List Definitions

typedef struct book
{
    char* name;
    char* author;
    int rating;
    char category;
} Book;


typedef struct node
{
    Book book;
    struct node* next;
} Node;


//**********************************************************************
// Linked List Function Declarations

Node * insertBook (Node *head);
Node * deleteBook (Node *head);
void   printList (Node *head);
void   searchListbyName (Node *head);
void   searchListbyRating(Node *head);
Node *deleteAll(Node *head);
Book inputBook();
void printBook(Book book);
int toInt (char *str);
char *getString(char *str);
int  getCategoryID(char category);

//**********************************************************************
// Support Function Declarations
//
void safegets (char s[], int arraySize);        // gets without buffer overflow
void bookNameDuplicate (char bookName[]);   // marker/tester friendly
void bookNameFound (char bookName[]);       //   functions to print
void bookNameNotFound (char bookName[]);    //     messages to user
void bookNameDeleted (char bookName[]);
void printInventoryEmpty (void);
void printInventoryTitle (void);
void printNoBooksWithHigherRating (int rating);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char FICTION = 'F';
const char HISTORY = 'H';
const char PHILOSOPHY = 'P';
const char ART = 'A';


//**********************************************************************
// Main Program
//

int main (void)
{
    const char bannerString[]
        = "Online Bookstore Inventory Management Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by rating), P (print), Q (quit).\n";

    // Declare linked list head.
    Node *head=NULL;


    // announce start of program
    printf("%s", bannerString);
    printf("%s", commandList);

    char response;
    char input[MAX_LENGTH+1];
    do
    {
        printf("\nCommand?: ");
        safegets(input, MAX_LENGTH + 1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            // Insert a book entry into the linked list.
            // Maintain the list in correct order (F, H, P, A);
            head=insertBook(head);

        }
        else if (response == 'D')
        {
            // Delete a book from the list.

            printf("\nEnter the book name to delete: ");
            head=deleteBook(head);

        }
        else if (response == 'S')
        {
            // Search for a book by a name.
            printf("\nEnter the book name to search for: ");
            searchListbyName(head);
        }
        else if (response == 'V')
        {
            // Search for books that are rated higher than or equal to a rating.
            printf("\nEnter rating: ");
            searchListbyRating(head);

        }
        else if (response == 'P')
        {
            // Print the bookstore inventory.
            printList(head);


        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n", commandList);
        }
    }
    while (response != 'Q');

    // Delete the entire linked list that hold the bookstore inventory.
    head=deleteAll(head);


    // Print the linked list to confirm deletion.
    printList(head);

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when a user is trying to insert a book name
// that is already in the inventory.
void bookNameDuplicate (char bookName[])
{
    printf("\nAn entry for <%s> is already in the bookstore inventory!\n"
           "New entry not entered.\n", bookName);
}

// Function to call when a book with this name was found in the inventory.
void bookNameFound (char bookName[])
{
    printf("\nThe book with name <%s> was found in the bookstore inventory.\n",
           bookName);
}

// Function to call when a book with this name was not found in the inventory.
void bookNameNotFound (char bookName[])
{
    printf("\nThe book with name <%s> is not in the bookstore inventory.\n",
           bookName);
}

// Function to call when a name that is to be deleted
// was found in the inventory.
void bookNameDeleted (char bookName[])
{
    printf("\nDeleting book with name <%s> from the bookstore inventory.\n",
           bookName);
}

// Function to call when printing an empty bookstore inventory.
void printInventoryEmpty (void)
{
    printf("\nThe bookstore inventory is empty.\n");
}

// Function to call to print title when the entire inventory is printed.
void printInventoryTitle (void)
{
    printf("\nMy Inventory: \n");
}

// Function to call when no book in the bookstore inventory has higher
// or equal rating to the given rating
void printNoBooksWithHigherRating (int rating)
{
    printf("\nNo book(s) in the bookstore inventory is rated higher than or equal to <%d>.\n", rating);
}

//**********************************************************************
Book  inputBook()
{
    char input[MAX_LENGTH +1];
    Book book;
    char *name;
    char *author;
    int rating;
    char category;

    printf("  book: ");
    safegets(input, MAX_LENGTH+1 );
    name=getString(input);

    printf("  author: ");
    safegets(input, MAX_LENGTH +1);
    author=getString(input);

    printf("  rating: ");
    safegets(input, MAX_LENGTH +1);
    rating=toInt(input);

    printf("  category: ");
    safegets(input, MAX_LENGTH +1);
    category = toupper(input[0]);

    book.name=name;
    book.author=author;
    book.rating=rating;
    book.category=category;

    return book;
}


Node * insertBook (Node *head)
{
    int check=0;
    Node * temp=head;
    Node * newNode;
    newNode=(Node *)malloc(sizeof(Node));
    newNode->book=inputBook();

    newNode->next=NULL;


    while (temp!=NULL && check==0)
    {
        if(strcmp(temp->book.name, newNode->book.name)==0)
            check=1;
        temp=temp->next;
    }

    if (check==1)
    {
        bookNameDuplicate(newNode->book.name);
        free (newNode->book.name);
        free (newNode->book.author);
        free(newNode);
        return head;
    }

    if (head==NULL)
    {
        return newNode;
    }
    // insert book
    temp=head;
    check=0;

    if (getCategoryID(temp->book.category)>getCategoryID(newNode->book.category))
    {
        newNode->next=head;
        head=newNode;
        check=1;
    }
    else
    {
        while (temp->next!=NULL && check==0)
        {
            if (getCategoryID(temp->next->book.category)>getCategoryID(newNode->book.category))
                check=1;
            else
                temp=temp->next;
        }
        newNode->next=temp->next;

        temp->next=newNode;

    }
    return head;

}
Node * deleteBook (Node *head)
{
    char input[MAX_LENGTH +1];
    char *str;

    int check=0;
    Node *temp=head;
    Node *temp2;

    safegets(input,MAX_LENGTH+1);

    str=getString(input);


    // check head first
    if(head!=NULL && strcmp(head->book.name,str)==0)
    {
        temp2=head;
        head=temp2->next;
        temp2->next=NULL;
        free(temp2->book.name);
        free(temp2->book.author);
        free(temp2);
        check=1;

    }

    // check next
    while (temp!=NULL&&temp->next!= NULL  && check==0)
    {
        if (strcmp(temp->next->book.name,str)==0)
        {
            check=1;
            temp2= temp->next;

            temp->next = temp2->next;

            temp2->next = NULL;
            free(temp2->book.name);
            free(temp2->book.author);
            free(temp2);
        }
        else
            temp=temp->next;


    }

    if (check==1)
    {
        bookNameDeleted(str);
    }
    else
    {
        bookNameNotFound(str);
    }

    return head;

}
void   printList (Node *head)
{
    Node *temp;
    temp=head;

    if (temp==NULL)
    {
        printInventoryEmpty();
    }
    else
    {

        printInventoryTitle();
        while(temp!=NULL)
        {
            printBook(temp->book);
            printf("\n");
            temp=temp->next;


        }
    }




}
void   searchListbyName (Node *head)
{
    Node *temp;
    temp=head;
    char input[MAX_LENGTH+1];
    char *str;
    int check=0;
    safegets(input,MAX_LENGTH+1);

    str=getString(input);

    while (temp!=NULL && check==0)
    {

        if (strcmp(temp->book.name,str)==0)
        {
            check=1;
        }
        else
        {
            temp=temp->next;
        }
    }

    if (check==1)
    {
        bookNameFound(str);
        printBook(temp->book);
        printf("\n");
    }
    else
    {
        bookNameNotFound(str);
    }


}
void searchListbyRating(Node *head)
{

    Node *temp;
    temp=head;
    int rating;
    char input[MAX_LENGTH+1];

    safegets(input, MAX_LENGTH + 1);
    rating=toInt(input);


    int check=0;
    while (temp!=NULL)
    {
        if(temp->book.rating>=rating)
        {
            printBook(temp->book);
            printf("\n");
            check=1;
        }
        temp=temp->next;
    }

    if(check==0)
    {
        printNoBooksWithHigherRating(rating);
    }
}

Node *deleteAll(Node *head)
{
    Node * temp;
    while (head!=NULL)
    {
        temp=head;
        head=temp->next;
        temp->next=NULL;
        free(temp->book.name);
        free(temp->book.author);
        free(temp);
    }
    return NULL;
}



int toInt (char *str)
{
    int i=0;
    int v=0;
    while (str[i]!=NULL_CHAR)
    {
        v=v*10 + (str[i]- '0');


        i++;

    }
    return v;
}
char *getString(char *str)
{
    char *dest;
    int i=0;
    while (str[i]!=NULL_CHAR)
    {
        i++;
    }

    dest= (char *)malloc(i+1);

    strcpy(dest, str);
    return dest;
}

void printBook(Book book)
{
    printf("\n%s", book.name);
    printf("\n%s", book.author);
    printf("\n%d", book.rating);
    printf("\n%c", book.category);
}

int  getCategoryID(char category)
{
    if (category=='F')
        return 1;
    else if (category=='H')
        return 2;
    else if (category=='P')
        return 3;
    else if (category=='A')
        return 4;

}

