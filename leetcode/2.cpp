#include<bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remain = 0;
        ListNode* ret = nullptr;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = nullptr;
        while(p1 != nullptr || p2 != nullptr || remain > 0){
            ListNode* node = new ListNode();
            if(ret == nullptr) {
                ret = node;
                p3 = ret;
            } else {
                p3->next = node;
                p3 = p3->next;
            }
            if((p1 == nullptr && p2 == nullptr)){
                p3->val = remain;
                remain = 0;
            }else{
                if(p1 != nullptr) {
                    remain += p1->val;
                    p1 = p1 -> next;
                }
                if(p2 != nullptr) {
                    remain += p2->val;
                    p2 = p2 -> next;
                }
                p3 -> val = remain%10;
                remain /= 10;
            }
        }
        return ret;
    }
};

int main(){

    Solution sol;
    ListNode n01(2),n02(4),n03(3);
    ListNode n11(5),n12(6),n13(4);
    ListNode* h1 = &n01;
    n01.next = &n02;
    n02.next = &n03;
    ListNode* h2 = &n11;
    n11.next = &n12;
    n12.next = &n13;

    ListNode* ret = sol.addTwoNumbers(h1,h2);
    cout<<ret->val<<endl;
    cout<<ret->next->val<<endl;
    cout<<ret->next->next->val<<endl;
    return 0;
}