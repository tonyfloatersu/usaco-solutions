/*
ID: suhangt1
LANG: C
PROG: beads
*/

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct node {
    int lhs_rnum;
    int lhs_bnum;
    int rhs_rnum;
    int rhs_bnum;
} NODE;

int main() {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int bead_num;
    char beads[800];
    fscanf(fin, "%d", &bead_num);
    fscanf(fin, "%s", beads);
    for (int i = 0; i < bead_num; i++)
        beads[bead_num + i] = beads[i];
    int max_len = 0;
    NODE necklace[800];
    necklace[0].lhs_bnum = 0, necklace[0].lhs_rnum = 0;
    for (int i = 1; i < 2 * bead_num; i++) {
        if (beads[i - 1] == 'r')
            necklace[i].lhs_bnum = 0,
				necklace[i].lhs_rnum = 1 + necklace[i - 1].lhs_rnum;
        else if (beads[i - 1] == 'b')
            necklace[i].lhs_bnum = necklace[i - 1].lhs_bnum + 1,
				necklace[i].lhs_rnum = 0;
        else if (beads[i - 1] == 'w')
            necklace[i].lhs_bnum = necklace[i - 1].lhs_bnum + 1,
				necklace[i].lhs_rnum = necklace[i - 1].lhs_rnum + 1;
    }
    necklace[2 * bead_num - 1].rhs_rnum = 0, necklace[2 * bead_num - 1].rhs_bnum = 0;
    for (int i = 2 * bead_num - 2; i >= 0; i--) {
        if (beads[i + 1] == 'r')
            necklace[i].rhs_rnum = 1 + necklace[i + 1].rhs_rnum,
				necklace[i].rhs_bnum = 0;
        else if (beads[i + 1] == 'b')
            necklace[i].rhs_rnum = 0,
				necklace[i].rhs_bnum = necklace[i + 1].rhs_bnum + 1;
        else if (beads[i + 1] == 'w')
            necklace[i].rhs_rnum = necklace[i + 1].rhs_rnum + 1,
				necklace[i].rhs_bnum = necklace[i + 1].rhs_bnum + 1;
    }
    for (int i = 0; i < bead_num - 1; i++)
        max_len = max(max_len,
                      max(necklace[bead_num + i + 1].lhs_rnum, necklace[1 + bead_num + i].lhs_bnum)
                      + max(necklace[i].rhs_rnum, necklace[i].rhs_bnum));
    if (max_len < bead_num)
        fprintf(fout, "%d\n", max_len);
    else
        fprintf(fout, "%d\n", bead_num);
    exit(0);
}
