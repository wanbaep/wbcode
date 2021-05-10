#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int* stairs = new int[n + 1];
        for(int i = 0; i < n + 1; ++i ) {
            stairs[i] = 0;
        }
        
        if(n == 0 || n == 1) return 1;
        stairs[0] = 1;
        stairs[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }
        return stairs[n];
    }
};

int main() {
    Solution sol;
    int ret = 0;
    printf("n = 2, ret = %d\n", sol.climbStairs(2));
    printf("n = 3, ret = %d\n", sol.climbStairs(3));
    printf("n = 4, ret = %d\n", sol.climbStairs(4));
    printf("n = 45, ret = %d\n", sol.climbStairs(45));

}