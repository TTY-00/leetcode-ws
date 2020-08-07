/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void swap_adj(ListNode* b, ListNode* p, ListNode* q){
        if(b) b->next = q;
        p->next = q->next;
        q->next = p;
    }

    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode* b = NULL;
        ListNode* p = head;
        ListNode* hh = head->next;

        while(p && p->next){
            swap_adj(b, p, p->next);
            b = p;
            p = p->next;
        }

        return hh;
    }
};


void gen_list(int* l, int len, ListNode* &h){
    h = new ListNode(l[0]);
    ListNode* p = h;

    for(int i = 1; i < len; i++){
        p->next = new ListNode(l[i]);
        p = p->next;
    }
}

int main(){
    ListNode* h;
    int l[4] = {1,2,3,4};
    gen_list(l, 4, h);


    Solution sol;
    ListNode* n = sol.swapPairs(h);

    while(n){
        cout << n->val << " ";
        n = n->next;
        // sleep(1)
    }
    return 0;
}