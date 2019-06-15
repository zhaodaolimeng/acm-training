#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node* head = root, *p, *h, *t;

        while(head->left != NULL || head->right != NULL || head->next != NULL){

            for(p = head, t = NULL; p != NULL; p = p->next){
                if(p->left != NULL && p->right != NULL) p->left->next = p->right;

                if(t != NULL){
                    if(p->left != NULL) t->next = p->left;
                    else if(p->right != NULL) t->next = p->right;
                }

                if(p->left != NULL && p->left->next == NULL)
                    t = p->left;
                if(p->right != NULL && p->right->next == NULL)
                    t = p->right;
            }

            if(head->left != NULL) head = head->left;
            else if(head->right != NULL) head = head->right;
            else head = head->next;
        }
        return root;
    }
};

int main(){

    Solution sl;

    // Node* na[7];
    // na[6] = new Node(6, NULL, NULL, NULL);
    // na[5] = new Node(5, NULL, na[6], NULL);
    // na[3] = new Node(3, NULL, NULL, NULL);
    // na[4] = new Node(4, NULL, NULL, NULL);
    // na[2] = new Node(2, na[3], na[4], NULL);
    // na[1] = new Node(1, na[2], na[5], NULL);

    Node* na[8];
    na[7] = new Node(7, NULL, NULL, NULL);
    na[6] = new Node(6, NULL, NULL, NULL);
    na[5] = new Node(5, na[7], NULL, NULL);
    na[3] = new Node(3, NULL, na[5], NULL);
    na[4] = new Node(4, na[6], NULL, NULL);
    na[2] = new Node(2, NULL, na[4], NULL);
    na[1] = new Node(1, na[2], na[3], NULL);

    cout<<"init"<<endl;
    sl.connect(na[1]);
    cout<<"======================"<<endl;
    for(int i=1; i<sizeof(na)/sizeof(na[0]); i++){
        cout<<i<<" ";
        if(na[i]->next == NULL) cout<<"NULL"<<endl;
        else cout<<na[i]->next->val<<endl;
    }
}
