#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, &n);
        output_result(max(data, &n),
                  min(data, &n),
                  mean(data, &n),
                  variance(data, &n));
    } else printf("n/a");
    return 0;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

int max(int *a, int *n) {
    int max = a[0];
    for (int *p = a; p - a < *n; p++)
        if (*p > max)
            max = *p;
    return max;
}
int min(int *a, int *n) {
    int min = a[0];
    for (int *p = a; p - a < *n; p++)
        if (*p < min)
            min = *p;
    return min;
}
double mean(int *a, int *n) {
    int sum = 0;
    for (int *p = a; p - a < *n; p++) sum = sum + *p;
    return (sum * 1.0) / *n;
}
double variance(int *a, int *n) {
    int sum = 0;
    for (int *p = a; p - a < *n; p++) sum = sum + (*p * *p);
    return (sum * 1.0) / *n - mean(a, n) * mean(a, n);
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;

    for(int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
    }
    return 1;
}

void output(int *a, int *n) {
    for(int *p = a; p - a < *n; p++) printf("%d ", *p);
    printf("\n");
}


