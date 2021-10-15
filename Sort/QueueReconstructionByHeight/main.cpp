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
// Sorting, Greedy, Array

// Description: You are given an array of people, PEOPLE, which are the attributes of some people in a queue (not necessarily in order).
// Each PEOPLE[i] = [hi, ki] represents the ith person of height HI with exactly KI other people in front who have a height greater than or equal to HI.

// Reconstruct and return the queue that is represented by the input array PEOPLE.
// The returned queue should be formatted as an array QUEUE, where QUEUE[j] = [hj, kj] is the attributes of the jth person in the queue (QUEUE[0] is the person at the front of the queue).

// Example:
        // Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        // Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        // Explanation: Person 0 has height 5 with no other people taller or the same height in front.
                     // Person 1 has height 7 with no other people taller or the same height in front.
                    //  Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
                    //  Person 3 has height 6 with one person taller or the same height in front, which is person 1.
                    //  Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
                    //  Person 5 has height 7 with one person taller or the same height in front, which is person 1.
                    //  Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [] (vector<int> &a, vector<int> &b) { // Lambda expressions
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> ans;
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] == ans.size()) {
                ans.push_back(people[i]);
            } else {
                ans.insert(ans.begin() + people[i][1], people[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans;
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    ans = s.reconstructQueue(people);
    for(int i=0; i< ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
