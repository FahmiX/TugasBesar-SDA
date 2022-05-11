#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "antrian.h"
#include "pembeli.h"
#include "admin.h"

int main() 
{
	// Kamus Data
	Data_Kasir Kasir[JUMLAH_KASIR];
	address P;
	List L;
	value nama_pembeli;
	char nama[MAX_NAMA];
	int pilihan;
	
	create_kasir(Kasir);
	while(1)
	{
		memset(nama, 0, sizeof(nama));
		pilihan = 0;
		
		printf("\n");
		printf("\t 1. Insert Antrian\n");
		printf("\t 2. Proses Antrian\n");            
		printf("\t 3. Tampil Antrian\n"); 
		printf("\t 4. Admin\n");  
		printf("\t 5. Exit\n\n");  
		printf("\t Pilihan Kamu: ");
		scanf("%d", &pilihan);
		printf("\n");
		fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
			{
				printf("\t Masukkan Nama Pembeli: ");
				scanf("%25s", nama);
				nama_pembeli = (value) malloc(strlen(nama) + 1);
				strcpy(nama_pembeli,nama);
				printf("\n"); 
				fflush(stdin);
				insert_antrian(Kasir, &L, P, nama_pembeli);
				system("pause");
				system("cls");
				break;
			}
			
			case 2:
			{
				proses_antrian(Kasir, &L, P);
				system("pause");
				system("cls");
				break;
			}
			
			case 3:
			{
				tampil_antrian(Kasir, P);
				system("pause");
				system("cls");
				break;
			}
			
			case 4:
			{
				system("cls");
				admin();
				return 0;
			}
			
			case 5:
			{
				return 0;
			}
			
			default:
			{
				system("cls");
				printf("Pilihan Menu Tidak Tersedia!\n\n");
				break;
			}
		}
	}
}


