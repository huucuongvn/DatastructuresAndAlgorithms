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

//Description: Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

                    //1.Each row must contain the digits 1-9 without repetition.
                    //2.Each column must contain the digits 1-9 without repetition.
                    //3.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

bool isValidSudoku(vector<vector<char>>& board) {

//check for each row 1-9
    for(int i=0; i<board.size(); i++)
    {
        vector<int> rtemp(10,0);
        for(int j=0; j < board[0].size(); j++)
        {
            if('1' <= board[i][j] && board[i][j] <= '9')
                rtemp[board[i][j]-'0']++;
        }

        for(int k=1; k<10; k++)
        {
            if(rtemp[k] > 1)
                return false;
        }
    }

//check for each column 1-9

    for(int i=0; i<board[0].size(); i++)
    {
        vector<int> ctemp(10,0);
        for(int j=0; j<board.size(); j++)
        {
            if('1' <= board[j][i] && board[j][i] <= '9')
                ctemp[board[j][i]-'0']++;
        }

        for(int k=1; k<10; k++)
        {
            if(ctemp[k] > 1)
                return false;
        }
    }

//check for box 3x3

    for(int i=0; i<9; i+=3)
    {
        for(int j=0; j<9; j+=3)
        {
            vector<int> btemp(10,0);
            for(int k=i; k<i+3; k++)
            {
                for(int l=j; l<j+3; l++)
                {
                    if('1' <= board[k][l] && board[k][l] <= '9')
                        btemp[board[k][l]-'0']++;
                }
            }

            for(int m=1; m<10; m++)
            {
                if(btemp[m] > 1)
                    return false;
            }
        }
    }
    return true;
}


int main()
{
    char *temp[9][9] = {{"5","3",".",".","7",".",".",".","."}
                    ,{"6",".",".","1","9","5",".",".","."}
                    ,{".","9","8",".",".",".",".","6","."}
                    ,{"8",".",".",".","6",".",".",".","3"}
                    ,{"4",".",".","8",".","3",".",".","1"}
                    ,{"7",".",".",".","2",".",".",".","6"}
                    ,{".","6",".",".",".",".","2","8","."}
                    ,{".",".",".","4","1","9",".",".","5"}
                    ,{".",".",".",".","8",".",".","7","9"}};

    cout << isValidSudoku(temp);
    return 0;
}
