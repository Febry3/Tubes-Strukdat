#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct siswa {
    string nama, NISN;
    int umur;
};

struct ekskul {
    string nama;
    int jumlahPertemuan;
};

#define info(P) P->info
#define nextSiswa(P) P->nextSiswa
#define nextPenghubung(P) P->nextPenghubung
#define nextEkskul(P) P->nextEkskul
#define head(L) L.head

typedef struct elementSiswa *adrSiswa;
typedef struct elementEkskul *adrEkskul;
typedef struct elementPenghubung *adrPenghubung;

struct elementSiswa {
    siswa info;
    adrSiswa nextSiswa;
    adrPenghubung nextPenghubung;
};

struct elementEkskul {
    ekskul info;
    adrEkskul nextEkskul;
};

struct elementPenghubung {
    adrEkskul Ekskul;
    adrPenghubung nextPenghubung;
};

struct listSiswa {
    adrSiswa head;
};

struct listEkskul {
    adrEkskul head;
};

void createListSiswa(listSiswa LS);
void createListEkskul(listEkskul LE);
adrSiswa createElementSiswa(siswa data);
adrEkskul createElementEkskul(ekskul data);

#endif // TUBES_H_INCLUDED
