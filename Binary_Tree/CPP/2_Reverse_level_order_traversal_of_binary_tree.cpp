
// To check soln go to url : https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    // code 
    vector<int> res;
    stack<int> st;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *f = q.front();
        q.pop();
        
        st.push(f->data);
        
        if(f->right)
            q.push(f->right);
        if(f->left)
            q.push(f->left);
    }
    
    
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    
    return res;
}
