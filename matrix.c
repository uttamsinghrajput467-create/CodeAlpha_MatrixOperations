#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX],
                 int R[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            R[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX],
                      int R[MAX][MAX], int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            R[i][j] = 0;

            for (k = 0; k < c1; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int R[MAX][MAX], T[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    do {
        printf("\n====================================\n");
        printf("       MATRIX OPERATIONS\n");
        printf("====================================\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        if (choice == 4) {
            printf("Thank you for using Matrix Operations!\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        printf("Enter rows and columns of Matrix A: ");
        if (scanf("%d %d", &r1, &c1) != 2 ||
            r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX) {
            printf("Invalid matrix size!\n");
            return 1;
        }

        printf("Enter elements of Matrix A:\n");
        inputMatrix(A, r1, c1);

        if (choice == 1 || choice == 2) {
            printf("Enter rows and columns of Matrix B: ");

            if (scanf("%d %d", &r2, &c2) != 2 ||
                r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
                printf("Invalid matrix size!\n");
                return 1;
            }

            if (choice == 1 && (r1 != r2 || c1 != c2)) {
                printf("Addition not possible! Dimensions must match.\n");
                continue;
            }

            if (choice == 2 && c1 != r2) {
                printf("Multiplication not possible! Columns of A must equal rows of B.\n");
                continue;
            }

            printf("Enter elements of Matrix B:\n");
            inputMatrix(B, r2, c2);
        }

        switch (choice) {
            case 1:
                addMatrices(A, B, R, r1, c1);
                printf("\nAddition Result:\n");
                displayMatrix(R, r1, c1);
                break;

            case 2:
                multiplyMatrices(A, B, R, r1, c1, c2);
                printf("\nMultiplication Result:\n");
                displayMatrix(R, r1, c2);
                break;

            case 3:
                transposeMatrix(A, T, r1, c1);
                printf("\nTranspose Result:\n");
                displayMatrix(T, c1, r1);
                break;
        }

    } while (choice != 4);

    return 0;
}