#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

const int n = 1000;
int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);

    std::vector<std::pair<int,int>> liczbylewe(n),liczbyprawe(n);
    std::map<int,int> licznikWystopien;
    for(int i{};i<n;++i){
        std::cin >> liczbylewe[i].first >> liczbyprawe[i].first;
        liczbylewe[i].second = liczbyprawe[i].second = i;
        ++licznikWystopien[liczbyprawe[i].first];
    }

    unsigned long long suma{};
    for(int i{};i<n;++i){
        suma+=licznikWystopien[liczbylewe[i].first]*liczbylewe[i].first;
        //std::cout <<liczbylewe[i].first << ' ' << licznikWystopien[liczbylewe[i].first] << '\n';
    }

    std::cout << suma;


  /*  std::sort(liczbylewe.begin(),liczbylewe.end(),[&](const auto &a,const auto &b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    std::sort(liczbyprawe.begin(),liczbyprawe.end(),[&](const auto &a,const auto &b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    unsigned long long suma{};
    for(int i{};i<n;++i){
        suma += std::abs(liczbylewe[i].first - liczbyprawe[i].first);
       // std::cout << liczbylewe[i].first << ' ' << liczbyprawe[i].first << '\n';
    }
    
    std::cout << suma;-**/
    return 0;
}