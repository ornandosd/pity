#include <iostream>
#include <string>
using namespace std;
struct myseps : numpunct<char> { // code buat spasi doang gapenting :v
   /* use space as separator */
   char do_thousands_sep() const { return ' '; } 

   /* digits are grouped by 3 digits each */
   string do_grouping() const { return "\3"; }
};

struct data{
    int pull = 160;
    int primoToRupiah = 263; // 300 primo = rp 79 000 |=| rp 263.33 / primo dibulatkan menjadi rp 263
    int zhongli = 80 + 74 + 78 + 22 + 59 + 79 + 81;
    int xiao = 76;
    int hu_tao = 33;
    int mona = 22;
    int diluc = 6;
    int jean = 76 + 78 + 77;
    int keqing = 39;
    int totalPull = ((zhongli + xiao + hu_tao + mona + diluc + jean + keqing)*pull); // total pull 880x160primo = 140800
    int topup_bonus = 300 + 980 + 1980 + 3280 + 6480; // bonus per top up sekali pake doang // max bonus = 13020

    int get_totalpull(){
        return totalPull;
    }
    int get_primoToRupiah(){
        return primoToRupiah;
    }
};

int main(){

    data pull;
    int totalPull = pull.get_totalpull();
    int primoToRupiah = pull.get_primoToRupiah();
    double hari;
    double blessingDailyquest = 160;
    double dailyquest = 60;
    double f2p;

    cout.imbue(locale(locale(), new myseps));
    cout <<     "Total pull tanpa bonus           : " << totalPull <<" Pull" << endl;
    cout <<     "Total yang dibayar tanpa bonus   : Rp " << totalPull * primoToRupiah << endl;


    if(totalPull >= 6480){
        cout << "Total pull dengan bonus          : " <<(totalPull - (6480+3280+1980+980+300)) <<" Pull" << endl;
        cout << "Total yang dibayar adalah        : Rp "<< ((totalPull - (6480+3280+1980+980+300))*primoToRupiah) << endl;
    }else if (totalPull >= 3280){
        cout << "Total pull dengan bonus          : " <<(totalPull - (3280+1980+980+300)) <<" Pull" << endl;
        cout << "Total yang dibayar adalah        : Rp "<< ((totalPull - (3280+1980+980+300))*primoToRupiah) << endl;
    }else if (totalPull >= 1980){
        cout << "Total pull dengan bonus          : " <<(totalPull - (1980+980+300)) <<" Pull" << endl;
        cout << "Total yang dibayar adalah        : Rp "<< ((totalPull - (1980+980+300))*primoToRupiah) << endl;
    }else if (totalPull >= 980){
        cout << "Total pull dengan bonus          : " <<(totalPull - (980+300)) <<" Pull" << endl;
        cout << "Total yang dibayar adalah        : Rp "<< ((totalPull - (980+300))*primoToRupiah) << endl;
    }else if (totalPull >= 300){
        cout << "Total pull dengan bonus          : " <<(totalPull - 300) <<" Pull" << endl;
        cout << "Total yang dibayar adalah        : Rp "<< ((totalPull - 300)*primoToRupiah) << endl;
    }else{
        cout << "Total yang dibayar adalah        : Rp "<< (totalPull * primoToRupiah) << endl;
    }

    hari = totalPull/blessingDailyquest;
    cout <<     "Total Blessing + Daily doang     : "<< (hari/30)/12 << " Tahun" << endl;
    f2p = totalPull/dailyquest;
    cout <<     "Total Daily doang                : "<< (f2p/30)/12 << " Tahun" << endl;
    cout <<     "Total B5 Didapatkan              : 15 ";

    return 0;
}
