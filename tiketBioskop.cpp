#include "tiketBioskop.h"

void createListPenonton(listPenonton &LP){
    firstPenonton(LP) = NULL;
}

void createListFilm(listFilm &LF){
    firstFilm(LF) = NULL;
}

adrPenonton createElmPenonton(string nama, string email, string noHP){
    adrPenonton P = new elmPenonton;
    infoPenonton(P).nama = nama;
    infoPenonton(P).email = email;
    infoPenonton(P).noHP = noHP;
    infoPenonton(P).jumlahTiket = 0;
    nextPenonton(P) = NULL;
    return P;
}

adrFilm createElmFilm(string nama, int menitDurasi, string jamTayang){
    adrFilm P = new elmFilm;
    infoFilm(P).nama = nama;
    infoFilm(P).menitDurasi = menitDurasi;
    infoFilm(P).jamTayang = jamTayang;
    nextFilm(P) = NULL;
    return P;
}

void membeliTiket(listPenonton &LP, listFilm LF, string namaPenonton, string namaFilm, string noKursi){
    adrPenonton PPenonton = searchPenonton(LP, namaPenonton);
    adrFilm PFilm = searchFilm(LF, namaFilm);
    adrTiket P, PTiket = new elmTiket;

    if (PPenonton == NULL){
        cout << "Tidak ada data penonton dengan nama " << namaPenonton << endl;
    }
    if (PFilm == NULL){
        cout << "Tidak ada data film dengan nama " << namaFilm << endl;
    }
    if ((PPenonton != NULL) && (PFilm != NULL)){
        noKursi(PTiket) = noKursi;
        tiketFilm(PTiket) = PFilm;
        nextTiket(PTiket) = NULL;

        P = firstTiket(PPenonton);
        if (P == NULL){
            firstTiket(PPenonton) = PTiket;
        }else{
            while(nextTiket(P) != NULL){
                P = nextTiket(P);
            }
            nextTiket(P) = PTiket;
        }
        infoPenonton(PPenonton).jumlahTiket = infoPenonton(PPenonton).jumlahTiket + 1;
        cout << namaPenonton << " telah berhasil membeli tiket untuk film " << namaFilm << ", dengan nomor kursi " << noKursi << endl;
    }
}

void tambahPenonton(listPenonton &LP, adrPenonton PPenonton){
    adrPenonton P = firstPenonton(LP);
    if (searchPenonton(LP, infoPenonton(PPenonton).nama) != NULL){
        cout << "Penonton atas nama " << infoPenonton(PPenonton).nama << " telah terdaftar" << endl;
    }else if (P == NULL){
        firstPenonton(LP) = PPenonton;
        cout << "Penonton berhasil ditambahkan" << endl;
    }else{
        while (nextPenonton(P) != NULL){
            P = nextPenonton(P);
        }
        nextPenonton(P) = PPenonton;
        cout << "Penonton berhasil ditambahkan" << endl;
    }
}

void tambahFilm(listFilm &LF, adrFilm PFilm){
    adrFilm P = firstFilm(LF);
    if (searchFilm(LF, infoFilm(PFilm).nama) != NULL){
        cout << "Film dengan judul " << infoFilm(PFilm).nama << " telah terdaftar" << endl;
    }else if (P == NULL){
        firstFilm(LF) = PFilm;
        cout << "Film berhasil ditambahkan" << endl;
    }else{
        while (nextFilm(P) != NULL){
            P = nextFilm(P);
        }
        nextFilm(P) = PFilm;
        cout << "Film berhasil ditambahkan" << endl;
    }
}

void printAllPenonton(listPenonton LP){
//Mengoutputkan hanya data list penonton (gada child)
    adrPenonton P = firstPenonton(LP);
    int i = 1;
    if (P == NULL){
        cout << "Tidak Ada Penonton!" << endl;
    } else {
        cout << "========Data Penonton=======" << endl;
        while (P != NULL){
            cout << "Penonton ke-" << i << endl;
            cout << "Nama: " << infoPenonton(P).nama << endl;
            cout << "E-mail: " << infoPenonton(P).email << endl;
            cout << "Nomor Handphone: " << infoPenonton(P).noHP << endl;
            cout << "Jumlah Tiket: " << infoPenonton(P).jumlahTiket << endl << endl;
            i++;
            P = nextPenonton(P);
        }
    }
}

