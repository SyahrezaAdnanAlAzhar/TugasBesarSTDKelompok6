

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
        return P;
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
        return F;
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
