#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* next;
};
 
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int find_starting_point(Node* head)
{
    Node *slow,*fast;
    int flag = 0;
    slow = fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }
    else
    {
        return -1;
    }

}


int main()
{

    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    int start_of_loop = find_starting_point(head);

    if(start_of_loop == -1)
        cout<<"No loop detected"<<endl;
    else
        cout<<"Loop starts at Node "<<start_of_loop<<endl;
    return 0;
}

