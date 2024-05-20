#include <stdio.h>

// Fungsi untuk menampilkan elemen-elemen dari sebuah array
void showArray(int Array[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

// Fungsi untuk mengurutkan sebuah array menggunakan algoritma insertion sort
// Array[]: array yang akan diurutkan
// N: jumlah elemen dalam array
// isEven: penanda apakah array berisi angka genap (1) atau ganjil (0)
void sortingInsertion(int Array[], int N, int isEven) {
    int key;
    // Iterasi dari elemen kedua hingga terakhir
    for (int i = 1; i < N; i++) {
        key = Array[i]; // Menyimpan elemen yang akan diurutkan
        int j = i - 1;

        // Memindahkan elemen array yang lebih besar dari key satu posisi ke depan
        while (j >= 0 && key < Array[j]) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key; // Menempatkan key pada posisi yang benar

        // Menampilkan array setelah setiap pass
        printf("Pass-%d: ", i);
        showArray(Array, N);
    }
}

int main() {
    int Array[100]; // Array untuk menyimpan angka input
    int jumlahElemen; // Jumlah elemen dalam array

    // Meminta input jumlah elemen array dari pengguna
    printf("Masukkan Jumlah Data Array: ");
    scanf("%d", &jumlahElemen);

    // Meminta input elemen-elemen array dari pengguna
    printf("Masukkan %d elemen pada Array: ", jumlahElemen);
    for (int i = 0; i < jumlahElemen; i++) {
        int temp;
        scanf("%d", &temp);
        // Memastikan hanya angka antara 1 dan 100 yang diterima
        if (temp >= 1 && temp <= 100) {
            Array[i] = temp;
        } else {
            i--; // Mengulangi iterasi jika input tidak valid
        }
    }

    // Array untuk menyimpan angka genap dan ganjil dari array input
    int arrayGanjil[100], arrayGenap[100];
    int jumlahGanjil = 0, jumlahGenap = 0;

    // Memisahkan array input menjadi angka genap dan ganjil
    for (int i = 0; i < jumlahElemen; i++) {
        if (Array[i] % 2 == 0) {
            arrayGenap[jumlahGenap++] = Array[i];
        } else {
            arrayGanjil[jumlahGanjil++] = Array[i];
        }
    }

    // Menampilkan dan mengurutkan array genap menggunakan insertion sort
    printf("\nData Array Genap Setelah Proses Insertion Sort:\n");
    sortingInsertion(arrayGenap, jumlahGenap, 1);

    // Menampilkan dan mengurutkan array ganjil menggunakan insertion sort
    printf("\nData Array Ganjil Setelah Proses Insertion Sort:\n");
    sortingInsertion(arrayGanjil, jumlahGanjil, 0);

    return 0; // Menandakan program berakhir dengan sukses
}
