include<iostream>
include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Using hashing...See another approaches on gfg.
// To check soln go to url : https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#
int intersectPoint(Node* head1, Node* head2)
{
    unordered_set<Node*> hs;
    while (head1 != NULL) {
        hs.insert(head1);
        head1 = head1->next;
    }
    while (head2)
    {
        if (hs.find(head2) != hs.end()) {
            return head2->data;
        }
        head2 = head2->next;
    }
}
