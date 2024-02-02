#include <cstdio>
#include <cstdlib>

int** alloc2DInt(int rows, int cols) {
    if (rows <= 0 || cols <= 0)
        return NULL;

    int** mat = new int* [rows];

    for (int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
    }

    return mat;
}

void free2DInt(int** mat, int rows, int cols = 0) {
    if (mat != NULL) {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
}


void setMatrix(int** mat, int rows, int cols) {
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
//void set2Drandowm(int** mat, int rows, int cols) {
//    for (int i = 0; i < rows; i++)
//        for (int j = 0; j < cols; j++) {
//            mat[i][j] = rand() % 100;
//        }
//}

//void print2DInt(int** mat, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            printf("%4d", mat[i][j]);
//        }
//        printf("\n");
//    }
//}
void calculatePrintMat(int** A,int** B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] += B[i][j];
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int** matA;
    int** matB;
    int rows, cols;

    scanf("%d%d", &rows, &cols);
    matA = alloc2DInt(rows, cols); // 할당
    matB = alloc2DInt(rows, cols);
        
    setMatrix(matA, rows, cols);
    setMatrix(matB, rows, cols);
    //set2Drandowm(matA, rows, cols);
    calculatePrintMat(matA, matB, rows, cols);
    //print2DInt(matA, rows, cols);
    free2DInt(matA, rows, cols);
    free2DInt(matB, rows, cols);

    return 0;
}
