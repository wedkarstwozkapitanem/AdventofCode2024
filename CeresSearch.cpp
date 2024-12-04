/*
    nazwa: Day 4: Ceres Search
    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <queue>

unsigned long long liczbaWystopien(const std::vector<std::string>& plansza, const std::string wzorzec) {
    unsigned long long suma = 0;

    struct P {
        long long x, y, krok;
        std::pair<short, short> kierunek;
    };

    const short kierunki[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0}, {1, 1}
    };

    std::queue<P> doodwiedzenia;

    for (int i{}; i < plansza.size(); ++i) {
        for (int j{}; j < plansza[i].size(); ++j) {
            if (plansza[i][j] == wzorzec[0]) {
                for (const auto& k : kierunki) {
                    doodwiedzenia.push({i + k[0], j + k[1], 1, {k[0], k[1]}});
                }
            }
        }
    }

    while (!doodwiedzenia.empty()) {
        auto aktualny = doodwiedzenia.front();
        doodwiedzenia.pop();

        if (aktualny.x < 0 || aktualny.x >= plansza.size() || aktualny.y < 0 || aktualny.y >= plansza[0].size()) continue;
        
        if (plansza[aktualny.x][aktualny.y] == wzorzec[aktualny.krok]) {
            if (aktualny.krok == wzorzec.size() - 1) {
                ++suma;
                continue;
            }

            doodwiedzenia.push({
                aktualny.x + aktualny.kierunek.first,
                aktualny.y + aktualny.kierunek.second,
                aktualny.krok + 1,
                aktualny.kierunek
            });
        }
    }

    return suma;
}

unsigned long long liczbaWystopienxmas(const std::vector<std::string>& plansza) {
    unsigned long long suma = 0;

    for (int i{1}; i < plansza.size() - 1; ++i) {
        for (int j{1}; j < plansza[0].size() - 1; ++j) {
            if (plansza[i][j] == 'A') {
                if ((plansza[i - 1][j - 1] == 'M' && plansza[i - 1][j + 1] == 'M')) {
                    if ((plansza[i + 1][j - 1] == 'S' && plansza[i + 1][j + 1] == 'S')) ++suma;
                }

                if((plansza[i - 1][j - 1] == 'S' && plansza[i - 1][j + 1] == 'S')){
                    if((plansza[i + 1][j - 1] == 'M' && plansza[i + 1][j + 1] == 'M')) ++suma;
                }

                if ((plansza[i - 1][j - 1] == 'S' && plansza[i + 1][j - 1] == 'S')) {
                    if ((plansza[i + 1][j + 1] == 'M' && plansza[i - 1][j + 1] == 'M'))  ++suma;
                }

                if((plansza[i - 1][j - 1] == 'M' && plansza[i + 1][j - 1] == 'M')){
                    if((plansza[i + 1][j + 1] == 'S' && plansza[i - 1][j + 1] == 'S')) ++suma;
                }
            }
        }
    }

    return suma;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<std::string> plansza;
    std::string tmp;

    while (std::cin >> tmp) plansza.push_back(tmp);

    std::cout << liczbaWystopien(plansza, "XMAS") << ' ' << liczbaWystopienxmas(plansza);

    return 0;
}
