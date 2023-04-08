#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        
        ListNode *head = new ListNode();
        ListNode *q = head;
        for(auto& node : lists) pq.push(node);

        while(!pq.empty()){
            ListNode *p = pq.top(); pq.pop();
            q->next = p;
            q = q->next;
            if(q != nullptr) pq.push(q->next);
        }
        return head->next;
    }
};

int main(){

    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(1);
    ListNode* l21 = new ListNode(5);
    l2->next = l21;
    lists.push_back(l1);
    lists.push_back(l2);
    Solution sl;
    ListNode* ret = sl.mergeKLists(lists);
}
