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
#define noKursi(P) ((P)->noKursi)

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
adrTiket createElmTiket(string noKursi); //ini kayaknya perlu buat elemen tiket, udah ku include in di procedure membeliTiket Qi, oh gitu yaudauh :V
void membeliTiket(listPenonton &LP, listFilm LF, string namaPenonton, string namaFilm, int noKursi);
void tambahPenonton(listPenonton &LP, adrPenonton PPenonton);
void tambahFilm(listFilm &LF, adrFilm PFilm);
void printAllPenonton(listPenonton LP);
void printAllFilm(listFilm LF);
void hapusElmPenonton(listPenonton &LP, string nama);
void hapusElmFilm(listFilm &LF, string nama);
void deleteFirstTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteLastTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteAfterTiket(listPenonton &LP, adrPenonton &PPenonton, adrTiket precTiket);
void deleteAllTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteTiketWithSpesificFilm(listPenonton &LP, adrFilm PFilm);
void deleteFirstPenonton(listPenonton &LP);
void deleteLastPenonton(listPenonton &LP);
void deleteAfterPenonton(listPenonton &LP, adrPenonton prec);
void deleteFirstFilm(listFilm &LF, listPenonton &LP);
void deleteLastFilm(listFilm &LF, listPenonton &LP);
void deleteAfterFilm(listFilm &LF, adrFilm prec, listPenonton &LP);
adrPenonton searchPenonton(listPenonton LP, string nama);
adrFilm searchFilm(listFilm LF, string nama);
adrTiket searchTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm);
void printSpecificTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm);
void printAllTiket(listPenonton LP, listFilm LF);
int selectMenu();
