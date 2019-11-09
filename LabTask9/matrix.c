#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STRLEN 1024

typedef char String[STRLEN];

double *input_matrix(int *row, int *col, String name) {
    double *m;
    String trash;
    printf("Enter the number of rows for %s: ",name);
    scanf("%d",row);
    fgets(trash,STRLEN,stdin);
    printf("Enter the number of columns for %s: ",name);
    scanf("%d",col);
    fgets(trash,STRLEN,stdin);
    if ((m = malloc((*row)*(*col)*sizeof(double))) == NULL) return NULL;
    printf("Enter each number for %s in row major order separated by spaces or newlines:\n",name);
    int i = 0;
    while (i < (*row)*(*col) && (scanf("%lf",m++)==1)) {i++;}
    fgets(trash,STRLEN,stdin);
    m-=(*row)*(*col);
    return m;
}

void output_matrix(double *m, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.4lf ", *(m++));
        }
        printf("\n");
    }
}

bool matrix_multiply(double *m1, int row1, int col1, double *m2, int row2, int col2, double *m3) {
    if (col1 != row2) { return false; }
    double *m1i;
    double *m2i;
    for (int row3 = 0; row3 < row1; row3++) {
        for (int col3 = 0; col3 < col2; col3++) {
            double sum = 0;
            m1i = m1 + row3 * col1;
            m2i = m2 + col3;
            for (int k = 0; k < col1; k++ ) {
                sum += (*m1i)*(*m2i);
                m1i += 1;
                m2i += col2;
            }
            *(m3++) = sum;
        }
    }
    return true;
}

int main(void) {
  double *m1,*m2,*m3;
  int m1_rows,m1_columns,m2_rows,m2_columns;
  if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
      ((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
      ((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
    printf("Matrix 1\n");
    output_matrix(m1,m1_rows,m1_columns);
    printf("Matrix 2\n");
    output_matrix(m2,m2_rows,m2_columns);
    if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
      printf("Product\n");
      output_matrix(m3,m1_rows,m2_columns);
      free(m1);
      free(m2);
      free(m3);
      return(0);
    } else {
      printf("Error in dimensions\n");
      free(m1);
      free(m2);
      free(m3);
      return(-1);
    }
  } else {
    free(m1);
    free(m2);
    free(m3);
    printf("Error allocating memory\n");
    return(-2);
  }
}
