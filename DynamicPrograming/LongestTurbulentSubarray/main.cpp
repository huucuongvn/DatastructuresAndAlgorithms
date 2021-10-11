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

// Dynamic Programing, Sliding Window

// Description

// Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

// A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

// More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

    // For i <= k < j:
        // + arr[k] > arr[k + 1] when k is odd, and
        // + arr[k] < arr[k + 1] when k is even.
    // Or, for i <= k < j:
        // + arr[k] > arr[k + 1] when k is even, and
        // + arr[k] < arr[k + 1] when k is odd.
// Example : arr = [9,4,2,10,7,8,8,1,9]
            // arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
    // output: 5

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int increase = 1; int decrease = 1; int ans = 1;
        for(int i=0; i < arr.size()-1; i++){
            if(arr[i] > arr[i+1]){
                increase = decrease + 1;
                decrease = 1;
            }
            else if(arr[i] < arr[i+1]){
                decrease = increase + 1;
                increase = 1;
            }
            else{
                increase = 1;
                decrease = 1;
            }
            ans = max(ans, max(increase, decrease));
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {9,4,2,10,7,8,8,1,9};
    Solution s;
    cout << s.maxTurbulenceSize(arr) << endl;
    return 0;
}
