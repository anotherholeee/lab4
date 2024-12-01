#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define I 100

void findzero(int arr[I][I], int z, int x) {
    int count = 0;
    for (int j = 0; j < x; j++) {
        for (int i = 0; i < z; i++) {
            if (arr[i][j] == 0) {
                count++;
                break;
            }
        }
    }
    printf("\n количество столбцов с 0: %d", count);
}

void maxf(int arr[I][I], int z, int x) {
    int longest = 0, row = 0;
    for (int i = 0; i < z; i++) {
        int count = 0;
        for (int j = 1; j < x; j++) {
            if (arr[i][j] == arr[i][j - 1]) {
                count++;
            }
            else {
                count = 0;
            }
            if (count > longest) {
                longest = count;
                row = i;
            }
        }
    }
    printf(" наибольшая серия в %d строке", row + 1);
}

int main() {
    setlocale(LC_ALL, "");
    int z, x, v;
    int arr[I][I];
    printf("введите размерность массива ");

    while (1) {
        if (scanf_s("%d%d", &z, &x) != 2 || z > I || x > I || z <= 0 || x <= 0) {
            printf("ошибка, неправильный ввод, попробуйте снова ");
            while (getchar() != '\n');
        }
        else {
            break;
        }
    }

    printf("ввести массив с клавиатуры - 1 \nввести случайные элементы массива - любая клавиша \n");
    scanf_s("%d", &v);

    if (v != 1) {
        srand(time(NULL));
        for (int i = 0; i < z; i++) {
            printf("\n");
            for (int j = 0; j < x; j++) {
                arr[i][j] = rand() % 4;
                printf("%d ", arr[i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < z; i++) {
            printf("\n");
            for (int j = 0; j < x; j++) {
                scanf_s("%d", &arr[i][j]);
            }
        }
    }

    findzero(arr, z, x);
    printf("\n");
    maxf(arr, z, x);

    return 0;
}
