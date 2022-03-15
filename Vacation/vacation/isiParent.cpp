#include "parentData.h"

tempat create_data_tempat()
{
    tempat d;
    cout<<"  ID Tempat (integer)  : ";
    cin>> d.id_tempat;
    if(cin.fail())
    {
        cin.clear();
        cout<<"  ID Tempat yang anda inputkan bukan integer. Tekan 'Enter' untuk melanjutkan...";
    }
    else
    {
        cout<<"  Nama Tempat         : ";
        cin.ignore();
        getline(cin, d.nama_tempat);
        d.total_tempat = 0;
    }
    return d;
}

void lihatTempat(tempat t)
{
    cout<<"  ID Tempat        : " <<t.id_tempat<<endl;
    cout<<"  Nama Tempat  : " <<t.nama_tempat<<endl;
    cout<<"  Jumlah total    : " <<t.total_tempat<<endl;
}

void edit_data_tempat(tempat &t){
    cout<<"  Nama Tempat     : ";
    cin.ignore();
    getline(cin, t.nama_tempat);
}
