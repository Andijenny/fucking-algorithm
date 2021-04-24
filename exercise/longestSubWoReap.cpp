#include <string>
#include <unordered_map>
#include <iostream>

size_t longestSubstringWoRept(const std::string& src)
{
    std::unordered_map<char, size_t>  mp;

    size_t left = 0, right = 0, len = 0, misMatch = 0;

    while(right != src.size()) {
        char c = src[right];
        right++;
        mp[c]++;

        if(mp[c] > 1) {
            misMatch++;
        }

        if(misMatch == 0 && right - left > len) {
            len = right - left;
        }
        while(misMatch > 0) {
            char d = src[left];
            left++;
            mp[d]--;
            if(mp[d] == 1) {
                misMatch--;
            }
        }
    }
    return len;
}

int main()
{
    std::string src("abcabcbb");
    std::cout << src << " " << longestSubstringWoRept(src) << std::endl;
    src = "bbbb";
    std::cout << src << " " << longestSubstringWoRept(src) << std::endl;
    src = "pwwpew";
    std::cout << src << " " << longestSubstringWoRept(src) << std::endl;
}
