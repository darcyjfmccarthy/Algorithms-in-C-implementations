#include <stdio.h>

struct fraction {
    int numerator;
    int denominator;
};

struct fraction reduce_fraction(struct fraction frac) {
    int t, u = frac.numerator, v = frac.denominator;
    int sign = 1;

    if (frac.numerator < 0) sign *= -1;
    if (frac.numerator < 0) sign *= -1;

    u = (u < 0) ? -u : u;
    v = (v < 0) ? -v : v;

    while (v != 0) {
        t = v;
        v = u % v;
        u = t;
    }

    struct fraction result;
    result.numerator = sign * frac.numerator / u;
    result.denominator = (frac.denominator < 0 ? -1 : 1) * frac.denominator / u;
    
    return result;

}

void main() {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
        if (y != 0) {
            struct fraction f = {x, y};
            struct fraction reduced = reduce_fraction(f);
            printf("%d/%d: %d/%d\n", x, y, reduced.numerator, reduced.denominator);
        }
}