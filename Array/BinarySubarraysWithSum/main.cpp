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

// Array, Sliding Windown, Prefix Sum

// Description: Given a binary array NUMS and an integer GOAL, return the number of non-empty subarrays with a sum goal.

//              A subarray is a contiguous part of the array.

// Example: Input: nums = [1,0,1,0,1], goal = 2
        //  Output: 4
        // Explanation: The 4 subarrays are bolded and underlined below:
                // [1,0,1,0,1]
                // [1,0,1,0,1]
                // [1,0,1,0,1]
                // [1,0,1,0,1]

class Solution {
public:
    int numSubarraysWithSum(const vector<int> &arr, int goal) {
        int left = 0, count = 0, n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            count += arr[i];
            while (left < i && count > goal)
                count -= arr[left++];
            if (count < goal)
                continue;
            if (count == goal)
                ans++;
            int t = left;
            while(t < i && arr[t] == 0) {
                t++, ans++;
            }
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << s.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
