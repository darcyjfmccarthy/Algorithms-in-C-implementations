#define max 100

static int stack[max+1], p;

push(int v) {
    stack[p++] = v;
}

int pop() {
    return stack[--p];
}

stackinit() {
    p = 0;
}

int stackempty() {
    return !p;
}