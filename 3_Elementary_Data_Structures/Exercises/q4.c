#include <stdio.h>
#include <stdlib.h>

int josephus(int n, int m) {
    int *circle = malloc(m * sizeof(int));
    int i, count = 0, position = 0;

    for (i = 0; i < m; i++) {
        // 1 means alive. We set everyone to alive at the start
        circle[i] = 1;
    }

    while (count < m - 1) { // loop until all but 1 person is dead
        for (i = 0; i < n; ) {
            // the mod below does the wrap-around if required
            // eg if we're at position 20/20 and we have to go one step forward,
            // 21 % 20 = 1. nice.
            position = (position + 1) % m;
            if (circle[position]) {
                i++;
            }
        }
        circle[position] = 0;
        count++;
    }

    // loop through until we find the alive guy
    for (i = 0; i < m; i++) {
        if (circle[i]) {
            free(circle);
            return i;
        }
    }
    
}

void main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int survivor = josephus(n, m);
    printf("Surivor: %d\n", survivor);
}