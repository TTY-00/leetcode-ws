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

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

class Solution {
public:
    int tl[10000] = {0};
    int sl[10000] = {0};
    int max_i = 0;
    int tree_deep = 0;

    void walk_tree(int* tl, TreeNode* root, int i){
        if(root != NULL){
            if(i > max_i) max_i = i;

            tl[i] = root->val;
            walk_tree(tl, root->left, i * 2 + 1);
            walk_tree(tl, root->right, i * 2 + 2);
        }else{
            tl[i] = 0;
        }
    }

    void count_sl(int i){
        // if(i > 2 ** (tree_deep - 2) ){
        //     sl[i] = tl[i];
        // }else{

        if(i <= max_i){
            int m1 = sl[(i * 2 + 1) * 2 + 1] +  sl[(i * 2 + 1) * 2 + 2] + sl[(i * 2 + 2) * 2 + 1] +  sl[(i * 2 + 2) * 2 + 2] + tl[i];
            int m2 = sl[i * 2 + 1] + sl[i * 2 + 2];

            if(m2 > m1) m1 = m2;
            sl[i] = m1;
        }
    }

    int count_2(TreeNode* root){
        if(root == NULL) return 0;

        int left_m = 0;
        int left_mm = 0;

        int right_m = 0;
        int right_mm = 0;


        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if(l != NULL){
            left_m = count_2(l);
            left_mm = count_2(l->left) + count_2(l->right);
        }
        
        if(r != NULL){
            right_m = count_2(r);
            right_mm = count_2(r->left) + count_2(r->right);
        }

        int m1 = root->val + left_mm + right_mm;
        int m2 = left_m + right_m;

        // printf("%d %d\n", m1, m2);

        return (m1 > m2) ? m1 : m2;
    }

    void count_3(TreeNode* pn, int* res){
        if(pn == NULL){
            res[0] = 0;
            res[1] = 0;
            return;
        }
        
        int l[2];
        count_3(pn->left, l);

        int r[2];
        count_3(pn->right, r);

        int r1 = pn->val + l[1] + r[1];
        
        int lm = (l[0] > l[1])?l[0]:l[1];
        int rm = (r[0] > r[1])?r[0]:r[1];
        int r2 = lm + rm;

        res[0] = r1;
        res[1] = r2;
        // printf("\nn: %d %d %d %d", l[0], l[1], r[0], r[1]);
        // printf("\nmax: %d %d", res[0], res[1]);
    }

    int rob(TreeNode* root) {
        // walk_tree(tl, root, 0);

        // printf("\ntl: ");
        // for(int i = 0; i <= max_i; i++){
        //     printf("%d ", tl[i]);
        // }

        // for(int i = max_i; i >= 0; i--){
        //     count_sl_2(i);
        // }

        // printf("\nsl: ");
        // for(int i = 0; i <= max_i; i++){
        //     printf("%d ", sl[i]);
        // }
        int rr[2];
        count_3(root, rr);
        int r = (rr[0] > rr[1])? rr[0]:rr[1];

        printf("\nmax: %d %d", rr[0], rr[1]);
        return r;
    }
};



TreeNode* walk_tree2(int* value, int i, int size){
    // TreeNode n(value[i]);

    if(value[i] == -1){return NULL;}
    TreeNode* pr = new TreeNode(value[i]);

    if (i < size / 2){
        pr->left = walk_tree2(value, i * 2 + 1, size);
        pr->right =  walk_tree2(value, i * 2 + 2, size);
    }

    return pr;
}

TreeNode* gen_treenode(){
    // int a[15] = {0,1,2,3,-1,5,6,7,8,-1,-1,11,12,13,14};
    // int a[8] = {4,1,-1,2,-1, -1, -1,3};
    int a[7] = {3, 2, 3, -1, 3, -1, 1};
    
    int len = sizeof(a) / sizeof(a[0]);

    return walk_tree2(a, 0, len);
}

TreeNode* pn;
int main(){
    Solution sl;
    TreeNode* pn = gen_treenode();
    sl.rob(pn);
    return 0;
}


// void walk_tree2(int* value, TreeNode* pr, int i, int size){
//     // TreeNode n(value[i]);
//     pr = new TreeNode(value[i]);

//     printf("[] i %d\n", i);
//     if (i * 2 + 2 < size){
//         walk_tree2(value, pr->left, i * 2 + 1, size);
//         walk_tree2(value, pr->right, i * 2 + 2, size);
//     }
// }