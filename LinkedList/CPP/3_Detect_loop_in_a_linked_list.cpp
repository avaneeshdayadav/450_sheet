#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Check soln on https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1#
class Solution
{
    public:
    bool detectLoop(Node* head)
    {
        Node * s,*f;
        
        s = f = head;
        
        while(s && f && f->next)
        {
            s = s->next;
            f = f->next->next;
            
            if(s == f)
                return true;
            
        }
        return false;
    }
};

