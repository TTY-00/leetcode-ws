/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void count(TreeNode* pn, int* res){
        if(pn == NULL){
            res[0] = 0;
            res[1] = 0;
            return;
        }
        
        int l[2];
        count(pn->left, l);

        int r[2];
        count(pn->right, r);

        int r1 = pn->val + l[1] + r[1];
        
        int lm = (l[0] > l[1])?l[0]:l[1];
        int rm = (r[0] > r[1])?r[0]:r[1];
        int r2 = lm + rm;

        res[0] = r1;
        res[1] = r2;
    }

    int rob(TreeNode* root) {
        int rr[2];
        count(root, rr);
        int r = (rr[0] > rr[1])? rr[0]:rr[1];

        return r;
    }
};