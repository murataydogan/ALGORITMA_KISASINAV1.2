#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
 
  //sifreli dosyay� a��n
  FILE *dosya = fopen("sifrelimetin.txt","r");
  

  //sifreli metni bir dizi olarak tan�ml�yoruz.
  char sifreli[1024];
  
//fread komutu burada okunan harf say�s�n� kontrol ediyor.  
  int k = fread(sifreli,1,sizeof(sifreli),dosya);
  
  fclose(dosya);

  
  int anahtar = 2;
  int i;
 
  for ( i = 0; i < k; i++) {
    if (isalpha(sifreli[i])) {
      sifreli[i] = tolower(sifreli[i]);
      sifreli[i] -= 'a';
      sifreli[i] -= anahtar;
      sifreli[i] %= 26;
      sifreli[i] += 'a';
    }
  }

//sifresi cozulmu� metni yeni bir dosya olarak kaydediyoruz.
  FILE *dosya2 = fopen("��z�lm��.txt","w");
  fputs(sifreli, dosya2);
  
  fclose(dosya2);
  
  printf("cozulmus adinda dosyaniz olusturuldu");
  
  return 0;
}
 
 
