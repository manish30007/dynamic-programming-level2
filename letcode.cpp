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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode*t=head;
        int ct=0;
        while(t->next){
        ct++;
        t=t->next;
        }
        int nct=ct-k;
        ListNode*x=head;
         ListNode*y=head;
        for(int i=0;i<nct;i++){
            x=x->next;
}
        y=x->next;
        x->next=NULL;
        t->next=head;
        return y;
    }
};