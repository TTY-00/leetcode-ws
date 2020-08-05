/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
#include <memory.h>

class Solution1 {
public:
    int count(TreeNode* root){
        if(root == NULL) return 0;

        int left_m = 0;
        int left_mm = 0;

        int right_m = 0;
        int right_mm = 0;


        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if(l != NULL){
            left_m = count(l);
            left_mm = count(l->left) + count(l->right);
        }
        
        if(r != NULL){
            right_m = count(r);
            right_mm = count(r->left) + count(r->right);
        }

        int m1 = root->val + left_mm + right_mm;
        int m2 = left_m + right_m;


        return (m1 > m2) ? m1 : m2;
    }

    int rob(TreeNode* root) {
        int r = count(root);

        return r;
    }
};


class Solution {
public:

    array<int , 2> fac(TreeNode * root)
    {
        if(!root)
        {
            array<int , 2> p = {0,0};
            return p;
        }
        array<int , 2>  l = fac(root->left) , r = fac(root->right)  , s;
        s[0] = max(l[0] , l[1]) + max(r[0] , r[1]);
        s[1] = root->val + l[0] + r[0];
        return s;
    }

    int rob(TreeNode* root) {
        array<int , 2> a = fac(root);
        return max(a[0] , a[1]);
    }
};