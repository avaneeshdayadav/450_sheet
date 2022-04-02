struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// To check soln go to url : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
    
    if(head == NULL)
    {
        // cout<<"Head NULL"<<endl;
        return -1;
    }
        
    
    if(head->next == NULL)
    {
        if(n>1);
        {
            // cout<<"head next null"<<endl;
            return -1;
        }
        return head->data;
    }
    
    int count = 1;
    Node *first = head;
    Node *second = head;
    
    while(count < n)
    {
        // If first ptr crossed last node and count still not reached n means n > no.of nodes
        if(first == NULL && count<n)
        {
            return -1;
        }
        first = first->next;
        count++;
    }
    
    // Check wheather fist pointer crossed last node. e.g Case when nodes=9 and n=10
    if(first == NULL)
        return -1;
        
    while(first->next != NULL)
    {
        second = second->next;
        first = first->next;
    }
    // cout<<first->data<<endl;
    return second->data;
       
}

