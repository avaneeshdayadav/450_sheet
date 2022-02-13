#include <iostream>
using namespace std;


class Trie
{
  char data,wc;
  Trie *arr[26];
  
  public:
  Trie* createNode(char d)
  {
      Trie *temp = new Trie;
      temp->data = d;
      temp->wc = 0;
      
      for(int i=0;i<26;i++)
          temp->arr[i] = NULL;
      
      return temp;
  }
  
  void insertNode(Trie* root,string str)
  {
      Trie *curr = root;
      for(int i=0;i<str.length();i++)
      {
        cout<<"Inserting "<<str[i]<<endl;
        int indx = str[i]-'a';
        if(curr->arr[indx] == NULL)
        {
          Trie * t = createNode(str[i]);
          curr->arr[indx] = t;
        }
        
        curr = curr->arr[indx];
      }
      
      curr->wc++;
  }
  
  
  bool searchNode(Trie *root,string str)
  {
      Trie *curr = root;
      
      for(int i=0;i<str.length();i++)
      {
          int indx = str[i]-'a';
          if(curr->arr[indx] == NULL)
              return false;
          
          curr = curr->arr[indx];
      }
      
      if(curr->wc !=0)
        return true;
      
      return false;
        
  }
  
  
  void delNode(Trie *root,string str)
  {
      Trie *curr = root;
      
      for(int i=0;i<str.length();i++)
      {
          int indx = str[i]-'a';
          if(curr->arr[indx] == NULL)
              return;
          
          curr = curr->arr[indx];
      }
      
      if(curr->wc !=0)
      curr->wc--;
      return;
      
  }
};
int main() {
	// your code goes here
	Trie obj;
	Trie *root = obj.createNode('/');
	
	obj.insertNode(root,"hello");
    cout<<obj.searchNode(root,"hello")<<endl;
    
	obj.insertNode(root,"neha");
    cout<<obj.searchNode(root,"neha")<<endl;
    
    obj.delNode(root,"hello");
    cout<<"Finding Hello "<<obj.searchNode(root,"hello")<<endl;
    
    

	return 0;
}
