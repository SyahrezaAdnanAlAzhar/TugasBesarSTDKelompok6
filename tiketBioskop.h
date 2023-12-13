#include <iostream>
#define first(L) (L.first)
#define next(P) ((P)->next)
#define info(P) ((P)->info)
#define nextFilm(Q) ((Q)->nextFilm)


using namespace std;

// Penonton

struct penonton{
    string nama;
    string email;
    string nomorHp;
    int jumlahTiker;
};

typedef struct elmPenonton *adrPenonton;

struct elmPenonton{
    penonton info;
    adrPenonton next;
    listTiket tiket;

};

struct listPenonton{
    adrPenonton first;
};

//film

struct film{
    string nama;
    int menitDurasi;
    string jamTayang;
};

typedef struct elmFilm *adrFilm;

struct elmFilm{
    film info;
    adrFilm next;
};

struct listFilm{
    adrFilm first;
};

// Tiket

typedef struct elmTiket *adrTiket

struct elmTiket{
    string noKursi;
    adrFilm nextFilm;
    adrTiket next;
};

struct listTiket{
    adrTiket first;
};
