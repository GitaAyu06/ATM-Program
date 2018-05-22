#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<ctype.h>

void loading();             //modular untuk menunjukkan program sedang memproses
void verifikasi();          //modular untuk memverifikasi pin yang dimasukkan
void menu();                //modular untuk menampilkan pilihan menu
void keluar();              //menu untuk keluar dari program
void informasi_saldo();     //menu untuk menampilkan informasi saldo
void transfer();            //menu untuk melakukan transfer
void bayar();               //menu untuk melakukan pembayaran tertentu
void bantuan();             //menu untuk menampilkan informasi bantuan
void tarik_tunai();         //menu untuk melakukan tarik tunai

int awal=7500000;           //saldo awal dideklarasikan

char pass[10]="112233";     //inisialisasi variabel untuk verifikasi pin
char pin[10]={0};
char ch, c;
          
struct identitas{
                char nama[20];
                long int  norek;
                char nama_bank[20];
         };
int main ()
{
    system("color 9e");    //membuat background program berwarna biru dan font berwarna kuning
    printf("\n\n========================================================================================================================");
    printf("\n\n================================SELAMAT DATANG DI PROGRAM ATM SEDERHANA BANK ABC========================================");
    printf("\n=============================OLEH: GITA AYU SALSABILA & ANANDA RIZKY DUTO PAMUNGKAS=====================================");
    printf("\n\n========================================================================================================================");
    verifikasi();
    menu();
}

void loading()             
	{
		int i;
		printf("\nLOADING ");
         for (i=1;i<6;i++)  //menampilkan titik-titik dengan delay
		  {
			printf(". ");
			sleep(200);
		  }
		system("cls");    //mengganti layar
	}

void verifikasi()
{      
    printf("\n\n\n\n\t\t\t\t\t\tSILAHKAN MASUKKAN KARTU ATM\n");
    sleep (1000);          //memberikan delay pada program
    ch=fgetc(stdin);  
 
    if (ch==10)                           //saat ditekan enter, program akan lanjut bekerja
    {
       loading ();
       printf ("\n\n\t\t\t\t\t\tMASUKKAN 6 DIGIT PIN ATM\n\t\t\t\t\t\t\t");
       
       int i=0;
         do
         {
           c = getch();
           if( isprint(c))                  //membuat karakter yang dimasukkan menjadi bintang
           {
               pin[i++] = c;
               printf("%c", '*');
           }
           else if(c==6 && pass)
           {
               pin[i--] = '\0';
               printf("%s", "\b \b");
           }
         }             
         while(c!=13);
    }
    else
    {
       printf ("\n\n\n\n\t\t\t\t\t\tSILAHKAN MASUKKAN KARTU ATM\n");     //jika tombol yang ditekan bukan enter maka pengguna akan diperingatkan
       ch=fgetc(stdin);
    }   
    
    if (strcmp(pin,"112233")==0)              //memverifikasi pin yang dimasukkan
    {
       menu ();                               //jika pin terverifikasi akan muncul menu             
    }
    else
    {
       printf("\nPIN YANG DIMASUKKAN SALAH\nSILAHKAN COBA LAGI\n");       //pesan eror bahwa pin yang dimasukkan salah
       loading();
       printf("\n\n\t\t\t\t\t\tMASUKKAN 6 DIGIT PIN ATM\n\t\t\t\t\t\t\t");      //mengulang input pin hingga pin benar
       
       int i=0;
         do
         {
           c = getch();
           if( isprint(c))                  //membuat karakter yang dimasukkan menjadi bintang
           {
               pin[i++] = c;
               printf("%c", '*');
           }
           else if(c==6 && pass)
           {
               pin[i--] = '\0';
               printf("%s", "\b \b");
           }
         }             
         while(c!=13);
    }
printf ("\n");
loading ();
}    

