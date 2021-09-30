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

//Given a string S and a dictionary of strings WordDict, return true if S can be segmented into a space-separated sequence of one or more dictionary words.

//Note that the same word in the dictionary may be reused multiple times in the segmentation.


bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for(auto c: wordDict)
        dict.insert(c);
    if(dict.size()==0)
        return false;

    vector<bool> dp(s.size()+1,false);
    dp[0]=true;

    for(int i=1;i<=s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j])
            {
                string word = s.substr(j,i-j);
                if(dict.find(word)!= dict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }

    return dp[s.size()];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict={"leet","code"};
    bool a;
    a = wordBreak(s, wordDict);
    cout << a << endl;
    return 0;
}
