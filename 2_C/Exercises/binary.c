#include <stdio.h>

void binary (int x) {

    int binarynumber[32];
    int i = 0;

    for (;x>0;) {
        binarynumber[i++] = x % 2;
        x /=2;
    }

    for (int j = i-1; j >= 0; j--)
        printf("%d", binarynumber[j]);

}

void main() {
    int x;
    while (scanf("%d", &x) != EOF)
        if (x > 0)
            binary(x);
}