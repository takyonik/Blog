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

#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void SinyalYakalandiginda(int sinyalKodu)
{
    if(sinyalKodu == SIGINT)
    {
        cout << "SIGINT sinyali yakalandı!\n";
    }
}

int main()
{    
    cout << "SIGINT sinyali kaydediliyor\n";
    if(signal(SIGINT, &SinyalYakalandiginda) == SIG_ERR)
    {
        cout << "Hata! SIGINT için bir yakalayıcı belirleyemedik\nVarsayılan sinyal yakalama davranışı gerçekleşecek\n";
    }
    else cout << "Sinyal yakalayici ayarlandı\n";
    while(true)
    {
        sleep(1);
    }
    return 0;
}
