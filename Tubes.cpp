#include "Tubes.h"

void createListSiswa(listSiswa LS){
    head(LS) = NULL;
}
void createListEkskul(listEkskul LE){
    head(LE) = NULL;
}

adrSiswa createElementSiswa(siswa data) {
    adrSiswa P = new elementSiswa;
    info(P) = data;
    nextSiswa(P) = NULL;
    nextPenghubung(P) = NULL;
    return P;
}

adrEkskul createElementEkskul(ekskul data){
    adrEkskul P = new elementEkskul;
    info(P) = data;
    nextEkskul(P) = NULL;
    return P;
}