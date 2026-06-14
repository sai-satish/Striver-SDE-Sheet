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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }
        if (length == 0) {
            return head;
        }
        k = k % length;
        if (k == 0) {
            return head;
        }
        ListNode* tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = nullptr;
        ListNode* newTail = newHead;
        while (newTail->next) {
            newTail = newTail->next;
        }
        newTail->next = head;
        return newHead;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;
    
    ListNode* result = sol.rotateRight(head, k);
    
    cout << "Rotated linked list: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}