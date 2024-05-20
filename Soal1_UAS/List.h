#ifndef list_h
#define list_h
#include "boolean.h"

#define Nil NULL
typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList
{
   infotype Info;
   address Next;
} ElmtList;
typedef address List;

/* ----- Selektor ----- */
#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(L) (L)

/* ----- Test List Kosong ----- */
boolean IsListEmpty(List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */

void CreateList(List *L);
address Alokasi(infotype X);
void Dealokasi(address P);
address Search(List L, infotype X);
boolean FSearch(List L, address P);
address SearchPrec(List L, infotype X);
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst(List *L, address P);
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter(List *L, address P, address Prec);
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
           P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast(List *L, address P);
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelVFirst(List *L, infotype *X);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelP(List *L, infotype X);
/* I.S.     : Sembarang
   F.S.     : Jika ada elemen list beraddress P, dengan Info(P) = X
              Maka P dihapus dari list dan di-dealokasi
              Jika tidak ada elemen list dengan Info(P) = X,
              maka list tetap.
              List mungkin menjadi kosong karena penghapusan */
void DelLast(List *L, address P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelAfter(List *L, address Pdel, address Prec);
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus

/* Proses Semua Elemen List */
void PrintInfo(List L);
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
int NbElmt(List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* Prekondisi untuk Max/Min/rata-rata : List tidak kosong */
infotype Max(List L);
/* Mengirimkan nilai Info(P) yang maksimum */
address AdrMax(List L);
/* Mengirimkan address P, dengan Info(P) yang bernilai maksimum */
infotype Min(List L);
/* Mengirimkan nilai Info(P) yang minimum */
address AdrMin(List L);
/* Mengirimkan address P, dengan Info(P) yang bernilai minimum */
float Average(List L);
/* Mengirimkan nilai rata-rata Info(P) */

/* ----- Proses Terhadap List */
void DelAll(List *L);
void InversList(List *L);
List FInversList(List L);
void CopyList(List L1, List *L2);
List FCopyList(List L);
void CpAlokList(List Lin, List *Lout);
void Konkat(List L1, List L2, List *L3);
void Konkat1(List *L1, List *L2, List *L3);
void PecahList(List *L1, List *L2, List L);
void PrintAddress(List L);

#endif
