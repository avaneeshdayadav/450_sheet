
// To check soln go to url : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
class Solution
{
    public:
    //Function to add two numbers represented by linked list.

    struct Node* reverseList(struct Node *head)
    {
        Node *p,*q,*r;
        p = head;
        q = r = NULL;

        if(head == NULL)
            return NULL;

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
    
    int getLen(Node *head)
    {
        if(head == NULL)
            return 0;
        if(head->next == NULL)
        {
            // cout<<"returning 1"<<endl;
            return 1;
        }

        Node *p = head;
        int len = 0;
        
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        
        return len;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // Rev first
        Node *fr = reverseList(first);
        
        // Rev second
        Node *sr = reverseList(second);
        

        // Make two traversal pointers for both reversed lists i.e p and q.
        Node *p = fr;
        Node *q = sr;
        Node *ret,*retTraverse;
        
        // Make a third ret pointer pointing to greater list in p or q.
        if(getLen(p) > getLen(q))
            ret = p;
        else
            ret = q;
        
        retTraverse = ret;
        // carry = 0
        int carry = 0;
        
        
        // loop till any of the traversal pointers are not null
        while(p || q)
        {
            int sum = 0;
            
            // If p not null add p->data to sum
            if(p)
                sum += p->data;
            
            // If q not null add q->data to sum
            if(q)
                sum += q->data;
            
            // Add carry to sum.
            sum += carry;
            
            // check if sum <= 9 then
            if(sum <= 9)
            {
                //ret->data = sum
                retTraverse->data = sum;
            }
            else // else if sum > 9 then
            {
                //ret->data = sum%10
                retTraverse->data = sum%10;
            }
                
            // Update carry   
            carry = sum/10;
            
            //if p->next not null then p = p->next
            if(p)
                p = p->next;
                
            //if q->next not null then q = q->next
            if(q)
                q = q->next;
                
            retTraverse = retTraverse->next;
        }
            
        
        
        // when both p and q reached null reverse ret list
        ret = reverseList(ret);

        // check if carry == 0 then return ret list
        if(carry == 0)
            return ret;
        else if(carry > 0)
        {
            // else if carry > 0 then make a newNode and put carry in newNode->data add this newNode infront of ret list and then return ret.
            Node *newNode = new Node(carry);
            newNode->next = ret;
            ret =  newNode;
            return ret;
        }
        
        return NULL;
    }
};
