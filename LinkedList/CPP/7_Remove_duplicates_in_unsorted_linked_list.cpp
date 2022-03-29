#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

// To check soln submit at url : https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,int> mp;
        
        if(head == NULL || head->next == NULL)
            return head;
            
        mp[head->data] = 1;
        
        Node *p = head->next;
        Node *q = head;
        
        
        while(p != NULL)
        {
           if(mp.find(p->data) == mp.end())
           {
               mp[p->data] = 1;
               q = p;
               p = p->next;
           }
           else
           {
               q->next = p->next;
               p = p->next;
           }
        }

        return head;
    }
};
