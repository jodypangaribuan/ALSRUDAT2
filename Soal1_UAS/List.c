#include "list.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsListEmpty(List L)
{
    return (First(L) == Nil);
}

void CreateList(List *L)
{
    First(*L) = Nil;
}

address Alokasi(infotype X)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

address Search(List L, infotype X)
{
    address P;
    boolean Found;

    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found))
    {
        if (X == Info(P))
        {
            Found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    return P;
}

boolean FSearch(List L, address P)
{
    address Pcek;
    boolean ketemu;

    Pcek = First(L);
    ketemu = false;
    while ((Pcek != Nil) && (!ketemu))
    {
        if (Pcek == P)
        {
            ketemu = true;
        }
        else
        {
            Pcek = Next(Pcek);
        }
    }
    return ketemu;
}
address SearchPrec(List L, infotype X)
{
    address P;
    boolean Found;

    P = First(L);
    Found = false;
    if (P == Nil)
    {
        return Nil;
    }
    else
    {
        while ((Next(P) != Nil) && (!Found))
        {
            if (X == Info(Next(P)))
            {
                Found = true;
            }
            else
            {
                P = Next(P);
            }
        }
    }
    if (Next(P) == Nil)
    {
        return Nil;
    }
    else
    {
        return P;
    }
}

void InsVFirst(List *L, infotype X)
{
    address P;

    P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X)
{
    address P;

    P = Alokasi(X);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}
void DelVFirst(List *L, infotype *X)
{
    address P;
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi(P);
}
void DelVLast(List *L, infotype *X)
{
    address P;
    DelLast(L, P);
    (*X) = Info(P);
    Dealokasi(P);
}
void InsertFirst(List *L, address P)
{
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertAfter(List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLast(List *L, address P)
{
    address Last;
    Last = First(*L);
    if (First(*L) == Nil)
    {
        InsertFirst(L, P);
    }
    else
    {
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}
void DelFirst(List *L, address P)
{
    P = First(*L);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi(P);
}
void DelP(List *L, infotype X)
{
    address P, Prec;
    P = Search(*L, X);
    if (P != Nil)
    {
        if (P == First(*L))
        {
            DelFirst(L, P);
        }
        else
        {
            Prec = SearchPrec(*L, X);
            DelAfter(L, P, Prec);
        }
    }
}

void DelLast(List *L, address P)
{
    address Last, PrecLast;
    Last = First(*L);
    PrecLast = Nil;
    while (Next(Last) != Nil)
    {
        PrecLast = Last;
        Last = Next(Last);
    }
    P = Last;
    if (PrecLast == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(PrecLast) = Nil;
    }
}
void DelAfter(List *L, address Pdel, address Prec)
{
    Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(Pdel) = Nil;
}
void PrintInfo(List L)
{
    address P;
    P = First(L);
    if (P == Nil)
    {
        printf("List Kosong");
    }
    else
    {
        while (Next(P) != Nil)
        {
            printf("%d ", Info(P));
            P = Next(P);
        }
        printf("%d", Info(P));
    }
}
int NbElmt(List L)
{
    address P;
    int i;

    i = 0;
    P = First(L);

    while (P != Nil)
    {
        i++;
        P = Next(P);
    }
    return i;
}
infotype Max(List L)
{
    infotype maksimum = Info(First(L));
    address P = Next(First(L));

    while (P != Nil)
    {
        if (Info(P) > maksimum)
        {
            maksimum = Info(P);
        }
        P = Next(P);
    }

    return maksimum;
}

address AdrMax(List L)
{
    infotype maksimum;
    address P;

    maksimum = Max(L);
    P = Search(L, maksimum);
    return P;
}
infotype Min(List L)
{
    infotype minimum;
    address P;

    P = First(L);
    minimum = Info(P);
    P = Next(P);
    while (P != Nil)
    {
        if (minimum > Info(P))
        {
            minimum = Info(P);
        }
        P = Next(P);
    }
    return minimum;
}
address AdrMin(List L)
{
    infotype minimum;
    address P;

    minimum = Min(L);
    P = Search(L, minimum);
    return P;
}

float Average(List L)
{
    float sum;
    address P;

    P = First(L);
    sum = Info(P);
    P = Next(P);
    while (P != Nil)
    {
        sum = sum + Info(P);
        P = Next(P);
    }
    return sum / NbElmt(L);
}

void DelAll(List *L)
{
    address P;

    P = First(*L);
    while (P != Nil)
    {
        First(*L) = Next(First(*L));
        Next(P) = Nil;
        Dealokasi(P);
        P = First(*L);
    }
}
void InversList(List *L)
{
    address P, Pt;

    CreateList(&Pt);
    if (P != Nil)
    {
        while (Next(P) != Nil)
        {
            Pt = Next(P);
            DelAfter(L, P, Pt);
            InsertFirst(L, Pt);
        }
    }
}
List FInversList(List L)
{
    List Li;
    address P, Pt;
    boolean gagal;

    gagal = false;
    CreateList(&Li);
    P = First(L);
    while ((P != Nil) && (!gagal))
    {
        Pt = Alokasi(Info(P));
        if (Pt != Nil)
        {
            InsertFirst(&Li, Pt);
            P = Next(P);
        }
        else
        {
            gagal = true;
        }
    }
    return Li;
}

void CopyList(List L1, List *L2)
{
    First(*L2) = First(L1);
}
List FCopyList(List L)
{
    address P, Pt;
    List Lt;
    boolean gagal;

    gagal = false;
    CreateList(&Lt);
    P = First(L);
    while ((P != Nil) && (!gagal))
    {
        Pt = Alokasi(Info(P));
        if (Pt != Nil)
        {
            InsertLast(&Lt, Pt);
            P = Next(P);
        }
        else
        {
            gagal = true;
            DelAll(&Lt);
        }
    }
    return Lt;
}

void CpAlokList(List Lin, List *Lout)
{
    address P, Pt;
    boolean gagal;

    CreateList(Lout);
    gagal = false;

    P = First(Lin);
    while ((P != Nil) && (!gagal))
    {
        Pt = Alokasi(Info(P));
        if (Pt != Nil)
        {
            InsertLast(Lout, Pt);
            P = Next(P);
        }
        else
        {
            gagal = true;
            DelAll(Lout);
        }
    }
}

void Konkat(List L1, List L2, List *L3)
{
    address P, Pt;
    boolean gagal;

    CreateList(L3);
    gagal = false;
    P = First(L1);
    while ((P != Nil) && (!gagal))
    {
        Pt = Alokasi(Info(P));
        if (Pt != Nil)
        {
            InsertLast(L3, Pt);
            P = Next(P);
        }
        else
        {
            gagal = true;
            DelAll(L3);
        }
    }
    if (!gagal)
    {
        P = First(L2);
        while ((P != Nil) && (!gagal))
        {
            Pt = Alokasi(Info(P));
            if (Pt != Nil)
            {
                InsertLast(L3, Pt);
                P = Next(P);
            }
            else
            {
                gagal = true;
                DelAll(L3);
            }
        }
    }
}

void Konkat1(List *L1, List *L2, List *L3)
{
    address P;

    P = First(*L1);
    CreateList(L3);
    First(*L3) = First(*L1);
    if (P != Nil)
    {
        while (Next(P) != Nil)
        {
            P = Next(P);
        }
    }
    Next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}

void PecahList(List *L1, List *L2, List L)
{
    address P, Pt;
    boolean gagal;
    int i, N;

    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L);
    P = First(L);
    while ((P != Nil) && (!gagal))
    {
        Pt = Alokasi(Info(P));
        if ((i <= N))
        {
            if (Pt != Nil)
            {
                InsertLast(L1, Pt);
                P = Next(P);
                i++;
            }
            else
            {
                gagal = true;
                DelAll(L1);
            }
        }
        else
        {
            if (Pt != Nil)
            {
                InsertLast(L2, Pt);
                P = Next(P);
                i++;
            }
            else
            {
                gagal = true;
                DelAll(L2);
            }
        }
    }
}