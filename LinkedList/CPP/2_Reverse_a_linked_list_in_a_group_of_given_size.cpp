#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};



// To check soln submit at url : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
class Solution
{
    public:
    Node *reverse (Node *head, int k)
    { 
        if(head == NULL)
            return NULL;
        
        Node *p,*q,*r;
        p = head;
        q = r = NULL;
        int count =0;

        while(p != NULL && count < k)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }

        if(p != NULL)
            head->next = reverse(p,k);
        
        return r;
    }
};