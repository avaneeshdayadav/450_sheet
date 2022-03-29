#include<bits/stdc++.h>
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

// To check this soln visit to https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *slow,*fast,*fast_follower = NULL;
        int flag = 0;
        slow = fast = head;
    
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
    
            if(slow == fast)
            {
                flag = 1;
                break;
            }
        }
    
        if(flag == 1)
        {
            // i.e if slow == fast == head
            if(slow == head)
            {
                while(fast->next != slow)
                    fast = fast->next;
                fast->next = NULL;
            }
            else
            {
                slow = head;
                while(slow != fast)
                {
                    slow = slow->next;
                    fast_follower = fast;
                    fast = fast->next;
                }
        
                fast_follower->next = NULL;                
            }
                
        }
    }
};
