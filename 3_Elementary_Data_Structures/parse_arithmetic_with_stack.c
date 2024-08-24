char c;

for (stackinit(); scanf("%ls", &c) != EOF;) {
    if (c == ')') printf("%lc", (char) pop());
    if (c == '+') push((int) c);
    if (c == '*') push((int) c);
    while (c >= '0' && c <= '9') {
        printf("%lc", c);
        scanf("%lc", &c);
    }

    if (c != '(') printf(" ");
}
printf("\n");