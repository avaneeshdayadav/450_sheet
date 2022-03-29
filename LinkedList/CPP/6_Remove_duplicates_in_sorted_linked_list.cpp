#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

};

// To check soln submit at url : https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1
Node *removeDuplicates(Node *head)
{

    if(head == NULL || head->next == NULL)
        return head;
    
    Node *p = head;

    while(p->next != NULL)
    {
        if(p->data == p->next->data)
            p->next = p->next->next;
        else
            p = p->next;

    }
    return head;
    
}