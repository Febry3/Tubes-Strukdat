#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct siswa {
    string namaSiswa, NISN;
    int umur, angkatan;
};

struct ekskul {
    string namaEkskul;
    int jumlahPertemuan;
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
adrEkskul searchEkskul(ekskul target, listEkskul LE);
void showDLL(listEkskul LE);

//Single Linked List element Siswa
void insertLastSiswa(listSiswa &LS, adrSiswa P);
void deleteFirstSiswa(listSiswa &LS, adrSiswa &P);
void deleteAfterSiswa(listSiswa &LS, adrSiswa &P, adrSiswa Prec);
void deleteLastSiswa(listSiswa &LS, adrSiswa &P);
adrSiswa searchSiswa(string nama, string NISN, listSiswa LS);
void showSLL(listSiswa LS);

int selecMenu();
#endif // TUBES_H_INCLUDED
