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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = head;
        stack<ListNode*> stk;
        int size = 0;
        while(root != NULL) {
            size++;
            stk.push(root);
            root = root -> next;
        }
        
        n = size - n;
        
        // exception
        if(n <= 0) return head->next;
        
        ListNode* prev = NULL;
        // return to previous node until it reaches the node before removing node
        while(size > n) {
            if(size - n == 1) prev = root;
            root = stk.top();
            stk.pop();
            size--;
        }
        delete root;
        
        root = stk.top();
        stk.pop();
        root->next = prev;
        
        return head;
    }
};