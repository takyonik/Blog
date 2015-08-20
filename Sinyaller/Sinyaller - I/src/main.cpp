/*
   Sinyaller - I : Temel Sinyal Yakalama


Copyright (c) 2013-2015 Tachyon Engineering, Talha ORAK <talhaorak at takyon.com.tr>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
    cout << "Sinyal yakalayici ayarlandı\n";
    while(true)
    {
        sleep(1);
    }
    return 0;
}
