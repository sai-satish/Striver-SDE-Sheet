#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> nodeMap;
        Node* curr = head;
        
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        return nodeMap[head];
    }
};


int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    Node* result = sol.copyRandomList(head);
    
    cout << "Copied linked list: ";
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}