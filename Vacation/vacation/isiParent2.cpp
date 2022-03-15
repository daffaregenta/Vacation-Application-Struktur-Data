#include "parent2Data.h"

pengunjung create_data_pengunjung() {
    pengunjung d;
    cout<<"  ID Pengunjung (integer)  : ";
    cin>> d.id_pengunjung;
    if(cin.fail())
    {
        cin.clear();
        d.id_pengunjung = NULL;
        cout<<"  ID Pengunjung yang anda inputkan bukan integer. Tekan 'Enter' untuk melanjutkan...";
    }
    else
    {
        cout<<"  Nama Pengunjung         : ";
        cin.ignore();
        getline(cin, d.nama_pengunjung);
    }
    return d;
}
void lihatPengunjung(pengunjung p) {
    cout<<"  ID Pengunjung        : " <<p.id_pengunjung<<endl;
    cout<<"  Nama Pengunjung      : " <<p.nama_pengunjung<<endl;
}
void edit_data_pengunjung(pengunjung &p) {
    cout<<"  ID Pengunjung (integer)  : ";
    cin>> p.id_pengunjung;
    if(cin.fail())
    {
        cin.clear();
        p.id_pengunjung = NULL;
        cout<<"  ID Pengunjung yang anda inputkan bukan integer. Tekan 'Enter' untuk melanjutkan...";
    }
    else
    {
        cout<<"  Nama Pengunjung         : ";
        cin.ignore();
        getline(cin, p.nama_pengunjung);
    }
}
