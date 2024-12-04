/*
    nazwa: Day 2: Red-Nosed Reports
    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>

bool czyBezpieczne(const std::vector<int> &liczby) {
          bool rosnoce{liczby[0] < liczby[1]},czyraz{false};
            for(int i{0};i<liczby.size()-1;++i){
            if((rosnoce && liczby[i]>=liczby[i+1]) || (!rosnoce && liczby[i]<=liczby[i+1]) || std::abs(liczby[i]-liczby[i+1]) > 3) return false; 
        }
        return true;
}


bool czyBezpieczne(const std::vector<int> &liczby, const int indekswykluczony) {
        bool rosnoce{liczby[0] < liczby[1]},czyraz{false};
        for(int i{0};i<liczby.size();++i){
            if(i==indekswykluczony || i == indekswykluczony - 1 || i == indekswykluczony + 1) continue;
            if((rosnoce && liczby[i]>=liczby[i+1]) || (!rosnoce && liczby[i]<=liczby[i+1]) || std::abs(liczby[i]-liczby[i+1]) > 3) return false; 
        }
        return true;
}


int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);

    //std::vector<std::vector<int>> liczby(1);
    std::string tmp;
    //int i{};

    std::vector<int> liczby;
    long long suma1{},suma2{},licznik{};
    while (std::getline(std::cin, tmp)) {
        if (tmp.empty()) break;
        int i = 0;
        while (i < tmp.size()) {
            while (i < tmp.size() && tmp[i] == ' ') ++i;
            std::string liczba;
            while (i < tmp.size() && tmp[i] != ' ') {
                liczba.push_back(tmp[i]);
                ++i;
            }
            if (!liczba.empty()) liczby.push_back(std::stoi(liczba));
        }
        
        if(!czyBezpieczne(liczby)) {
            suma1++;
            bool bezpieczna2{false};
            for(int i{};i<liczby.size();++i){
                if(czyBezpieczne(liczby,i)) {
                    bezpieczna2 = true;
                    break;
                }
            }
            if(!bezpieczna2) ++suma2; 
        }


        liczby.clear();
        ++licznik;
    }
   
   
    std::cout << licznik - suma1 << ' ' << licznik - suma2;
    return 0;
}
