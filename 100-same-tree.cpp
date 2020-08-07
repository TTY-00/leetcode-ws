/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool walk_two_tree(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;

        if(p && q){
            // cout << "qx: " << qx << " px: " << px << endl;
            if(p->val != q->val) return false;

            bool same_r = walk_two_tree(p->right, q->right);
            bool same_l = walk_two_tree(p->left, q->left);

            return same_r && same_l;
        }
        else{
            return false;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return walk_two_tree(p, q);
    }
};