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

//Given an m x n integer matrix MAXTRIX, if an element is 0, set its entire row and column to 0's, and return the matrix.

//You must do it in place.

//array, hash table, maxtrix.

void setZeroes(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    set<int> row;
    set<int> col;

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(matrix[i][j] == 0) {
            row.insert(i);
            col.insert(j);
        }
      }
    }

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(row.count(i) || col.count(j)) {
          matrix[i][j] = 0;
        }
      }
    }
}

int main()
{
    vector<vector<int>> m = {{1,1,1},
                            {1,0,1},
                            {1,1,1}};
    setZeroes(m);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << endl;
        }
    }
    return 0;
}
