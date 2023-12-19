#include "Tubes.h"
//menu
void menu(){
    cout << "============DATA SISWA BESERTA EKSKUL STM KAPAL LAOET============" << endl;
    cout << "1. Menambah Data Siswa" << endl; //done
    cout << "2. Menampilkan Semua Data Siswa" << endl; //done
    cout << "3. Menghapus Data Siswa" << endl; //done
    cout << "4. Mencari Data Siswa" << endl; //done
    cout << "5. Menambahkan Data Ekskul" << endl; //done
    cout << "6. Mencari Data Ekskul" << endl; //done
    cout << "7. Siswa Memilih Ekskul (menghubungkan data parent ke child)" << endl; //done
    //cout << "8. Menampilkan Data Siswa Beserta Ekskul yang Diikutinya " << endl; //done di nomor 2
    cout << "8. Mencari Data Ekskul Pada Siswa tertentu" << endl;
    cout << "9. Menghapus Ekskul pada Siswa Tertentu" << endl;
    //cout << "10. Menghitung Jumlah Ekskul yang Diikuti Siswa Tertentu" << endl; //done di nomor 2
    cout << "10. Keluar" << endl;
    cout << "==================================================================" << endl;
}

void menambahkanDataSiswa(listSiswa &LS){
    siswa dataSiswa;
    cout << "Masukkan data siswa berikut: " << endl;
    cout << "Nama: ";
    cin >> dataSiswa.namaSiswa;
    cout << "Umur: ";
    cin >> dataSiswa.umur;
    cout << "Kelas: ";
    cin >> dataSiswa.kelas;
    cout << "Jurusan: ";
    cin >> dataSiswa.jurusan;
    cout << "NISN: ";
    cin >> dataSiswa.NISN;
    cout << "Angkatan: ";
    cin >> dataSiswa.angkatan;
    insertLastSiswa(LS, createElementSiswa(dataSiswa));
    cout << "Input Berhasil" << endl;
}

void menampilkanDataSiswa(listSiswa LS) {
    showSLL(LS);
}

void menghapusDataSiswa(listSiswa &LS) { 
    string nama, NISN;
    showSLL(LS);
    cout << "Nama Siswa yang ingin dihapus: ";
    cin >> nama;
    cout << "NISN Siswa yang ingin dihapus: ";
    cin >> NISN;
    cout << endl;
    adrSiswa P = searchSiswa(nama, NISN, LS);
    
    if (P != NULL) {
        adrSiswa Q = head(LS);
        while (nextSiswa(Q) != NULL) {
            Q = nextSiswa(Q);
        }

        if (head(LS) == P) {
            deleteAllPenghubung(LS, P);
            deleteFirstSiswa(LS, P);
            cout << "Penghapusan Berhasil" << endl;
        } else if (Q == P) {
            deleteAllPenghubung(LS, P);
            deleteLastSiswa(LS, P);
            cout << "Penghapusan Berhasil" << endl;
        } else {
            adrSiswa R = head(LS);
            while (nextSiswa(R) != P) {
                R = nextSiswa(R);
            }
            deleteAllPenghubung(LS, P);
            deleteAfterSiswa(LS, P, R);
            cout << "Penghapusan Berhasil" << endl; 
        }
    } else {
        cout << "Siswa tidak ditemukan" << endl;
    }

}

void mencariDataSiswa(listSiswa LS){
    string nama, NISN;
    cout << "Masukkan Nama Siswa yang Ingin dicari: ";
    cin >> nama;
    cout << "Masukkan NISN Siswa yang Ingin dicari: ";
    cin >> NISN;
    cout << endl;
    adrSiswa P = searchSiswa(nama, NISN, LS);

    if (P != NULL) {
        cout << "Nama: " << infoSiswa(P).namaSiswa << endl;
        cout << "Umur: " << infoSiswa(P).umur << endl;
        cout << "Kelas: " << infoSiswa(P).kelas << endl;
        cout << "Jurusan: " << infoSiswa(P).jurusan << endl;
        cout << "NISN: " << infoSiswa(P).NISN << endl;
        cout << "Angkatan: " << infoSiswa(P).angkatan << endl;
        cout << "Ekskul yang diikuti: " << endl;
    } else {
        cout << "Data Siswa Tidak Ditemukan" << endl;
    }
}

