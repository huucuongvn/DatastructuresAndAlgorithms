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

    // String, Backtracking

    // Description: You have n  TILES, where each tile has one letter TILES[i] printed on it.
                // Return the number of possible non-empty sequences of letters you can make using the letters printed on those TILES.

    // Input: tiles = "AAB"
    // Output: 8
    // Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

    // Constraints:
        //  1 <= tiles.length <= 7
        //  TILES consists of uppercase English letters.

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int counts[26] {};
        for (auto c :  tiles) {
            counts[c - 'A']++;
        }
        int ans = 0;
        recursion(counts, ans);
        return ans;
    }
    void recursion(int counts[26], int &ans) {
        for(int i = 0; i < 26; i++) {
            if (counts[i]){
                counts[i]--;
                ans++;
                recursion(counts, ans);
                counts[i]++;
            }
        }
    }
};

int main()
{
    Solution s;
    string tiles = "AAB";
    cout << s.numTilePossibilities(tiles) << endl;
    return 0;
}
