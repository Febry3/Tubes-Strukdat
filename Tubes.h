#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct siswa {
    string namaSiswa, NISN, kelas, jurusan;
    int umur, angkatan, jumlahEkskul;
};

struct ekskul {
    string namaEkskul;
    int jumlahPertemuan, anggota = 0;
};

#define infoSiswa(P) P->infoSiswa
#define nextSiswa(P) P->nextSiswa
#define nextPenghubung(P) P->nextPenghubung
#define infoEkskul(P) P->infoEkskul
#define nextEkskul(P) P->nextEkskul
#define prevEkskul(P) P->prevEkskul
#define head(L) L.head
#define tail(L) L.tail
#define Penghubung(P) P->Penghubung
#define Ekskul(P) P->Ekskul

typedef struct elementSiswa *adrSiswa;
typedef struct elementEkskul *adrEkskul;
typedef struct elementPenghubung *adrPenghubung;

struct elementSiswa {
    siswa infoSiswa;
    adrSiswa nextSiswa;
    adrPenghubung nextPenghubung;
};

struct elementEkskul {
    ekskul infoEkskul;
    adrEkskul nextEkskul, prevEkskul;
};

struct elementPenghubung {
    adrEkskul Ekskul;
    adrPenghubung Penghubung;
};

struct listSiswa {
    adrSiswa head;
};

struct listEkskul {
    adrEkskul head, tail;
};

//menu
void menu();
void menambahkanDataSiswa(listSiswa &LS);
void menampilkanDataSiswa(listSiswa LS);
void menghapusDataSiswa(listSiswa &LS);
void mencariDataSiswa(listSiswa LS);
void menambahkanDataEkskul(listEkskul &LE);
void mencariDataEkskul(listEkskul LE);
void siswaMemilihEkskul(listSiswa &LS, listEkskul &LE);
void mencariEkskulPadaSeorangSiswa(listSiswa LS);
void mengurangiEkskulSiswa(listSiswa &LS);
void menampilkanEkskul(listEkskul LE);
void menampilkanDaftarEkskul(listEkskul LE);
void jumlahAngkatanPadaEkskul(listSiswa LS, listEkskul LE);

//create
void createListSiswa(listSiswa &LS);
void createListEkskul(listEkskul &LE);
adrSiswa createElementSiswa(siswa data);
adrEkskul createElementEkskul(ekskul data);
adrPenghubung createElementPenghubung();

//double linked list element ekskul
bool isEmptyDLL(listEkskul LE);
void insertLastEkskul(listEkskul &LE, adrEkskul P);
void deleteFirstEkskul(listEkskul &LE, adrEkskul &P);
void deleteLastEkskul(listEkskul &LE, adrEkskul &P);
void deleteAfterEkskul(listEkskul &LE, adrEkskul prec, adrEkskul &P);
adrEkskul searchEkskul(string namaEkskul, listEkskul LE);
void showDLL(listEkskul LE);

//Single Linked List element Siswa
void insertLastSiswa(listSiswa &LS, adrSiswa P);
void deleteFirstSiswa(listSiswa &LS, adrSiswa &P);
void deleteAfterSiswa(listSiswa &LS, adrSiswa &P, adrSiswa Prec);
void deleteLastSiswa(listSiswa &LS, adrSiswa &P);
adrSiswa searchSiswa(string nama, string NISN, listSiswa LS);
void showSLL(listSiswa LS);
bool cariSiswa(listSiswa LS, string nama, string NISN);

//Penghubung
bool isEkskulDuplicate(adrSiswa adrS, adrEkskul adrE);
void insertLastPenghubung(listSiswa &LS, adrSiswa adrS, adrEkskul adrE);
void deleteFirstPenghubung(listSiswa &LS, adrSiswa &adrS);
void deleteAfterPenghubung(listSiswa &LS, adrSiswa &adrS, adrPenghubung prec);
void deleteLastPenghubung(listSiswa &LS, adrSiswa &adrS);
void deleteAllPenghubung(listSiswa &LS, adrSiswa &adrS);
adrPenghubung cariEkskulSeorangSiswa(listSiswa LS, adrSiswa adrS, string namaEkskul);
int menghitungAnggotaClubBerdasarkanAngkatan(listSiswa LS, listEkskul LE, string ekskul, int angkatan);
#endif // TUBES_H_INCLUDED
