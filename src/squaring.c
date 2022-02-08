#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
void squaring(int *a, int *n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, &n);
        output(data, &n);
        } else {
        printf("n/a");
        }
    return 0;
}

int input(int *a, int *n) {
    if (!scanf("%d", n)) return 0;
    if ((int *) n  != n) return 0;

    for (int *p = a; p - a < *n; p++) {
        if (!scanf("%d", p)) return 0;
        if ((int *) p  != p) return 0;
    }
    if (getchar() != 10) return 0;
    return 1;
}

void squaring(int *a, int *n) {
    for (int *p = &a[0]; p - a < *n; p++) *p = *p * *p;
}

void output(int *a, int *n) {
    for (int *p = a; p - a < *n; p++) {
        if (p - a == *n - 1) {
            printf("%d", *p);
            return;
        }
        printf("%d ", *p);
    }
}