void menampilkanEkskul(listEkskul LE) {
    showDLL(LE);
}

void menambahkanDataEkskul(listEkskul &LE) {
    ekskul data;
    cout << "Masukkan Nama Ekskul yang Ingin Ditambahkan: ";
    cin >> data.namaEkskul;
    cout << "Masukkan Jumlah Pertemuan Ekskul yang Ingin Ditambahkan: ";
    cin >> data.jumlahPertemuan;
    adrEkskul adrE = searchEkskul(data.namaEkskul, LE);
    if (adrE == NULL) {
        insertLastEkskul(LE, createElementEkskul(data));
        cout << "Input Berhasil" << endl;
    } else {
        cout << "Ekskul sudah ada" << endl;
    }

}

void mencariDataEkskul(listEkskul LE) {
    string namaEkskul;
    cout << "Masukkan Nama Ekskul yang Ingin Dicari: ";
    cin >> namaEkskul;
    adrEkskul adrE = searchEkskul(namaEkskul, LE);
    cout << "Nama Ekskul: " << infoEkskul(adrE).namaEkskul << endl;
    cout << "Jumlah Pertemuan Perminggu: " << infoEkskul(adrE).jumlahPertemuan << endl;
    cout << "Jumlah Anggota: " << infoEkskul(adrE).anggota << endl;
}

void siswaMemilihEkskul(listSiswa &LS, listEkskul &LE) {
    string namaSiswa, namaEkskul, NISN;
    showSLL(LS);
    cout << "Masukkan Nama Siswa yang Ingin dicari: ";
    cin >> namaSiswa;
    cout << "Masukkan NISN Siswa yang Ingin dicari: ";
    cin >> NISN;
    cout << "Masukkan Ekskul yang Dipilih Siswa: ";
    cin >> namaEkskul;
    cout << endl;

    adrEkskul adrE = searchEkskul(namaEkskul, LE);
    adrSiswa adrS = searchSiswa(namaSiswa, NISN, LS);

    if (adrS == NULL) {
        cout << "Siswa Tidak Ditemukan" << endl;
    } else if (adrE == NULL) {
        cout << "Ekskul Belum Ada" << endl;
    } else {
        if (!isEkskulDuplicate(adrS, adrE)) {
            insertLastPenghubung(LS, adrS, adrE);
            infoEkskul(adrE).anggota++;
            infoSiswa(adrS).jumlahEkskul++;
        } else {
            cout << "Siswa Telah Terdaftar Pada Ekskul Tersebut" << endl;
        }
        
    }
}

void mencariEkskulPadaSeorangSiswa(listSiswa LS) {
    string namaSiswa, NISN, namaEkskul;

    showSLL(LS);
    cout << endl;
    cout << "Masukkan nama siswa yang ingin dicari ekskulnya: ";
    cin >> namaSiswa;
    cout << "Masukkan NISN siswa yang ingin dicari ekskulnya: ";
    cin >> NISN;
    adrSiswa adrS;
    adrPenghubung P;

    adrS = searchSiswa(namaSiswa, NISN, LS);
    if (adrS == NULL) {
        cout << "Siswa tidak ada pada daftar" << endl;
    } else {
        cout << "Masukkan ekskul yang ingin dicari pada " << infoSiswa(adrS).namaSiswa << " : ";
        cin >> namaEkskul;
        P = nextPenghubung(adrS);
        while (P != NULL) {
            if (namaEkskul == infoEkskul(Ekskul(P)).namaEkskul) {
                cout << "Siswa terdapat pada ekskul tersebut" << endl;
                break;
            }
            P = Penghubung(P);
        }
        if (P == NULL) {
            cout << "Siswa tidak terdapat pada ekskul tersebut" << endl; 
        }
    }
}

