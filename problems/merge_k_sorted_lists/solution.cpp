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

/* scratch:
while (lists have values) {
    i = minHead(lists);
    next = lists[i]
    lists[i] = lists[i]->next;
    if (!head) {
        // 1st iteration
        head = next;
        tail = head;
    } else {
        tail->next = next;
        tail = next;
    }
}

Time: O(nk)
Space O(1)
-----------------
better: use min priority queue

Time: O(log (nk))
Space: O(nk)

*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *tail = nullptr;
        auto cmp = [&lists](int a, int b) {
            return lists[a]->val > lists[b]->val;
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int i = 0;
        int k = lists.size();
        for (int i = 0; i < k; ++i)
            if (lists[i])
                q.push(i);
        while (!q.empty()) {
            int i = q.top(); q.pop();
            ListNode *next = lists[i];
            lists[i] = next->next;
            if (lists[i])
                q.push(i);
            if (!head) {
                head = next;
                tail = head;
            } else {
                tail->next = next;
                tail = next;
            }
        }
        return head;
    }
};