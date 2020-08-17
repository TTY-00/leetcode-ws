#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int tmp = 1;

    int get_tree_d(TreeNode* root){
        int d_left;
        int d_right;

        if(root == NULL) return 0;

        d_left = get_tree_d(root->left);
        d_right = get_tree_d(root->right);

        if(abs(d_left - d_right) > 1) {
            tmp = -1;
        }

        return (d_left > d_right)? d_left + 1: d_right + 1;

    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        get_tree_d(root);
        
        if(tmp == -1) return false;
        else return true;
    }
};

int main(){
    Solution sol;
    struct TreeNode root(0);
    sol.isBalanced(&root);

    return 0;
}