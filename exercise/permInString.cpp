#include <string>
#include <unordered_map>
#include <iostream>

bool isPerm(const std::string& s1, const std::string& s2)
{
    std::unordered_map<char, size_t>  m1;
    for(const auto& i : s1)
        m1[i]++;

    std::unordered_map<char, size_t> mw;
    size_t left = 0, right = 0, start = 0, len = s2.size();
    size_t matchLength = 0;
    while(right < s2.size()) {
        char c = s2[right];
        right++;

        if(m1.count(c)) {
            mw[c]++;
            if(mw[c] == m1[c])
                matchLength++;
        }

        while(matchLength == m1.size()) {
            if(right - left == s1.size())
                return true;

            char d = s2[left];
            left++;
            if(m1.count(d)) {
                if(mw[d] == m1[d])
                    matchLength--;
                mw[d]--;
            }
        }
    }
    return false;
}

int main()
{
    std::string s1("fiipoewrkpo");
    std::string s2("wepoo");

    std::cout << s1 << " " << s2 << " ? " << std::boolalpha << isPerm(s2, s1) << std::endl;
}
