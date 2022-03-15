#ifndef RELASILIST_H_INCLUDED
#define RELASILIST_H_INCLUDED

#include <iostream>
#include "parent2.h"
#include "parent.h"

#define first(L) L.first
#define parent(P) P->parent
#define parent2(P) P->parent2
#define next(P) P->next


using namespace std;

typedef struct elmlistParent *addressParent;
typedef struct elmlistParent2 *addressParent2;
typedef struct elmlistRelation *addressRelation;

struct elmlistRelation{
    addressParent parent;
    addressParent2 parent2;
    addressRelation next;
};

struct ListRelation{
    addressRelation first;
};

void createListRelation(ListRelation &L);
addressRelation allocateRelation(addressParent aP, addressParent2 aQ);
void insertRelation(ListRelation &L, addressRelation P);
void deleteRelation(ListRelation &L, addressRelation &P);
addressRelation findRelation(ListRelation L, addressParent aP, addressParent2 aQ);
void printTempatdanPengunjungByID(addressParent listTempat, ListRelation listRelasi);
void printTempatdanPengunjung(ListParent listTempat, ListRelation listRelasi);


#endif // RELASILIST_H_INCLUDED
