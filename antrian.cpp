#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "antrian.h"
#include "pembeli.h"

void create_kasir(Data_Kasir Kasir[])
{
	for(int i=1; i <= JUMLAH_KASIR; i++){
		Kasir[i].info = i; 
		Kasir[i].next = NULL;
	}
}

void tampil_antrian(Data_Kasir Kasir[], address P)
{	
	for(int i=1; i <= JUMLAH_KASIR; i++)
	{
		// Print Kasir
		printf("\t KASIR "); 
		printf("%d",i);
		printf(" |");
		
		// Print Pembeli
		P = Kasir[i].next;
		if (P != NULL)
		{
			while(Next(P) != NULL)
			{
				printf(" %s ", Info(P));
				printf(" --> ");
				P = Next(P);
			}
			printf(" %s ", Info(P));
			printf("\n\n");
		}else{
			printf("\n\n");
		}
	}
}

void insert_antrian(Data_Kasir Kasir[], List *L, address P, value nama_pembeli)
{
	bool antrian_penuh;
	int i = 0;
	int jumlah_antrian;
	
	// Tampilkan Antrian Sebelum
	tampil_antrian(Kasir,P);
	
	// Pilih Kasir
	printf("\t Pilih kasir: "); scanf("%d", &i); printf("\n");
	set_head_tail(Kasir, *(&L), i);
	
	// Proses Insertion
	if (i <= JUMLAH_KASIR and i > 0)
	{
		antrian_penuh = Is_AntrianFull(Kasir, *L);
		if (antrian_penuh != true)
		{
			Push(Kasir, *(&L), P, nama_pembeli, i);
			pembelian(Kasir, *(&L), P, i);
		}else{
			printf("\t Mohon Maaf Antrian Penuh!\n\n");
		}
	}else{
		printf("\t Kasir Tidak Ada!\n\n");
	}
}

void proses_antrian(Data_Kasir Kasir[], List *L, address P)
{
	int i = 0;
	
	// Tampilkan Antrian Sekarang
	tampil_antrian(Kasir,P);
	
	// Pilih Kasir
	printf("Pilih kasir: "); scanf("%d", &i); printf("\n");
	set_head_tail(Kasir, *(&L), i);
	
	// Proses Deletion
	if (i <= JUMLAH_KASIR and i > 0)
	{
		if (Head(*L) != NULL and Tail(*L) != NULL)
		{
			Pop(Kasir, *(&L), P, i);
		}else{
			printf("\t Customer Kosong!\n");
			printf("\t Tidak Memproses Antrian Apapun!\n\n");
		}
	}else{
		printf("\t Kasir Tidak Ada!\n\n");
	}
}

void set_head_tail(Data_Kasir Kasir[], List *L, int i)
{
	address P;
	P = Kasir[i].next;
	
	Head(*L) = P;
	Tail(*L) = P;
	
	while(P != NULL)
	{
		Tail(*L) = P;
		P = Next(P);
	}
}

int count_antrian(Data_Kasir Kasir[], List L)
{
	address P;
	int jumlah = 0;
	
	P = Head(L);
	while (P != NULL)
	{
		jumlah = jumlah + 1;
		P = Next(P);
	}
	return jumlah;
}

bool Is_AntrianFull(Data_Kasir Kasir[], List L)
{
	int jumlah_antrian = 0;
	
	jumlah_antrian = count_antrian(Kasir, L);
	
	if (jumlah_antrian < 5){
		return false;
	}else{
		return true;
	}
}

void Push(Data_Kasir Kasir[], List *L, address P, value nama, int i)
{	
	//Alokasi 
	P = Alokasi(nama);
	
	//Proses Insert Dari Belakang
	if (P != NULL)
	{
		if (Head(*L) == NULL and Tail(*L) == NULL)
		{
			Head(*L) = P;
			Tail(*L) = P;
		}else{
			Next(Tail(*L)) = P;
			Tail(*L) = P;
		}
		Kasir[i].next = Head(*L);
	}else{
		printf("\tInsertion Gagal Karena Memori Penuh!\n");
	}
}

void Pop(Data_Kasir Kasir[], List *L, address P, int i)
{	
	P = Head(*L);
	if (P != NULL)
	{
		if (Head(*L) == Tail(*L))
		{
			Head(*L) = NULL;
			Tail(*L) = NULL;
		}else{
			Head(*L) = Next(P);
		}
		Kasir[i].next = Head(*L);
		Dealokasi(&P);
	}
}

address Alokasi(value nama)
{
	address P;
	
	P = (address) malloc (sizeof(Data_Pembeli));
	if (P != NULL){
		Info(P) = nama;
		Next(P) = NULL;
		List_Beli(P) = NULL;
		return P;
	}else{
		return NULL;
	}
}

void Dealokasi(address *P)
{
	free(*P);
}


