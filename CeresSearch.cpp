#include<iostream>
#include<vector>
#include<queue>


unsigned long long liczbaWystopien(const std::vector<std::string> &plansza,const std::string wzorzec){
    unsigned long long suma{};

    struct p {long long x{},y{},krok{};};
    std::queue<p> doodwiedzenia;
    for(int i{};i<plansza.size();++i){
        for(int j{};j<plansza[i].size();++j){
            if(plansza[i][j]==wzorzec[0]) doodwiedzenia.push({i,j,1});
        }
    }

    const short kierunki[][2]{
    {-1,-1},{-1,0},{-1,1},
    {0,1},{0,-1},
    {1,-1},{1,0},{1,1}};

    while (!doodwiedzenia.empty()) {
        auto aktualny = doodwiedzenia.front();
        doodwiedzenia.pop();
        if(plansza[aktualny.x][aktualny.y] == wzorzec[aktualny.krok]){
            if(aktualny.krok == wzorzec.size()-1) ++suma;
            for(const auto &i : kierunki){
                doodwiedzenia.push({aktualny.x+i[0],aktualny.y+i[1],aktualny.krok+1});
            }
        }
    }
    

    return suma;
}


int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    std::vector<std::string> plansza;

    std::string tmp;
    while(std::cin >> tmp)  plansza.push_back(tmp);

    std::cout << liczbaWystopien(plansza,"XMAS");
   
    return 0;
}