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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using boolean variable is an only way to check the presence of listnode
        // since value of listnode exists for all value
        bool updated = false;
        ListNode* root = new ListNode();
        ListNode* temp = root;
        // sorted queue, lowest value is located at top
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        int i = 0;
        while(i < lists.size()) {
            if(!lists[i]) {
                i++;
                continue;
            }
            pq.push(lists[i]->val);
            lists[i] = lists[i]->next;
        }
        
        int size = pq.size() - 1;
        for(int i = 0; i < size; i++) {
            root->val = pq.top();
            pq.pop();
            root->next = new ListNode();
            root = root->next;
        }
            
        if(!pq.empty()) {
            root->val = pq.top();
            pq.pop();
            updated = true;
        }
        
        
        return updated? temp : nullptr;
    }
};