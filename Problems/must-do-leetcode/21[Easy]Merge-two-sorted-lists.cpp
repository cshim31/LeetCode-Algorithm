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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // exception
        if(!l1 && !l2) return nullptr;
        
        ListNode* l3 = new ListNode();
        ListNode* root = l3;
        // compare and insert
        while(l1 && l2) {
            if(l1->val > l2->val) {
                l3->val = l2->val;
                l2 = l2->next;
            }
            
            else {
                l3->val = l1->val;
                l1 = l1->next;
            }
            
            l3->next = new ListNode();
            l3 = l3 -> next;
        }
        
        // copy the remaining
        while(l1) {
            l3->val = l1->val;
            l1 = l1 -> next;
            if(l1) l3->next = new ListNode();
            l3 = l3 -> next;
        }
        
        while(l2) {
            l3->val = l2->val;
            l2 = l2 -> next;
            if(l2) l3->next = new ListNode();
            l3 = l3 -> next;
        }
    
        return root;
    }
};