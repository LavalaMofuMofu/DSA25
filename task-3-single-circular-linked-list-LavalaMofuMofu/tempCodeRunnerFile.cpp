#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void tambahDepan(int nilai) {
    Node* baru = new Node{nilai, head};
    head = baru;

    cout << "Data " << nilai << " berhasil ditambahkan di depan. \n";
}

void tambahBelakang(int nilai) {
    Node* baru = new Node{nilai, NULL};
    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }

    cout << "Data " << nilai << " berhasil ditambahkan di belakang. \n";
}

void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }
    Node* hapus = head;
    head = head->next;
    delete hapus;
    cout << "Data di depan berhasil dihapus.\n";
}

void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Data di belakang berhasil dihapus.\n";
        return;
    }
    Node* bantu = head;
    while (bantu->next->next != NULL) {
        bantu = bantu->next;
    }
    delete bantu->next;
    bantu->next = NULL;
    cout << "Data di belakang berhasil dihapus.\n";
}

void tampilkan() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }
    Node* bantu = head;
    while (bantu != NULL) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int pil;
char pilihan[1];

int main() {

    do {
        cout << "Single Linked List Non-Circular (SLLNC)\n";
        cout << "==================================\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Hapus Depan\n";
        cout << "4. Hapus Belakang\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil) {
            case 1: {
                int nilai;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahDepan(nilai);
                break;
            }
            case 2: {
                int nilai;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahBelakang(nilai);
                break;
            }
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

        cout << "\nPress any key to continue!";
        getch();
        system("cls");
    }while (pil < 7);
}
