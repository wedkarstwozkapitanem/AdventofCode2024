/*
*    nazwa: Day 7: Bridge Repair
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>
#include<queue>



bool czyDaSieUlozycRownanie(const std::vector<long long> &rownanie,const long long &wynik){
    std::queue<std::pair<long long,int>> doPrzetworzenia;
    
    int i{};
    doPrzetworzenia.push({rownanie[0],0});
    do {
        const auto aktualny = doPrzetworzenia.front();
        if(aktualny.second==rownanie.size()-1 && aktualny.first == wynik) return true;
        doPrzetworzenia.pop();
        if(aktualny.second<rownanie.size()) {
            if(aktualny.first+rownanie[aktualny.second+1]<=wynik) doPrzetworzenia.push({aktualny.first+rownanie[aktualny.second+1],aktualny.second+1});
            if(aktualny.first*rownanie[aktualny.second+1]<=wynik) doPrzetworzenia.push({aktualny.first*rownanie[aktualny.second+1],aktualny.second+1});
        }
    } while ((!doPrzetworzenia.empty()));
    
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    long long suma{};
    std::vector<long long> rownanie;

    std::string linia;
    while (std::getline(std::cin,linia)) {
        std::string wynik;
        int i{};
        for(i;i<linia.size();++i) {
            if(linia[i]==':')break;
            wynik.push_back(linia[i]);
        }
        long long  wynikDoUtworzenia = std::stoll(wynik);
        wynik.clear();

        while(++i<=linia.size()){
            if(linia[i]==' ' && !wynik.empty()) {
                rownanie.push_back(std::stoll(wynik));
                wynik.clear();
                continue;
            }
            wynik.push_back(linia[i]);
        }
         rownanie.push_back(std::stoll(wynik));
         if(czyDaSieUlozycRownanie(rownanie,wynikDoUtworzenia)) suma += wynikDoUtworzenia;

         wynik.clear();
         rownanie.clear();
    }
    
    std::cout << suma;

    return EXIT_SUCCESS;
}
