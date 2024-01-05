#include <iostream>
#include "Tubes.h"
using namespace std;

int main()
{
    listSiswa LS;
    createListSiswa(LS);
    listEkskul LE;
    createListEkskul(LE);

    int pilihan = 0;
    menu();
    cout << "Masukkan Pilihan: ";
    cin >> pilihan;
    cout << endl;

    while (pilihan != 12) {
        switch (pilihan)
        {
        case 1:
            menambahkanDataSiswa(LS);
            break;
        case 2:
            menampilkanDataSiswa(LS);
            break;
        case 3:
            menghapusDataSiswa(LS);
            break;
        case 4:
            mencariDataSiswa(LS);
            break;
        case 5:
            menambahkanDataEkskul(LE);
            break;
        case 6:
            mencariDataEkskul(LE);
            break;
        case 7:
            menampilkanDaftarEkskul(LE);
            break;
        case 8:
            siswaMemilihEkskul(LS, LE);
            break;
        case 9:
            mencariEkskulPadaSeorangSiswa(LS);
            break;
        case 10:
            mengurangiEkskulSiswa(LS);
            break;
        case 11:
            jumlahAngkatanPadaEkskul(LS, LE);
            break;
        default:
            break;
        }
        menu();
        cout << "Masukkan Pilihan: ";
        cin >> pilihan;
        cout << endl;
    }


    return 0;
}