void menu ()
{    
     system("cls");
     char m;
     printf("\n\n\t\t\t\t\t\t\t===MENU UTAMA===\n");
     printf("\n\n\n\t\t[1] INFORMASI SALDO\n\t\t[2] TARIK TUNAI\n\t\t[3] TRANSFER\n\t\t[4] BAYAR/BELI\n\t\t[5] BANTUAN DAN INFORMASI\n\t\t[6] KELUAR\n");
     printf("PILIH NOMOR: ");         //memilih menu
     scanf ("%c", &m);
      
switch (m)
       {
       case '1':
            loading();
            informasi_saldo();
       case '2':
            loading();
            tarik_tunai();
       case '3':
            loading();
            transfer();
       case '4':
            loading();
            bayar();
       case '5':
            loading();
            bantuan();
       case '6':
            loading();
            keluar();
       default:       
            printf("\n\t\t\t\t\t\tMAAF, HARAP PILIH MENU BERDASARKAN ANGKA YANG TERTERA");
            sleep (100); //pesan eror jika input yang dimasukkan tidak sesuai dengan pilihan apapun
            menu();      //kembali untuk memilih menu
       }
}

void informasi_saldo ()
{ 
     system("cls");
     int a;
     printf("\n\n\t\t\t\t\t\t===INFORMASI SALDO===\n\n\n");
     printf("\n\n\t\t\t\t\tSALDO ANDA SAAT INI= RP %d,00\n", awal); //menampilkan saldo saat ini
     printf("\n\t\t\t\t\t INGIN MELAKUKAN TRANSAKSI LAIN?\n\n\t\t\t\t\t\t [1]YA\t[2]TIDAK\n");
     printf("\t\t\t\t\tPILIH NOMOR: ");
     scanf ("%d", &a);
        if (a==1)     
          {  
            menu();        //kembali ke menu   
          }
        else if (a==2)
          {  
            keluar();     //membatalkan transaksi
          }
        else
          {
             system("cls");
             printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t     HARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
             printf("\n\t\t\t\t\t\tINGIN MELAKUKAN TRANSAKSI LAIN?\n\n\t\t\t\t\t\t\t [1]YA\t[2]TIDAK\n");
             printf("\t\t\t\t\t\t PILIH NOMOR: ");
             scanf ("%d", &a);
          }               
     system ("pause");
} 

void tarik_tunai()
{
	   int a, b, i;
	   long int uang_ditarik, saldo;
	   system("cls");
	   printf("\n\n\t\t\t\t\t\t===TARIK TUNAI===\n\n\n");
       printf("\n\n\t\t\t\t\t\tMASUKKAN NOMINAL\n");
	   printf("\n\t\t\t\t\t\tRP ");     //memasukkan jumlah uang yang akan ditarik
	   scanf("%d", &uang_ditarik);
	   loading();
	
       if (uang_ditarik>awal)         //jika uang yang ditarik melebihi saldo awal
       {
       system("cls");
       printf("\n\n\t\t\t\tSALDO ANDA TIDAK CUKUP UNTUK MELAKUKAN TRANSAKSI INI\n\n\n");
       printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
       printf("\n\t\t\t\t\tPILIH NOMOR= ");
       scanf ("%d", &b);
           if (b==1)             //membatalkan transaksi dan keluar dari program
           {
              keluar();
           }
           else if (b==2)        //memasukkan ulang jumlah yang akan ditarik
           {
              system("cls");
              printf("\n\n\t\t\t\t\t\t===TARIK TUNAI===\n\n\n");
              printf("\n\n\t\t\t\t\t\tMASUKKAN NOMINAL\n");
	          printf("\n\t\t\t\t\t\tRP ");     //memasukkan jumlah uang yang akan ditarik
	          scanf("%d", &uang_ditarik);
           }
              else
           {
              system("cls");             //pesan eror jika input yg dimasukkan tidak cocok dengan pilihan yang ada
              printf("\n\n\t\t\t\tMAAF, HARAP MASUKKAN PILIHAN BERDASARKAN ANGKA YANG TERTERA\n\n\n");
              printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
              printf("\n\t\t\t\t\tPILIH NOMOR= ");
              scanf("%d", &b);
           }
       }
       printf("\n\n\n\t\t\t\t\tSILAHKAN AMBIL UANG ANDA");
       
       for (i=1;i<6;i++)
	    {
		   printf(". ");
		   sleep(100);
        }
       system("cls");
       saldo=awal-uang_ditarik;         //jumlah saldo adalah saldo awal dikurangi jumlah uang yang ditarik
       printf("\n\n\t\t\t\t\tSALDO ANDA SAAT INI= RP %d,00\n", saldo);
       printf("\t\t\t\t\tINGIN MELAKUKAN TRANSAKSI LAIN?\n\n\t\t\t\t\t\t [1]YA\t[2]TIDAK\n"); //pilihan untuk melakukan transaksi lain atau tidak
       printf("\t\t\t\t\t\t PILIH NOMOR= ");
       scanf("%d", &a);
    if (a==1)
    {
       loading();
   	   menu();
    }
	else if (a==2)
    {
       keluar();
    }
	else
    {
   	    printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\tHARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
    }
}

