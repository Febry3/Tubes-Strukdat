#include "Tubes.h"
//menu
void menu(){
    cout << "============DATA SISWA BESERTA EKSKUL STM KAPAL LAOET============" << endl;
    cout << "1. Menambah Data Siswa" << endl; //done
    cout << "2. Menampilkan Semua Data Siswa" << endl; //done
    cout << "3. Menghapus Data Siswa" << endl; //done
    cout << "4. Mencari Data Siswa" << endl; //done
    cout << "5. Mencari Data Ekskul" << endl; //done
    cout << "6. Menambahkan Data Ekskul" << endl; //done
    cout << "7. Siswa Memilih Ekskul (menghubungkan data parent ke child)" << endl;
    cout << "8. Menampilkan Data Siswa Beserta Ekskul yang Diikutinya " << endl;
    cout << "9. Mencari Data Ekskul Pada Siswa tertentu" << endl;
    cout << "10. Menghapus Ekskul pada Siswa Tertentu" << endl;
    cout << "11. Menghitung Jumlah Ekskul yang Diikuti Siswa Tertentu" << endl;
    cout << "==================================================================" << endl;
}

void menambahkanDataSiswa(listSiswa &LS){
    siswa dataSiswa;
    cout << "Masukkan data siswa berikut: " << endl;
    cout << "Nama: ";
    cin >> dataSiswa.namaSiswa;
    cout << endl;
    cout << "Umur: ";
    cin >> dataSiswa.umur;
    cout << endl;
     cout << "Kelas: ";
    cin >> dataSiswa.kelas;
    cout << endl;
     cout << "Jurusan: ";
    cin >> dataSiswa.jurusan;
    cout << endl;
     cout << "NISN: ";
    cin >> dataSiswa.NISN;
    cout << endl;
     cout << "Angkatan: ";
    cin >> dataSiswa.angkatan;
    cout << endl;
    insertLastSiswa(LS, createElementSiswa(dataSiswa));
    cout << "Input Berhasil" << endl;
}

void menampilkanDataSiswa(listSiswa LS) {
    showSLL(LS);
}

void menghapusDataSiswa(listSiswa &LS) { 
    string nama, NISN;
    cout << "Nama Siswa yang ingin dihapus: ";
    cin >> nama;
    cout << endl;
    cout << "NISN Siswa yang ingin dihapus: ";
    cin >> NISN;
    cout << endl;
    adrSiswa P = searchSiswa(nama, NISN, LS);
    
    adrSiswa Q = head(LS);
    while (nextSiswa(Q) != NULL) {
        Q = nextSiswa(Q);
    }

    if (head(LS) == P) {
        deleteFirstSiswa(LS, P);
        cout << "Penghapusan Berhasil" << endl;
    } else if (Q == P) {
        deleteLastSiswa(LS, P);
        cout << "Penghapusan Berhasil" << endl;
    } else {
        adrSiswa R = head(LS);
        while (nextSiswa(R) != P) {
            R = nextSiswa(R);
        }
        deleteAfterSiswa(LS, P, R);
        cout << "Penghapusan Berhasil" << endl; 
    }
}

void mencariDataSiswa(listSiswa LS){
    string nama, NISN;
    cout << "Masukkan Nama Siswa yang Ingin dicari: ";
    cin >> nama;
    cout << endl;
    cout << "Masukkan NISN Siswa yang Ingin dicari: ";
    cin >> NISN;
    cout << endl;
    adrSiswa P = searchSiswa(nama, NISN, LS);
    cout << "Nama: " << infoSiswa(P).namaSiswa << endl;
    cout << "Umur: " << infoSiswa(P).umur << endl;
    cout << "Kelas: " << infoSiswa(P).kelas << endl;
    cout << "Jurusan: " << infoSiswa(P).jurusan << endl;
    cout << "NISN: " << infoSiswa(P).NISN << endl;
    cout << "Angkatan: " << infoSiswa(P).angkatan << endl;
    cout << "Ekskul yang diikuti: " << endl;
    adrPenghubung Q = nextPenghubung(P);
    int i = 0;
    while (Penghubung(Q) != NULL) {
        cout << i + 1 << ". " << infoEkskul(Ekskul(Q)).namaEkskul << " " << infoEkskul(Ekskul(Q)).jumlahPertemuan << endl;
        i++;
        Q = Penghubung(Q);
    } 
    
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

adrEkskul searchEkskul(string namaEkskul, listEkskul LE) {
    adrEkskul P = head(LE);
    while (P != NULL && infoEkskul(P).namaEkskul != namaEkskul) {
        P = nextEkskul(P);
    }
    return P;
}

void showDLL(listEkskul LE){
    adrEkskul P = head(LE);

    while (P != NULL) {
        cout << "Nama Ekskul: " << infoEkskul(P).namaEkskul << endl;
        cout << "Jumlah Pertemuan perminggu: " << infoEkskul(P).jumlahPertemuan << endl;
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
adrSiswa searchSiswa(string namaSiswa, string NISN, listSiswa LS) {
    adrSiswa P = head(LS);
    while (P != NULL) {
        if (infoSiswa(P).namaSiswa == namaSiswa && infoSiswa(P).NISN == NISN) {
            return P;
        }
        P = nextSiswa(P);
    }
    return P;
}
void showSLL(listSiswa LS) {
    adrSiswa P = head(LS);
        if (head(LS) == NULL) {
            cout << "Tidak Terdapat Siswa yang terdaftar" << endl;
        } else {
            while (P != NULL) {
            cout << "Nama: " << infoSiswa(P).namaSiswa << endl;
            cout << "Umur: " << infoSiswa(P).umur << endl;
            cout << "Kelas: " << infoSiswa(P).kelas << endl;
            cout << "Jurusan: " << infoSiswa(P).jurusan << endl;
            cout << "NISN: " << infoSiswa(P).NISN << endl;
            cout << "Angkatan: " << infoSiswa(P).angkatan << endl;
            P = nextSiswa(P);
        }
    }
}