void printAllFilm(listFilm LF){
//Mengoutputkan hanya data list film
    adrFilm F = firstFilm(LF);
    int i = 1;
    if (F == NULL){
        cout << "Tidak Ada Film Yang Tayang!" << endl;
    } else {
        cout << "========Data Film========" << endl;
        while (F != NULL){
            cout << "Film ke-" << i << endl;
            cout << "Nama Film: " << infoFilm(F).nama << endl;
            cout << "Durasi Film: " << infoFilm(F).menitDurasi << " menit" << endl;
            cout << "Jam Tayang: " << infoFilm(F).jamTayang << endl << endl;;
            F = nextFilm(F);
            i++;
        }
    }
}

void hapusElmPenonton(listPenonton &LP, string nama){
    adrPenonton PPenonton = searchPenonton(LP, nama);
    adrPenonton P;
    if (PPenonton != NULL){
        if (PPenonton == firstPenonton(LP)){
            deleteFirstPenonton(LP);
        }else if (nextPenonton(PPenonton) == NULL){
            deleteLastPenonton(LP);
        }else{
            P = firstPenonton(LP);
            while ((P != NULL) && (infoPenonton(nextPenonton(P)).nama != nama)){
                P = nextPenonton(P);
            }
            if (infoPenonton(nextPenonton(P)).nama == nama){
                deleteAfterPenonton(LP, P);
            }
        }
    }
}

void hapusElmFilm(listFilm &LF, string nama, listPenonton &LP){
    adrFilm PFilm = searchFilm(LF, nama);
    adrFilm P;
    if (PFilm != NULL){

        if (PFilm == firstFilm(LF)){
            deleteFirstFilm(LF, LP);
        }else if (nextFilm(PFilm) == NULL){
            deleteLastFilm(LF, LP);
        }else{
            P = firstFilm(LF);
            while ((P != NULL) && (infoFilm(nextFilm(P)).nama != nama)){
                P = nextFilm(P);
            }
            if (infoFilm(nextFilm(P)).nama == nama){
                deleteAfterFilm(LF, P, LP);
            }
        }
    }
}

void hapusElmTiket(listPenonton &LP, listFilm LF, adrPenonton &PPenonton, string namaPenonton, string namaFilm){
    adrTiket PTiket = searchTiket(LP, LF, namaPenonton, namaFilm);
    adrTiket P;
    if (PTiket != NULL){
        if (PTiket == firstTiket(PPenonton)){
            deleteFirstTiket(LP, PPenonton);
        }else if (nextTiket(PTiket) == NULL){
            deleteLastTiket(LP, PPenonton);
        }else{
            P = firstTiket(PPenonton);
            while ((P != NULL) && (infoFilm(tiketFilm(nextTiket(P))).nama != namaFilm)){
                P = nextTiket(P);
            }
            if (infoFilm(tiketFilm(nextTiket(P))).nama == namaFilm){
                deleteAfterTiket(LP, PPenonton, P);
            }
        }
    }
}

void deleteFirstTiket(listPenonton &LP, adrPenonton &PPenonton){
    adrTiket P;
    if (firstTiket(PPenonton) != NULL){
        P = firstTiket(PPenonton);
        if (nextTiket(P) == NULL){
            delete P;
        }else{
            firstTiket(PPenonton) = nextTiket(P);
            nextTiket(P) = NULL;
            delete P;
        }
        infoPenonton(PPenonton).jumlahTiket--;
    }
}

void deleteLastTiket(listPenonton &LP, adrPenonton &PPenonton){
    adrTiket P, Q;
    if (firstTiket(PPenonton) != NULL){
        Q = firstTiket(PPenonton);
        if (nextTiket(Q) == NULL){
            delete Q;
        }else{
            while (nextTiket(nextTiket(Q)) != NULL){
                Q = nextTiket(Q);
            }
            P = nextTiket(Q);
            nextTiket(Q) = NULL;
            delete P;
        }
        infoPenonton(PPenonton).jumlahTiket--;
    }
}

void deleteAfterTiket(listPenonton &LP, adrPenonton &PPenonton, adrTiket precTiket){
    adrTiket P;
    P = nextTiket(precTiket);
    nextTiket(precTiket) = nextTiket(P);
    nextTiket(P) = NULL;
    infoPenonton(PPenonton).jumlahTiket--;
    delete P;
}

void deleteAllTiket(listPenonton &LP, adrPenonton &PPenonton){
    adrTiket P, Q;
    P = firstTiket(PPenonton);
    while (P != NULL){
        Q = nextTiket(P);
        delete P;
        P = Q;
    }
}

