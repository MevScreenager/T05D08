#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int *n, double mean_v);
int rulse(int *a, int *n, int np);
double mean(int *a, int *n);
double root_mean_square(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) output(data, &n, mean(data, &n));
    else
    printf("n/a");
    return 0;
}

int rulse(int *a, int *n, int np) {
    double mean_v = mean(a, n), down, up, root_mean_square_v = root_mean_square(a, n);
    down = mean_v - 3 * root_mean_square_v;
    up = mean_v + 3 * root_mean_square_v;
    if (np >= down || np <= up) return 1;
    return 0;
}

double root_mean_square(int *a, int *n) {
    double mean_v = mean(a, n), sum = 0;
    for (int *p = a; p - a < *n; p++)
        sum = sum + pow(*p - mean_v, 2);
    return sqrt((sum * 1.0) / *n);
}

double mean(int *a, int *n) {
    int sum = 0;
    for (int *p = a; p - a < *n; p++) sum = sum + *p;
    return (sum * 1.0) / *n;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;

    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
        if (getchar() != 10) return 0;
    }
    if (getchar() != 10) return 0;
    return 1;
}

void output(int *a, int *n, double mean_v) {
    for (int *p = a; p - a < *n; p++) {
        if (*p % 2 == 0 && (*p > mean_v || *p == mean_v) && rulse(a, n, *p) && *p != 0) {
            printf("%d", *p);
            return;
        }
    }
    printf("%d", 0);
}
