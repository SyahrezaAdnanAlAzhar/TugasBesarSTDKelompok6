#include <iostream>
#define firstPenonton(L) (L.firstPenonton)
#define firstFilm(L) (L.firstFilm)
#define firstTiket(L) (L.firstTiket)
#define nextPenonton(P) ((P)->nextPenonton)
#define nextFilm(P) ((P)->nextFilm)
#define nextTiket(P) ((P)->nextTiket)
#define infoPenonton(P) ((P)->infoPenonton)
#define infoFilm(P) ((P)->infoFilm)
#define tiketFilm(P) ((P)->tiketFilm)

using namespace std;

// Penonton

struct penonton{
    string nama;
    string email;
    string noHP;
    int jumlahTiket;
};

typedef struct elmPenonton *adrPenonton;

struct elmPenonton{
    penonton infoPenonton;
    adrPenonton nextPenonton;
    listTiket tiket;

};

struct listPenonton{
    adrPenonton firstPenonton;
};

//film

struct film{
    string nama;
    int menitDurasi;
    string jamTayang;
};

typedef struct elmFilm *adrFilm;

struct elmFilm{
    film infoFilm;
    adrFilm nextFilm;
};

struct listFilm{
    adrFilm firstFilm;
};

// Tiket

typedef struct elmTiket *adrTiket

struct elmTiket{
    string noKursi;
    adrFilm tiketFilm;
    adrTiket nextTiket;
};

struct listTiket{
    adrTiket firstTiket;
};

void createListPenonton(listPenonton &LP);
void createListFilm(listFilm &LF);
adrPenonton createElmPenonton(string nama, string email, string noHP);
adrFilm createElmFilm(string nama, int menitDurasi, string jamTayang);
adrTiket createElmTiket(string noKursi); //ini kayaknya perlu buat elemen tiket
void membeliTiket(string namaPenonton, string namaFilm);
void tambahPenonton(listPenonton &LP, adrPenonton P);
void printAllPenonton(listPenonton LP);
void printAllFilm(listFilm LF);
adrPenonton searchPenonton(listPenonton LP, string nama);
adrFilm searchFilm(listFilm LF, string nama);
void tambahTiket(listPenonton &LP, listFilm LF, string noKursi, string namaPenonton, string namaFilm);
void printInfoNonton(listPenonton LP, listFilm LF));
void deleteTiket(listPenonton &LP, string namaFilm);
