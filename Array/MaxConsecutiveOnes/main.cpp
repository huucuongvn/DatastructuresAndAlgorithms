#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;

// Description: Given a binary array NUMS and an integer K, return the maximum number of consecutive 1's in the array if you can flip at most K 0's.

    // Example: Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
            //  Output: 10
// Explanation: [0,0,1,1,[1],[1],1,1,1,[1],1,1,0,0,0,1,1,1,1]

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0, i=0;
        int ans = 0;
        for(int j = 0 ; j < nums.size() ; j++) {
            if(nums[j] == 0)
                count++;
            while(count > k) {
                if(nums[i] == 0)
                    count--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout << s.longestOnes(nums,k) << endl;
    return 0;
}
