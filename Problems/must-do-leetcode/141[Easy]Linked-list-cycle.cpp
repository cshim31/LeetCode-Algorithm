/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // note : valid linked list do not share repeated values
    //      : values of list shouldn't be saved
    bool hasCycle(ListNode *head) {
        if(!head) return false;
    // solve problem by comparing node
        ListNode *oneMove = head;
        ListNode *secondMove = head;
        
        while(secondMove -> next != NULL && secondMove->next-> next != NULL) {
            oneMove = oneMove->next;
            secondMove = secondMove->next->next;
            if(oneMove == secondMove) return true;
        }
        
        return false;
    }
};