/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *h=head;
        unordered_map<Node*,Node*> map;
        while(h!=NULL)
        {
            map[h]=new Node(h->val);
            h=h->next;
        }
        h=head;
        while(h!=NULL)
        {
            map[h]->next   = map[h->next];
            map[h]->random = map[h->random];
            h=h->next;
        }
        return map[head];
    }
};
