// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // return head of list after adding one
        int carry = carryRet(head);
        
        if(carry>0)
        {
            Node *newNode = new Node(carry);
            newNode->next = head;
            return newNode;
        }
        
        return head;
    }
    
    // Utility function
    int carryRet(Node *head)
    {
        if(head == NULL)
            return 1;   // returned 1 bcoz we want to add 1 to last number in qn. If wanted to add 2 then return 2.
        
        int carry = head->data + carryRet(head->next);
        
        // We are taking unit digit after adding to genralize this. But as we know that our carry can at max be 1 or 9 here bcoz only one is added so we can
        // just check if carry is 1 then head->data = 0 and return 1 and if carry zero no change in head->data and return 0.
        head->data = carry % 10;
        return carry/10;
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends