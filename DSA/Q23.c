//Given n ropes and a target number of pieces k, find the maximum possible length to cut the ropes into at least k pieces using ternary search on the answer space.
#include <stdio.h>

int n, k;
double ropes[1000];

int pieces(double len) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int p = (int)(ropes[i] / len);
        count += p;
    }
    return count;
}

double ternarySearch(double l, double r) {
    for (int i = 0; i < 20; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        int p1 = pieces(m1);
        int p2 = pieces(m2);

        if (p1 >= k)
            l = m1;
        else
            r = m1;

        if (p2 >= k)
            l = m2;
        else
            r = m2;
    }
    return l;
}

int main() {
    printf("Enter number of ropes and required pieces: ");
    scanf("%d %d", &n, &k);

    double max = 0;

    printf("Enter rope lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &ropes[i]);
        if (ropes[i] > max) max = ropes[i];
    }

    double ans = ternarySearch(0, max);

    printf("\nMaximum possible piece length = %.6f\n", ans);

    return 0;
}
