#include <iostream>

#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int ambil_kartu()
{
    return 1 + rand()%10;
}


class lanjut
{
    public :
    void giliran(int& TotalKartu,char pilih,bool& no)
    {
        if(pilih == 'y' || pilih == 'Y')
        {
            if((TotalKartu += ambil_kartu()) >= 21)
            {
                cout << "jumlah kartu anda adalah = " << TotalKartu << endl;
                no = true;
            }
            return;
        }
        no = true;
    }

    void data(int& TotalKartu, int& dealer)
    {
        cout << "Total kartu player = " << TotalKartu << endl;
        cout << "Total Kartu Dealer = Kartu tertutup" << endl;
    }
};
int main()
{
    cout << "================  TUGAS MODUL 4  ================" << endl;
    cout << "=====  PRAKTIKUM DKP KELOMPOK 23 (SHIFT 4)  =====" << endl;
    cout << "ANGGOTA :  1. Fajri Arif Rasyid (21120122120003) " << endl;
    cout << "           2. Leonardus Deni P. (21120122120012) " << endl;
    cout << "           3. Femas Arianda R.  (21120122130080) " << endl;
    cout << "           4. Fahmi Rizqi P.N   (21120122140161) " << endl;
    cout << "=================================================" << endl;
    cout << "-----------------   BLAC JACK   -----------------" << endl;
    cout << "=================================================" << endl;

    bool no;
    char pilih;

    while (true)
    {
        no = false;
        srand(time(0));
        int dealer = ambil_kartu();
        int TotalKartu = ambil_kartu() + ambil_kartu();
        int TotalDealer = dealer + ambil_kartu();

        while(!no)
        {
            lanjut myObj;
            myObj.data(TotalKartu, dealer);
            cout << "Ambil kartu ? (y/n) " << endl;
            cin >> pilih;
            myObj.giliran(TotalKartu, pilih, no);
        }
        no = false;

        cout << "Sekarang giliran dealer";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        cout << "Ok giliran Dealer selesai" << endl;
        cout << "Hasil : " << endl;
        Sleep(1000);

        while(TotalDealer <= 21 && !no)
        {
            if(TotalDealer >= 17)
                no = true;
            else
                TotalDealer += ambil_kartu();
        }

        cout << "Total Kartu Player = " << TotalKartu << endl;
        cout << "Total Kartu Dealer = " << TotalDealer << endl;

        if ((TotalKartu < 22) && (TotalKartu > TotalDealer) || (TotalDealer > 21) && (TotalKartu < 22) || (TotalKartu > 21) && (TotalKartu < TotalDealer))
            {
                cout << "Anda menang" << endl;
                cout << "======================================================"<<endl;
            }
        else if (TotalKartu == TotalDealer)
            {
                cout << "Seri" << endl;
                cout << "======================================================"<<endl;
            }
        else
            {
                cout << "Anda Kalah" << endl;
                cout << "======================================================"<<endl;
            }
    }
}
