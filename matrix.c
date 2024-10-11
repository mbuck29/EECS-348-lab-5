#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void add_matrices(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int sum[rows][cols]){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiply_matrices(int row_m1, int col_m1,  int row_m2, int col_m2, int m1[row_m1][col_m1], int m2[row_m2][col_m2], int product[row_m1][col_m2]){
    
    int total;
    for (int i = 0; i < row_m1; i++) {
        for (int j = 0; j < col_m2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < col_m1; k++) {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transpose_matrix(int row_m1, int col_m1, int m1[row_m1][col_m1], int result[row_m1][col_m1]){
    for(int i = 0; i < row_m1; i++){
        for(int j = 0; j < col_m1; j++){
            result[j][i] = m1[i][j];
        }
    }
}

void print_matrix(int row_m1, int col_m1, int m1[row_m1][col_m1]){
    for(int i = 0; i < row_m1; i++){
        for(int j= 0; j < col_m1; j++){
                printf("%-5d", m1[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    
    int row_m1 = sizeof(m1) / sizeof(m1[0]);
    int col_m1 = sizeof(m1[0]) / sizeof(m1[0][0]);
    int row_m2 = sizeof(m2) / sizeof(m2[0]);
    int col_m2 = sizeof(m2[0]) / sizeof(m2[0][0]);
    
    if((row_m1 != row_m2) || (col_m1 != col_m2)){
        printf("The size of the matrices do not match\n");
    }else{    
        printf("Add m1 and m2\n");
        int sum[row_m1][col_m1];
        add_matrices(row_m1, col_m1, m1, m2, sum);
        print_matrix(row_m1, col_m1, sum);
    }
    
    if(col_m1 != row_m2){
        printf("The number of columns of the first matrix does not match the number of rows of the second matrix\n");
    }else{
        printf("\nMultiply m1 and m2\n");
        int product[col_m1][row_m2];
        multiply_matrices(row_m1, col_m1, row_m2, col_m2, m1, m2, product);
        print_matrix(row_m1, col_m2, product);
    }
    printf("\nTranspose m1\n");
    int result[row_m1][col_m1];
    transpose_matrix(row_m1, col_m1, m1, result);
    print_matrix(row_m1, col_m1, result);
    

    return 0;
}