#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

// To check soln submit at url : https://practice.geeksforgeeks.org/problems/circular-linked-list/1

bool isCircular(Node *head)
{
   if(head == NULL)
        return 1;
    
    Node *p = head->next;
    
    while(p!=NULL && p!=head)
        p = p->next;
    
    if(p == head)
        return 1;
    return 0;
}
