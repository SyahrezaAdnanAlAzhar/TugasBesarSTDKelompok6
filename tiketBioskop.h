#include <iostream>


using namespace std;

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
};

struct film{
    string nama;
    int menitDurasi;
    string jamTayang;
};
