preorder_traversal(struct node *t) {
    push(t);
    while (!stackempty()) {
        t = pop(); visit(t);
        if (t->r != z) push(t->r);
        if (t->l != z) push(t->l);
    }
}

inorder_traversal(struct node *t) {
    while (t != z) {
        push(t);
        t = t->l;
    }
    if (stackempty()) break;
    t = pop();
    visit(t);
    t = t->r;
}

postorder_traversal(struct node *t) {
    struct node *lastVisited = z;
    while (t != z) {
        push(t);
        t = t->l;
    }
    if (stackempty()) break;
    t = peek();
    if (t->r != z && lastVisited != t->r) {
        t = t->r;
    } else {
        visit(t);
        lastVisited = pop();
        t = z;
    }
}