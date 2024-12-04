/*
    nazwa: Day 3: Mull It Over
    autor: Dominik Kapitan Łempicki
*/
#include<iostream>

bool mul(const std::string &txt,const int poczotek){
    char instrukcja[] {'m','u','l','('};
    if(txt.size() - poczotek < 0) return false;
    int j{};
    for(int i{poczotek};i<poczotek + 4;++i) {
        if(txt[i]!=instrukcja[j++]) return false;
    }
    return true;
}

bool dont(const std::string &txt,const int poczotek) {
    char instrukcja[] {'d','o','n','\'','t','(',')'};
    if(txt.size() - poczotek < 0) return false;
    int j{};
    for(int i{poczotek};i<poczotek + 7;++i) {
        if(txt[i]!=instrukcja[j++]) return false;
    }
    return true;
}

bool wlocz(const std::string &txt,const int poczotek) {
    char instrukcja[] {'d','o','(',')'};
    if(txt.size() - poczotek < 0) return false;
    int j{};
    for(int i{poczotek};i<poczotek + 4;++i) {
        if(txt[i]!=instrukcja[j++]) return false;
    }
    return true;
}

void parser(const std::string &txt) {
    long long suma{},suma2{};
    bool czywloczone{true};
    for(int i{};i<txt.size();++i) {
        if(dont(txt,i)) czywloczone = false;
        if(!czywloczone && wlocz(txt,i)) czywloczone = true;

        if(mul(txt,i)){
            std::string liczba;
            int p = i+3;

            bool walidowany{true};
            while(txt[++p] != ',' && p < txt.size() && walidowany) {
                if(txt[p]>='0' && txt[p]<='9')
                liczba.push_back(txt[p]);
                else if(txt[i] != ',') {
                    walidowany = false;
                    break;
                }
            }
            
            long long liczba1 = walidowany ? std::stoi(liczba) : 0;
            liczba.clear();
            while(txt[++p] != ')' && p < txt.size() && walidowany) {
                if(txt[p]>='0' && txt[p]<='9')
                liczba.push_back(txt[p]);
                else if(txt[i] != ')'){
                    walidowany = false;
                    break;
                }
            }
          
            if(walidowany){
                long long liczba2 = std::stoi(liczba);
                 //std::cout << liczba1 << ' ' << liczba2 << '\n';
                 suma += liczba1 * liczba2;
                 if(czywloczone) suma2 += liczba1 * liczba2;
            }
        }
    }
    std::cout << suma << ' ' << suma2;
}


int main() {
    std::string txt; std::getline(std::cin,txt);
    parser(txt);
    return 0;
}
