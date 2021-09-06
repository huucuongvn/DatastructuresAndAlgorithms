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
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include<bits/stdc++.h>

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// The algorithm run in O(n) time.
// Related topics : array, hash table, union find


using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size()==0)
        return 0;
    unordered_set<int> record(nums.begin(),nums.end());
    int ans = 1;
    for(int n : nums){
        if(record.find(n)==record.end())
            continue;
        record.erase(n);
        int prev = n-1,next = n+1;
        while(record.find(prev) != record.end())
            record.erase(prev--);
        while(record.find(next) != record.end())
            record.erase(next++);
        ans = max(ans,next-prev-1);
    }
    return ans;
}

int main()
{
    vector<int> temp={0,3,7,2,5,8,4,6,0,1};
    int n=longestConsecutive(temp);

    cout << n << endl;
    return 0;
}
