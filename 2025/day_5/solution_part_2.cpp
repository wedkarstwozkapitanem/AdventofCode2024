/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<iostream>
#include<vector>
#include<algorithm>


int main() {
    std::vector<std::pair<long long,long long>> przedzialy,poloczone;
    long long wynik{};
    std::string tmp;
    while(std::getline(std::cin,tmp)) {
        auto it = tmp.find('-');
        if(it != std::string::npos) {
            const auto liczba1 = std::stoll(tmp.substr(0,it));
            const auto liczba2 = std::stoll(tmp.substr(it + 1));
            przedzialy.emplace_back(liczba1,liczba2);
        } else {
            std::sort(przedzialy.begin(),przedzialy.end(),[&](const auto &a,const auto &b){
                return a.first < b.first;
            });           
            
            for(const auto &i : przedzialy) {
                if (poloczone.empty() || poloczone.back().second < i.first) poloczone.push_back(i);
                else poloczone.back().second = std::max(poloczone.back().second, i.second);
            }
 
        }
    }
    for(const auto &i : poloczone) wynik += (i.second - i.first + 1);
    std::cout << wynik << '\n';
    return 0;
}