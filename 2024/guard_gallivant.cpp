/*
    nazwa: Day 6: Guard Gallivant
    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include <vector>


std::pair<long long,long long> pobierz(std::vector<std::string> &plansza) {
    std::string tmp;
    long long x{},y{},tmp_y{};
    while(std::cin >> tmp) {
        plansza.push_back(tmp);
        if(x!=0 && y !=0) continue;
        for(int i{};i<tmp.size();++i) {
            if(tmp[i]=='^') {
                x=i;
                y = tmp_y;
            }
        }
        ++tmp_y;
    }
    return {y,x};
}


std::pair<short,short> zwrocKierunekNaPrawo(const std::pair<short,short> &kierunek) {
    const short kierunki[][2]{{-1,0},{0,1},{1,0},{0,-1}};

    short p{};
    for(const auto &i : kierunki) {
        p = (p+1) % (sizeof(kierunki)/sizeof(kierunki[0]));
        if(kierunek.first == i[0] && kierunek.second == i[1]) return {kierunki[p][0],kierunki[p][1]};
    }
    return {0,0};
}

unsigned long long ileKrokow(const std::vector<std::string> &plansza,std::pair<long long,long long> &wspolrzedneStraznika){
    unsigned long long liczbaKrokow{};

    std::pair<short,short> kierunek = {-1,0};

    std::vector<std::vector<bool>> odwiedzone(plansza.size(),std::vector<bool>(plansza[0].size(),false));
    while (true) {
        if(plansza[wspolrzedneStraznika.first][wspolrzedneStraznika.second] == '#') {
            wspolrzedneStraznika.first -= kierunek.first;
            wspolrzedneStraznika.second -= kierunek.second;
            kierunek = zwrocKierunekNaPrawo(kierunek);
        } else if (!(odwiedzone[wspolrzedneStraznika.first][wspolrzedneStraznika.second]))  ++liczbaKrokow;
        
        odwiedzone[wspolrzedneStraznika.first][wspolrzedneStraznika.second] = true;
       
        wspolrzedneStraznika.first += kierunek.first;
        wspolrzedneStraznika.second += kierunek.second;
        if (!(wspolrzedneStraznika.first >= 0 && wspolrzedneStraznika.first < plansza.size() && wspolrzedneStraznika.second >= 0 && wspolrzedneStraznika.second < plansza[0].size())) break;
    }

    return liczbaKrokow;
}


int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);

    std::vector<std::string> plansza;
    auto wsporzedneStraznika = pobierz(plansza);
    std::cout << ileKrokow(plansza,wsporzedneStraznika);

    return EXIT_SUCCESS;
}