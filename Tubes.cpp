#include "Tubes.h"
//menu
void menu(){
    cout << "============DATA SISWA BESERTA EKSKUL STM KAPAL LAOET============" << endl;
    cout << "1. Menambah Data Siswa" << endl;
    cout << "2. Menunjukkan Semua Data Siswa" << endl;
    cout << "3. Menghapus Data Siswa" << endl;
    cout << "4. Mencari Nama Siswa" << endl;
    cout << "5. Mencari Data Ekskul" << endl;
    cout << "6. Menambahkan Data Ekskul" << endl;
    cout << "7. Siswa Memilih Ekskul (menghubungkan data parent ke child)" << endl;
    cout << "8. Menampilkan Data Siswa Beserta Ekskul yang Diikutinya " << endl;
    cout << "9. Mencari Data Ekskul Pada Siswa tertentu" << endl;
    cout << "10. Menghapus Ekskul pada Siswa Tertentu" << endl;
    cout << "11. Menghitung Jumlah Ekskul yang Diikuti Siswa Tertentu" << endl;
    cout << "==================================================================" << endl;
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

adrEkskul searchEkskul(ekskul target, listEkskul LE) {
    adrEkskul P = head(LE);
    while (P != NULL && infoEkskul(P).namaEkskul != target.namaEkskul) {
        P = nextEkskul(P);
    }
    return P;
}

void showDLL(listEkskul LE){
    adrEkskul P = head(LE);

    while (P != NULL) {
        cout << infoEkskul(P).namaEkskul << " " << infoEkskul(P).jumlahPertemuan << endl;
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
        while (Q != NULL) {
            Q = nextSiswa(Q);
        }
        nextSiswa(Q) = P;
    }
}

void deleteFirstSiswa(listSiswa &LS, adrSiswa &P) {
    if (head(LS) == NULL) {
        head(LS) == NULL;
    } else {
        P = head(LS);
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
        while (nextSiswa(Q) != NULL) {
            Q = nextSiswa(Q);
        }
        nextSiswa(Q) = NULL;
    
}
}
adrSiswa searchSiswa(siswa target, listSiswa LS) {
    adrSiswa P = head(LS);
    while (P != NULL) {
        if (infoSiswa(P).namaSiswa == target.namaSiswa) {
            return P;
        }
        P = nextSiswa(P);
    }
}
void showSLL(listSiswa LS) {
    adrSiswa P = head(LS);
        if (head(LS) == NULL) {
            cout << "Tidak Terdapat Siswa yang terdaftar" << endl;
        } else {
            while (P != NULL) {
            cout << "Nama: " << infoSiswa(P).namaSiswa << endl;
            cout << "Umur: " << infoSiswa(P).umur << endl;
            cout << "NISN: " << infoSiswa((P)).NISN << endl;
            cout << "Angkatan: " << infoSiswa(P).angkatan << endl;
            P = nextSiswa(P);
            }
        }
    }
