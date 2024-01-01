#include "tiketBioskop.h"

void createListPenonton(listPenonton &LP){
    firstPenonton(LP) = NULL;
}

void createListFilm(listFilm &LF){
    firstFilm(LP) = NULL;
}

adrPenonton createElmPenonton(string nama, string email, string noHP){
    adrPenonton P = new elmPenonton;
    infoPenonton(P).nama = nama;
    infoPenonton(P).email = email;
    infoPenonton(P).noHP = noHP;
    infoPenonton(P).jumlahTiket = 0;
    return P;
}

adrFilm createElmFilm(string nama, int menitDurasi, string jamTayang){
    adrFilm P = new elmFilm;
    infoFilm(P).nama = nama;
    infoFilm(P).menitDurasi = menitDurasi;
    infoFilm(P).jamTayang = jamTayang;
    return P;
}

void membeliTiket(listPenonton &LP, listFilm LF, string namaPenonton, string namaFilm, int noKursi){
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
            P = PTiket
        }else{
            while(nextTiket(P) != NULL){
                P = nextTiket(P);
            }
            nextTiket(P) = PTiket;
        }
        cout << namaPenonton << " telah berhasil membeli tiket untuk film " << namaFilm << ", dengan nomor kursi " << noKursi << endl;
    }
}

void tambahPenonton(listPenonton &LP, adrPenonton PPenonton){
    adrPenonton P = firstPenonton(LP);
    if (searchPenonton(LP, infoPenonton(PPenonton).nama) != NULL){
        cout << "Penonton atas nama " << infoPenonton(PPenonton).nama << " telah terdaftar" << endl;
    }else if (P == NULL){
        P = PPenonton;
    }else{
        while (nextPenonton(P) != NULL){
            P = nextPenonton(P);
        }
        nextPenonton(P) = PPenonton;
    }
}

void tambahFilm(listFilm &LF, adrFilm PFilm){
    adrFilm P = firstFilm(LF);
    if (searchFilm(LF, infoFilm(PFilm).nama) != NULL){
        cout << "Film dengan judul " << infoFilm(PFilm).nama << " telah terdaftar" << endl;
    }else if (P == NULL){
        P = PFilm;
    }else{
        while (nextFilm(P) != NULL){
            P = nextFilm(P);
        }
        nextFilm(P) = PFilm;
    }
}

void printAllPenonton(listPenonton LP){
//Mengoutputkan hanya data list penonton (gada child)
    adrPenonton P = firstPenonton(LP);
    if (P == NULL){
        cout << "Tidak Ada Penonton!" << endl;
    } else {
        while (P != NULL){
            cout << "========Data Penonton=======" << endl;
            printf("Nama\t: ");
            cout << infoPenonton(P).nama << endl;
            printf("E-mail\t: ");
            cout << infoPenonton(P).email << endl;
            printf("No.HP\t: ");
            cout << infoPenonton(P).noHP << endl;
            printf("Jumlah Tiket\t: ");
            cout << infoPenonton(P).jumlahTiket << endl;
            P = nextPenonton(P);
        }
    }
}

void printAllFilm(listFilm LF){
//Mengoutputkan hanya data list film
    adrFilm F = firstFilm(LF);
    if (F == NULL){
        cout << "Tidak Ada Film Yang Tayang!" << endl;
    } else {
        while (F != NULL){
            cout << "========Data Penonton=======" << endl;
            printf("Nama Film\t: ");
            cout << infoFilm(F).nama << endl;
            printf("Durasi Film\t: ")
            cout << infoFilm(F).menitDurasi << "Menit" << endl;
            printf("Jam Tayang\t: ") << endl;
            cout << infoFilm(F).jamTayang << endl;
            F = nextFilm(F);
        }
    }
}

void hapusElmPenonton(listPenonton &LP, string nama){

}

void hapusElmFilm(listFilm &LF, string nama){

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
    }
}

