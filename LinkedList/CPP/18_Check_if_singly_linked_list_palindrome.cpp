
// To chek soln go to url : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        // If list has only one node
        if(head->next == NULL)
            return 1;
            
        Node *s,*f,*behindS;
        s = f = head;
        behindS = NULL;
        
        while(f && f->next)
        {
            behindS = s;
            s = s->next;
            f = f->next->next;
        }


        // If fast ptr is not null (i.e is on last node of list) that means length is odd.
        if(f != NULL)
        {
            Node *tempNode = new Node(s->data);
            behindS->next = tempNode;
        }
        else
        {
            behindS->next = NULL;
        }
        
        s = reverse_list_iterative(s);
        
        return compare2List(s,head);
    }
    
    bool compare2List(Node *n1, Node *n2)
    {
        Node *p,*q;
        p = n1;
        q = n2;
        
        while(p && q)
        {
            if(p->data != q->data)
                return 0;
            p = p->next;
            q = q->next;
        }
        
        return 1;
    }
    
    Node* reverse_list_iterative(Node *head)
    {
        Node *p,*q,*r;
        p = head;
        q = r = NULL;

        if(head == NULL)
        {
            return NULL;
        }


        while(p != NULL)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }

        head = q;
        return head;
    }
};
