Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// To check soln go to url : https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head == NULL || head->next == NULL)
            return head;
            
        int zeroCount = 0, oneCount = 0, twoCount = 0;
        
        Node *trav = head;
        
        while(trav)
        {
            if(trav->data == 0)
                zeroCount++;
            else if(trav->data == 1)
                oneCount++;
            else
                twoCount++;
            trav = trav->next;
        }

        trav = head;
        
        while(trav)
        {
            if(zeroCount > 0)
            {
                trav->data = 0;
                zeroCount--;
            }
            else if(oneCount > 0)
            {
                trav->data = 1;
                oneCount--;
            }
            else if(twoCount > 0)
            {
                trav->data = 2;
                twoCount--;
            }
            trav = trav->next;
        }
        
        return head;
        
    }
};
