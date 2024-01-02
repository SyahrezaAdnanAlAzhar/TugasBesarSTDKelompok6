#include <iostream>
#include "tiketBioskop.h"

using namespace std;

int main()
{
    listFilm LF;
    listPenonton LP;
    int nFilm, nPenonton, pilihan = 0;
    string nomorKursi;
    adrFilm inputAdrF;
    adrPenonton inputAdrP;
    adrTiket inputAdrT;
    film inputF;
    penonton inputP;


    createListFilm(LF);
    createListPenonton(LP);

    pilihan = selectMenu();

    while (pilihan != 0){
        switch(pilihan){
            case 1:
                cout << "Masukkan jumlah film yang ingin anda tambahkan: ";
                cin >> nFilm;
                for (int i = 1; i <= nFilm; i++){
                    cout << "Masukkan data film ke-" << i << endl;
                    cout << "Nama: ";
                    cin >> inputF.nama;
                    cout << "Durasi (menit): ";
                    cin >> inputF.menitDurasi;
                    cout << "Jam Tayang: ";
                    cin >> inputF.jamTayang;
                    inputAdrF = createElmFilm(inputF.nama, inputF.menitDurasi, inputF.jamTayang);
                    tambahFilm(LF, inputAdrF);
                    cout << endl;
                }
                break;

            case 2:
                cout << "Masukkan jumlah penonton yang ingin anda tambahkan: ";
                cin >> nPenonton;
                for (int i = 1; i <= nPenonton; i++){
                    cout << "Masukkan data penonton ke-" << i << endl;
                    cout << "Nama: ";
                    cin >> inputP.nama;
                    cout << "Email: ";
                    cin >> inputP.email;
                    cout << "Nomor Handphone: ";
                    cin >> inputP.noHP;
                    inputAdrP = createElmPenonton(inputP.nama, inputP.email, inputP.noHP);
                    tambahPenonton(LP, inputAdrP);
                    cout << endl;
                }
                break;

            case 3:
                cout << "Masukkan nama penonton: ";
                cin >> inputP.nama;
                inputAdrP = searchPenonton(LP, inputP.nama);
                cout << endl;
                while (inputAdrP == NULL){
                    cout << "Data penonton tidak ditemukkan." << endl;
                    cout << "Silahkan masukkan kembali nama penonton. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama penonton: ";
                    cin >> inputP.nama;
                    inputAdrP = searchPenonton(LP, inputP.nama);
                    if (inputP.nama == "CANCEL"){
                        break;
                    }
                }

                cout << endl << "Masukkan nama film: ";
                cin >> inputF.nama;
                inputAdrF = searchFilm(LF, inputF.nama);
                cout << endl;
                while (inputAdrF == NULL){
                    cout << "Data film tidak ditemukan." << endl;
                    cout << "Silahkan masukkan kembali nama film. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama film: ";
                    cin >> inputF.nama;
                    inputAdrF = searchFilm(LF, inputF.nama);
                    if (inputF.nama == "CANCEL"){
                        break;
                    }
                }

                cout << endl << "Masukkan nomor kursi: ";
                cin >> nomorKursi;
                inputAdrT = searchNoKursiWithFilm(LP, inputF.nama, nomorKursi);
                cout << endl;

                while (inputAdrT != NULL){
                    cout << "Sudah ada penonton yang memesan nomor kursi tersebut." << endl;
                    cout << "Silahkan masukkan kembali nomor kursi. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nomor kursi: ";
                    cin >> nomorKursi;
                    inputAdrT = searchNoKursiWithFilm(LP, inputF.nama, nomorKursi);
                    if (nomorKursi == "CANCEL"){
                        break;
                    }
                }

                membeliTiket(LP, LF, inputP.nama, inputF.nama, nomorKursi);
                break;

            case 4:
                cout << "Masukkan nama penonton: ";
                cin >> inputP.nama;
                inputAdrP = searchPenonton(LP, inputP.nama);
                cout << endl;
                while (inputAdrP == NULL){
                    cout << "Data penonton tidak ditemukkan." << endl;
                    cout << "Silahkan masukkan kembali nama penonton. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama penonton: ";
                    cin >> inputP.nama;
                    inputAdrP = searchPenonton(LP, inputP.nama);
                    if (inputP.nama == "CANCEL"){
                        break;
                    }
                }

                if (infoPenonton(inputAdrP).jumlahTiket == 0){
                    cout << "Penonton atas nama " << inputP.nama << " tidak memiliki pemesanan tiket film." << endl;
                    break;
                }

                cout << endl << "Masukkan nama film: ";
                cin >> inputF.nama;
                inputAdrT = searchTiket(LP, LF, inputP.nama, inputF.nama);
                cout << endl;
                while (inputAdrT == NULL){
                    cout << "Data pemesanan tiket film atas nama" << inputP.nama << "tidak ditemukan." << endl;
                    cout << "Silahkan masukkan kembali nama film. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama film: ";
                    cin >> inputF.nama;
                    inputAdrT = searchTiket(LP, LF, inputP.nama, inputF.nama);
                    if (inputF.nama == "CANCEL"){
                        break;
                    }
                }

                hapusElmTiket(LP, LF, inputAdrP, inputP.nama, inputF.nama);
                break;

            case 5:
                cout << "Masukkan nama film yang ingin anda hapus: ";
                cin >> inputF.nama;
                inputAdrF = searchFilm(LF, inputF.nama);
                cout << endl;
                while (inputAdrF == NULL){
                    cout << "Data film tidak ditemukan." << endl;
                    cout << "Silahkan masukkan kembali nama film. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama film: ";
                    cin >> inputF.nama;
                    inputAdrF = searchFilm(LF, inputF.nama);
                    if (inputF.nama == "CANCEL"){
                        break;
                    }
                }
                hapusElmFilm(LF, inputF.nama, LP);
                break;

            case 6:
                cout << "Masukkan nama penonton yang ingin anda hapus: ";
                cin >> inputP.nama;
                inputAdrP = searchPenonton(LP, inputP.nama);
                cout << endl;
                while (inputAdrP == NULL){
                    cout << "Data penonton tidak ditemukkan." << endl;
                    cout << "Silahkan masukkan kembali nama penonton. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama penonton: ";
                    cin >> inputP.nama;
                    inputAdrP = searchPenonton(LP, inputP.nama);
                    if (inputP.nama == "CANCEL"){
                        break;
                    }
                }
                hapusElmPenonton(LP, inputP.nama);
                break;

            case 7:
                cout << "Masukkan nama penonton yang ingin anda periksa tiketnya: ";
                cin >> inputP.nama;
                inputAdrP = searchPenonton(LP, inputP.nama);
                cout << endl;
                while (inputAdrP == NULL){
                    cout << "Data penonton tidak ditemukkan." << endl;
                    cout << "Silahkan masukkan kembali nama penonton. Jika ingin kembali ke menu utama ketik CANCEL." << endl;
                    cout << "Masukkan nama penonton: ";
                    cin >> inputP.nama;
                    inputAdrP = searchPenonton(LP, inputP.nama);
                    if (inputP.nama == "CANCEL"){
                        break;
                    }
                }
                printAllTiket(inputAdrP);
                break;

            case 8:
                printAllFilm(LF);
                break;

            case 9:
                printAllPenonton(LP);
                break;

            case 10:
                printAllPenontonWithTiket(LP, LF);
                break;

        }
        pilihan = selectMenu();
    }


    return 0;
}
