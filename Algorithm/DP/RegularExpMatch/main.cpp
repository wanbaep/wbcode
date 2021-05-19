#include <iostream>

using namespace std;

#define MAX_STR 21
#define MAX_PAT 31

class Solution {
private:
    bool dp[MAX_STR][MAX_PAT];
public:
    
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        
        dp[s_len][p_len] = true;

        for(int i = s_len; i >= 0; --i) {
            for(int j = p_len - 1; j >= 0; --j) {
                bool curr_match = i < s_len && (s[i] == p[j] || p[j] == '.');

                if(j + 1 < p_len && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || curr_match && dp[i + 1][j];
                } else {
                    dp[i][j] = curr_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        
    }
};

int main() {
    return 0;
}