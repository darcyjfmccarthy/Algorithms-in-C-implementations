static struct node {
    int key;
    struct node *next;
};

static struct node *head, *z, *t;

struct node queueinit() {
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);
    head->next = z; head->key = 0;
    z->next = z;
    return *head;
}

void put(int v) {
    t = (struct node *) malloc(sizeof *t);
    t->key = v;
    t->next = z;
    
    struct node *current = head;
    while (current->next != z) {
        current = current->next;
    }

    current->next = t;
}

int get() {
    struct node *temp = head->next;
    int x = temp->key;
    head->next = temp->next;
    free(temp);
    return x;
}

int queueempty() {
    return head->next == z;
}