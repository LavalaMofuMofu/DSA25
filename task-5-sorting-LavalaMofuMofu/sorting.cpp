#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <iomanip>
#include <conio.h>

using namespace std;

string nama = "MuhammadIrgiFahrezha";
string nim = "2410817210005";

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(10);
    cout << sortName << " took " << duration.count() << " seconds\n";
}

void insertionSort(string &str){
    for (int i = 1; i < str.size(); i++) {
        char key = str[i];
        int j = i - 1;

        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }

        str[j + 1] = key;
    }
}

void merge(string &str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char *tempL = new char[n1];
    char *tempR = new char[n2];

    for (int i = 0; i < n1; i++) tempL[i] = str[left + i];
    for (int j = 0; j < n2; j++) tempR[j] = str[mid +1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (tempL[i] <= tempR[j]) {
            str[k] = tempL[i];
            i++;
        } else {
            str[k] = tempR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        str[k] = tempL[i];
        i++;
        k++;
    }

    while (j < n2) {
        str[k] = tempR[j];
        j++;
        k++;
    }

    delete[] tempL;
    delete[] tempR;
}

void mergeSort(string &str, int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

void shellSort(string &str, int n){
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = str[i];

            int j;
            for (j = i; j >= gap && str[j - gap] > temp; j -= gap) str[j] = str[j - gap];

            str[j] = temp;
        }
    }
}

void bubbleSort(string &str){
    for (int i = 0; i < str.size() - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < str.size() - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

int partition(string &str, int low, int high) {
    int pivot = str[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (str[j] <= pivot) {
            i++;
            swap(str[i], str[j]);
        }
    }

    swap(str[i + 1], str[high]);

    return (i + 1);
}

void quickSort(string &str, int low, int high){
    if (low < high) {
        int p_idx = partition(str, low, high);
        quickSort(str, low, p_idx - 1);
        quickSort(str, p_idx + 1, high);
    }
}

void selectionSort(string &str){
    for (int i = 0; i < str.size() - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < str.size(); j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }

        swap(str[i], str[minIndex]);
    }
}


int main(){
    int ch;
    string temp;

    do {
        cout << "=====================================" << endl;
        cout << "=         - S O R T I N G -         =" << endl;
        cout << "=         A L G O R I T H M         =" << endl;
        cout << "=====================================" << endl;
        cout << "| Pilih Algoritma Sorting :         |" << endl;
        cout << "| => 1. Insertion Sort              |" << endl;
        cout << "| => 2. Merge Sort                  |" << endl;
        cout << "| => 3. Shell Sort                  |" << endl;
        cout << "| => 4. Bubble Sort                 |" << endl;
        cout << "| => 5. Quick Sort                  |" << endl;
        cout << "| => 6. Selection Sort              |" << endl;
        cout << "| => 7. Exit                        |" << endl;
        cout << "+===================================+" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> ch;
        cout << endl;

        switch(ch) {
            case 1:
                temp = nama;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {insertionSort(temp);}, "Insertion Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 2:
                temp = nama;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {mergeSort(temp, 0, temp.size() - 1); }, "Merge Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 3:
                temp = nama;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {shellSort(temp, temp.size()); }, "Shell Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 4:
                temp = nim;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {bubbleSort(temp); }, "Bubble Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 5:
                temp = nim;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {quickSort(temp, 0, temp.size() - 1); }, "Quick Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 6:
                temp = nim;
                cout << "Data Sebelum Diurutkan : " << temp << endl;
                cout << endl;
                timeSort([&]() {selectionSort(temp); }, "Selection Sort");
                cout << endl;
                cout << "Data Setelah Diurutkan : " << temp << endl;
                break;
            case 7:
                cout << "TERIMA KASIH!" << endl;
                cout << "This Program was Created by Muhammad Irgi Fahrezha (2410817210005)" << endl;
                break;
            default:
                cout << "Opsi Tidak Valid! Silahkan Coba Lagi." << endl;
        }
        cout << "\nPress any key to continue..." << endl;
        getch();
        system("cls");
    } 
    while (ch != 7);

    return 0;
}