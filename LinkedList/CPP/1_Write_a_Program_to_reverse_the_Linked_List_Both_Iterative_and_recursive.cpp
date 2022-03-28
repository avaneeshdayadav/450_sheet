#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
};


class Linked_list{

    public:
    Node *head;

    Linked_list(int node_data)
    {
        Node *p = new Node;
        p->data = node_data;
        p->next = NULL;
        this->head = p;
    }

    void add_node(int node_data)
    {
        Node *p = this->head;
        Node *new_node = new Node;
        new_node->data = node_data;

        if(p == NULL)
        {
            this->head = new_node;
            return;
        }

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = new_node;
        return;
    }


    void display_linked_list()
    {
        if(this->head == NULL)
        {
            cout<<"Cannot display as linked List is empty ."<<endl;
            return;
        }

        Node *p = this->head;
        while(p != NULL)
        {
            cout<<p->data<<" -> ";
            p = p->next;
        }
        cout<<"NULL"<<endl;
        return;
    }

    void delete_node(int node_data)
    {
        if(this->head == NULL)
        {
            cout<<"Cannot delete as the list is already empty"<<endl;
            return;
        }

        Node *p = this->head;

        if(p->data == node_data)
        {
            this->head = p->next;
            free(p);
            return;
        }

        Node *q = NULL;
        while(p != NULL)
        {
            if(p->data != node_data)
            {
                q = p;
                p = p->next;
            }
            else
                break;
        }

        if(p != NULL)
        {
            q->next = p->next;
            free(p);
            p = NULL;
        }
        else
            cout<<"Cannot find element "<<node_data<<endl;
        return;
    }


    void reverse_list_iterative()
    {
        Node *p,*q,*r;
        p = this->head;
        q = r = NULL;

        if(this->head == NULL)
        {
            cout<<"Cannot reverse as list is empty"<<endl;
            return;
        }


        while(p != NULL)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }

        this->head = q;
        return;
    }
    

    Node * reverse_list_recc(Node *start)
    {
        if(start == NULL)
            return NULL;
        
        if(start->next == NULL)
        {
            this->head = start;
            return start;
        }

        Node *ret = reverse_list_recc(start->next);
        ret->next = start;
        start->next = NULL;
        return start;
    }
};


int main()
{
    Linked_list *ll = new Linked_list(1);
    ll->add_node(2);
    ll->add_node(3);
    ll->delete_node(1);
    ll->reverse_list_iterative();
    ll->display_linked_list();
    ll->reverse_list_recc(ll->head);
    ll->display_linked_list();
    return 0;
}