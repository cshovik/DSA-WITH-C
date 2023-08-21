#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to perform matrix multiplication
int** matrixMultiply(int** mat1, int rows1, int cols1, int** mat2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return NULL;
    }

    int** result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 1;
    }

    int** mat1 = allocateMatrix(rows1, cols1);
    int** mat2 = allocateMatrix(rows2, cols2);

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    int** result = matrixMultiply(mat1, rows1, cols1, mat2, rows2, cols2);

    if (result) {
        printf("Resultant matrix:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        freeMatrix(result, rows1);
    }

    freeMatrix(mat1, rows1);
    freeMatrix(mat2, rows2);

    return 0;
}