adrPenghubung cariEkskulSeorangSiswa(listSiswa LS, adrSiswa adrS, string namaEkskul) {
    adrPenghubung P = nextPenghubung(adrS);
    while (P != NULL) {
        if (namaEkskul == infoEkskul(Ekskul(P)).namaEkskul) {
            return P;
        }
        P = Penghubung(P);
    }
    return NULL;
}

void mengurangiEkskulSiswa(listSiswa &LS) {
    string namaSiswa, namaEkskul, NISN;
    showSLL(LS);
    cout << endl;
    cout << "Masukkan nama siswa yang ingin dihapus ekskulnya: ";
    cin >> namaSiswa;
    cout << "Masukkan NISN siswa yang ingin dihapus ekskulnya: ";
    cin >> NISN;
    adrEkskul adrE;
    adrSiswa adrS = searchSiswa(namaSiswa, NISN, LS);
    if (adrS == NULL) {
        cout << "Siswa tidak ada pada daftar" << endl;
    } else {
        cout << "Masukkan ekskul yang ingin dihapus dari " << infoSiswa(adrS).namaSiswa << " : ";
        cin >> namaEkskul;
        adrPenghubung P = cariEkskulSeorangSiswa(LS, adrS, namaEkskul);
        if (P == NULL) {
            cout << "Siswa tidak mengikuti ekskul tersebut" << endl;
        } else {
            adrPenghubung Q = nextPenghubung(adrS);
            while (Penghubung(Q) != NULL) {
                Q = Penghubung(Q);
            }
            if (P == nextPenghubung(adrS)) {
                deleteFirstPenghubung(LS, adrS);
            } else if (P == Q) {
                deleteLastPenghubung(LS, adrS);
            } else {
                adrPenghubung R = nextPenghubung(adrS);
                while (Penghubung(R) != P && R != NULL) {
                    R = Penghubung(R);
                }
                deleteAfterPenghubung(LS, adrS, R);
            }
            cout << "Proses Berhasil" << endl;
        }
    }

}

//end of menu

// create
void createListSiswa(listSiswa &LS){
    head(LS) = NULL;
}
void createListEkskul(listEkskul &LE){
    head(LE) = NULL;
    tail(LE) = NULL;
}

adrSiswa createElementSiswa(siswa data) {
    adrSiswa P = new elementSiswa;
    infoSiswa(P) = data;
    infoSiswa(P).jumlahEkskul = 0;
    nextSiswa(P) = NULL;
    nextPenghubung(P) = NULL;
    return P;
}

adrEkskul createElementEkskul(ekskul data){
    adrEkskul P = new elementEkskul;
    infoEkskul(P) = data;
    nextEkskul(P) = NULL;
    prevEkskul(P) = NULL;
    return P;
}

adrPenghubung createElementPenghubung(){
    adrPenghubung P = new elementPenghubung;
    Ekskul(P) = NULL;
    Penghubung(P) = NULL;
    return P;
}
//end of create

//double linked list ekskul
bool isEmptyDLL(listEkskul LE) {
    return head(LE) == NULL && tail(LE) == NULL;
}

