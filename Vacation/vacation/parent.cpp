#include "parent.h"
#include "parentData.h"

void createListTempat(ListParent &L) {
    first(L) = NULL;
    last(L)  = NULL;
}
addressParent allocateTempat(tempat x) {
    addressParent P;
    P = new elmlistParent;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertFirstTempat(ListParent &L, addressParent P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastTempat(ListParent &L, addressParent P) {
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstTempat(L,P);
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void printInfoTempat(ListParent L) {
     if((first(L) != NULL) && (last(L) != NULL)){
        addressParent P = first(L);
        cout << "  ---------------  LIST TEMPAT  ---------------" << endl;
        while(P != NULL){
            lihatTempat(info(P));
            cout<<endl;
            P = next(P);
        }
    }
    else
    {
        cout << "Silahkan inputkan tempat anda terlebih dahulu, karena data kosong..." << endl;
    }
}
void deleteFirstTempat(ListParent &L, addressParent &P) {
    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}
void deleteLastTempat(ListParent &L, addressParent &P) {
    if(last(L) != NULL){
        P = last(L);
        if(first(L) == last(L)){
            deleteFirstTempat(L,P);
        }
        else{
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}
void deleteAfterTempat(ListParent &L, addressParent Prec, addressParent &P) {
    if((Prec != NULL) && next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteByIDTempat(ListParent &L, addressParent &P) {
    if(P == first(L)){
        deleteFirstTempat(L,P);
    }
    else if(P == last(L)){
        deleteLastTempat(L,P);
    }
    else{
        addressParent Q = prev(P);
        deleteAfterTempat(L,Q,P);
    }
}
addressParent findElmTempat(ListParent L, tempat x) {
    if((first(L) != NULL) && (last(L) != NULL)){
        addressParent P = first(L);
        while(P != NULL){
            if(info(P).id_tempat == x.id_tempat){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}
