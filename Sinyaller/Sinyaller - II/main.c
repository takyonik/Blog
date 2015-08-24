/*
   Sinyaller - II : Daha Gelişmiş Seçenekler


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
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

struct sigaction act;

void GelismisYakalayici(int sinyalNo, siginfo_t *bilgi, void *ptr)
{
    printf("%s(%d) sinyalini yakaladık.\n", strsignal(sinyalNo), sinyalNo);    
}

int main()
{
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = GelismisYakalayici;
    act.sa_flags = SA_SIGINFO;

    int yakalanacakSinyal = SIGINT;

    if(sigaction(yakalanacakSinyal, &act, NULL) == -1)
    {
        int hata = errno;
        if(hata == EFAULT)
        {
            perror("Hata: Belirtilen sigaction adresi geçersiz\n");
        }
        else if(hata == EINVAL)
        {
            perror("Hata: Yakalanmaya çalışılan sinyal geçersiz(SIGKILL ve SIGSTOP da geçersiz) \n");
        }
        // varsa yapılacak temizlik

        exit(EXIT_FAILURE);
    }

    printf("%s(%d) sinyali başarıyla kaydedildi\n", strsignal(yakalanacakSinyal), yakalanacakSinyal);
    while(1)
    {
        sleep(1);
    }

    return 0;
}