void deleteTiketWithSpesificFilm(listPenonton &LP, adrFilm PFilm, listFilm &LF){
    adrPenonton PPenonton;
    adrTiket PTiket;
    if(firstPenonton(LP) != NULL){
        PPenonton = firstPenonton(LP);
        while (PPenonton != NULL){
            if (infoPenonton(PPenonton).jumlahTiket != 0){
                cout << infoPenonton(PPenonton).nama;
                PTiket = firstTiket(PPenonton);
                while (PTiket != NULL){
                    if (tiketFilm(PTiket) == PFilm){
                        if (PTiket == firstTiket(PPenonton)){
                            deleteFirstTiket(LP, PPenonton);
                        }else if (nextTiket(PTiket) == NULL){
                            deleteLastTiket(LP, PPenonton);
                        }
                    }else if ((nextTiket(PTiket) != NULL) && (tiketFilm(nextTiket(PTiket)) == PFilm)){
                        deleteAfterTiket(LP, PPenonton, PTiket);
                    }
                    PTiket = nextTiket(PTiket);
                }
            }
            PPenonton = nextPenonton(PPenonton);
        }
    }
}

void deleteFirstPenonton(listPenonton &LP){
    adrPenonton P;
    if (firstPenonton(LP) != NULL){
        P = firstPenonton(LP);
        if (nextPenonton(P) == NULL){
            deleteAllTiket(LP, P);
            delete P;
        }else{
            firstPenonton(LP) = nextPenonton(P);
            nextPenonton(P) = NULL;
            deleteAllTiket(LP, P);
            delete P;
        }
    }
}

void deleteLastPenonton(listPenonton &LP){
    adrPenonton P, Q;
    if (firstPenonton(LP) != NULL){
        Q = firstPenonton(LP);
        if (nextPenonton(Q) == NULL){
            deleteAllTiket(LP, Q);
            delete Q;
        }else{
            while (nextPenonton(nextPenonton(Q)) != NULL){
                Q = nextPenonton(Q);
            }
            P = nextPenonton(Q);
            nextPenonton(Q) = NULL;
            deleteAllTiket(LP, P);
            delete P;
        }
    }
}

void deleteAfterPenonton(listPenonton &LP, adrPenonton prec){
    adrPenonton P;
    P = nextPenonton(prec);
    nextPenonton(prec) = nextPenonton(P);
    nextPenonton(P) = NULL;
    deleteAllTiket(LP, P);
    delete P;
}

void deleteFirstFilm(listFilm &LF, listPenonton &LP){
    adrFilm P;
    if (firstFilm(LF) != NULL){
        P = firstFilm(LF);
        if (nextFilm(P) == NULL){
            deleteTiketWithSpesificFilm(LP, P, LF);
            delete P;
        }else{
            firstFilm(LF) = nextFilm(P);
            nextFilm(P) = NULL;
            deleteTiketWithSpesificFilm(LP, P, LF);
            delete P;
        }
    }
}

void deleteLastFilm(listFilm &LF, listPenonton &LP){
    adrFilm Q, P;
    if (firstFilm(LF) != NULL){
        Q = firstFilm(LF);
        if (nextFilm(Q) == NULL){
            deleteTiketWithSpesificFilm(LP, P, LF);
            delete Q;
        }else{
            while (nextFilm(nextFilm(Q)) != NULL){
                Q = nextFilm(Q);
            }
            P = nextFilm(Q);
            nextFilm(Q) = NULL;
            deleteTiketWithSpesificFilm(LP, P, LF);
            delete P;
        }
    }
}

void deleteAfterFilm(listFilm &LF, adrFilm prec, listPenonton &LP){
    adrFilm P;
    P = nextFilm(prec);
    nextFilm(prec) = nextFilm(P);
    nextFilm(P) = NULL;
    deleteTiketWithSpesificFilm(LP, P, LF);
    delete P;
}

adrPenonton searchPenonton(listPenonton LP, string nama){
//Mencari lokasi dari data penonton sesuai namanya
    adrPenonton P = firstPenonton(LP);
    if (P == NULL){
        return NULL;
    } else {
        while (P != NULL){
            if (infoPenonton(P).nama == nama){
                return P;
            }
            P = nextPenonton(P);
        }
        return NULL;
    }
}

adrFilm searchFilm(listFilm LF, string nama){
//Mencari lokasi dari data film sesuai namanya
    adrFilm F = firstFilm(LF);
    if (F == NULL){
        cout << "Film dengan nama " << nama << " tidak ada pada data film." << endl;
        return NULL;
    } else {
        while (F != NULL){
            if (infoFilm(F).nama == nama){
                return F;
            }
            F = nextFilm(F);
        }
        return NULL;
    }
}

