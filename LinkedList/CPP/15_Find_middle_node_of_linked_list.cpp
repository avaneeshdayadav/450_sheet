
// To check soln go to url : https://leetcode.com/problems/middle-of-the-linked-list/submissions/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *s,*f;
        s = f = head;
        
        while(f != NULL && f->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
        
        return s;
    }
};
