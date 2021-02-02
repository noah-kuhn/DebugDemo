/*
 *  Authors: Thomas Peavler and Noah Kuhn
 *
 */

/* Here are some fairly standard libraries */
#include <stdlib.h>     /* standard library */
#include <stdio.h>      /* standard input/output library */
#include <string.h>     /* standard string library */

#include "debug.h"      /* we also need to include our header file! this includes stdbool for us */

int function1();

/* this is similar to Java main: this is the actual function that executes */
int main() {
    printf("Welcome to this debugging demo! Find the bugs :)\n");

    function1();

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
    // After a few iterations, run display command
    // There is a breakpoint on line 37
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

    return 0;
}



