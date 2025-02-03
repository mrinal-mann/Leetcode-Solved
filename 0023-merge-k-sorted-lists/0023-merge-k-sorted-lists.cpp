class Solution {
public:
    struct comp {
        bool operator()(ListNode * a, ListNode * b) {
            if (b == nullptr) return a;
            if (a == nullptr) return b;
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;
        for (ListNode* item: lists) {
            if (item == nullptr) continue;
            pq.push(item);
        } 

        ListNode * head = new ListNode(-1);
        ListNode *tail = head;
        while (!pq.empty()) {
            ListNode *cur = pq.top(); 
            pq.pop();
            if (cur == nullptr) continue;
            if (cur -> next)
                pq.push(cur -> next);

            tail -> next = cur;
            tail = tail -> next;
            
        }
        return head -> next;
    }
};