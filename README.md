# DebugDemo

**Just a little debugging demo**

*Authors: Thomas Peavler and Noah Kuhn*

# Get the Code
Simply clone the repository and you're good to go.

# How to Run
Here is a good reference to have open while you go through
this demo: (https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf)

1) Run `make` which will create an object called `debug`

2) Then run `debug` in gdb by running the command `gdb debug`

3) To save you time from putting breakpoints on all of the files, 
run `source breakpoints.txt` to automatically load in several
breakpoints

4) Type `run` to run the program

You should also pull up `debug.c` which contains comments that
walks through several commands that demonstrate the functionality
of gdb. Feel free to try any command you would like, the comments
are simply suggestions.

Note: The code will segfualt at the end of execution


