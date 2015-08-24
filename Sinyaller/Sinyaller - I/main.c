/*
   Sinyaller - I : Temel Sinyal Yakalama


Telif Hakkı (c) 2013-2015 Takyon Mühendislik

 Hiçbir ücret talep edilmeden burada işbu yazılımın bir kopyasını ve belgelendirme dosyalarını (“Yazılım”)
elde eden herkese verilen izin; kullanma, kopyalama, değiştirme, birleştirme, yayımlama, dağıtma, alt lisanslama,
ve/veya yazılımın kopyalarını satma eylemleri de dahil olmak üzere ve bununla kısıtlama olmaksızın, yazılımın 
sınırlama olmadan ticaretini yapmak için verilmiş olup, bunları yapmaları için yazılımın sağlandığı kişilere 
aşağıdakileri yapmak koşuluyla sunulur:

Yukarıdaki telif hakkı bildirimi ve işbu izin bildirimi yazılımın tüm kopyalarına veya önemli parçalarına 
eklenmelidir. 

YAZILIM “HİÇBİR DEĞİŞİKLİK YAPILMADAN” ESASINA BAĞLI OLARAK, TİCARETE ELVERİŞLİLİK, ÖZEL BİR AMACA UYGUNLUK VE 
İHLAL OLMAMASI DA DAHİL VE BUNUNLA KISITLI OLMAKSIZIN AÇIKÇA VEYA ÜSTÜ KAPALI OLARAK HİÇBİR TEMİNAT OLMAKSIZIN 
SUNULMUŞTUR. HİÇBİR KOŞULDA YAZARLAR VEYA TELİF HAKKI SAHİPLERİ HERHANGİ BİR İDDİAYA, HASARA VEYA DİĞER 
YÜKÜMLÜLÜKLERE KARŞI, YAZILIMLA VEYA KULLANIMLA VEYA YAZILIMIN BAŞKA BAĞLANTILARIYLA İLGİLİ, BUNLARDAN KAYNAKLANAN 
VE BUNLARIN SONUCU BİR SÖZLEŞME DAVASI, HAKSIZ FİİL VEYA DİĞER EYLEMLERDEN SORUMLU DEĞİLDİR.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void SinyalYakalandiginda(int sinyalNo)
{
    printf("%s(%d) sinyali yakalandı!\n", strsignal(sinyalNo), sinyalNo);
}

int main()
{    
    int sinyalNo = SIGINT;
    printf("%s(%c) sinyali kaydediliyor\n", strsignal(sinyalNo), sinyalNo);
    if(signal(sinyalNo, &SinyalYakalandiginda) == SIG_ERR)
    {
        printf("Hata! %s(%c) sinyali için bir yakalayıcı belirleyemedik\n",strsignal(sinyalNo), sinyalNo);
        exit(EXIT_FAILURE);
    }
    printf("%s(%d) sinyali başarıyla kaydedildi\n", strsignal(sinyalNo), sinyalNo);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
