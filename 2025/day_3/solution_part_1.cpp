/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<iostream>
#include<limits>

int main() {
    std::string tmp;
    
    long long wynik{};
    while(std::getline(std::cin,tmp)) {
        int max1 = std::numeric_limits<int>::min(),max2 = std::numeric_limits<int>::min();
        for(const auto &i : tmp) {
            int liczba = i - '0';
            if(liczba > 9) continue;
            if(max1 < max2) {
                max1 = max2;
                max2 = liczba;
                continue;
            }
            if(max1 == std::numeric_limits<int>::min()) max1 = liczba;
            else if(max2 == std::numeric_limits<int>::min()) max2 = liczba;
            else if(max2 < liczba) {
                max1 = std::max(max2,max1);
                max2 = liczba;
            }
            
        }
        wynik += max1 * 10 + max2;
    }
    std::cout << wynik << '\n';
    
    return 0;
}