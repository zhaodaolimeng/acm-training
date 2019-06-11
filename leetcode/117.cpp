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

        Node* h = root, *p, *t; 
        // h是每一层的第一个，p记录“搭桥”的位置，t记录“桥头”

        while(h->left != NULL || h->right != NULL || h->next != NULL){
            
            for(p = h; p->next != NULL; p = p->next){
                cout<<p->val<<endl;
                if(p->left != NULL || p->right != NULL){
                    if(p->left != NULL && p->right != NULL)
                        p->left->next = p->right;
                    if(p->right != NULL)
                        t = p->right;
                    else if(p->left != NULL) t = p->left;
                    else continue;
                }
                if(p->next->left != NULL)
                    t->next = p->next->left;
                else {
                    if(p->next->right != NULL)
                        t->next = p->next->right;
                    else t->next = NULL;
                }
            }
            if(h->left != NULL) h = h->left;
            else if(h->right != NULL) h = h->right;
            else h = h->next;
        }
        return root;
    }
};

int main(){

    Solution sl;

    Node* na[7];
    na[6] = Node(7, NULL, NULL, NULL);
    na[5] = Node(3, NULL, na[6], NULL);
    na[3] = Node(4, NULL, NULL, NULL);
    na[4] = Node(5, NULL, NULL, NULL);
    na[2] = Node(2, na[3], na[4], NULL);
    na[1] = Node(1, na[2], na[5], NULL);
    sl.connect(na[1]);
}
