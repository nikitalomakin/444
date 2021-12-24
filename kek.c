#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int n, int *mass) {
    int newElement, location;
 
    for (int i = 1; i < n; i++) {
        newElement = mass[i];
        location = i - 1;
        while(location >= 0 && mass[location] > newElement) {
            mass[location + 1] = mass[location];
            location--;
        }
        mass[location + 1] = newElement;
    }
}

void initMatrix(FILE *file, int **matrix, int *rowsAndCols) {
    for (int i = 0; i < *rowsAndCols && !feof(file); i++) { // заполнение матрицы 
        for (int j = 0; j < *rowsAndCols && !feof(file); j++) {
            if (!fscanf(file, "%d", &matrix[i][j])) {
                exit (6);
            }
        }
    }

    fclose(file);
}

int countRowsAndCol(FILE *file) { // подсчёт строк и столбцов
    int rowsAndCols = 1; // 1 тк отсутствует newline в последней строчке

    while (!feof(file))
        if (fgetc(file) == '\n')
            rowsAndCols++;

    rewind(file);

    return rowsAndCols;
}

int main (void) {
    FILE *file = fopen("kek.txt", "r");
    int rows = countRowsAndCol(file);
    printf("Вершины с чётной степень вершины:\n");
    int **matrix = (int**) malloc((1 + rows) * sizeof(int *));
    for (int i = 0; i <= (rows * 2); i++)
        matrix[i] = (int *) malloc((1,
         + rows) * (sizeof(int)));

    initMatrix(file, matrix, &rows);
    int *mas = (int*) malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++)
        mas[i] = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (matrix[i][j] != 0) {
                mas[i]++;
            } 
        }
    }
    int *evenArr = (int*)malloc((1 + rows) * sizeof(int));
    int indEvenArr = 0;
    for (int i = 0; i < rows; i++) {
        if (mas[i] % 2 == 0) {
            evenArr[indEvenArr++] = mas[i];
            printf("Вершина %d - четная\n", i);
        }
    }
    printf("Usorted array of vertex:\n");
    for (int i = 0; i < indEvenArr; i++) {
        printf("%d ", evenArr[i]);
    }
    printf ("\n");

    InsertionSort(indEvenArr, evenArr);

    printf("Sorted array of vertex:\n");
    for (int i = 0; i < indEvenArr; i++) {
        printf("%d ", evenArr[i]);
    }
    printf("\n");
    return 0;
}
