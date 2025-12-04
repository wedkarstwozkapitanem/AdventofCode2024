/*
*    nazwa: Day 11: Plutonian Pebbles
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include <vector>


void zmiana(std::vector<long long> &liczby) {
    const int n = liczby.size();
    for (int i = 0; i < n; ++i) {
        if (liczby[i] == 0) liczby[i] = 1;
        else if (!(std::to_string(liczby[i]).size() % 2)) {
            std::string liczba = std::to_string(liczby[i]);
            std::string tmp;
            int p{};
            for(;p<liczba.size()/2;++p) tmp.push_back(liczba[p]);
            liczby[i] = std::stoll(tmp);
            tmp.clear();
            for(;p<liczba.size();++p) tmp.push_back(liczba[p]);
            liczby.push_back(std::stoll(tmp));
        } else liczby[i] *= 2024; 
        
    }
}


int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);

    std::vector<long long> liczby;

    {
        long long tmp;
        while(std::cin >> tmp) liczby.push_back(tmp);
    }


    const int n=25;
    for(int i{};i<n;++i) zmiana(liczby);
    std::cout << liczby.size();
    /*for(int i{};i<75;++i) zmiana(liczby);
    std::cout << ' ' << liczby.size();*/

    return EXIT_SUCCESS;
}