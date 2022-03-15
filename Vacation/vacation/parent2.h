#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include "parent2Data.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmlistParent2 *addressParent2;

struct elmlistParent2{
    pengunjung info;
    addressParent2 next;
};

struct ListParent2{
    addressParent2 first;
};

void createListPengunjung(ListParent2 &L);
addressParent2 allocatePengunjung(pengunjung x);
void insertFirstPengunjung(ListParent2 &L, addressParent2 P);
void insertLastPengunjung(ListParent2 &L, addressParent2 P);
void insertAfterPengunjung(ListParent2 &L, addressParent2 Prec, addressParent2 P);
void printInfoPengunjung(ListParent2 L);
void deleteFirstPengunjung(ListParent2 &L, addressParent2 &P);
void deleteLastPengunjung(ListParent2 &L, addressParent2 &P);
void deleteAfterPengunjung(ListParent2 &L, addressParent2 Prec, addressParent2 &P);
void deleteByIDPengunjung(ListParent2 &L, addressParent2 &P);
addressParent2 findElmPengunjung(ListParent2 L, pengunjung x);

#endif // CHILD_H_INCLUDED