void transfer ()
{
    system("cls");
    int tf, tuj, akhir, pil1, pil2, b;
    long int norek;                //untuk identitas penerima transfer
    char nama[20];
    char nama_bank[20];               
    printf("\n\n\t\t\t\t\t\t===TRANSFER DANA===\n\n\n\n");
    printf("\n\n\t\t\t\tMASUKKAN 9 DIGIT NOMOR REKENING PENERIMA= ");     //memasukkan nomor rekening tujuan
    scanf ("%d", &norek);
    printf ("\n\t\t\t\tMASUKKAN JUMLAH UANG YANG AKAN DITRANSFER= ");     //memasukkan jumlah uang yang akan ditransfer
    scanf ("%d", &tf);
    akhir=awal-tf;                  //jumlah saldo adalah saldo awal dikurangi jumlah uang yang ditransfer
    system("cls"); 
    while ((norek!=123456789)&&(norek!=987654321))
    {
       printf("\n\n\t\t\t\tNOMOR REKENING YANG DIMASUKKAN TIDAK VALID\n");
       printf("\n\n\t\t\t\tMASUKKAN 9 DIGIT NOMOR REKENING PENERIMA= ");     //memasukkan nomor rekening tujuan
       scanf ("%d", &norek);
       printf("\n\t\t\t\tMASUKKAN JUMLAH UANG YANG AKAN DITRANSFER= ");     //memasukkan jumlah uang yang akan ditransfer
       scanf ("%d", &tf);
       akhir=awal-tf;                  //jumlah saldo adalah saldo awal dikurangi jumlah uang yang ditransfer
       system("cls"); 
    }
    
    if (tf>awal)         //jika uang yang ditransfer melebihi saldo awal
    {
       system("cls");
       printf("\n\n\t\t\t\tSALDO ANDA TIDAK CUKUP UNTUK MELAKUKAN TRANSAKSI INI\n\n\n");
       printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
       printf("\n\t\t\t\t\tPILIH NOMOR= ");
       scanf("%d", &b);
           if (b==1)             //membatalkan transaksi dan keluar dari program
           {
              keluar();
           }
           else if (b==2)        //memasukkan ulang jumlah yang akan ditransfer
           {
              system("cls");
              printf("\n\n\t\t\t\t\t\t===TRANSFER===\n\n\n");
              printf("\n\t\t\t\tMASUKKAN JUMLAH UANG YANG AKAN DITRANSFER= ");     //memasukkan jumlah uang yang akan ditransfer
              scanf ("%d", &tf);
              system("cls");
           }
              else
           {
              system("cls");             //pesan eror jika input yg dimasukkan tidak cocok dengan pilihan yang ada
              printf("\n\n\t\t\t\tMAAF, HARAP MASUKKAN PILIHAN BERDASARKAN ANGKA YANG TERTERA\n\n\n");
              printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
              printf("\n\t\t\t\t\tPILIH NOMOR= ");
              scanf("%d", &b);
           }
    }
       
    if (norek==123456789)          //menyesuaikan nomor rekening tujuan dengan identitas penerima
    {
       struct identitas* budi = NULL;
       budi=(struct identitas*) malloc(sizeof(struct identitas));
       strcpy(budi->nama, "BUDI");
       budi->norek=123456789;
       strcpy(budi->nama_bank, "BANK A");
       
       printf("\t\t\t\t\tIDENTITAS PENERIMA\n");
       printf("\t\t\t\t\t\tATAS NAMA= ");
       printf("%s\n", budi->nama);
       printf("\t\t\t\t\t\tNOMOR REKENING= ");
       printf("%d\n", budi->norek);
       printf("\t\t\t\t\t\tBANK= ");
       printf("%s\n", budi->nama_bank);
    }
    else if (norek==987654321)
    {
        struct identitas* adi = NULL;
        adi=(struct identitas*) malloc(sizeof(struct identitas));
        strcpy(adi->nama, "ADI");
        adi->norek=987654321;
        strcpy(adi->nama_bank, "BANK B");
        
        printf("\t\t\t\t\tIDENTITAS PENERIMA\n");
        printf("\t\t\t\t\t\tATAS NAMA= ");
        printf("%s\n", adi->nama);
        printf("\t\t\t\t\t\tNOMOR REKENING= ");
        printf("%d\n", adi->norek);
        printf("\t\t\t\t\t\tBANK= ");
        printf("%s\n", adi->nama_bank);
    }
    
    
    printf("\t\t\t\t\t\tNOMINAL TRANSFER= %d", tf);
    printf("\n\nDATA BENAR?");                       //memvalidasi apakah data benar atau tidak
    printf("\n\t\t\t\t[1] YA\t\t[2] TIDAK");
    printf("\nPILIH NOMOR: ");
    scanf ("%d", &pil1);
                 
    while ((pil1!=1)&&(pil1!=2))
    {
       system("cls");
       printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
       printf("\n\nDATA BENAR?");
       printf("\n\t\t\t\t[1] YA\t\t[2] TIDAK");
       printf("\nPILIH NOMOR: ");
       scanf ("%d", &pil1);
    }                 
    if (pil1==1)
    {
       system("cls");
       printf("\n\n\t\t\t\t\t\tTRANSAKSI BERHASIL\n\n");              //transfer dilakukan
       printf("\n\n\t\t\t\t\t\tSISA SALDO=%d\n", akhir);
       printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
       printf("\n\t\t\t\tPILIH NOMOR: ");
       scanf ("%d", &pil2);
                         
             while ((pil2!=1)&&(pil2!=2))
             {
                   system("cls");
                   printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                   printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                   printf("\n\t\t\t\tPILIH NOMOR: ");
                   scanf ("%d", &pil1);
             }
             if (pil2==1)
             {
                   loading();
                   menu();                          
             }
             else if (pil2==2)
             {
                   printf ("TRANSAKSI SELESAI, SILAHKAN AMBIL KARTU ANDA");
             }
    }         
    else if (pil1==2)
    {
       system("cls");
       printf("\n\n\tTRANSAKSI DIBATALKAN\n");
       printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
       printf("\n\t\t\t\tPILIH NOMOR: ");
       scanf ("%d", &pil2);
                         
             while ((pil2!=1)&&(pil2!=2))
             {
                   system("cls");
                   printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                   printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                   printf("\n\t\t\t\tPILIH NOMOR: ");
                   scanf ("%d", &pil1);
             }
             if (pil2==1)
             {
                   loading();
                   menu();                          
             }
             else if (pil2==2)
             {
                   printf ("TRANSAKSI SELESAI, SILAHKAN AMBIL KARTU ANDA");
             }
    }
}

