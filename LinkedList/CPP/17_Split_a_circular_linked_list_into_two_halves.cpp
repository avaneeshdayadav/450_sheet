#include<bits/stdc++.h>
using namespace std;


// To check soln go to url : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *f,*s;
    f = s = head;
    
    while(f->next->next != head && f->next != head)
    {
        f = f->next->next;
        s = s->next;
    }
    
    *head1_ref = head;
    *head2_ref = s->next;
    
    Node *end = *head2_ref;

    while(end->next != head)
        end = end->next;

    end->next = *head2_ref;
    
    s->next = head;

}
