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
    
    while (pilihan != 10) {
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
            siswaMemilihEkskul(LS, LE);
            break;
        case 8:
            mencariEkskulPadaSeorangSiswa(LS);
            break;
        case 9:
            mengurangiEkskulSiswa(LS);
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
