/*
 * =========================== *
 *  Dominik Łempicki (kapitan) *
 * =========================== *
 */

#include <iostream>
#include <vector>
#include <algorithm>

inline bool czywprzedziale(const std::vector<std::pair<long long, long long>> &przedzialy, const long long liczba)
{
    auto it = std::lower_bound(przedzialy.begin(), przedzialy.end(), std::make_pair(liczba, 0LL));
    if (it == przedzialy.begin())
        return false;
    --it;
    return it->first <= liczba && it->second >= liczba;
}

int main()
{
    std::vector<std::pair<long long, long long>> przedzialy, poloczone;
    long long wynik{};
    std::string tmp;
    while (std::getline(std::cin, tmp))
    {
        auto it = tmp.find('-');
        if (it != std::string::npos)
        {
            const auto liczba1 = std::stoll(tmp.substr(0, it));
            const auto liczba2 = std::stoll(tmp.substr(it + 1));
            przedzialy.emplace_back(liczba1, liczba2);
        }
        else if (!tmp.empty())
        {
            long long liczba = std::stoll(tmp);
            if (czywprzedziale(poloczone, liczba))
                ++wynik;
        }
        else
        {
            std::sort(przedzialy.begin(), przedzialy.end(), [&](const auto &a, const auto &b)
                      { return a.first < b.first; });

            for (const auto &i : przedzialy)
            {
                if (poloczone.empty() || poloczone.back().second < i.first)
                    poloczone.push_back(i);
                else
                    poloczone.back().second = std::max(poloczone.back().second, i.second);
            }

            przedzialy.clear();
            przedzialy.shrink_to_fit();
        }
    }
    std::cout << wynik << '\n';
    return 0;
}