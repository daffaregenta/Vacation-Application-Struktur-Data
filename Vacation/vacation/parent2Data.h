#ifndef CHILDDATA_H_INCLUDED
#define CHILDDATA_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

struct pengunjung{
    int id_pengunjung;
    string nama_pengunjung;
};

pengunjung create_data_pengunjung();
void lihatPengunjung(pengunjung p);
void edit_data_pengunjung(pengunjung &p);

#endif // CHILDDATA_H_INCLUDED
