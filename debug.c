/*
 *  Authors: Thomas Peavler and Noah Kuhn
 *
 */

/* Here are some fairly standard libraries */
#include <stdlib.h>     /* standard library */
#include <stdio.h>      /* standard input/output library */
#include <string.h>     /* standard string library */
#include <assert.h>     /* assertion library */

#include "debug.h"      /* we also need to include our header file */

/* this is similar to Java main: this is the actual function that executes */
int main() {
    printf("Welcome to this debugging demo! Find the bugs :)\n");

    // Create dummy linked list
    struct node *root = calloc(1, sizeof(struct node));
    struct node *temp = root;
    for (int i = 0; i < 10; i++)
    {
        temp->a = i;
        temp->b = i * 2;
        temp->next = calloc(1, sizeof(struct node));
        temp = temp->next;
    }
    temp->next = NULL;

    function1();
    // assert(function1() == 24); // we know the expected output; an assert here can verify that we get it
    defensiveProgramming();
    recursive(root);

    // ---------------- This is where the bugs start -------------------

    // Let's see what happens when we access freed memory
    free(root);
    recursive(root);

    return 0;
}

/* Demonstrate how to step through code. Show difference
   between step and continue. Also demonstrate print, 
   display, undisplay, and set. */
int function1()
{
    // Will break at beginning of function
    // Step through until loop
    int x = 0;
    int y = 0;

    // Print out variables throughout loop
    // After a few iterations, run 'display x' command

    // Run 'l' to show lines and put breakpoint on next line
    for ( ; x<10; x++)
    {
        if (x % 2 == 0)
            y++;
        else
            x++;
    }

    // Use finish command
    while (y < 1000000)
        y++;

    x = y;

    return 24;
}

/* Demonstrates how to move through a stack. 
   Also demonstrates reading pointers and 
   accessing memory at a memory address */
struct node *recursive(struct node *next_node)
{
    // Call 'print next_node'
    // Call 'print *next_node'
    // Call 'print *next_node->next'
    // Call 'bt' and 'info stack' and 'info frame'
    if (next_node == NULL)
        return NULL;
        // a note: you would NOT want to use an assert statement here, as next_node == NULL is a
        // base case. asserts will stop execution, while this behaves appropriately for recursion
    else
    {
        int useless = next_node->a + next_node->b;
        return recursive(next_node->next);
    }
}

void defensiveProgramming()
{
    char string[8];
    char string2[8];

    char *first_string = "********1234567";
    char *second_string = "abcdefg";

    // Copy a string WITHOUT a limit
    strcpy(string2, second_string);
    printf("string2 = %s\n", string2);

    strcpy(string, first_string);
    printf("string = %s\n\n", string2);

    // assert statements are a good way to check preconditions and postconditions, and are a good
    // defensive programming technique.
    // either of these assert statements would have gotten our attention:

    // assert(strlen(string) == strlen(string2));
    // assert(strlen(string) == 8);

    // NEVER COPY A STRING WITH strcpy!
    // strncpy (with an 'n') will include a limit of how many characters it should copy over

    strncpy(string2, second_string, 8);
    printf("string2 = %s\n", string2);

    strncpy(string, first_string, 8);
    printf("string = %s\n\n", string2);

    // But how does the computer know when a string ends?
    char *new_string1 = "12345678";
    strncpy(string, new_string1, 8);

    printf("string1 = %s\n", string);

    // We didn't leave room for the null character '\0'
    string[7] = '\0';
    printf("finalString = %s\n", string);
}



