//Dela Puspita Lasminingrum
//22081010209
//UTS METODE NUMERIK (B-081)

#include <stdio.h> 
#include <math.h> //library yang berisi fungsi-fungsi matematika
#include <conio.h>

double fungsi(double x) {
    return pow(x, 2) - exp(x) + 9;
} //mendefisikan fungsi matematika yang akan dihitung akarnya

int main() {
	//mendefinisikan variabel-variabel yang akan digunakan
	//x1 untuk batas bawah, x2 untuk batas atas, fx1 dan fx2 merupakan nilai fungsi dari batas-batas tersebut
	//x adalah langkah antara x1 dan x2, temp adalah nilai x saat ini, dan indeks adalah nilai x dimana akar ditemukan (Inisialisasi indeks ke 0.0)
    //iterasi untuk mendefinisikan iterasi dalam sebuah proses, yaitu 10 dan i untuk penghitung dalam loop
	double x1, x2, fx1, fx2, x, temp, indeks = 0.0;
    int iterasi = 10, i;
    char ulangi;
    
    //judul program
    printf("------------------------------------------------\n");
    printf("PROGRAM MENGHITUNG AKAR MENGGUNAKAN METODE TABEL\n");
    printf("------------------------------------------------\n");
    
    //perulangan untuk mengulangi program ketika sudah selesai
    do {
    	printf("\nDidefinisikan sebuah fungsi sebagai berikut : ");
        printf("\nf(x) = x^2 - exp(x) + 9\n");

		//perulangan jika user memasukkan batas yang salah
        do {
            printf("Masukan batas bawah: ");
            scanf("%lf", &x1);
            printf("Masukan batas atas: ");
            scanf("%lf", &x2);
            if (x1 >= x2) {
                printf("Batas bawah harus kurang dari batas atas. Silakan coba lagi.\n");
            }
        } while (x1 >= x2);
		
		//menghitung langkah antarabatas bawh dan batas atas
        x = (x2 - x1) / iterasi;
		
		//menghitung nilai fungsi batas bawah dan batas atas
        printf("\n      METODE TABEL      \n");
        fx1 = fungsi(x1);
        fx2 = fungsi(x2);
		
		//Mengecek apakah nilai fungsi di batas bawah dan batas atas memiliki tanda yang sama. 
		//Jika ya, maka batas bawah dan batas atas tidak valid dan program akan keluar.
        if (fx1 * fx2 >= 0) {
            printf("Batas bawah dan batas atas Anda kurang tepat\n");
            return 1; 
        }
		
		//menyetel nilai temp ke batas bawah dan menampilkan tabel
        temp = x1;
        printf("    x              fx\n");
        
        //perulangan untuk menghitung nilai fungsi di setiap titik antara batas bawah dan batas atas.
		i=1;
        do {
            fx1 = fungsi(temp);
            fx2 = fungsi(temp + x);
            printf("%.7lf\t%.7lf\n", temp, fx1); 
            //Jika nilai fungsi di titik temp dan titik berikutnya memiliki tanda yang berbeda, maka temp adalah akar
            if (fx1 * fx2 <= 0)
                indeks = temp;
            //Menyetel nilai fx1 ke nilai fx2 untuk iterasi berikutnya
            fx1 = fx2;
            temp = temp + x;
            i++;
        } while (i <= iterasi);
		
		//menampilkan akar yang ditemukan
        printf("Akar berada diantara %.7lf dan %.7lf\n", indeks, indeks + x);
		
		//menanyakan kepada user apakah ingin mengulang program dengan batas yang baru (akar yang ditemukan) atau tidak.
        printf("Apakah Anda ingin mencoba lagi dengan batas baru? (y/n): ");
        scanf(" %c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');

    printf("\npress any key to exit..");
    getch();

    return 0;
}

