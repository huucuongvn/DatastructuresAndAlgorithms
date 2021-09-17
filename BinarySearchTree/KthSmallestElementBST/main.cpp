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


//Given the ROOT of a binary search tree, and an integer K, return the Kth (1-indexed) smallest element in the tree.
//in-order traversal. 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insert(TreeNode* root, int x)
{
    if (root == NULL)
        return new TreeNode(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);
    return root;
}

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &temp){
        if(!root)
            return;
        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right,temp);

    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        vector<int> temp;
        inorder(root, temp);
        return temp[k-1];
    }
};

int main()
{
    Solution s;
    TreeNode* t = NULL;
    int keys[] = {3,1,4,NULL,2};

    for (int x : keys)
        t = insert(t, x);
    cout << s.kthSmallest(t, 1);

    return 0;
}
