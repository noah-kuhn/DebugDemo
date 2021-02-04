# DebugDemo

Just a little debugging demo with gdb. It will require you to
look at the comments in `debug.c` to understand what commands to
run. 

# Get the Code
Simply clone the repository and you're good to go.

# How to Run
Here is a good reference to have open while you go through
this demo: (https://users.ece.utexas.edu/~adnan/gdb-refcard.pdf)

1) Run `make` which will create an object called `debug`

2) Then run `gdb debug` to execute debug in gdb

3) To save you time from putting breakpoints on all of the functions, 
run `source breakpoints.txt` to automatically load in several
breakpoints

4) Type `run` to run the program

You should also pull up `debug.c` which contains comments that
walk through several commands that demonstrate the functionality
of gdb. Feel free to try any command you would like, the comments
are simply suggestions.

Note: The code will segfualt at the end of execution


