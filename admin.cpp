#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "admin.h"

/* MENU ADMIN */
int admin(){
  // Deklarasi
  int pilihan;
  float potongan;

  //Menu
  while(1){
    pilihan = 0;
    
    system("color 0B");
    printf("===============================================================================================================\n");
    printf("===============|                   >>>>> SELAMAT DATANG ADMIN <<<<<                            |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Entry Data\n");
    printf("  2. Delete Data\n");
    printf("  3. Cek Data\n");
    printf("  4. Reset Data\n");
    printf("  5. Update Stok\n");
    printf("  6. Exit\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                            MENU SECTION                                       |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: ");
    scanf("%d", &pilihan);
    fflush(stdin);

    switch(pilihan)
    {
      case 1:
      {
        system("cls");
        entry_data();
        break;
      }
      case 2:
      {
        system("cls");
        delete_data();
        break;
      }
      case 3:
      {
        system("cls");
        cek_data();
        break;
      }
      case 4:
      {
        system("cls");
        reset_data();
        break;
      }
      case 5:
      {
        system("cls");
        stok_data();
        break;
      }
      case 6:
      {
        system("cls");
//       diskon_data();
		exit(0);
        break;
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


/* PROGRAM ENTRY DATA BARANG */
void entry_data(){
  // Deklarasi
  FILE *entry_file;
  list data;
  
  int pilihan;          // Pilihan Kategori Barang
  int jumlah_entry;     // Banyaknya Barang Yang Dimasukkan
  int nomor;            // Untuk Penyimpanan Sementara Nomor Yang Akan Dimasukkan Pada File
  char barang[100];     // Untuk Penyimpanan Sementara Barang Yang Akan Dimasukkan Pada File
  char barang_1[100];   // Untuk Pembanding Dengan Barang Pada File
  char barang_2[100];   // Untuk Pembanding Dengan Barang Pada Input
  char ulang;           // Untuk Pengulangan Memasukkan Data

  // Pemilihan Kategori
  while(1)
  {
    nomor = 0;
    jumlah_entry = 0;
    pilihan = 0;
    
    printf("===============================================================================================================\n");
    printf("===============|                     >>>>> PROGRAM ENTRY DATA <<<<<                            |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                  PILIH KATEGORI BARANG YANG INGIN DIMASUKKAN                  |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");

    while(1)
    {
      if (pilihan == 1){
        entry_file=fopen("list_makanan_ringan.dat", "ab+");
        system("cls");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> ENTRY MAKANAN RINGAN <<<<<                            |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 2){
        entry_file=fopen("list_minuman.dat", "ab+");
        system("cls");
        printf("===============================================================================================================\n");
        printf("===============|                      >>>>> ENTRY MINUMAN <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 3){
        entry_file=fopen("list_bumbu_masakan.dat", "ab+");
        system("cls");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> ENTRY BUMBU DAPUR <<<<<                             |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 4){
        entry_file=fopen("list_obat.dat", "ab+");
        system("cls");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> ENTRY OBAT-OBATAN <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 5){
        entry_file=fopen("list_alat.dat", "ab+");
        system("cls");
        printf("===============================================================================================================\n");
        printf("===============|               >>>>> ENTRY ALAT KEBERSIHAN & KESEHATAN <<<<<                   |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 6){
        system("cls");
        break;
      }

      // Jika Pilihan Kategori Barang Tidak Valid
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
        system("cls");
        ulang = 'Y';
        printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
        break;
      }

      // Cek Valid Tidaknya File
      if (entry_file == NULL){
        printf("File Tidak Dapat Dibuka!\n");
        break;
      }

      // Entry Barang Pada File
      while(1)
      {
        while(1)
        {
          ulang = 'T';

          /* Input Otomatis Nomor Barang */
          // Cek Nomor Terakhir File
          rewind(entry_file);
          while(fread(&data, sizeof(data), 1, entry_file)){
            nomor = data.nomor;
          }

          if (nomor < 1 or nomor == NULL){
            data.nomor = 1;
          }

          if (nomor == 1){
            data.nomor = 2;
          }

          if (nomor > 1){
            data.nomor = nomor + 1;
          }
          nomor = data.nomor;
          fflush(stdin);



          // Input Barang
          if (ulang = 'T')
          {
            printf("Nama Barang: ");
            gets(barang); fflush(stdin);

            // Mengcopy barang ke barang_1 sebagai temporary (temp) barang input
            strcpy(barang_1,barang);
            // Mengubah barang_2 menjadi uppercase untuk dibandingkan dengan barang pada file
            strupr(barang_1);

            // Mengecek Validasi Daftar Barang pada file
            rewind(entry_file);
            while(fread(&data, sizeof(data), 1, entry_file))
            {
              // Mengcopy data.barang ke barang_2 sebagai temporary (temp) barang pada file
              strcpy(barang_2, data.barang);
              // Mengubah barang_2 menjadi uppercase untuk dibandingkan dengan barang_1 hasil input
              strupr(barang_2);

              // Jika Barang Sudah Terdaftar Pada File
              if (strcmp(barang_1,barang_2) == 0){
                ulang = 'Y';
                printf("Barang Yang Kamu Masukkan Sudah Terdaftar!\n\n");
                break;

              // Jika Belum Terdaftar Maka Lanjut Tahap Berikutnya
              }else{
                ulang ='T';
              }
            }
          }



          // Input Harga
          if (ulang == 'T')
          {
            data.harga = -1; // Agar Ketika Memasukkan Karakter Terjadi Error
            printf("Harga: ");
            scanf("%f", &data.harga); fflush(stdin);
            // Jika Data Harga Yang Dimasukkan Invalid
            if (data.harga < 0){
              ulang = 'Y';
              printf("Harga Yang Kamu Masukkan Tidak Valid!\n\n");
            }
          }



          // Input Stok
          if (ulang == 'T')
          {
            data.stok = -1; // Agar Ketika Memasukkan Karakter Terjadi Error
            printf("Stok: ");
            scanf("%d", &data.stok); fflush(stdin);
            // Jika Stok Yang Dimasukkan Invalid
            if (data.stok <= 0){
              ulang = 'Y';
              printf("Stok Yang Kamu Masukkan Tidak Valid!\n\n");

            // Jika Stok Yang Dimasukkan Valid Dan Seluruh Proses Entry Data Pun Berhasil Dilakukan
            }else{
              printf("Data Barang Berhasil Dimasukkan!\n");
              
              // Menulis Ke Dalam File
              strcpy(data.barang, barang);
              data.nomor = nomor;
              fwrite(&data, sizeof(data), 1, entry_file);
              jumlah_entry++;
              break;
            }
          }
        }

        // Choice Untuk Mengulang Entry Data
        printf ("\nIngin Entry Data Lagi (Y/T)? ");
        ulang = toupper(getche());

        // Entry Data Kembali Jika Menjawab Y
        if (ulang == 'Y'){
          printf("\n\n");

        // Entry Data Selesai Jika Menjawab Selain Y
        }else{
          fclose(entry_file);
          system("cls");
          printf ("Sebanyak %d Data berhasil disimpan ke dalam file.\n\n", jumlah_entry);
          break;
        }
      }
      
      // Kembali Ke Kategori Barang
      if (ulang != 'Y'){
        break;
      }
    }
    
    // Kembali Ke Menu Utama Admin
    if (pilihan == 6){
      break;
    }
  }
}




/* PROGRAM CEK DATA BARANG */
void cek_data(){
  // Deklarasi
  FILE *cek_file;
  list data;
  char pilihan;
  char ulang;

  while(1){
    printf("===============================================================================================================\n");
    printf("===============|                     >>>>> PROGRAM CEK DATA <<<<<                              |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                  PILIH KATEGORI BARANG YANG INGIN DICEK                       |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");
    fflush(stdin);

    while(1){
      if (pilihan == 1){
        cek_file=fopen("list_makanan_ringan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> CEK MAKANAN RINGAN <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 2){
        cek_file=fopen("list_minuman.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                       >>>>> CEK MINUMAN <<<<<                                 |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 3){
        cek_file=fopen("list_bumbu_masakan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> CEK BUMBU DAPUR <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 4){
        cek_file=fopen("list_obat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> CEK OBAT-OBATAN <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 5){
        cek_file=fopen("list_alat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|             >>>>> CEK ALAT KEBERSIHAN & KESEHATAN <<<<<                       |===============\n");
        printf("===============================================================================================================\n\n");
      }
      
      // Keluar Loop Pilih
      if (pilihan == 6){
        system("cls");
        break;
      }
      
      // Jika Pilihan Tidak Valid
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
      system("cls");
      ulang = 'Y';
      printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
      break;
      }

      // Membaca File List Data Barang Untuk Mengecek Isinya
      while(fread(&data, sizeof(data), 1, cek_file))
      {
        printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", data.nomor, data.barang, data.harga, data.stok);
      }
      fclose(cek_file);

      printf ("\n\nIngin Cek Kategori Barang Lainnya (Y/T)? ");
      ulang = toupper(getche());
      
      // Kembali Ke Menu Cek Barang
      if (ulang == 'Y' or ulang != 'Y'){
        system("cls");
        break;
      }
    }
    
    // Kembali Ke Menu Utama Admin
    if (pilihan == 6 or ulang != 'Y'){
      break;
    }
  }
}





/* PROGRAM RESET DATA BARANG */
void reset_data(){
  // Deklarasi
  FILE *reset_file;
  int pilihan;
  int nomor;
  char ulang;
  list data;

  // Pemilihan Kategori
  while(1)
  {
    printf("===============================================================================================================\n");
    printf("===============|                     >>>>> PROGRAM RESET DATA <<<<<                            |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                  PILIH KATEGORI BARANG YANG INGIN DIRESET                     |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");

    while(1)
    {
      if (pilihan == 1){
        reset_file=fopen("list_makanan_ringan.dat", "wb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> RESET MAKANAN RINGAN <<<<<                            |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 2){
        reset_file=fopen("list_minuman.dat", "wb");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> RESET MINUMAN <<<<<                                  |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 3){
        reset_file=fopen("list_bumbu_masakan.dat", "wb");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> RESET BUMBU DAPUR <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 4){
        reset_file=fopen("list_obat.dat", "wb");
        printf("===============================================================================================================\n");
        printf("===============|                    >>>>> RESET OBAT-OBATAN <<<<<                               |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 5){
        reset_file=fopen("list_alat.dat", "wb");
        printf("===============================================================================================================\n");
        printf("===============|                >>>>> RESET ALAT KEBERSIHAN & KESEHATAN <<<<<                  |===============\n");
        printf("===============================================================================================================\n\n");
      }
      if (pilihan == 6){
        system("cls");
        break;
      }

      // Jika Pilihan Kategori Barang Tidak Valid
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
        system("cls");
        ulang = 'Y';
        printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
        break;
      }

      // Cek Valid Tidaknya File
      if (reset_file == NULL){
        printf("File Tidak Dapat Dibuka!\n");
        break;
      }

      // Informasi Reset Data
      printf("Reset Data Berhasil!");
      printf ("\nIngin Reset Data Lagi (Y/T)? ");
      ulang = toupper(getche());

      // Kembali Ke Menu Reset Data
      if (ulang == 'Y' or ulang != 'Y'){
        system("cls");
        break;
      }
      fclose(reset_file);
    }
    
    // Kembali Ke Menu Utama Admin
    if (ulang != 'Y' or pilihan == 6){
      break;
    }
  }
}



/* PROGRAM UPDATE STOCK BARANG*/
void stok_data(){
  // Deklarasi
  FILE *list_file;  // File Untuk Menyimpan List Stok Baru (Utama)
  list daftar;
  
  FILE *temp_file; // File Untuk Menyimpan List Stok Lama (Sementara)
  list temp;
  
  int pilihan;
  int pilihan_stok;
  int jumlah_stok;
  int nomor;
  char ulang;
  char status;

  // Pemilihan Kategori
  while(1)
  {
  	pilihan = 0;
    printf("===============================================================================================================\n");
    printf("===============|                  >>>>> PROGRAM UPDATE STOK DATA <<<<<                         |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                PILIH KATEGORI BARANG YANG INGIN DIUPDATE                      |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");

    while(1)
    {
      // Keadaan Awal;
      status = 'Y';
      nomor = 0;
      jumlah_stok = 0;
      pilihan_stok = 0;
      
      
    /* PILIHAN KATEGORI BARANG YANG DIUPDATE STOK */
      // PILIHAN MAKANAN RINGAN
      if (pilihan == 1){
        list_file=fopen("list_makanan_ringan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                  >>>>> UPDATE MAKANAN RINGAN <<<<<                            |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN MINUMAN
      if (pilihan == 2){
        list_file=fopen("list_minuman.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                     >>>>> UPDATE MINUMAN <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN BUMBU MASAKAN
      if (pilihan == 3){
        list_file=fopen("list_bumbu_masakan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> UPDATE BUMBU DAPUR <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN OBAT-OBATAN
      if (pilihan == 4){
        list_file=fopen("list_obat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> UPDATE OBAT-OBATAN <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN ALAT KEBERSIHAN & KESEHATAN
      if (pilihan == 5){
        list_file=fopen("list_alat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                >>>>> UPDATE ALAT KEBERSIHAN & KESEHATAN <<<<<                 |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }
      
      // KEMBALI KE MENU AWAL ADMIN
      if (pilihan == 6){
        ulang = 'T';
        system("cls");
        break;
      }

      // Jika Pilihan Kategori Barang Tidak Valid
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
        system("cls");
        ulang = 'Y';
        printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
        break;
      }

      // Cek Valid Tidaknya File
      if (list_file == NULL){
        printf("File Tidak Dapat Dibuka!\n\n");
        break;
      }

      /* PEMILIHAN JENIS BARANG YANG AKAN DIUPDATE STOK */
      printf("\n---------------------------------------------------------------------------------------------------------------\n");
      printf("\nSilahkan Pilih Jenis Barang Yang Ingin Diupdate Stoknya\n");
      while(1)
      {
        // Memasukkan Nomor Barang Yang Ingin Ditambahkan Stoknya
        printf("Nomor: "); scanf("%d", &nomor); fflush(stdin);
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        
        // Validasi Nomor Jenis Barang
        rewind(list_file);
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == nomor)
          {
            break;
          }
        }
        if (daftar.nomor != nomor or daftar.nomor == NULL)
        {
          // Kembali Ke List Kategori Barang
          ulang = 'Y';
          status = 'T';
          break;
        }
      
        //Memasukkan Jumlah Stok Yang Ingin Ditambahkan
        while(1)
        {
          printf("\nSilahkan Pilih Ingin Melakukan Penambahan Atau Pengurangan Stok\n");
          printf("1. Penambahan Stok\n");
          printf("2. Pengurangan Stok\n\n");
          printf("Pilihan Anda: "); scanf("%d", &pilihan_stok); fflush(stdin);

          if (pilihan_stok == 1)
          {
            printf("\nSilahkan Masukkan Jumlah Stok Yang Ingin Ditambahkan\n");
            printf("Jumlah Penambahan Stok: "); scanf("%d", &jumlah_stok); fflush(stdin);
            break;
          }
          
          if (pilihan_stok == 2)
          {
            printf("\nSilahkan Masukkan Jumlah Stok Yang Ingin Dikurangkan\n");
            printf("Jumlah Pengurangan Stok: "); scanf("%d", &jumlah_stok); fflush(stdin);
            break;
          }
          
          if (pilihan_stok != 1 and pilihan_stok != 2)
          {
            printf("\nPilih Sesuai Nomor Yang Tertera Pada Pilihan\n");
          }
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        
        // Mengecek Validasi Stok
        rewind(list_file);
        temp_file=fopen("list-temp.dat", "wb");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == nomor)
          {
            // Jika Jumlah Stok Invalid
            if (jumlah_stok <= 0)
            {
            printf("\nUpdate Stok Gagal Karena Jumlah Invalid\n");
            // Jika Jumlah Stok Valid Maka Terjadi Penambahan Stok
            }else{
              // Penambahan Stok
              if(pilihan_stok == 1)
              {
                daftar.stok = daftar.stok + jumlah_stok;
                printf ("\nStok %s Berhasil Ditambah Menjadi %d Buah!\n", daftar.barang, daftar.stok);
              }
              // Pengurangan Stok
              if(pilihan_stok == 2)
              {
                if (daftar.stok == 0)
                {
                  printf ("\nStok %s Tidak Terjadi Pengurangan Dan Tetap Sebesar %d Buah!\n", daftar.barang, daftar.stok);
                }else{
                  if(daftar.stok < jumlah_stok)
                  {
                    daftar.stok = 0;
                    printf ("\nStok %s Berhasil Dikurang Menjadi %d Buah Karena Melebihi Stok Yang Tersedia!\n", daftar.barang, daftar.stok);
                  }else{
                    daftar.stok = daftar.stok - jumlah_stok;
                    printf ("\nStok %s Berhasil Dikurang Menjadi %d Buah!\n", daftar.barang, daftar.stok);
                  }
                }
              }
            }
          }
          // Memasukkan List Yang Stoknya Sudah Ditambahkan Ke Dalam List Temp (Sementara)
          temp.nomor = daftar.nomor;
          strcpy(temp.barang, daftar.barang);
          temp.harga = daftar.harga;
          temp.stok = daftar.stok;
          fwrite(&temp, sizeof(temp), 1, temp_file);
        }
        fclose(temp_file);
        fclose(list_file);
        
        // Replace File Utama dengan LFile Temp yang sudah ditambahkan stok barangnya
        if (pilihan == 1){
          list_file=fopen("list_makanan_ringan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 2){
          list_file=fopen("list_minuman.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 3){
          list_file=fopen("list_bumbu_masakan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 4){
          list_file=fopen("list_obat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 5){
          list_file=fopen("list_alat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }
        fclose(list_file);
        fclose(temp_file);
      /* REPLACE LIST STOK PADA FILE UTAMA SELESAI */
      
        printf ("\nIngin Update Stok Barang Lainnya (Y/T)? ");
        ulang = toupper(getche());
        
        // Kembali Ke List Barang
        if (ulang == 'Y' or ulang != 'Y'){
          break;
        }
      }
      // Kembali Ke Kategori Barang
      if (ulang == 'Y' or ulang != 'Y'){
        system("cls");
        if (status == 'T')
        {
          printf("Nomor Barang Yang Kamu Masukkan Sebelumnya Tidak Valid!\n\n");
        }
        break;
      }
    }
    // Kembali Ke Menu Utama Admin
    if (ulang != 'Y'){
      break;
    }
  }
}



/* PROGRAM PENGECEKAN DAN PEMBERIAN DISKON */
void diskon_data(){
  FILE *diskon_file;
  float i, potongan;
  int pilihan;
  char ulang;
  char status;

  while(1)
  {
    status = 'T';
    potongan = 0;
    
    printf("===============================================================================================================\n");
    printf("===============|                     >>>>> PROGRAM DISKON MEMBER <<<<<                         |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Diskon Persentase\n");
    printf("  2. Diskon Potongan Rupiah\n");
    printf("  3. Cek Diskon Yang Berlaku\n");
    printf("  4. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                    PILIH JENIS DISKON YANG INGIN DIBERIKAN                    |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");
    
    while(1)
    {
      if (pilihan == 1)
      {
        diskon_file = fopen("diskon-file.dat", "wb");
        printf("Silahkan Isi Besaran Persentase Diskon Yang Ingin Diberikan\n");
        printf("Contoh: Diskon 30 Persen\n\n");
        while(1){
          printf("Diskon = "); scanf("%f", &potongan); fflush(stdin);
          if (potongan >= 100 or potongan <= 0)
          {
            printf("Diskon Invalid, Masukkan Persentase Diskon Dengan Benar!\n\n");
          }else{
            status = 'Y';
            break;
          }
        }
        potongan = potongan / 100;
        fwrite(&potongan, sizeof(potongan), 1, diskon_file);
        fclose(diskon_file);
      }

      if (pilihan == 2)
      {
        diskon_file = fopen("diskon-file.dat", "wb");
        printf("Silahkan Isi Besaran Diskon Dalam Rupiah Yang Ingin Diberikan!\n");
        printf("Contoh: Diskon -15000 Rupiah\n\n");
        while(1){
          printf("Diskon = -"); scanf("%f", &potongan); fflush(stdin);
          if (potongan <= 0)
          {
            printf("Diskon Invalid, Masukkan Besaran Diskon Dengan Benar!\n\n");
          }else{
            status = 'Y';
            break;
          }
        }
        fwrite(&potongan, sizeof(potongan), 1, diskon_file);
        fclose(diskon_file);
      }
      
      if (pilihan == 3){
        potongan = diskon(i, &potongan); // Menjadi Nilai Float Yang Direturnkan
        // Jika Yang Terdeteksi Diskon Persentase
        if (potongan < 1){
          printf("Diskon Yang Berlaku Saat Ini Sebesar: %.0f Persen\n", potongan * 100);
        // Jika Yang Terdeteksi Diskon Berdasarkan Rupiah
        }else{
          printf("Diskon Yang Berlaku Saat Ini Sebesar: -Rp%.2f\n", potongan);
        }
      }
      
      // Keluar Loop Pilihan
      if (pilihan == 4){
        system("cls");
        break;
      }

      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4)
      {
        system("cls");
        ulang = 'Y';
        printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
        break;
      }

      printf ("\nKembali Ke Menu Diskon (Y/T)? ");
      ulang = toupper(getche());
      
      // Kembali Ke Menu Diskon
      if (ulang == 'Y' or ulang != 'Y')
      {
        system("cls");
        if (status == 'Y'){
          printf("Diskon Untuk Member Berhasil Di Update!\n\n");
        }
        break;
      }
    }
    // Kembali Ke Menu Utama Admin
    if (ulang != 'Y' or pilihan == 4)
    {
      break;
    }
  }
}





/* PROGRAM DELETE BARANG*/
void delete_data(){
  // Deklarasi
  FILE *list_file;  // File Untuk Menyimpan List Stok Baru (Utama)
  list daftar;

  FILE *temp_file; // File Untuk Menyimpan List Stok Lama (Sementara)
  list temp;

  int pilihan;
  int nomor;
  char ulang;
  char status;

  // Pemilihan Kategori
  while(1)
  {
  	pilihan = 0;
  	
    printf("===============================================================================================================\n");
    printf("===============|                  >>>>> PROGRAM DELETE DATA <<<<<                              |===============\n");
    printf("===============================================================================================================\n\n");
    printf("  1. Makanan Ringan\n");
    printf("  2. Minuman\n");
    printf("  3. Bumbu Dapur\n");
    printf("  4. Obat-Obatan\n");
    printf("  5. Alat Kesehatan & Kebersihan\n");
    printf("  6. Selesai\n\n");
    printf("===============================================================================================================\n");
    printf("===============|                PILIH KATEGORI BARANG YANG INGIN DIDELETE                      |===============\n");
    printf("===============================================================================================================\n\n");
    printf("Pilihan Kamu: "); scanf("%d", &pilihan); fflush(stdin);
    printf("\n");

    while(1)
    {
      // Keadaan Awal;
      status = 'T';
      nomor = 0;

    /* PILIHAN KATEGORI BARANG YANG DIDELETE STOK */
      // PILIHAN MAKANAN RINGAN
      if (pilihan == 1){
        list_file=fopen("list_makanan_ringan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                  >>>>> DELETE MAKANAN RINGAN <<<<<                            |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN MINUMAN
      if (pilihan == 2){
        list_file=fopen("list_minuman.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                     >>>>> DELETE MINUMAN <<<<<                                |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN BUMBU MASAKAN
      if (pilihan == 3){
        list_file=fopen("list_bumbu_masakan.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> DELETE BUMBU DAPUR <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN OBAT-OBATAN
      if (pilihan == 4){
        list_file=fopen("list_obat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                   >>>>> DELETE OBAT-OBATAN <<<<<                              |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // PILIHAN ALAT KEBERSIHAN & KESEHATAN
      if (pilihan == 5){
        list_file=fopen("list_alat.dat", "rb");
        printf("===============================================================================================================\n");
        printf("===============|                >>>>> DELETE ALAT KEBERSIHAN & KESEHATAN <<<<<                 |===============\n");
        printf("===============================================================================================================\n\n");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          printf("Nomor: %-5d Barang: %-12s Harga: Rp%-15.2f Stok: %d\n", daftar.nomor, daftar.barang, daftar.harga, daftar.stok);
        }
      }

      // KEMBALI KE MENU AWAL ADMIN
      if (pilihan == 6){
        ulang = 'T';
        system("cls");
        break;
      }

      // Jika Pilihan Kategori Barang Tidak Valid
      if (pilihan != 1 and pilihan != 2 and pilihan != 3 and pilihan != 4 and pilihan != 5 and pilihan !=6){
        system("cls");
        ulang = 'Y';
        printf("Pilihan Kamu Tidak Valid, Pilihlah Nomor Yang Tertera Pada Menu!!!\n\n");
        break;
      }

      // Cek Valid Tidaknya File
      if (list_file == NULL){
        printf("File Tidak Dapat Dibuka!\n\n");
        break;
      }

      /* PEMILIHAN JENIS BARANG YANG AKAN DIDELETE */
      printf("\n---------------------------------------------------------------------------------------------------------------\n");
      printf("\nSilahkan Pilih Jenis Barang Yang Ingin Dihapus\n");
      while(1)
      {
        // Memasukkan Nomor Barang Yang Ingin Dihapus
        printf("Nomor: "); scanf("%d", &nomor); fflush(stdin);

        // Cek Validasi Nomor
        rewind(list_file);
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == nomor)
          {
            status = 'Y';
            break;
          }else{
            ulang = 'Y';
            status = 'T';
          }
        }
        // Jika File Kosong (Antisipasi Else Tidak Terbaca Oleh Sistem)
        if (status == 'T'){
          ulang = 'Y';
          break;
        }

        // Memasukkan List Barang Yang Tidak Dihapus Ke Dalam List Temp (Sementara)
        rewind(list_file);
        temp_file=fopen("list-temp.dat", "wb");
        while(fread(&daftar, sizeof(daftar), 1, list_file))
        {
          if (daftar.nomor == nomor)
          {
            printf("\nNama barang: %s telah dihapus dari list\n", daftar.barang);
          }
          
          if (daftar.nomor != nomor and daftar.nomor > nomor)
          {
            temp.nomor = daftar.nomor - 1;
            strcpy(temp.barang, daftar.barang);
            temp.harga = daftar.harga;
            temp.stok = daftar.stok;
            fwrite(&temp, sizeof(temp), 1, temp_file);
          }
          
          if (daftar.nomor != nomor and daftar.nomor < nomor)
          {
            temp.nomor = daftar.nomor;
            strcpy(temp.barang, daftar.barang);
            temp.harga = daftar.harga;
            temp.stok = daftar.stok;
            fwrite(&temp, sizeof(temp), 1, temp_file);
          }
        }
        printf("\n---------------------------------------------------------------------------------------------------------------\n");
        fclose(temp_file);
        fclose(list_file);

        // Replace File Utama dengan List File Temp yang sudah dihapus salah satu barangnya
        if (pilihan == 1){
          list_file=fopen("list_makanan_ringan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 2){
          list_file=fopen("list_minuman.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 3){
          list_file=fopen("list_bumbu_masakan.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 4){
          list_file=fopen("list_obat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }

        if (pilihan == 5){
          list_file=fopen("list_alat.dat", "wb");
          temp_file=fopen("list-temp.dat", "rb");
          while(fread(&temp, sizeof(temp), 1, temp_file))
          {
            daftar.nomor = temp.nomor;
            strcpy(daftar.barang, temp.barang);
            daftar.harga = temp.harga;
            daftar.stok = temp.stok;
            fwrite(&daftar, sizeof(daftar), 1, list_file);
          }
        }
        fclose(list_file);
        fclose(temp_file);
      /* REPLACE LIST STOK PADA FILE UTAMA SELESAI */

        printf ("\nIngin Hapus Barang Lainnya (Y/T)? ");
        ulang = toupper(getche());

        // Kembali Ke List Barang
        if (ulang == 'Y' or ulang != 'Y'){
          break;
        }
      }
      
      // Kembali Ke Kategori Barang
      if (ulang == 'Y' or ulang != 'Y'){
        system("cls");
        
        // Status Untuk Nomor Barang Invalid
        if (status == 'T')
        {
          printf("Nomor Barang Yang Kamu Masukkan Sebelumnya Tidak Valid!\n\n");
        }
        break;
      }
    }
    
    // Kembali Ke Menu Utama Admin
    if (ulang != 'Y'){
      break;
    }
  }
}


/* FUNGSI MEMBACA FILE DAN ME-RETURN NILAI BESARAN DISKON */
float diskon(float i, float *potongan){
  FILE *diskon_file;
  diskon_file=fopen("diskon-file.dat", "rb");
  
  fread(&i, sizeof(i), 1, diskon_file);
  *potongan = i;
  fclose(diskon_file);
  return *potongan;
}