void insertLastEkskul(listEkskul &LE, adrEkskul P){
    if (isEmptyDLL(LE)) {
        head(LE) = P;
        tail(LE) = P;
    } else {
        nextEkskul(tail(LE)) = P;
        prevEkskul(P) = tail(LE);
        tail(LE) = P;
    }
}
void deleteFirstEkskul(listEkskul &LE, adrEkskul &P){
    if (isEmptyDLL(LE)) {
        cout << "Ekskul Telah Kosong" << endl;
    } else if (head(LE) == tail(LE)) {
        P = head(LE);
        head(LE) = NULL;
        tail(LE) = NULL;
    } else {
        P = head(LE);
        head(LE) = nextEkskul(head(LE));
        prevEkskul(head(LE)) = NULL;
        nextEkskul(P) = NULL;
    }
}
void deleteLastEkskul(listEkskul &LE, adrEkskul &P){
    if (isEmptyDLL(LE)) {
        cout << "Ekskul Telah Kosong" << endl;
    } else if (head(LE) == tail(LE)) {
        P = head(LE);
        head(LE) = NULL;
        tail(LE) = NULL;
    } else {
        P = tail(LE);
        tail(LE) = prevEkskul(tail(LE));
        nextEkskul(tail(LE)) = NULL;
        prevEkskul(P) = NULL;
    }
}
void deleteAfterEkskul(listEkskul &LE, adrEkskul prec, adrEkskul &P){
    P = nextEkskul(prec);
    nextEkskul(prec) = nextEkskul(P);
    prevEkskul(nextEkskul(P)) = prec;
    nextEkskul(P) = NULL;
    prevEkskul(P) = NULL;
}

adrEkskul searchEkskul(string namaEkskul, listEkskul LE) {
    adrEkskul P = head(LE);
    while (P != NULL && infoEkskul(P).namaEkskul != namaEkskul) {
        P = nextEkskul(P);
    }
    return P;
}

void showDLL(listEkskul LE){
    adrEkskul P = head(LE);
    cout << "Daftar Ekskul STM KAPAL LAOET" << endl;
    while (P != NULL) {
        cout << "Nama Ekskul: " << infoEkskul(P).namaEkskul << endl;
        cout << "Jumlah Pertemuan perminggu: " << infoEkskul(P).jumlahPertemuan << endl;
        cout << "Jumlah Anggota: " << infoEkskul(P).anggota << endl;
        P = nextEkskul(P);
    }
}

//end of double linked list

//Single Linked List Siswa
void insertLastSiswa(listSiswa &LS, adrSiswa P) {
    adrSiswa Q = head(LS);
    if (head(LS) == NULL) {
        head(LS) = P;
    } else {
        while (nextSiswa(Q) != NULL) {
            Q = nextSiswa(Q);
        }
        nextSiswa(Q) = P;
    }
}

void deleteFirstSiswa(listSiswa &LS, adrSiswa &P) {
    if (head(LS) == NULL) {
        cout << "Kosong"; 
    } else {
        P = head(LS);
        head(LS) = nextSiswa(P);
        nextSiswa(P) = NULL;
    }
}

void deleteAfterSiswa(listSiswa &LS, adrSiswa &P, adrSiswa Prec) {
    P = nextSiswa(Prec);
    nextSiswa(Prec) = nextSiswa(P);
    nextSiswa(P) = NULL;
}

void deleteLastSiswa(listSiswa &LS, adrSiswa &P) {
    adrSiswa Q = head(LS);
    if (head(LS) == NULL) {
        cout << "Tidak Terdapat Siswa yang terdaftar" << endl;
    } else if (nextSiswa(head(LS)) == NULL) {
        P = head(LS);
        head(LS) = NULL;
    } else {
        while (nextSiswa(nextSiswa(Q)) != NULL) {
            Q = nextSiswa(Q);
        }
        P = nextSiswa(Q);
        nextSiswa(Q) = NULL;
}
}
adrSiswa searchSiswa(string namaSiswa, string NISN, listSiswa LS) {
    adrSiswa P = head(LS);
    while (P != NULL) {
        if (infoSiswa(P).namaSiswa == namaSiswa && infoSiswa(P).NISN == NISN) {
            return P;
        }
        P = nextSiswa(P);
    }
    return P;
}
void showSLL(listSiswa LS) {
    adrSiswa P = head(LS);
        if (head(LS) == NULL) {
            cout << "Tidak Terdapat Siswa yang terdaftar" << endl;
        } else {
            cout << "Daftar Siswa STM KAPAL LAOET" << endl;
            while (P != NULL) {
                cout << "Nama: " << infoSiswa(P).namaSiswa << endl;
                cout << "Umur: " << infoSiswa(P).umur << endl;
                cout << "Kelas: " << infoSiswa(P).kelas << endl;
                cout << "Jurusan: " << infoSiswa(P).jurusan << endl;
                cout << "NISN: " << infoSiswa(P).NISN << endl;
                cout << "Angkatan: " << infoSiswa(P).angkatan << endl;
                cout << "Jumlah ekskul yang diikuti: " << infoSiswa(P).jumlahEkskul << endl;
                cout << "Ekskul yang diikuti: "<< endl;
                adrPenghubung Q = nextPenghubung(P);
                int i = 0;
                while (Q != NULL) {
                    cout << i + 1 << ". " << infoEkskul(Ekskul(Q)).namaEkskul << endl;
                    i++;
                    Q = Penghubung(Q);
                } 
                cout << endl;
                P = nextSiswa(P);
            }
        }
}
//End of Single Linked List Siswa

