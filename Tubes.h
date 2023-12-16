#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct siswa {
    string nama, NISN;
    int umur;
};

typedef struct elemenJadwal *adrSiswa;
typedef struct elementEkskul *adrEkskul;
typedef struct elementAngkatan *adrAngkatan;
typedef struct elementPenghubung *adrPenghubung;

struct ekskul {
    string nama;
    int jumlahPertemuan;
};

struct angkatan {
    int tahunMasuk;
};

struct elementSiswa {
    siswa info;
    adrSiswa nextSiswa;
    adrPenghubung nextPenghubung;
};

struct elementEkskul {
    ekskul info;
    adrEkskul nextEkskul;
};

struct elementAngkatan {
    angkatan info;
    adrAngkatan nextAngkatan;
};

struct elementPenghubung {
    adrAngkatan Angkatan;
    adrEkskul Ekskul;
};

struct listSiswa {
    adrSiswa head;
};

struct listAngkatan {
    adrAngkatan head;
};

struct listEkskul {
    adrEkskul head;
};
#endif // TUBES_H_INCLUDED
