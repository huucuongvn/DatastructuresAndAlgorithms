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

// Two Pointers, String, Greedy.

// Descriptions:   You are given a string 'num', representing a large integer, and an integer 'k'.
                // We call some integer 'wonderful' if it is a permutation of the digits in 'num' and is greater in value than 'num'.
                // There can be many wonderful integers. However, we only care about the smallest-valued ones.
                // For example, when num = "5489355142":
                        // The 1st smallest wonderful integer is "5489355214".
                        // The 2nd smallest wonderful integer is "5489355241".
                        // The 3rd smallest wonderful integer is "5489355412".
                        // The 4th smallest wonderful integer is "5489355421".

                // Return the minimum number of adjacent digit swaps that needs to be applied to 'num' to reach the kth smallest wonderful integer.
                // The tests are generated in such a way that kth smallest wonderful integer exists.


class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp = num;
        int ans=0;
        for(int i=0; i<k; i++) {
            next_permutation(num.begin(), num.end());
        }
        int i=0, j=0;
        while(i < num.size()) {
            j=i;
            while(temp[j] != num[i])
                j++;
            while(i<j) {
                swap(temp[j], temp[j-1]);
                j--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};

// Example:
// Input: num = "5489355142", k = 4
// Output: 2
// Explanation: The 4th smallest wonderful number is "5489355421". To get this number:
// - Swap index 7 with index 8: "5489355142" -> "5489355412"
// - Swap index 8 with index 9: "5489355412" -> "5489355421"


int main()
{
    string num = "5489355142";
    int k=4;
    Solution s;
    cout << s.getMinSwaps(num, k) << endl;
    return 0;
}
