/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


#include<iostream>
#include<vector>
#include<set>

int main() {
    
    std::string tmp;
    long long wynik{};
    

    while(std::cin >> tmp) {
        
        std::vector<int> liczby(12,0);
        std::set<int> uzyteidx;
        
        int jaki_i{};
        for(int i{};i<12;++i) {
            int maks{},maks_i{};
            for(int j = jaki_i;j<tmp.size()-12+i+1;++j){
                if((tmp[j] - '0') > maks && uzyteidx.find(j) == uzyteidx.end()){
                    maks = (tmp[j] - '0');
                    maks_i = j;
                    jaki_i = j + 1;
                }
            }
            liczby[i] = maks;
            uzyteidx.insert(maks_i);
        }
        long long w{};
        for(const auto &i : liczby) w = (w * 10) + i;
        
        wynik += w;
    }
    std::cout << wynik << '\n';
    return 0;
}