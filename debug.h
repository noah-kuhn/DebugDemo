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

void create_dummy_list(struct node *root);
int function1();
struct node *recursive(struct node *next_node);
struct node *recursive_segfault(struct node *next_node);
void defensiveProgramming();
