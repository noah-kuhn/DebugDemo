/*
 *  Authors: Thomas Peavler and Noah Kuhn
 *
 */

/* Here are some fairly standard libraries */
#include <stdlib.h>     /* standard library */
#include <stdio.h>      /* standard input/output library */
#include <string.h>     /* standard string library */

#include "debug.h"      /* we also need to include our header file! this includes stdbool for us */

struct node
{
    int a;
    int b;
    struct node *next;
} *root;

int function1();
struct node *recursive(struct node *next_node);

/* this is similar to Java main: this is the actual function that executes */
int main() {
    printf("Welcome to this debugging demo! Find the bugs :)\n");

    // Create dummy linked list
    root = calloc(1, sizeof(struct node));
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
    else
    {
        int useless = next_node->a + next_node->b;
        return recursive(next_node->next);
    }
}



