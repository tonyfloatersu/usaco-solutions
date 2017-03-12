/*
ID: suhangt1
LANG: C
PROG: milk2
*/

#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct length {
    int start;
    int end;
} LEN;

int main() {
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    int cow_num;
    char hash_arr[1000005];
    fscanf(fin, "%d", &cow_num);
    int low_bd = 1000005, hgh_bd = 0;
    for (int i = 0; i < cow_num; i++) {
        LEN temp;
        fscanf(fin, "%d %d", &temp.start, &temp.end);
        low_bd = min(low_bd, temp.start);
        hgh_bd = max(hgh_bd, temp.end);
        for (int j = temp.start; j < temp.end; j++)
            hash_arr[j] = 1;
    }
    int max_milk_time = 0, max_idle_time = 0;
    int temp_count_milk = 0, temp_count_idle = 0;
    for (int i = low_bd; i <= hgh_bd; i++) {
        if (hash_arr[i] == 1)
            temp_count_milk += 1;
        else if (hash_arr[i] == 0)
            temp_count_idle += 1;
        if (hash_arr[i + 1] != hash_arr[i] && i <= hgh_bd) {
            if (hash_arr[i] == 1) {
                max_milk_time = max(max_milk_time, temp_count_milk);
                temp_count_milk = 0;
            } else if (hash_arr[i] == 0) {
                max_idle_time = max(max_idle_time, temp_count_idle);
                temp_count_idle = 0;
            }
        }
    }
    fprintf(fout, "%d %d\n", max_milk_time, max_idle_time);
    exit(0);
}
