#include "caseFungsilitas.h"

void total(ListParent &L, tempat &x, tempat &y, int &day) {
    addressParent P = findElmTempat(L, x);
    addressParent Q = findElmTempat(L, y);


    if(P != NULL && Q != NULL)
    {
        srand(time(0));
        int i = rand()%6;
        info(P).total_tempat = info(P).total_tempat + i;
        int j = rand()%7;
        info(Q).total_tempat = info(Q).total_tempat + j;
        day++;
        cout << "Hasil Akhir Kunjungan : " << endl;
        cout << "Tempat '"<<info(P).nama_tempat<<"' : " << i << endl;
        cout << "Tempat '"<<info(Q).nama_tempat<<"' : " << j << endl;
    }
    else
    {
        cout << "ID Tempat tidak ditemukan silahkan masukkan ID ulang..." << endl;
    }
}
void listJumlahKunjungan(ListParent L) {
    const int nMax = 100;
    int n = hitungTempat(L);
    int ID[nMax];
    string nama[nMax];
    int total[nMax];
    if((first(L) != NULL) && (last(L) != NULL))
    {
        addressParent P = first(L);
        int k = 1;
        while(P != NULL){
            ID[k] = info(P).id_tempat;
            nama[k] = info(P).nama_tempat;
            total[k] = info(P).total_tempat;
            k++;
            P = next(P);
        }
        int tmp;
        for(int a = n-1; a>=1; a--){
            for(int b = 1; b<=a; b++){
                if(total[b] > total[b+1]){
                    tmp = total[b+1];
                    total[b+1]= total[b];
                    total[b] = tmp;
                }
            }
        }
           cout<<"========================================="<<endl;
            cout<<"          LIST TOTAL SAAT INI          "<<endl;
            cout<<"========================================="<<endl;
        for(int a = n; a>=1; a--){
            cout<<"  ID Tempat        : " <<ID[a]<<endl;
            cout<<"  Nama Tempat  : " <<nama[a]<<endl;
            cout<<"  Jumlah total    : " <<total[a]<<endl;
            cout<<"========================================="<<endl;
        }
    }
    else
    {
        cout << "Silahkan inputkan tempat anda terlebih dahulu, karena data kosong..." << endl;
    }
}
int hitungTempat(ListParent &L) {
    int i = 0;
    addressParent P = first(L);
    while(P != NULL){
        i++;
        P = next(P);
    }
    return i;
}
