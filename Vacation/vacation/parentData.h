#ifndef PARENTDATA_H_INCLUDED
#define PARENTDATA_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

struct tempat{
    int id_tempat;
    string nama_tempat;
    int total_tempat;
};

tempat create_data_tempat();
void lihatTempat(tempat t);
void edit_data_tempat(tempat &t);

#endif // PARENTADATA_H_INCLUDED
