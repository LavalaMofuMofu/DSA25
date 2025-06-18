#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


void sequentialSearch(){
    int target;
    vector<int> nums(100);
        mt19937_64 rng(random_device{}());
        uniform_int_distribution<int> dist(1, 50);
        for (auto &val: nums) 
        {
            val = dist(rng);
        }
        

    cout << "\nDaftar angka:\n";
    for (int i = 0; i < nums.size(); ++i) {
        cout << "[" << i << "]" << nums[i] << " ";
    }
    cout << "\n\n";

    cout << "Masukkan angka yang ingin dicari : ";
    cin >> target;
    cout << endl;
    cout << "Hasil Pencarian : " << endl;

    bool found = false;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            cout << "Angka " << target << " ditemukan di indeks ke-" << "[" << i << "]" << ".\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Angka " << target << " tidak ditemukan dalam daftar.\n";
    }
}

void binarySearch(){
    int target, size;
    cout << "Masukkan ukuran vector yang ingin dibuat : ";
    cin >> size;
    vector<int> nums(size);
        mt19937_64 rng(random_device{}());
        uniform_int_distribution<int> dist(1, 100);
        for (auto &val: nums) 
        {
            val = dist(rng);
        }

    sort(nums.begin(), nums.end());

    cout << "\nDaftar nums setelah diurutkan:\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]" << nums[i] << " ";
    }
    cout << "\n\n";

    cout << "Masukkan nums yang ingin dicari : ";
    cin >> target;
    cout << endl;

    cout << "Hasil Pencarian : " << endl;
    int kiri = 0, kanan = size - 1;
    bool found = false;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (nums[tengah] == target) {
            cout << "nums " << target << " ditemukan di indeks ke-" << "[" << tengah << "]"
                << " (dalam daftar terurut).\n";
            found = true;
            break;
        } else if (nums[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    if (!found) {
        cout << "nums " << target << " tidak ditemukan dalam daftar.\n";
    }
}

void clearScreen(){
    system("cls"); // Gunakan "clear" jika di Linux/Mac
}

void explain(){
    cout << "\n=== Penjelasan ===\n";

    cout << "1. Sequential Search (Pencarian Sekuensial):\n";
    cout << "   - Metode pencarian yang dilakukan dengan memeriksa setiap elemen secara berurutan dari awal hingga akhir.\n";
    cout << "   - Tidak memerlukan data dalam kondisi terurut, sehingga dapat diterapkan pada data acak.\n";
    cout << "   - Cocok digunakan untuk dataset kecil atau jika data tidak disortir.\n";
    cout << "   - Mudah diimplementasikan dan tidak membutuhkan struktur data tambahan.\n";
    cout << "   - Kompleksitas waktu dalam kasus terburuk adalah O(n), di mana n adalah jumlah elemen.\n";
    cout << "   - Kekurangannya: Tidak efisien untuk dataset yang besar karena memerlukan banyak perbandingan.\n\n";

    cout << "2. Binary Search (Pencarian Biner):\n";
    cout << "   - Metode pencarian yang bekerja dengan cara membagi dua bagian data yang sudah terurut.\n";
    cout << "   - Setiap langkah membandingkan elemen tengah dengan elemen yang dicari:\n";
    cout << "     Jika elemen tengah lebih kecil, pencarian dilanjutkan ke separuh kanan,\n";
    cout << "     jika lebih besar, ke separuh kiri.\n";
    cout << "   - Sangat efisien untuk dataset besar yang sudah dalam kondisi terurut.\n";
    cout << "   - Kompleksitas waktu dalam kasus terburuk adalah O(log n).\n";
    cout << "   - Kekurangannya: Hanya dapat digunakan jika data sudah terurut, jika belum maka perlu proses\n";
    cout << "     sorting terlebih dahulu.\n";
    cout << "   - Implementasi sedikit lebih kompleks dibandingkan Sequential Search.\n";
}

int main() {
    int opt;
    do {
        cout << "============================= " << endl;
        cout << "             MENU             " << endl;
        cout << "     SEARCHING ALGORITHM      " << endl;
        cout << "============================= " << endl;
        cout << "| 1. Sequential Searching" << endl;
        cout << "| 2. Binary Searching" << endl;
        cout << "| 3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "| 4. Exit" << endl;
        cout << "============================= " << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                sequentialSearch();
                break;
            }

            case 2: {
                binarySearch();
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH!" << endl;
                cout << "Programme was made by Muhammad Irgi Fahrezha (2410817210005)" << endl;
                break;

            default:
                cout << endl;
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi." << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}