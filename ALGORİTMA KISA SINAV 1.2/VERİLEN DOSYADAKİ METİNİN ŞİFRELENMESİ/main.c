#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
//sifrelenecek metni bir dizi olarak tanimliyoruz.
  
  char metin[] ="The quick brown fox jumps over the lazy dog";
  int i,anahtar;
  
  anahtar=2;

//strlen komutu metin dizisinin boyutunu hesaplayarak dongunun dizinin son harfine kadar calismasini saglar.

  for ( i = 0; i <strlen(metin); i++) {

    if (isalpha(metin[i])) {
      metin[i] = tolower(metin[i]);
      metin[i] -= 'a';
      metin[i] += anahtar;
      metin[i] %= 26;
      metin[i] += 'a';
    }
  }

//sifrelenmis metni yeni bir dosya olarak kaydediyoruz.
//asagidaki "w" bir modu ifade edip bu modun anlami ise eger ayni isimde bir dosya varsa iceriginin silinmesi ayni isimde dosya yoksa yeni bir dosya acilmasidir. 
  
  FILE *dosya = fopen("sifrelimetin.txt","w");
  
//fputs ile sifrelenmis metni actigimiz dosyaya yazdiriyoruz.  
  fputs(metin,dosya);
  
  
  fclose(dosya);
  printf("sifrelimetin adinda sifrelenmis dosyaniz olusturuldu ");

  return 0;
}