//Penghubung
bool isEkskulDuplicate(adrSiswa adrS, adrEkskul adrE){
    adrPenghubung P = nextPenghubung(adrS);
    while (P != NULL) {
        if (infoEkskul(Ekskul(P)).namaEkskul == infoEkskul(adrE).namaEkskul) {
            return true;
        }
        P = Penghubung(P);
    }
    return false;
}

void insertLastPenghubung(listSiswa &LS, adrSiswa adrS, adrEkskul adrE){
    adrPenghubung P = createElementPenghubung();
    if (nextPenghubung(adrS) == NULL) {
        nextPenghubung(adrS) = P;
    } else {
        adrPenghubung Q = nextPenghubung(adrS);
        while (Penghubung(Q) != NULL) {
            Q = Penghubung(Q);
        }
        Penghubung(Q) = P;
    }

    if (adrE != NULL) {
        Ekskul(P) = adrE;
    } 
    
}

void deleteFirstPenghubung(listSiswa &LS, adrSiswa &adrS){
    adrPenghubung P;
    if (Penghubung(nextPenghubung(adrS)) == NULL){
        P = nextPenghubung(adrS);
        nextPenghubung(adrS) = NULL;
        infoEkskul(Ekskul(P)).anggota--;
        infoSiswa(adrS).jumlahEkskul--;
    } else if (nextPenghubung(adrS) != NULL) {
        P = nextPenghubung(adrS);
        nextPenghubung(adrS) = Penghubung(P);
        Penghubung(P) = NULL;
        infoEkskul(Ekskul(P)).anggota--;
        infoSiswa(adrS).jumlahEkskul--;
    }
}

void deleteLastPenghubung(listSiswa &LS, adrSiswa &adrS) {
    adrPenghubung P;
    if (Penghubung(nextPenghubung(adrS)) == NULL){
        P = nextPenghubung(adrS);
        nextPenghubung(adrS) = NULL;
        infoEkskul(Ekskul(P)).anggota--;
        infoSiswa(adrS).jumlahEkskul--;
    } else if (nextPenghubung(adrS) != NULL) {
        P = nextPenghubung(adrS);
        while (Penghubung(Penghubung(P)) != NULL) {
            P = Penghubung(P);
        }
        infoEkskul(Ekskul(Penghubung(P))).anggota--;
        Penghubung(P) = NULL;
        infoSiswa(adrS).jumlahEkskul--;
    }
}

void deleteAfterPenghubung(listSiswa &LS, adrSiswa &adrS, adrPenghubung prec){
    adrPenghubung P;
    P = Penghubung(prec);
    Penghubung(prec) = Penghubung(P);
    Penghubung(P) = NULL;
    infoEkskul(Ekskul(P)).anggota--;
    infoSiswa(adrS).jumlahEkskul--;
}

void deleteAllPenghubung(listSiswa &LS, adrSiswa &adrS) {
    while (nextPenghubung(adrS) != NULL) {
        deleteLastPenghubung(LS, adrS);
    }
}
//End of Penghubung