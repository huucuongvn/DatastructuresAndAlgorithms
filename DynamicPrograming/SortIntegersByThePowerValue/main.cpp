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

// Description:
        //  The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
                // + if x is even then x = x / 2
                // + if x is odd then x = 3 * x + 1
        //  For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
        //
        //  Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, 
	     //if two or more integers have the same power value sort them by ascending order.
        //
        //  Return the k-th integer in the range [lo, hi] sorted by the power value.
        //
        //  Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.
        //
        //

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<vector<int>> temp;
        for(int i=lo; i<=hi; i++) {
            temp.push_back({power(i),i});
        }
        sort(temp.begin(),temp.end());
        return temp[k-1][1];
    }

    int power(int i) {
        int count=0;
        while(i!=1) {
            if(i%2==0) {
                i /= 2;
            }
            else {
                i = 3*i+1;
            }
            count++;
        }
        return count;
    }
};


int main()
{
    Solution s;
    int lo = 12, hi = 15, k = 2;
    cout << s.getKth(12,15,2) << endl;
    return 0;
}


// Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
// The power of 13 is 9
// The power of 14 is 17
// The power of 15 is 17
// The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
// Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
