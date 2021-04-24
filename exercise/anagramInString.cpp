#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

std::vector<size_t>  anagramInString(const std::string& src, const std::string& perm)
{
    std::unordered_map<char, size_t> mp;
    for(const auto& i : perm)
        mp[i]++;

    std::unordered_map<char, size_t> ms;

    size_t left = 0, right = 0, matchLength = 0;
    std::vector<size_t> res;

    while(right < src.size()) {
        char c = src[right];
        right++;
        if(mp.count(c)) {
            ms[c]++;
            if(mp[c] == ms[c])
                matchLength++;
        }

        while(matchLength == mp.size()) {
            if(right - left == perm.size())
                res.push_back(left);

            char d = src[left];
            left++;
            if(mp.count(d)) {
                if(mp[d] == ms[d])
                    matchLength--;
                ms[d]--;
            }
        }
    }
    return res;
}

int main()
{
    std::string src("cbaebabacd");
    std::string perm("abc");

    auto vec = anagramInString(src, perm);
    std::cout << src << " " << perm << std::endl;
    for(const auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