void deleteAfterTiket(listPenonton &LP, adrPenonton &PPenonton, adrTiket precTiket){
    adrTiket P;
    P = nextTiket(precTiket);
    nextTiket(precTiket) = nextTiket(P);
    nextTiket(P) = NULL;
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

void deleteTiketWithSpesificFilm(listPenonton &LP, adrFilm PFilm){
    adrPenonton PPenonton;
    adrTiket PTiket;
    if(firstPenonton(LP) != NULL){
        PPenonton = firstPenonton(LP);
        while (PPenonton != NULL){
            PTiket = firstTiket(PPenonton);
            while (PTiket != NULL){
                if (tiketFilm(firstTiket(PPenonton)) = PFilm){
                    deleteFirstTiket(LP, PPenonton);
                }
                if ((nextTiket(PTiket) == NULL)&& (tiketFilm(PTiket))){
                    deleteLastTiket(LP, PPenonton);
                }
                if (tiketFilm(nextTiket(PTiket)) == PFilm){
                    deleteAfterTiket(LP, PPenonton, nextTiket(PTiket));
                }
                PTiket = nextTiket(PTiket);
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
            deleteTiketWithSpesificFilm(LP, P);
            delete P;
        }else{
            firstFilm(LF) = nextFilm(P);
            nextFilm(P) = NULL;
            deleteTiketWithSpesificFilm(LP, P);
            delete P;
        }
    }
}

void deleteLastFilm(listFilm &LF, listPenonton &LP){
    adrFilm Q, P;
    if (firstFilm(LF) != NULL){
        Q = firstFilm(LF);
        if (nextFilm(Q) == NULL){
            deleteTiketWithSpesificFilm(LP, P);
            delete Q;
        }else{
            while (nextFilm(nextFilm(Q)) != NULL){
                Q = nextFilm(Q);
            }
            P = nextFilm(Q);
            next(Q) = NULL;
            deleteTiketWithSpesificFilm(LP, P);
            delete P;
        }
    }
}

void deleteAfterFilm(listFilm &LF, adrFilm prec, listPenonton &LP){
    adrFilm P;
    P = nextFilm(prec);
    nextFilm(prec) = nextFilm(P);
    nextFilm(P) = NULL;
    deleteTiketWithSpesificFilm(LP, P);
    delete P;
}

adrPenonton searchPenonton(listPenonton LP, string nama){
//Mencari lokasi dari data penonton sesuai namanya
    adrFilm P = firstPenonton(LP);
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
        return NULL
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

void tambahTiket(listPenonton &LP, listFilm LF, string noKursi, string namaPenonton, string namaFilm){
//Menambahkan tiket yang dibeli sesuai nama penonton nama film. Elemen tiket sudah didefinisikan
    adrPenonton P = searchPenonton(LP,namaPenonton);
    adrFilm F = searchFilm(LF,namaFilm);
    if (P != NULL && F != NULL){
        listTiket LT = P.tiket;
        adrTiket T = createElmTiket(noKursi); //ini tambahin aja
        insertLast(LT,T); //reja yang buat insert lastnya nanti ikutin reja
        tiketFilm(T) = F;
    }
}

void printInfoNonton(listPenonton LP, listFilm LF){
//Mencetak semua info mulai dari penonton-tiket-film
    adrPenonton P = firstPenonton(LP);
    if (P != NULL){
        cout << "Tidak ada penonton!" << endl;
    } else {
        while (P != NULL){
            cout << "===========TIKET==========" << endl;
            printf("Nama\t\t: ");
            cout << infoPenonton(P).nama << endl;
            printf("E-mail\t\t: ");
            cout << infoPenonton(P).email << endl;
            printf("No.HP\t\t: ");
            cout << infoPenonton(P).noHP << endl;
            printf("Jumlah Tiket\t: ");
            cout << infoPenonton(P).jumlahTiket << endl;
            printf("Nama Film\t: ");
            cout << infoFilm(F).nama << endl;
            printf("Durasi Film\t: ")
            cout << infoFilm(F).menitDurasi << "Menit" << endl;
            printf("Jam Tayang\t: ") << endl;
            cout << infoFilm(F).jamTayang << endl;
            P = nextPenonton(P);
        }
    }
}

void deleteTiket(listPenonton &LP, string namaFilm){

}
