
// To check soln go to url : https://practice.geeksforgeeks.org/problems/level-order-traversal/1

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        vector<int> res;
        
        queue<Node*> q;
        
        q.push(node);
        
        while(!q.empty())
        {
            Node *f = q.front();
            q.pop();
            
            res.push_back(f->data);
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
        
        
        return res;
    }
};
