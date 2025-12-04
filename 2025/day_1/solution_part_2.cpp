/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include <iostream>
#include <string>

int main()
{
    int aktualny = 50;
    const int MOD = 100;
    
    std::string tmp;
    int wynik{};
    
    while(std::getline(std::cin,tmp)) {
        char k = tmp[0];
        tmp.erase(0,1);
        int krok = std::stoi(tmp);
        wynik += krok / 100;
        krok %= MOD;
        
        if(k == 'L') {
            if(aktualny < krok && aktualny != 0) ++wynik;
            aktualny = (aktualny - krok + MOD) % MOD;
        }
        else {
            if((aktualny + krok) > 100) ++wynik;
            aktualny = (aktualny + krok + MOD) % MOD;
        }
        
        if(aktualny == 0) ++wynik;
    }
    std::cout << wynik << '\n';
    return 0;
}