void bayar()
{
     system("cls");
     int y;
     int tagihan, akhir, pil, pil2;
     printf("\n\n\t\t\t\t\t\t===PEMBAYARAN===\n\n\n[1] LISTRIK/PLN\n[2] PDAM\n[3] PAJAK\n[4] PULSA\n[5] KEMBALI\n[6] KELUAR");
     printf("\nPILIH NOMOR: "); //memilih pembayaran yang akan dilakukan
     scanf ("%d", &y);
     
switch (y)
       {
       case 1:                                 //bayar listrik
            system("cls");
            long int no_listrik;
            printf("\n\n\n\n\t\t\t\t\t MASUKKAN 10 DIGIT NOMOR REKENING LISTRIK\n\t\t\t\t\t\t\t");
            scanf ("%d", &no_listrik);          //memeriksa nomor rekening listrik yang dimasukkan
            while (no_listrik!=1111111111) 
            {
               system("cls");
               printf("\n\t\t\t\t\t    REKENING LISTRIK TIDAK TERDAFTAR");
               printf("\n\n\n\n\t\t\t\t\t MASUKKAN 10 DIGIT NOMOR REKENING LISTRIK\n\t\t\t\t\t\t\t");
               scanf ("%d", &no_listrik);
            }
              
            if (no_listrik==1111111111)
            {
               system("cls");
               tagihan=300000;                  //inisialisasi jumlah tagihan listrik 
               printf("\n\n\n\t\t\t\t\tTAGIHAN ANDA PADA PERIODE INI SEBESAR\n\t\t\t\t\t\t\tRp%d,00", tagihan);
               printf("\n\n\t\t\t\t\t\t   LAKUKAN PAMBAYARAN?\n\n\t\t\t\t\t\t   [1]YA\t[2]TIDAK\n\n\t\t\t\t\t\t   PILIH NOMOR: ");
               scanf ("%d", &pil);
               akhir=awal-tagihan;            //jumlah saldo adalah saldo awal dikurangi jumlah tagihan
                  if (pil==1)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\t  TRANSAKSI BERHASIL\n");         //notifikasi transaksi telah dilakukan
                     printf("\n\n\n\t\t\t\t\t\t  SISA SALDO=%d\n", akhir);     //menampilkan sisa saldo
                     printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\nPILIH NOMOR: ");
                     scanf ("%d", &pil2);
                         if (pil2==1)
                         {
                            loading();        //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();        //keluar dari program
                         }
                         else
                         {
                             system("cls");  //notifikasi kesalahan input
                             printf("\n\n\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                             printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                             printf("\n\t\t\t\t\t\t PILIH NOMOR: ");
                             scanf ("%d", &pil);
                         }
                  }
                  else if (pil==2)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\tTRANSAKSI DIBATALKAN\n");
                     printf("\n\n\t\t\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                     scanf ("%d", &pil2);    
                         if (pil2==1)
                         {
                            loading();         //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();          //keluar dari program
                         }
                         else
                         {
                            system("cls");
                            printf("\n\n\t\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                            printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                            printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                            scanf ("%d", &pil2);
                         }
                  }
            } 
       case 2:                              //bayar PDAM
            system("cls");
            long int no_pdam;
            printf("\n\n\n\n\t\t\t\t\t MASUKKAN 10 DIGIT NOMOR PELANGGAN PDAM\n\t\t\t\t\t\t\t");
            scanf ("%d", &no_pdam);          //memeriksa nomor pelanggan PDAM yang dimasukkan
            while (no_pdam!=2222222222) 
            {
               system("cls");
               printf("\n\t\t\t\t\t    NOMOR PELANGGAN TIDAK TERDAFTAR");
               printf("\n\n\n\n\t\t\t\t\t MASUKKAN 10 DIGIT NOMOR REKENING LISTRIK\n\t\t\t\t\t\t\t");
               scanf ("%d", &no_pdam);
            }
               
            if (no_pdam==2222222222)
            {
               system("cls");
               tagihan=200000;                  //inisialisasi jumlah tagihan PDAM 
               printf("\n\n\n\t\t\t\t\tTAGIHAN ANDA PADA PERIODE INI SEBESAR\n\t\t\t\t\t\t\tRp%d,00", tagihan);
               printf("\n\n\t\t\t\t\t\t   LAKUKAN PAMBAYARAN?\n\n\t\t\t\t\t\t   [1]YA\t[2]TIDAK\n\n\t\t\t\t\t\t   PILIH NOMOR: ");
               scanf ("%d", &pil);
               akhir=awal-tagihan;            //jumlah saldo adalah saldo awal dikurangi jumlah tagihan
                  if (pil==1)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\t  TRANSAKSI BERHASIL\n");         //notifikasi transaksi telah dilakukan
                     printf("\n\n\n\t\t\t\t\t\t  SISA SALDO=%d\n", akhir);     //menampilkan sisa saldo
                     printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\nPILIH NOMOR: ");
                     scanf ("%d", &pil2);
                         if (pil2==1)
                         {
                            loading();        //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();        //keluar dari program
                         }
                         else
                         {
                             system("cls");  //notifikasi kesalahan input
                             printf("\n\n\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                             printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                             printf("\n\t\t\t\t\t\t PILIH NOMOR: ");
                             scanf ("%d", &pil);
                         }
                  }
                  else if (pil==2)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\tTRANSAKSI DIBATALKAN\n");
                     printf("\n\n\t\t\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                     scanf ("%d", &pil2);    
                         if (pil2==1)
                         {
                            loading();         //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();          //keluar dari program
                         }
                         else
                         {
                            system("cls");
                            printf("\n\n\t\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                            printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                            printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                            scanf ("%d", &pil2);
                         }
                  }
            } 
       case 3:                           //bayar pajak
            system("cls");
            long int npwp;
            printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN 10 DIGIT NPWP\n\t\t\t\t\t\t");
            scanf ("%d", &npwp);          //memeriksa NPWP yang dimasukkan
            while (npwp!=3333333333) 
            {
               system("cls");
               printf("\n\t\t\t\t\t\t    NPWP TIDAK TERDAFTAR");
               printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN 10 DIGIT NPWP\n\t\t\t\t\t\t");
               scanf ("%d", &npwp); 
            }
               
            if (npwp==3333333333)
            {
               system("cls");
               tagihan=150000;                  //inisialisasi jumlah tagihan pajak 
               printf("\n\n\n\t\t\t\t\tTAGIHAN ANDA PADA PERIODE INI SEBESAR\n\t\t\t\t\t\t\tRp%d,00", tagihan);
               printf("\n\n\t\t\t\t\t\t   LAKUKAN PAMBAYARAN?\n\n\t\t\t\t\t\t   [1]YA\t[2]TIDAK\n\n\t\t\t\t\t\t   PILIH NOMOR: ");
               scanf ("%d", &pil);
               akhir=awal-tagihan;            //jumlah saldo adalah saldo awal dikurangi jumlah tagihan
                  if (pil==1)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\t  TRANSAKSI BERHASIL\n");         //notifikasi transaksi telah dilakukan
                     printf("\n\n\n\t\t\t\t\t\t  SISA SALDO=%d\n", akhir);     //menampilkan sisa saldo
                     printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\nPILIH NOMOR: ");
                     scanf ("%d", &pil2);
                         if (pil2==1)
                         {
                            loading();        //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();        //keluar dari program
                         }
                         else
                         {
                             system("cls");  //notifikasi kesalahan input
                             printf("\n\n\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                             printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                             printf("\n\t\t\t\t\t\t PILIH NOMOR: ");
                             scanf ("%d", &pil);
                         }
                  }
                  else if (pil==2)
                  {
                     system("cls");
                     printf("\n\n\t\t\t\t\t\tTRANSAKSI DIBATALKAN\n");
                     printf("\n\n\t\t\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t\t\t  [1]YA\t[2]TIDAK");
                     printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                     scanf ("%d", &pil2);    
                         if (pil2==1)
                         {
                            loading();         //kembali ke menu
                            menu();                          
                         }
                         else if (pil2==2)
                         {
                            keluar();          //keluar dari program
                         }
                         else
                         {
                            system("cls");
                            printf("\n\n\t\t\t\t\t\tPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                            printf("\n\n\t\t\t\t\t\t KEMBALI KE MENU AWAL?\n\t\t\t\t\t\t [1]YA\t[2]TIDAK");
                            printf("\n\t\t\t\t\t\tPILIH NOMOR: ");
                            scanf ("%d", &pil2);
                         }
                  }
            }
       case 4:                          //beli pulsa
            system("cls");
            int no_hp;
            int pulsa, pil1, pil2, b;
            printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN NOMOR TELEPON= (+62)");
            scanf ("%d", &no_hp);          //memeriksa nomor telepon yang dimasukkan
            printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN JUMLAH PULSA= RP ");   
            scanf ("%d", &pulsa);          //memeriksa jumlah pulsa yang akan dibeli
            if (pulsa>awal)         //jika uang yang dibayarkan melebihi saldo awal
            {
                system("cls");
                printf("\n\n\t\t\t\tSALDO ANDA TIDAK CUKUP UNTUK MELAKUKAN TRANSAKSI INI\n\n\n");
                printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
                printf("\n\t\t\t\t\tPILIH NOMOR= ");
                scanf("%d", &b);
                            if (b==1)             //membatalkan transaksi dan keluar dari program
                            {
                               keluar();
                            }
                            else if (b==2)        //memasukkan ulang jumlah yang akan ditarik
                            {
                               system("cls");
                               printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN NOMOR TELEPON= (+62)");
                               scanf ("%d", &no_hp);          
                               printf("\n\n\n\n\t\t\t\t\t\tMASUKKAN JUMLAH PULSA= RP ");   
                               scanf ("%d", &pulsa);   
                            }
                            else
                            {
                               system("cls");             //pesan eror jika input yg dimasukkan tidak cocok dengan pilihan yang ada
                               printf("\n\n\t\t\t\tMAAF, HARAP MASUKKAN PILIHAN BERDASARKAN ANGKA YANG TERTERA\n\n\n");
                               printf("\n\n\t\t\t\t\t\tBATALKAN TRANSAKSI?\n\n\n\t\t\t\t\t[1]YA     [2]MASUKKAN JUMLAH LAIN\n");
                               printf("\n\t\t\t\t\tPILIH NOMOR: ");
                               scanf("%d", &b);
                            }
           }
           else 
           {
                system("cls");
                printf("\t\t\t\t\t\tKONFIRMASI PEMBELIAN\n\n");
                printf("\n\t\t\t\t\t\tNOMOR TELEPON= (+62)%d", no_hp);
                printf("\n\t\t\t\t\t\tJUMLAH PULSA= %d\n\n", pulsa);
                printf("\n\nDATA BENAR?");                       //memvalidasi apakah data benar atau tidak
                printf("\n\t\t\t\t[1] YA\t\t[2] TIDAK");
                printf("\nPILIH NOMOR: ");
                scanf ("%d", &pil1); 
                      while ((pil1!=1)&&(pil1!=2))
                      {
                            system("cls");
                            printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                            printf("\n\nDATA BENAR?");
                            printf("\n\t\t\t\t[1] YA\t\t[2] TIDAK");
                            printf("\nPILIH NOMOR: ");
                            scanf ("%d", &pil1);
                      }                 
                      if (pil1==1)
                      {
                            system("cls");
                            printf("\n\n\t\t\t\t\t\tTRANSAKSI BERHASIL\n\n");              //pembelian telah dilakukan
                            printf("\n\n\t\t\t\t\t\tSISA SALDO=%d\n", akhir);
                            printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                            printf("\n\t\t\t\tPILIH NOMOR: ");
                            scanf ("%d", &pil2);
                                  while ((pil2!=1)&&(pil2!=2))
                                  {
                                        system("cls");
                                        printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                                        printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                                        printf("\n\t\t\t\tPILIH NOMOR: ");
                                        scanf ("%d", &pil1);
                                  }
                                  if (pil2==1)
                                  {
                                        loading();
                                        menu();                          
                                  }
                                  else if (pil2==2)
                                  {
                                        printf ("TRANSAKSI SELESAI, SILAHKAN AMBIL KARTU ANDA");
                                  }
                      }         
                      else if (pil1==2)
                      {
                           system("cls");
                           printf("\n\n\tTRANSAKSI DIBATALKAN\n");
                           printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                           printf("\n\t\t\t\tPILIH NOMOR: ");
                           scanf ("%d", &pil2);
                                 while ((pil2!=1)&&(pil2!=2))
                                 {
                                       system("cls");
                                       printf("\nPILIHAN YANG DIMASUKKAN TIDAK TERSEDIA");
                                       printf("\n\t\t\t\tKEMBALI KE MENU AWAL?\n\t\t\t\t [1]YA\t[2]TIDAK");
                                       printf("\n\t\t\t\tPILIH NOMOR: ");
                                       scanf ("%d", &pil1);
                                 }
                                 if (pil2==1)
                                 {
                                       loading();
                                       menu();                          
                                 }
                                 else if (pil2==2)
                                 {
                                       printf ("TRANSAKSI SELESAI, SILAHKAN AMBIL KARTU ANDA");
                                 }
                     }           
           }
       case 5:
       	    loading();
       	    menu();
       case 6:
       		loading();
       		keluar();   
       default:
               printf("\n\t\t\t\t\t\tMAAF, PILIHAN YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\t\tHARAP COBA LAGI");
               printf("\n\n\t\t\t\t\t\t===PEMBAYARAN===\n\n\n[1] LISTRIK/PLN\n[2] PDAM\n[3] PAJAK\n[4] PULSA\n");
               printf("\nPILIH NOMOR: "); //memilih pembayaran yang akan dilakukan
               scanf ("%d", &y);
       } 
}
         
void bantuan()
{
	system("cls");
    int a, x;
	printf("\n\n\t\t\t\t\t\t\t===MENU BANTUAN===\n");
	printf("\n\n\n\t\t[1] BANTUAN DAN INFORMASI PROGRAM\n\t\t[2] INFORMASI MENU\n\t\t[3] KEMBALI KE MENU\n\t\t[4] KELUAR\n");
    printf("PILIH NOMOR= ");
    scanf ("%d",&x); 
      
	switch (x)
    {
       	case 1:
       	    loading();
       	    printf("\n\t\t\t\t\t\t[BANTUAN]\n");
			printf("\n\nPROGRAM INI DIBUAT UNTUK MEMENUHI TUGAS PENGANTAR TEKNIK KOMPUTER");
			printf("\nUNTUK FITUR LAINNYA, MASIH DALAM PENGEMBANGAN");
			printf("\nJIKA TERDAPAT KERUSAKAN/EROR, SILAHKAN HUBUNGI KAMI");
			printf("\n\nCONTACT PERSON :\nGITA AYU SALSABILA : +62 856 7899 4355\nANANDA RIZKY DUTO P. : +62 855 1696 073");
			printf("\n\n\n\t\t\t\t\t\tKEMBALI KE MENU?\n\n\t\t\t\t\t\t [1]YA\t[2]TIDAK\n");
  			printf("\t\t\t\t\t\t PILIH NOMOR= ");
    		scanf ("%d", &a);
    		printf("%d", a);
    		if (a==1)
    		{
    		menu();
     		}
     		else if (a==2)
     		{
     		keluar();
     		}
     		else
     		{
     		printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\tHARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
			}
	    case 2:
             loading();
             printf("\n\t\t\t\t\t\t[INFORMASI MENU]\n\n");
			 printf("\n[1] INFORMASI SALDO  = MENU UNTUK MENAMPILKAN SALDO SAAT INI");
			 printf("\n[2] TARIK TUNAI      = MENU UNTUK MELAKUKAN PENARIKAN TUNAI DAN MENAMPILKAN SALDO SETELAH PENARIKAN TUNAI");
			 printf("\n[3] TRANSFER         = MENU UNTUK MELAKUKAN TRANSFER DAN MENAMPILKAN SALDO SETELAH TRANSAKSI SELESAI");
			 printf("\n[4] BAYAR/BELI       = MENU UNTUK MELAKUKAN PEMBAYARAN TERTENTU DAN MENAMPILKAN SALDO SETELAH TRANSAKSI SELESAI");
       	   printf("\n\n\n\t\t\t\t\t\tKEMBALI KE MENU?\n\n\t\t\t\t\t\t [1]YA\t[2]TIDAK\n");
	       printf("\t\t\t\t\t\t PILIH NOMOR= ");
  		   scanf("%d", &a);
    	   printf("%d", a);
    	   if (a==1)
    		{
    	    	menu();
     		}
           else if (a==2)
     		{
     	 	    keluar();
     		}
  		   else
     		{
     		    printf("\n\t\t\t\t\t\tMAAF INPUT YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\tHARAP PILIH BERDASARKAN ANGKA YANG TERTERA\n");
			}
        case 3:
       	    loading();
       	    menu();
       	case 4:
       		loading();
       		keluar();
       	default:      //pesan eror jika input yang dimasukkan tidak sesuai dengan pilihan apapun
       	    printf("\n\t\t\t\t\t\tMAAF, PILIHAN YANG ANDA MASUKKAN SALAH\n\t\t\t\t\t\t\tHARAP COBA LAGI");
       	    sleep (5);
       	    system ("cls");
    		return bantuan();
   	}
}

void keluar ()
{
     system("cls");
     printf("\n\n\t\t\t\t\t\t    TRANSAKSI SELESAI\n\n\n\t\t\t\t\t\tSILAHKAN AMBIL KARTU ANDA\n");
     printf("\n\n\n\n\t\t\t\t\t TERIMAKASIH TELAH MENGGUNAKAN JASA BANK ABC\n\t\t\t\t\tSARAN DAN MASUKKAN HUBUNGI CALL CENTER 115000\n");
     system("pause");
     system("cls");
     return main();
}

      
