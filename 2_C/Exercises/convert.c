#include <stdio.h>


int convert(int x) {
    int sum = 0;

    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}


void main() {
    int x;

    while (scanf("%d", &x) != EOF) {
        int result = convert(x);
        printf("Converted: %d", result);
    }
    
        
}