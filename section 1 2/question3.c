/*
ID: suhangt1
LANG: C
PROG: namenum
 */

#include <stdio.h>
#include <stdlib.h>

int eval(char bit);

void ctoi(char *bit, long long *result);

long long iatoi(long long *arr);

int main() {
    FILE *fin = fopen("namenum.in", "r");
    FILE *fout = fopen("namenum.out", "w");
    FILE *dict = fopen("namenumdict.txt", "r");
    long long num; fscanf(fin, "%lld", &num);
    long long dict_num[5000][15];
    char dict_origin[5000][15];
    int counter = 0;
    while (!feof(dict)) {
        fscanf(dict, "%s", dict_origin[counter]);
        ctoi(dict_origin[counter], dict_num[counter]);
        counter++;
    } // here all the dictionary are digitalized
    long long dictdigit[5000];
    for (int i = 0; i < counter; i++)
        dictdigit[i] = iatoi(dict_num[i]);
    int none = 0;
    for (int i = 0; i < counter; i++) {
        if (dictdigit[i] == num) {
            fprintf(fout, "%s\n", dict_origin[i]);
            none += 1;
        }
    }
    if (none == 0)
        fprintf(fout, "NONE\n");
    exit(0);
}

int eval(char bit) {
    if (bit <= 'P' && bit >= 'A')
        return 2 + (bit - 'A') / 3;
    else
        return 2 + (bit - 'A' - 1) / 3;
}

void ctoi(char *bit, long long *result) {
    int i = 0;
    while (bit[i] != '\0') {
        result[i] = eval(bit[i]);
        i += 1;
    }
}

long long iatoi(long long *arr) {
    long long result = 0, counter = 0;
    while (arr[counter] != 0) {
        result = result * 10 + arr[counter];
        counter += 1;
    }
    return result;
}
