#include<stdio.h>
#include<stdlib.h>

void generateOddMagicSquare_sak(int **magic_sak, int n_sak) {
    int i_sak = 0;
    int j_sak = n_sak / 2;
    int num_sak = 1;

    while (num_sak <= n_sak * n_sak) {
        magic_sak[i_sak][j_sak] = num_sak;
        num_sak++;

        int newi_sak = (i_sak - 1 + n_sak) % n_sak;
        int newj_sak = (j_sak + 1) % n_sak;

        if (magic_sak[newi_sak][newj_sak] != 0) {
            i_sak = (i_sak + 1) % n_sak;
        } else {
            i_sak = newi_sak;
            j_sak = newj_sak;
        }
    }
}

void generateDoublyEvenMagicSquare_sak(int **magic_sak, int n_sak) {
    int i_sak, j_sak;

    int num_sak = 1;
    for (i_sak = 0; i_sak < n_sak; i_sak++) {
        for (j_sak = 0; j_sak < n_sak; j_sak++) {
            magic_sak[i_sak][j_sak] = num_sak;
            num_sak++;
        }
    }

    for (i_sak = 0; i_sak < n_sak; i_sak++) {
        for (j_sak = 0; j_sak < n_sak; j_sak++) {
            if ((i_sak % 4 == j_sak % 4) || ((i_sak % 4 + j_sak % 4) == 3)) {
                magic_sak[i_sak][j_sak] = n_sak * n_sak + 1 - magic_sak[i_sak][j_sak];
            }
        }
    }
}

void generateSinglyEvenMagicSquare_sak(int **magic_sak, int n_sak) {
    int half_sak = n_sak / 2;
    int subSquareSize_sak = half_sak * half_sak;
    int i_sak, j_sak;

    int **temp_sak = (int **)malloc(half_sak * sizeof(int *));
    for (i_sak = 0; i_sak < half_sak; i_sak++) {
        temp_sak[i_sak] = (int *)malloc(half_sak * sizeof(int));
    }

    generateOddMagicSquare_sak(temp_sak, half_sak);

    for (i_sak = 0; i_sak < half_sak; i_sak++) {
        for (j_sak = 0; j_sak < half_sak; j_sak++) {
            magic_sak[i_sak][j_sak] = temp_sak[i_sak][j_sak];
            magic_sak[i_sak + half_sak][j_sak] = temp_sak[i_sak][j_sak] + 2 * subSquareSize_sak;
            magic_sak[i_sak][j_sak + half_sak] = temp_sak[i_sak][j_sak] + 3 * subSquareSize_sak;
            magic_sak[i_sak + half_sak][j_sak + half_sak] = temp_sak[i_sak][j_sak] + subSquareSize_sak;
        }
    }

    int k_sak = (n_sak - 2) / 4;
    for (i_sak = 0; i_sak < half_sak; i_sak++) {
        for (j_sak = 0; j_sak < k_sak; j_sak++) {
            int tempVal_sak = magic_sak[i_sak][j_sak];
            magic_sak[i_sak][j_sak] = magic_sak[i_sak + half_sak][j_sak];
            magic_sak[i_sak + half_sak][j_sak] = tempVal_sak;
        }
        for (j_sak = n_sak - k_sak + 1; j_sak < n_sak; j_sak++) {
            int tempVal_sak = magic_sak[i_sak][j_sak];
            magic_sak[i_sak][j_sak] = magic_sak[i_sak + half_sak][j_sak];
            magic_sak[i_sak + half_sak][j_sak] = tempVal_sak;
        }
    }

    for (i_sak = 0; i_sak < half_sak; i_sak++) free(temp_sak[i_sak]);
    free(temp_sak);
}

int main() {
    int **magic_sak;
    int n_sak;

    printf("Enter order of magic square: ");
    scanf("%d", &n_sak);

    magic_sak = (int **)malloc(n_sak * sizeof(int *));
    for (int i_sak = 0; i_sak < n_sak; i_sak++) {
        magic_sak[i_sak] = (int *)malloc(n_sak * sizeof(int));
        for (int j_sak = 0; j_sak < n_sak; j_sak++) {
            magic_sak[i_sak][j_sak] = 0;
        }
    }

    if (n_sak % 2 == 1) {
        generateOddMagicSquare_sak(magic_sak, n_sak);
    } else if (n_sak % 4 == 0) {
        generateDoublyEvenMagicSquare_sak(magic_sak, n_sak);
    } else {
        generateSinglyEvenMagicSquare_sak(magic_sak, n_sak);
    }

    printf("Magic Square of size %d is:\n", n_sak);
    for (int i_sak = 0; i_sak < n_sak; i_sak++) {
        for (int j_sak = 0; j_sak < n_sak; j_sak++) {
            printf("%4d ", magic_sak[i_sak][j_sak]);
        }
        printf("\n");
    }

    for (int i_sak = 0; i_sak < n_sak; i_sak++) free(magic_sak[i_sak]);
    free(magic_sak);

    return 0;
}
