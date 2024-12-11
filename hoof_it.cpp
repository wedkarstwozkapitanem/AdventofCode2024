/*
*    nazwa: Day 10: Hoof It
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

unsigned long long WYNIK{};


void DFS(const std::vector<std::vector<int>> &plansza,const std::pair<long long,long long> &obecneWspolrzedne, std::unordered_map<long long,std::set<long long>> &odwiedzone){
    if(!plansza.size()) return;
    std::pair<short,short> kierunki[]{{0,1},{1,0},{0,-1},{-1,0}};
    const long long obecny = plansza[obecneWspolrzedne.first][obecneWspolrzedne.second];
    odwiedzone[obecneWspolrzedne.first].insert(obecneWspolrzedne.second);
    if(obecny==9) {
        ++WYNIK;
        return;
    };
    for(const auto &kierunek : kierunki) {
        if(obecneWspolrzedne.first + kierunek.first < 0 || obecneWspolrzedne.second+kierunek.second < 0 || obecneWspolrzedne.first + kierunek.first >= plansza.size() || obecneWspolrzedne.second+kierunek.second >= plansza[0].size()) continue;
        if(odwiedzone[obecneWspolrzedne.first + kierunek.first].find(obecneWspolrzedne.second+kierunek.second) != odwiedzone[obecneWspolrzedne.first + kierunek.first].end()) continue;
        if(obecny == plansza[obecneWspolrzedne.first + kierunek.first][obecneWspolrzedne.second+kierunek.second]-1) DFS(plansza,{obecneWspolrzedne.first + kierunek.first,obecneWspolrzedne.second+kierunek.second},odwiedzone);
    }
}


void startDFS(const std::vector<std::vector<int>> &plansza,const std::pair<long long,long long> &obecneWspolrzedne){
    std::unordered_map<long long,std::set<long long>> odwiedzone;
    DFS(plansza,obecneWspolrzedne,odwiedzone);
}

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);

    std::vector<std::vector<int>> plansza;
    std::vector<std::pair<int,int>> poczotkiPlanszy;
    std::string tmp;
    int y{};
    while (std::getline(std::cin,tmp)) {
        plansza.resize(plansza.size()+1);
        int x{};
        for(const auto &i : tmp) {
            plansza[y].push_back(i - '0');
            if(i-'0' == 0) poczotkiPlanszy.push_back({y,x});
            ++x; 
        }
        ++y;
    }


    for(const auto &i : poczotkiPlanszy)  startDFS(plansza,i);

    std::cout << WYNIK;

    return EXIT_SUCCESS;
}