#include <iostream>
#include "parent.h"
#include "relasiList.h"
#include "caseFungsilitas.h"


using namespace std;

int main()
{
    ListParent listTempat;
    ListParent2 listPengunjung;
    ListRelation listRelasi;

    tempat t;
    tempat tempat1, tempat2;
    pengunjung p;

    addressParent addP; // ini buat Tempat
    addressParent2 addQ; // ini buat Pengunjung
    addressRelation addR; // Relasi

    int menu;
    int day = 1;

    createListTempat(listTempat);
    createListPengunjung(listPengunjung);
    createListRelation(listRelasi);

    while(true)
    {
        cout << "VACATION - TUBES STRUKTUR DATA - IF-43-GAB 02" << endl;
        cout << "Pembuat Aplikasi : " << endl;
        cout << "   1. Daffa Ulayya Suhendra (1301184328)" << endl;
        cout << "   2. Muhammad Daffa Regenta S (1301184291)" << endl << endl;
        cout << "Silahkan Pilih Menu Dengan Menginputkan Nomor" << endl;
        cout << "[1.] Input Tempat" << endl;
        cout << "[2.] Input Pengunjung" << endl;
        cout << "[3.] List Tempat" << endl;
        cout << "[4.] List Pengunjung" << endl;
        cout << "[5.] Delete Tempat By ID" << endl;
        cout << "[6.] Delete Pengunjung By ID" << endl;
        cout << "[7.] Buat Koneksi Pengunjung dengan Tempat" << endl;
        cout << "[8.] Putuskan/Hapus Koneksi Pengunjung dengan Tempat" << endl;
        cout << "[9.] List Pengunjung dengan Tempat" << endl;
        cout << "[10.] Edit Tempat By ID" << endl;
        cout << "[11.] Edit Pengunjung By ID" << endl;
        cout << "[12.] History ('"<< day <<" Hari')" << endl;
        cout << "[13.] List total Kunjungan" << endl;
        cout << endl;
        cout << "[0.] Keluar Program" << endl;

        cout<<endl;
        cout<<"Pilihan (integer): ";
        cin>>menu;
        if(cin.fail())
        {
            cin.clear();
            cout<<"Pilihan yang anda inputkan bukan integer. Tekan 'Enter' untuk kembali ke menu utama...";
            cin.sync();
            cin.get();
            system("CLS");
        }
        else
        {
            switch(menu)
            {
            case 0:
                cout<<"Thank You For Used Our Program." << endl;
                return 0;
                break;
            case 1:
                t = create_data_tempat();
                if((t.id_tempat != NULL) && (findElmTempat(listTempat,t) == NULL))
                {
                    addP = allocateTempat(t);
                    insertLastTempat(listTempat, addP);
                    cout<<"  Tempat berhasil diinput! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else if(findElmTempat(listTempat,t) != NULL)
                {
                    cout<<"  ID duplikat! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 2:
                p = create_data_pengunjung();
                if((p.id_pengunjung != NULL) && (findElmPengunjung(listPengunjung,p) == NULL))
                {
                    addQ = allocatePengunjung(p);
                    insertLastPengunjung(listPengunjung, addQ);
                    cout<<"  Pengunjung berhasil diinput! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else if(findElmPengunjung(listPengunjung,p) != NULL)
                {
                    cout<<"  ID duplikat! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 3:
                printInfoTempat(listTempat);
                cout << endl;
                cout<<"Tekan 'Enter' untuk kembali ke menu utama...";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 4:
                printInfoPengunjung(listPengunjung);
                cout << endl;
                cout<<"Tekan 'Enter' untuk kembali ke menu utama...";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 5:
                cout<<"  Masukan ID Tempat : ";
                cin>>t.id_tempat;
                addP = findElmTempat(listTempat,t);
                if(addP == NULL)
                {
                    cout<<"  ID Tempat tidak ditemukan! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else
                {
                    deleteByIDTempat(listTempat,addP);
                    cout<<"  Tempat '"<<info(addP).nama_tempat<<"' berhasil dihapus! Tekan 'Enter' untuk kembali ke menu utama...";
                    delete addP;
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 6:
                cout<<"  Masukan ID Pengunjung : ";
                cin>>p.id_pengunjung;
                addQ = findElmPengunjung(listPengunjung, p);
                if(addQ == NULL)
                {
                    cout<<"  ID Pengunjung tidak ditemukan! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else
                {
                    deleteByIDPengunjung(listPengunjung,addQ);
                    cout<<"  Pengunjung bernama '"<<info(addQ).nama_pengunjung<<"' berhasil dihapus! Tekan 'Enter' untuk kembali ke menu utama...";
                    delete addQ;
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 7:
                cout<<"  Masukan ID Tempat  : ";
                cin>>t.id_tempat;
                cout<<"  Input ID Pengunjung : ";
                cin>>p.id_pengunjung;
                addP = findElmTempat(listTempat, t);
                addQ = findElmPengunjung(listPengunjung, p);
                if((addQ != NULL) && (addP != NULL))
                {
                    addR = findRelation(listRelasi,addP,addQ);
                    if(addR == NULL)
                    {
                        addR = allocateRelation(addP,addQ);
                        insertRelation(listRelasi, addR);
                    }
                    cout<<"  Pengunjung '"<<info(addQ).nama_pengunjung<<"' telah terelasi dengan tempat '"<<info(addP).nama_tempat<<"'.";
                    cout<< endl << "  Tekan 'Enter' untuk kembali ke menu utama...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                }
                else if((addQ == NULL) && (addP == NULL))
                {
                    cout<<"  ID Tempat dan ID Pengunjung tidak ditemukan!";
                    cout<< endl << "  Tekan 'Enter' untuk kembali ke menu utama...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                }
                else if(addQ == NULL)
                {
                    cout<<"  ID Pengunjung tidak ditemukan!";
                    cout<< endl << "  Tekan 'Enter' untuk kembali ke menu utama...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                }
                else if(addP == NULL)
                {
                    cout<<"  ID Tempat tidak ditemukan!";
                    cout<< endl << "  Tekan 'Enter' untuk kembali ke menu utama...";
                    cin.sync();
                    cin.get();
                    system("CLS");
                }
                break;
            case 8:
                cout<<"  Input ID Tempat  : ";
                cin>>t.id_tempat;
                cout<<"  Input ID Pengunjung : ";
                cin>>p.id_pengunjung;
                addP = findElmTempat(listTempat, t);
                addQ = findElmPengunjung(listPengunjung, p);
                addR = findRelation(listRelasi,addP,addQ);
                deleteRelation(listRelasi,addR);

                cout<<" Tekan 'Enter' untuk kembali ke menu utama...";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 9:
                cout<<endl;
                cout<<"  ----------  List Pengunjung dengan Tempat  ----------"<<endl;
                printTempatdanPengunjung(listTempat, listRelasi);
                cout<<"  Tekan 'Enter' untuk kembali ke menu utama...";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 10:
                cout<<"  Input ID Tempat  : ";
                cin>>t.id_tempat;
                addP = findElmTempat(listTempat,t);
                if(addP == NULL)
                {
                    cout<<"  ID tidak ditemukan! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else
                {
                    t = info(addP);
                    edit_data_tempat(info(addP));
                    cout<<"  Tempat berhasil diganti menjadi '"<<info(addP).nama_tempat<<"' ! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 11:
                cout<<"  Input ID Pengunjung  : ";
                cin>>p.id_pengunjung;
                addQ = findElmPengunjung(listPengunjung,p);
                if(addQ == NULL)
                {
                    cout<<"  ID Pengunjung tidak ditemukan! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                else
                {
                    p = info(addQ);
                    edit_data_pengunjung(info(addQ));
                    cout<<"  Pengunjung berhasil diganti menjadi '"<<info(addQ).nama_pengunjung<<"' ! Tekan 'Enter' untuk kembali ke menu utama...";
                }
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 12:
                cout<<"Input ID Tempat Pertama : ";
                cin>>tempat1.id_tempat;
                cout<<"Input ID Tempat Kedua : ";
                cin>>tempat2.id_tempat;
                total(listTempat, tempat1, tempat2, day);
                cout<<"Tekan 'Enter' untuk kembali ke menu utama......";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            case 13:
                listJumlahKunjungan(listTempat);
                cout<<"Tekan 'Enter' untuk kembali ke menu utama......";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            default:
                cout<<"Pilihan tidak tersedia. Tekan 'Enter' untuk kembali ke menu utama...";
                cin.sync();
                cin.get();
                system("CLS");
                break;
            }
        }
    }
}

