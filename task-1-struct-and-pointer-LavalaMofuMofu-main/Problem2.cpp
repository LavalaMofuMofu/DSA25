#include<iostream>

using namespace std;

struct Info_Kendaraan {
    string plat_nomor_kendaraan;
    string jenis_kendaraan;
    string Nama_Pemilik;
    string Alamat;
    string Kota;
};

int main(){

    Info_Kendaraan kendaraan;

    kendaraan.plat_nomor_kendaraan = "DA1234MK";
    kendaraan.jenis_kendaraan = "RUSH";
    kendaraan.Nama_Pemilik = "Andika Hartanto";
    kendaraan.Alamat = "Jl. Kayu Tangi 1";
    kendaraan.Kota = "Banjarmasin";

    cout << "===== Info Kendaraan =====" << endl;
    cout << "Plat Nomor Kendaraan  : " << kendaraan.plat_nomor_kendaraan << endl;
    cout << "Jenis Kendaraan       : " << kendaraan.jenis_kendaraan << endl;
    cout << "Nama Pemilik          : " << kendaraan.Nama_Pemilik << endl;
    cout << "Alamat                : " << kendaraan.Alamat << endl;
    cout << "Kota                  : " << kendaraan.Kota << endl; 

    return 0;
}