

// To check soln go to url : https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        
        if(node == NULL)
            return 0;
        if(node->left == NULL && node->right==NULL)
            return 1;
            
        return 1 + max(height(node->left) , height(node->right));
    }
};
