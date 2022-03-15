#include "parent2.h"
#include "parent2Data.h"

void createListPengunjung(ListParent2 &L) {
    first(L) = NULL;
}
addressParent2 allocatePengunjung(pengunjung x) {
    addressParent2 P;
    P = new elmlistParent2;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void insertFirstPengunjung(ListParent2 &L, addressParent2 P) {
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else{
        addressParent2 Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertLastPengunjung(ListParent2 &L, addressParent2 P) {
    if(first(L) == NULL){
        insertFirstPengunjung(L,P);
    }
    else{
        addressParent2 Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}
void insertAfterPengunjung(ListParent2 &L, addressParent2 Prec, addressParent2 P) {
    if((Prec != NULL) && (first(L) != NULL)){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void printInfoPengunjung(ListParent2 L) {
    if(first(L) != NULL){
        addressParent2 P = first(L);
        cout << "  ---------------  LIST PENGUNJUNG  ---------------" << endl;
        do{
            lihatPengunjung(info(P));
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    } else {
        cout << "Silahkan inputkan pengunjung anda terlebih dahulu, karena data kosong..." << endl;
    }
}
void deleteFirstPengunjung(ListParent2 &L, addressParent2 &P) {
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            first(L) = NULL;
        }
        else{
            addressParent2 Q = first(L);
            while(next(Q) != first(L)){
                Q = next(Q);
            }
            first(L) = next(P);
            next(Q) = first(L);
        }
    }
}
void deleteLastPengunjung(ListParent2 &L, addressParent2 &P) {
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            deleteFirstPengunjung(L,P);
        }
        else{
            addressParent2 Q = first(L);
            while(next(next(Q)) != first(L)){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
        }
    }
}
void deleteAfterPengunjung(ListParent2 &L, addressParent2 Prec, addressParent2 &P) {
    if((Prec != NULL) && (first(L) != NULL)){
        P = next(Prec);
        next(Prec) = next(P);
    }
}
void deleteByIDPengunjung(ListParent2 &L, addressParent2 &P) {
    if(P == first(L)){
        deleteFirstPengunjung(L,P);
    }
    else if(next(P) == first(L)){
        deleteLastPengunjung(L,P);
    }
    else{
        addressParent2 Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        deleteAfterPengunjung(L,Q,P);
    }
}
addressParent2 findElmPengunjung(ListParent2 L, pengunjung x) {
    if(first(L) != NULL){
        addressParent2 P = first(L);
        do{
            if(info(P).id_pengunjung == x.id_pengunjung){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}
