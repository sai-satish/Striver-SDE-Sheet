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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};

int main() {
    Solution sol;
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* intersection = new ListNode(8);
    headA->next->next = intersection;
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);
    
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;
    
    ListNode* result = sol.getIntersectionNode(headA, headB);
    
    if (result) {
        cout << "Intersection at node with value: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }
    
    return 0;
}