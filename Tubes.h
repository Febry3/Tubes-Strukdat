#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

struct siswa {
    string nama, NISN;
    int umur;
};
typedef struct elemenJadwal *adrSiswa;

struct ekskul {
    string nama;
    int jumlahPertemuan;
};

typedef struct elementEkskul *adrEkskul;

struct angkatan {
    int tahunMasuk;
};

typedef struct elementAngkatan *adrAngkatan;

struct elementSiswa {
    siswa info;
    adrSiswa nextSiswa;
};

struct elementEkskul {
    ekskul info;
    adrEkskul nextEkskul;
};

struct elementAngkatan {
    angkatan info;
    adrAngkatan nextAngkatan;
};
#endif // TUBES_H_INCLUDED
