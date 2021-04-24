#include <string>
#include <unordered_map>
#include <iostream>

std::string minWinSubstring(const std::string& src, const std::string& target)
{
    std::unordered_map<char, size_t>    cTar;
    for(const auto& i : target)
        cTar[i]++;

    std::unordered_map<char, size_t>  cWin;

    size_t left = 0, right = 0;
    size_t start = 0, len = src.size();
    size_t matchLength = 0;

    while(right < src.size()) {
        char c = src[right];
        right++;

        if(cTar.count(c)) {
            cWin[c]++;
            if(cWin[c] == cTar[c]) {
                matchLength++;
            }
        }

        while(matchLength == cTar.size()) {
            if(right - left < len) {
                start = left;
                len = right - left;
            }

            char d = src[left];
            left++;

            if(cTar.count(d)) {
                cWin[d]--;
                if(cWin[d] < cTar[d]) {
                    matchLength--;
                }
            }
        }
    }
    return len==src.size()?"":src.substr(start, len);
}

int main()
{
    std::string src("fiofjweojfoohfowe");
    std::string target("fhe");
    std::cout << src << " " << target << " " << minWinSubstring(src, target) << std::endl;
}
