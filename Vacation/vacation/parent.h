#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
#include "parentData.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmlistParent *addressParent;
struct elmlistParent{
    tempat info;
    addressParent next;
    addressParent prev;
};

struct ListParent{
    addressParent first;
    addressParent last;
};

void createListTempat(ListParent &L);
addressParent allocateTempat(tempat x);
void insertLastTempat(ListParent &L, addressParent P);
void printInfoTempat(ListParent L);
void deleteFirstTempat(ListParent &L, addressParent &P);
void deleteLastTempat(ListParent &L, addressParent &P);
void deleteAfterTempat(ListParent &L, addressParent Prec, addressParent &P);
void deleteByIDTempat(ListParent &L, addressParent &P);
addressParent findElmTempat(ListParent L, tempat x);

#endif // PARENT_H_INCLUDED
