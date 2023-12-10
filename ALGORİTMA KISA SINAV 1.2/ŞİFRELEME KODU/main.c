#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */         
//                                   CALISABILEN  BIR SIFRELEME KODU ORNEGIDIR
int main() {
 char input_txt[50];
 int anahtar,i;

  printf("Mesajinizi girin: ");
  gets(input_txt);

start:
  printf("Anahtari girin: ");
// asagidaki komut blogu anahtar olarak tam sayi degeri dýsýnda bir deger girilmesini engellemek icin kullanildi.
  
  if(scanf("%d",&anahtar ) !=1){
printf("lutfen bir tam sayi girin\n");
fflush(stdin);
goto start;
}

// for dongusu yazilan kelimenin sadece ilk harfi deGil butun harflerinin sifrelenmesi icin gereklidir.
// mesaj[i] != '\0' bolumu dongunun kosulunun bos elemena(yani mesajdaki harf sayisi kadar) denk gelinceye kadar devam edicegini ifade eder.
  for (i = 0; input_txt[i] != '\0'; i++) {
  	
// asagidaki isalpha komutu mesaj olarak tanimladigimiz dizininin elemanlarinin alfabede olup olmadigini kontrol eder.
    
	if (isalpha(input_txt[i])) {
    
// tolower komutu yazilan kelimenin harflerini eger buyuk harfse kucuk harfe donusturur.
	 	
      input_txt[i] = tolower(input_txt[i]);
      
// asagidaki input_txt[i] -= 'a'; komutu harfin alfabedeki sirasini belirler.
      input_txt[i] -= 'a';
      
//asagidaki input_txt[i] += anahtar; komutu harfi girilen anahtar kadar kaydirir.      
      input_txt[i] += anahtar;       
      input_txt[i] %= 26;
      input_txt[i] += 'a';
    }
  }

  printf("SifrelenmiS mesaj: %s\n",input_txt);

}

