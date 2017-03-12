/*
ID: suhangt1
LANG: C
PROG: dualpal
 */

#include <stdio.h>
#include <stdlib.h>

void base_trans(int target, int base, char *dest);

int is_dual(char *arr);

int main() {
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");
    int quantity, lower_bound;
    fscanf(fin, "%d %d", &quantity, &lower_bound);
    int current = lower_bound + 1;
    while (quantity > 0) {
        int times = 0;
        for (int i = 2; i <= 10; i++) {
            char transform[30];
            for (int j = 0; j < 30; j++)
                transform[j] = '\0';
            base_trans(current, i, transform);
            if (is_dual(transform))
                times += 1;
        }
        if (times >= 2) {
            quantity -= 1;
            fprintf(fout, "%d\n", current);
        }
        current += 1;
    }
    exit(0);
}

void base_trans(int target, int base, char *dest) {
    int place = 0;
    while (target != 0) {
        int current = target % base;
        target /= base;
        dest[place] = (char)('0' + current);
        place++;
    }
}

int is_dual(char *arr) {
    int len = 0;
    while (arr[len] != '\0')
        len += 1;
    int i = 0, result = 1;
    while (1) {
        if (arr[i] != arr[len - i - 1])
            result = 0;
        if (i != len - 1 - i && i + 1 != len - 1 - i)
            i += 1;
        else
            break;
    }
    return result;
}
