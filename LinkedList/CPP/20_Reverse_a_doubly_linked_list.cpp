struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};



// To check soln visit url : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
Node* reverseDLL(Node * head)
{
    Node *t,*curr;
    curr = head;
    t = NULL;
    
    while(curr != NULL)
    {
        t = curr->prev;
        curr->prev = curr->next;
        curr->next = t;            
        curr = curr->prev;
    }
    
    if(t != NULL)
    {
        head = t->prev;
    }
    
    return head;
}
