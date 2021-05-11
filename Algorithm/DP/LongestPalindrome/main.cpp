#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); ++i) {
            int len1 = palindrome(s, i, i);
            int len2 = palindrome(s, i, i + 1);
            int len = max<int>(len1, len2);
            if(len > maxLength) {
                start = i - (len - 1)/2;
                maxLength = len;
            }
        }
        return s.substr(start, maxLength);
    }

    int palindrome(const string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

int main() {
    Solution solution;
    //Simple Test
    string ret = solution.longestPalindrome("babad");
    printf("%s\n", ret.c_str());
    return 0;
}