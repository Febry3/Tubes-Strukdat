#include <iostream>
#include "Tubes.h"
using namespace std;

int main()
{
    listEkskul LE;
    createListEkskul(LE);
    ekskul t;
    t.namaEkskul = "Tawuran";
    t.jumlahPertemuan = 10;
    insertLastEkskul(LE, createElementEkskul(t));
    t.namaEkskul = "Debat";
    t.jumlahPertemuan = 10;
    insertLastEkskul(LE, createElementEkskul(t));
    t.namaEkskul = "Menari";
    t.jumlahPertemuan = 10;
    insertLastEkskul(LE, createElementEkskul(t));
    adrEkskul Q = searchEkskul("Debat", LE);
    cout << infoEkskul(Q).namaEkskul;
    return 0;
}