adrTiket searchTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm){
    adrFilm PFilm = searchFilm(LF, namaFilm);
    adrPenonton PPenonton = searchPenonton(LP, namaPenonton);
    adrTiket PTiket;
    if ((PFilm == NULL) || (PPenonton == NULL)){
        return NULL;
    }else{
        PTiket = firstTiket(PPenonton);
        while ((PTiket != NULL) && (tiketFilm(PTiket) != PFilm)){
            PTiket = nextTiket(PTiket);
        }
        if (tiketFilm(PTiket) == PFilm){
            return PTiket;
        }
        return NULL;
    }
}

adrTiket searchNoKursiWithFilm(listPenonton LP, string namaFilm, string noKursi){
    adrPenonton P = firstPenonton(LP);
    adrTiket T;
    while (P != NULL){
        T = firstTiket(P);
        while (T != NULL){
            if ((noKursi(T) == noKursi) && (infoFilm(tiketFilm(T)).nama == namaFilm)){
                return T;
            }
            T = nextTiket(T);
        }
        P = nextPenonton(P);
    }
    return NULL;
}

void printSpecificTiket(listPenonton LP, listFilm LF, string namaPenonton, string namaFilm){
//Cetak tiket orang tertentu, ini kalo gaperlu apus aja deh
    adrPenonton P = searchPenonton(LP, namaPenonton);
    adrTiket T = searchTiket(LP,LF,namaPenonton,namaFilm);
    if ((P != NULL) && (T != NULL)){
        cout << "===========TIKET==========" << endl;
        cout << "Nama: " << infoPenonton(P).nama << endl;
        cout << "Nama Film: " << infoFilm(tiketFilm(T)).nama << endl;
        cout << "Durasi Film: " << infoFilm(tiketFilm(T)).menitDurasi << "Menit" << endl;
        cout << "Jam Tayang: " << infoFilm(tiketFilm(T)).jamTayang << endl;
        cout << "Nomor Kursi: " << noKursi(T) << endl;
        cout << "==========================" << endl;
    }else{
        cout << "Tidak ada data yang anda maksud." << endl;
    }
}

void printAllTiket(adrPenonton PPenonton){
//Mencetak semua info tiket
    adrTiket PTiket = firstTiket(PPenonton);
    int i = 1;
    printf("Nama\t: ");
    cout << infoPenonton(PPenonton).nama << endl;
    printf("E-mail\t: ");
    cout << infoPenonton(PPenonton).email << endl;
    printf("No.HP\t: ");
    cout << infoPenonton(PPenonton).noHP << endl;
    printf("Jumlah Tiket\t: ");
    cout << infoPenonton(PPenonton).jumlahTiket << endl;

    if (infoPenonton(PPenonton).jumlahTiket == 0){
        cout << "Tidak mempunyai tiket film." << endl;
    }else{
        cout << "=== Tiket ===" << endl;
        while (PTiket != NULL){
            cout << "     " << i << "." <<endl;
            cout << "     No Kursi: " << noKursi(PTiket) << endl;
            cout << "     Nama Film: " << infoFilm(tiketFilm(PTiket)).nama << endl;
            cout << "     Durasi Film: " << infoFilm(tiketFilm(PTiket)).menitDurasi << " menit" << endl;
            cout << "     Jam Tayang: " << infoFilm(tiketFilm(PTiket)).jamTayang << endl;
            PTiket = nextTiket(PTiket);
            i++;
        }
    }
}

void printAllPenontonWithTiket(listPenonton LP, listFilm LF){
    if (firstPenonton(LP) == NULL){
        cout << "Tidak ada penonton!" << endl;
    }else{
        adrPenonton P = firstPenonton(LP);
        int i = 1;
        cout << "===== Penonton =====" << endl;
        while (P != NULL){
            cout << "Penonton ke-" << i << endl;
            printAllTiket(P);
            P = nextPenonton(P);
            i++;
            cout << endl;
        }
    }
}

int selectMenu(){
    int input = 0;
    cout << "=-=-=-=-=-= M E N U =-=-=-=-=-=" << endl;
    cout << "1. Menambahkan Data Film" << endl;
    cout << "2. Menambahkan Data Penonton" << endl;
    cout << "3. Membeli Tiket" << endl;
    cout << "4. Batalkan Pesanan" << endl;
    cout << "5. Hapus Data Film" << endl;
    cout << "6. Hapus Data Penonton" << endl;
    cout << "7. Check Tiket" << endl;
    cout << "8. Check Daftar Film" << endl;
    cout << "9. Check Daftar Penonton" << endl;
    cout << "10. Check Daftar Penonton Beserta Tiketnya" << endl;
    cout << "0. Keluar" << endl;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "Masukkan Pilihanmu: ";
    cin >> input;
    cout << endl;
    return input;
}
