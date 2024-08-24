#include <stdio.h>

#define MAX 100

int a[MAX][MAX];


int gcd(int u, int v) {
    int t;
    while (u > 0)
        {
            if (u < v)
                { t = u; u = v; v = t;}
            u = u - v;
        }
    return v;
}

int main() {
    int i, j;
    for (i = 1; i < MAX; i++) {
        for (j = 1; j < MAX; j++) {
            a[i][j] = (gcd(i, j) == 1) ? 1 : 0;
            printf("i: %d j: %d GCD: %d result: %d\n", i, j, gcd(i, j), a[i][j]);
        }
    }

    return 0;
}