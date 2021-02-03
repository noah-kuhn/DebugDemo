/*
 *  Authors: Thomas Peavler and Noah Kuhn
 *
 */

struct node
{
    int a;
    int b;
    struct node *next;
};

int function1();
struct node *recursive(struct node *next_node);
void defensiveProgramming();
