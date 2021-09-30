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

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

   	// + Integers in each row are sorted from left to right.
	// + The first integer of each row is greater than the last integer of the previous row.

// Array, Binary Search, Matrix  

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();

    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else
            i++;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},
                                    {10,11,16,20},
                                    {23,30,34,60}};
    int target = 3;
    bool a;
    a = searchMatrix(matrix, target);
    cout << a << endl;
    return 0;
}
