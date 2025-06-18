#include<iostream>

using namespace std;

struct Masukkan {
    char huruf;
    char kata [100];
    int angka;
};

int main(){

    Masukkan input;

    cout << "Masukkan sebuah huruf = ";
    cin >> input.huruf;
    cout << "Masukkan Sebuah Kata  = ";
    cin >> input.kata;
    cout << "Masukkan Angka        = ";
    cin >> input.angka;

    cout << "Huruf yang Anda masukkan adalah = " << input.huruf << endl;
    cout << "Kata yang Anda masukkan adalah  = " << input.kata << endl;
    cout << "Angka yang Anda masukkan adalah = " << input.angka << endl;   

    return 0;
}