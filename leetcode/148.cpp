#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // cout<<"==="<<endl;        
        // cout<<"entry= "<<head->val<<endl; // 4->2->1->3
        // for(ListNode* p = head; p != NULL; p = p->next) cout<<p->val<<" ";
        // cout<<endl;

        if(head -> next == NULL) return head;
        
        ListNode*p1, *p2, *t;
        int cnt = 1;
        for(cnt = 0, p2 = head; p2 != NULL; p2 = p2->next) cnt++;
        for(cnt = cnt/2 - 1, p1 = head; cnt > 0; cnt--) p1 = p1->next;
        
        p2 = p1->next;
        p1->next = NULL;

        // exit(0);
        
        p1 = sortList(head);
        p2 = sortList(p2);
        
        // cout<<"---"<<endl;
        // cout<<"p1= ";
        // for(ListNode* p = p1; p != NULL; p = p->next) cout<<p->val<<" ";
        // cout<<endl;
        // cout<<"p2= ";
        // for(ListNode* p = p2; p != NULL; p = p->next) cout<<p->val<<" ";
        // cout<<endl;
        
        if(p1->val < p2->val) t = p1, p1 = p1->next;
        else t = p2, p2 = p2->next;
        t->next = NULL;
        head = t;
        // cout<<"t->val= "<<t->val<<" "<<(p1 == NULL)<<" "<<(p2 == NULL)<<endl;
        
        for(; p1 != NULL || p2 != NULL; t = t->next){
            if(p1 == NULL || (p1!=NULL && p2!=NULL) && p1->val >= p2->val){
                t->next = p2, p2 = p2->next;
            } else if(p2 == NULL ||  (p1!=NULL && p2!=NULL) && p1->val < p2->val){
                t->next = p1, p1 = p1->next;
            }
        }
        // cout<<"+++"<<endl;
        return head;
    }
};

int main(){
    Solution sl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(-1);

    ListNode* head = n4;
    n4->next = n2;
    n2->next = n1;
    n1->next = n3;
    n3->next = n5;

    ListNode* ret = sl.sortList(head);
    for(ListNode* p = ret; p != NULL; p = p->next)
        cout<<p->val<<" ";
    cout<<endl;
}
