#ifndef antrian_h
#define antrian_h

#include <stdio.h>
#include <stdlib.h>

#define JUMLAH_KASIR 3
#define MAX_NAMA 25

#define Info(P) P->info
#define Next(P) P->next
#define List_Beli(P) (P)->list_beli
#define Jumlah_Beli(P) (P)->jumlah_beli
#define Harga(P) (P)->harga
#define Head(L) (L).head
#define Tail(L) (L).tail

typedef char* value;
typedef struct element_1 *address;

// PEMBELI
typedef struct element_1{
	value info;
	address list_beli;
	address next;
}Data_Pembeli;

// KASIR
typedef struct element_2{
	int info;
	address next;
}Data_Kasir;

typedef struct element_4{
	value info;
	int jumlah_beli;
	int harga;
	address next;
}Data_Barang;

// HEAD & TAIL
typedef struct element_3{
	address head;
	address tail;
}List;

/* QUEUE UNTUK ANTRIAN */

address Alokasi(value nama);
// IS : P terdefinisi
// FS : Jika alokasi berhasil, maka:
//      - Info(P) berisi nama
//      - Next(P) berisi NULL
//      - List_Beli(P) berisi list barang yang dibeli oleh customer
//      Jika alokasi gagal, maka P berisi NULL

void Dealokasi(address *P);
// IS : P terdefinisi
// FS : P didealokasi dan dihapus dari memori

void Push(Data_Kasir Kasir[], List *L, address P, value nama, int i);
// IS : P mungkin kosong 
// FS : P dialokasi kemudian diinsert menjadi node paling belakang (Tail)
//      Jika P gagal dialokasi dan diinsert, maka FS = IS

void Pop(Data_Kasir Kasir[], List *L, address P, int i);
// IS : P mungkin kosong 
// FS : P menunjuk data paling depan kemudian dihapus dan didealokasi, 
//      data berikutnya kemudian menjadi data paling depan (Head)
//      Jika P gagal dihapus, maka FS = IS

void create_kasir(Data_Kasir Kasir[]);
// IS : Tidak Terdapat Satupun Kasir
// FS : Terbentuk Kasir Sebanyak JUMLAH_KASIR

void insert_antrian(Data_Kasir Kasir[], List *L, address P, value nama_pembeli);
// IS : Suatu kasir dalam keadaan kosong atau terdapat suatu customer
// FS : Terdapat penambahan customer pada suatu kasir di antrian paling akhir

void tampil_antrian(Data_Kasir Kasir[], address P);
// IS : Setiap kasir dalam keadaan kosong atau terdapat customer
// FS : Menampilkan data seluruh kasir beserta antrian customernya

void proses_antrian(Data_Kasir Kasir[], List *L, address P);
// IS : Setiap kasir dalam keadaan terdapat customer
// FS : Customer yang sudah diproses akan dihapus dari antrian dan akan digantikan posisinya oleh customer berikutnya

void set_head_tail(Data_Kasir Kasir[], List *L, int i);
// IS : Head dan Tail menunjuk NULL atau menunjuk suatu alamat
// FS : Head menunjuk customer paling awal dan Tail menunjuk customer paling akhir pada antrian di suatu kasir

int count_antrian(Data_Kasir Kasir[], List L);
// IS : terdapat sejumlah antrian customer atau kosong pada suatu kasir
// FS : terhitung antrian sebanyak-n pada suatu kasir kemudian nilainya dikembalikkan

bool Is_AntrianFull(Data_Kasir Kasir[], List L);
// IS : terdapat sebanyak-n customer pada suatu kasir
// FS : mengembalikkan nilai false jika banyaknya customer kurang dari JUMLAH_KASIR
//      mengembalikkan nilai true jika banyaknya customer lebih dari atau sama dengan JUMLAH_KASIR

#endif