//Dela Puspita Lasminingrum
//22081010209
//UTS METODE NUMERIK (B-081)

#include <stdio.h>
#include <math.h> //library yang berisi fungsi-fungsi matematika
#include <conio.h>

double f(double x) {
    return pow(x, 2) - exp(x) + 9;
} //mendefisikan fungsi matematika yang akan dihitung akarnya

//Mendefinisikan fungsi regula falsi, yang berisi parameter a(batas bawah), b(batas atas), dan error(toleransi error). 
void regulaFalsi(double a, double b, double error) {
    if (f(a) * f(b) >= 0) {
        printf("Anda telah memasukkan nilai batas yang salah.\n");
        return;
    } /*Mengecek apakah nilai fungsi di batas bawah dan batas atas memiliki tanda yang sama. 
	  Jika ya, maka batas bawah dan batas atas tidak valid dan program akan keluar.*/

	/*Mendefinisikan variabel c(untuk menyimpan nilai akar yang ditemukan), prev_c(untuk menyimpan nilai c pada iterasi sebelumnya)
	iterasion(untuk menyimpan jumlah iterasi yang telah dilakukan).*/
    double c = a;
    double prev_c = a;
    int iteration = 0;

	/*Baris ini memulai loop iterasi. Loop iterasi akan terus diulang selama nilai fabs(f(c)) 
	lebih besar dari toleransi error yang ditentukan dan jumlah iterasi belum mencapai 1000.*/
    while (fabs(f(c)) > error && iteration < 1000) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
		//rumus regula falsi
		
		//Mencetak informasi tentang informasi saat ini.
        printf("%d. a: %.9lf, b: %.9lf, f(a): %.9lf, f(b): %.9lf, c: %.9lf, f(c): %.9lf\n", iteration+1, a, b, f(a), f(b), c, f(c));

		//Memeriksa apakah nilai f(c) telah sama dengan nol. Jika ya, maka loop iterasi akan dihentikan.
        if (f(c) == 0.0)
            break;
		
		/*Menentukan nilai a dan b untuk iterasi selanjutnya. Jika nilai f(c) * f(a) negatif, 
		maka nilai b akan diperbarui menjadi nilai c. Sebaliknya, jika nilai f(c) * f(a) positif, 
		maka nilai a akan diperbarui menjadi nilai c.*/
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iteration++;
    }
	
	//Mencetak nilai akar yang telah ditemukan
    printf("Nilai akar yang ditemukan adalah: %.9lf\n", c);
    printf("f(c) = %.9lf\n", f(c));
}

int main() {
    double a, b;
    
    //Mencetak judul program
    printf("-------------------------------------------------------\n");
    printf("PROGRAM MENGHITUNG AKAR MENGGUNAKAN METODE REGULA FALSI\n");
    printf("-------------------------------------------------------\n");
	printf("\nDidefinisikan sebuah fungsi sebagai berikut : ");
    printf("\nf(x) = x^2 - exp(x) + 9\n");
    
    printf("Masukkan batas bawah: ");
    scanf("%lf", &a);
    printf("Masukkan batas atas: ");
    scanf("%lf", &b);
	
	//Mendefinisikan toleransi error minimal yang diinginkan
    double error = 1e-7;

    regulaFalsi(a, b, error);

    printf("\nPress any key to exit...");
    getch();
    
    return 0;
}

