#include <stdlib.h>
#include <stdio.h>

struct node {
    char info;
    struct node *l, *r;
};

struct node *x, *z;

char c;

z = (struct node *) malloc(sizeof *z);
z->l = z; z->r = z;

for (stackinit(); scanf("%ls", &c) != EOF;) {
    x = (struct node *) malloc(sizeof *x);
    x->info = c; x->l = z; x->r = z;
    if (c== '+' || c== '*') {
        x->r = pop(); x->l = pop();
    }
    push(x);
}
