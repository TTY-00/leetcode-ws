/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* p = head;
        ListNode* p2 = head;
        ListNode* pp = p;

        while(p2 != NULL && p2->next != NULL){
            pp = p;
            p = p->next;
            p2 = p2->next->next;
        }

        TreeNode* tn = new TreeNode(p->val);
        tn->right = sortedListToBST(p->next);
        pp->next = NULL;
        tn->left = sortedListToBST(head);

        return tn;
    }
};

int main(){
    Solution sol;


    int val[5] = {-10, -3, 0, 5, 9};
    ListNode* head = new ListNode(val[0]);
    ListNode* p = head;

    for(int i = 1; i < 5; i++){
        p->next = new ListNode(val[i]);
        p = p->next;
    }

    sol.sortedListToBST(head);

    return 0;
}