/*
    nazwa: Day 5: Print Queue
    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

std::map<long long, std::set<long long>> wczytajZasadyKolejnosci() {
    std::string tmp;
    std::map<long long, std::set<long long>> zasady;

    while (getline(std::cin, tmp)) {
        if (tmp.empty()) break;
        std::string liczba;
        int i = 0;

        while (tmp[i] != '|') liczba.push_back(tmp[i++]);
        long long liczba1 = std::stoll(liczba);

        liczba = "";
        while (++i < tmp.size()) liczba.push_back(tmp[i]);
        long long liczba2 = std::stoll(liczba);

        zasady[liczba2].insert(liczba1);
    }

    return zasady;
}



bool czyPoprawny(const std::vector<long long> &liczby,std::map<long long, std::set<long long>> &zasadyKolejnosci) {
        std::set<long long> doodwiedzenia;

        for (int i = 0; i < liczby.size(); i++) {
            long long liczba = liczby[i];

            for (const auto& p : zasadyKolejnosci[liczba]) doodwiedzenia.insert(p);
            auto iterator = doodwiedzenia.find(liczba);
            if (liczba == *iterator && iterator != doodwiedzenia.end()) return false;
        }

        return true;
}

unsigned long long stronyDoUtworzenia() {
    unsigned long long suma = 0;

    auto zasadyKolejnosci = wczytajZasadyKolejnosci();

    std::string tmp;
    while (getline(std::cin, tmp)) {
        int i = 0;
        std::vector<long long> liczby;

        while (i < tmp.size()) {
            std::string liczba;
            while (i < tmp.size() && tmp[i] != ',') liczba.push_back(tmp[i++]);
            liczby.push_back(std::stoll(liczba));
            ++i;
        }

        if (czyPoprawny(liczby,zasadyKolejnosci)) {
            suma += liczby[liczby.size() / 2];
        }
    }

    return suma;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cout << stronyDoUtworzenia() << "\n";
    return EXIT_SUCCESS;
}
