#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;

    }
};


Node* head;


void printList()
{
    Node* temp = head;
    while(temp != NULL)
    {

        cout<<temp->data<<" ";
        temp = temp->next;
    }




}

Node* reverseList(Node *head1)
{
    Node* pre = NULL;
    Node* curr = head1;
    Node* temp;
    while(curr!=NULL)
    {

        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;

    }
    return pre;
}



struct Node *reverse ( int k)
{
    Node* node = head;
    Node* pre = NULL;
    int flag = 1;
    Node* rest = NULL;
    bool quit = 0;
    Node* mainNode = node;
    while(1)
    {
        Node* first = node;
        int count = 1;
        while(count < k && node->next != NULL)
        {
            node = node->next;
            count++;
        }
        if(node->next == NULL)
            quit = 1;
        mainNode = node;
        if(flag == 1)
        {
           head = node;
        }
        rest = node->next;node->next = NULL;
        Node* n2Head = reverseList(first);
      //  head = n2Head;


        if(flag == 1)
        {

            pre = first;flag = 0;
            node = rest;
        }
        else{
            pre->next = n2Head;
            pre = first;
            node = rest;
        }

        if(quit)
            return head;

    }
    return head;

    // Complete this method
}


void addToList(vector<int>& v)
{
    int n = v.size();
    head = new Node(v[0]);
    Node* temp = head;
    for(int i = 1;i < n;i++)
    {
        Node* t = new Node(v[i]);
        temp->next = t;
        temp = temp->next;



    }
}



int main()
{
    head = NULL;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
        cin>>v[i];
    addToList(v);
    printList();
   // addOne();
    cout<<endl;

    head = reverse(4);

    printList();
    return 0;
}

