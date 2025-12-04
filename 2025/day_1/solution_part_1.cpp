/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


#include<iostream>

int main() {
    int start = 50;
    int mod = 100;
    
    std::string tmp;
    int wynik{};
    
    while(std::getline(std::cin,tmp)) {
        char t = tmp[0];
        tmp.erase(0,1);
        int liczba = std::stoi(tmp);
        if(t == 'L') start -= liczba;
        else start += liczba;

        start = ((start % mod) + mod) % mod;

        
        if(start == 0) ++wynik;
    }
    std::cout << wynik << '\n';
    return 0;
}