struct node {
    int key;
    struct node *next;
};

struct node *head, *z, *t;

struct node *listinitialize() {
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);
    head->next = z;
    z->next = z;

    return head;
}

void deletenext(struct node *t) {
    t->next = t->next->next;
}

struct node *insertafter(int v, struct node *t) {
    struct node *x;
    x = (struct node *) malloc(sizeof *x);
    x->key = v; x->next = t->next;
    t->next = x;
    return x;
}

void movenexttofront(struct node *t) {
    struct node *v;
    v = t->next;

    t->next = v->next;
    v->next = head->next;
    head->next = v;

}

void exchange(struct node *t, struct node *u) {
    struct node *temp = t->next;
    t->next = u->next;
    u->next = temp;
}
