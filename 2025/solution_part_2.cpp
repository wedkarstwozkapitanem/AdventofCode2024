/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<iostream>
#include<vector> 


long long dostepnemiejsca(std::vector<std::string> &plansza);

int main() {
    std::vector<std::string> plansza;
    std::string tmp;
    while(std::getline(std::cin,tmp)) plansza.push_back(tmp);
    

    long long wynik{};
    long long f = dostepnemiejsca(plansza);
    while(f != 0) {
        wynik += f;
        f = dostepnemiejsca(plansza);
    }
    std::cout << wynik << '\n';
    return 0;
}

long long dostepnemiejsca(std::vector<std::string> &plansza) {
    const int kierunki[][2] = {
        {-1,-1},{-1,0},{-1,1},
        {0,-1},         {0,1},
        {1,-1},{1,0},{1,1},
    };
    long long wynik{};
    

    for(int i{};i<plansza.size();++i) {
        for(int j{};j<plansza[0].size();++j) {
            int liczbaRolek{};
            if(plansza[i][j] != '@') continue;
            for(const auto &[xd,yd] : kierunki) {
                int x = j + xd;
                int y = i + yd;
                if(x < 0 || x >= plansza[0].size() || y < 0 || y >= plansza.size()) continue;
                if(plansza[y][x] == '@') ++liczbaRolek;
            }
            if(liczbaRolek < 4) {
                ++wynik;
                plansza[i][j] = '.';
            }
        }
    }
    

    return wynik;
}