#include <stdio.h>

// Fungsi untuk mengurutkan array menggunakan Shell Sort
// array[]: array yang akan diurutkan
// length: jumlah elemen dalam array
void shellSort(int array[], int length) {
    int gap, i, j, temp;
    // Mengatur gap dan menguranginya hingga menjadi 0
    for (gap = length / 2; gap > 0; gap /= 2) {
        // Iterasi melalui elemen array yang sesuai dengan gap saat ini
        for (i = gap; i < length; i++) {
            temp = array[i]; // Menyimpan nilai elemen saat ini
            // Menggeser elemen array untuk menemukan posisi yang benar untuk temp
            for (j = i; j >= gap && array[j - gap] < temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp; // Menempatkan temp pada posisi yang benar
        }
    }
}

// Fungsi untuk mencetak elemen-elemen array
// array[]: array yang akan dicetak
// length: jumlah elemen dalam array
void printArray(int array[], int length) {
    printf("Data Array Setelah Proses Shell Sort: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[100]; // Array untuk menyimpan angka input
    int length = 0; // Jumlah elemen dalam array
    int inputNumber; // Variabel untuk menyimpan input pengguna

    // Meminta input elemen array dari pengguna
    printf("Masukkan elemen pada Array (akhiri dengan -99): ");
    scanf("%d", &inputNumber);

    // Terus meminta input hingga pengguna memasukkan -99
    while (inputNumber != -99) {
        array[length++] = inputNumber; // Menyimpan input ke dalam array

        // Menampilkan array setelah setiap proses sorting
        printf("\n--- Data Array Setelah Proses Shell Sort ---\n");
        shellSort(array, length);
        printArray(array, length);

        // Menampilkan gap yang digunakan dalam proses sorting
        printf("Gaps yang digunakan: ");
        for (int gap = length / 2; gap > 0; gap /= 2) {
            printf("%d ", gap);
        }
        printf("\n");

        // Meminta input elemen berikutnya dari pengguna
        printf("Masukkan elemen pada Array (akhiri dengan -99): ");
        scanf("%d", &inputNumber);
    }

    return 0; // Menandakan program berakhir dengan sukses
}
