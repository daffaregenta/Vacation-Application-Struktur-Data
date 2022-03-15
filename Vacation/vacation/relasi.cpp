#include "relasiList.h"
#include "parent2Data.h"
#include "parentData.h"

void createListRelation(ListRelation &L) {
    first(L) = NULL;
}
addressRelation allocateRelation(addressParent aP, addressParent2 aQ) {
    addressRelation P = new elmlistRelation;
    parent(P) = aP;
    parent2(P)  = aQ;
    next(P) = NULL;
    return P;
}
void insertRelation(ListRelation &L, addressRelation P) {
    if(first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}
void deleteRelation(ListRelation &L, addressRelation &P) {
    if(first(L) != NULL)
    {
        if(P == first(L))
        {
            if(next(first(L)) != NULL)
            {
                first(L) = next(first(L));
            } else
            {
                delete P;
            }
        }
        else
        {
            addressRelation Q = first(L);
            while(next(Q) != NULL)
            {
                if(next(Q) == P)
                {
                    next(Q) = next(P);
                    break;
                }
                Q = next(Q);
            }
        }
    }
}
addressRelation findRelation(ListRelation L, addressParent aP, addressParent2 aQ) {
    if(first(L) != NULL)
    {
        addressRelation P = first(L);
        while(P != NULL)
        {
            if((parent(P) == aP) && (parent2(P) == aQ))
            {
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printTempatdanPengunjungByID(addressParent listTempat, ListRelation listRelasi) {
    lihatTempat(info(listTempat));
    bool ada = false;
    addressRelation pRelasi = first(listRelasi);
    cout<<"  Pengunjung     : ";
    while(pRelasi != NULL)
    {
        if(parent(pRelasi) == listTempat)
        {
            ada = true;
            cout<<info(parent2(pRelasi)).nama_pengunjung<<", ";
        }
        pRelasi = next(pRelasi);
    }
    if(ada == false)
    {
        cout<<"<kosong>";
    }
}
void printTempatdanPengunjung(ListParent listTempat, ListRelation listRelasi) {
    addressParent tTempat = first(listTempat);
    while(tTempat != NULL)
    {
        printTempatdanPengunjungByID(tTempat, listRelasi);
        cout<<endl<<endl;
        tTempat = next(tTempat);
    }
}


