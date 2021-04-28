#include <iostream>
#include <vector>
#include <algorithm>

//Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


using namespace std;
int countSquares(int matrix[3][4]) {
        int ans=0;
            for (int i=0; i<3; i++)
            {
                    for (int j=0; j<4; j++)
                    {
                         if (matrix[i][j]&&i&&j)
                            matrix[i][j]+=min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
                         ans+=matrix[i][j];
                    }
            }
            return ans;
}

int main()
{

    int matrix[3][4] = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};

    cout << countSquares(matrix);


    return 0;
};
