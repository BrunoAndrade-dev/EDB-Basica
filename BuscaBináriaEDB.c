#include <stdio.h>

// Função para realizar a busca binária
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Se o elemento do meio for o nosso alvo
        if (arr[mid] == target) {
            return mid;
        }

        // Se o alvo for maior, ignore a metade esquerda
        if (arr[mid] < target) {
            left = mid + 1;
        }

        // Se o alvo for menor, ignore a metade direita
        else {
            right = mid - 1;
        }
    }

    // Se o elemento não for encontrado
    return -1;
}

int main() {
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target = 23;

    int result = binarySearch(sortedArray, size, target);

    if (result != -1) {
        printf("Elemento encontrado na posicao: %d\n", result);
    } else {
        printf("Elemento nao encontrado no array.\n");
    }

    return 0;
}
