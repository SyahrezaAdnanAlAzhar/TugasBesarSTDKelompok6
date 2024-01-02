#include <iostream>
#define firstPenonton(L) (L.firstPenonton)
#define firstFilm(L) (L.firstFilm)
#define firstTiket(P) ((P)->firstTiket)
#define nextPenonton(P) ((P)->nextPenonton)
#define nextFilm(P) ((P)->nextFilm)
#define nextTiket(P) ((P)->nextTiket)
#define infoPenonton(P) ((P)->infoPenonton)
#define infoFilm(P) ((P)->infoFilm)
#define tiketFilm(P) ((P)->tiketFilm)
#define noKursi(P) ((P)->noKursi)

using namespace std;

typedef struct elmTiket *adrTiket;
typedef struct elmPenonton *adrPenonton;
typedef struct elmFilm *adrFilm;

// Penonton

struct penonton{
    string nama;
    string email;
    string noHP;
    int jumlahTiket;
};

struct elmPenonton{
    penonton infoPenonton;
    adrPenonton nextPenonton;
    adrTiket firstTiket;

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

struct elmFilm{
    film infoFilm;
    adrFilm nextFilm;
};

struct listFilm{
    adrFilm firstFilm;
};

// Tiket

struct elmTiket{
    string noKursi;
    adrFilm tiketFilm;
    adrTiket nextTiket;
};

/*
struct listTiket{
    adrTiket firstTiket;
};
*/

void createListPenonton(listPenonton &LP);
void createListFilm(listFilm &LF);
adrPenonton createElmPenonton(string nama, string email, string noHP);
adrFilm createElmFilm(string nama, int menitDurasi, string jamTayang);
void membeliTiket(listPenonton &LP, listFilm LF, string namaPenonton, string namaFilm, string noKursi);
void tambahPenonton(listPenonton &LP, adrPenonton PPenonton);
void tambahFilm(listFilm &LF, adrFilm PFilm);
void printAllPenonton(listPenonton LP);
void printAllFilm(listFilm LF);
void hapusElmPenonton(listPenonton &LP, string nama);
void hapusElmFilm(listFilm &LF, string nama, listPenonton &LP);
void hapusElmTiket(listPenonton &LP, listFilm LF, adrPenonton &PPenonton, string namaPenonton, string namaFilm);
void deleteFirstTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteLastTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteAfterTiket(listPenonton &LP, adrPenonton &PPenonton, adrTiket precTiket);
void deleteAllTiket(listPenonton &LP, adrPenonton &PPenonton);
void deleteTiketWithSpesificFilm(listPenonton &LP, adrFilm PFilm, listFilm &LF);
void deleteFirstPenonton(listPenonton &LP);
void deleteLastPenonton(listPenonton &LP);
void deleteAfterPenonton(listPenonton &LP, adrPenonton prec);
void deleteFirstFilm(listFilm &LF, listPenonton &LP);
void deleteLastFilm(listFilm &LF, listPenonton &LP);
void deleteAfterFilm(listFilm &LF, adrFilm prec, listPenonton &LP);
adrPenonton searchPenonton(listPenonton LP, string nama);
adrFilm searchFilm(listFilm LF, string nama);
adrTiket searchTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm);
adrTiket searchNoKursiWithFilm(listPenonton LP, string namaFilm, string noKursi);
void printSpecificTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm);
void printAllTiket(adrPenonton PPenonton);
void printAllPenontonWithTiket(listPenonton LP, listFilm LF);
int selectMenu();
