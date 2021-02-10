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

void printList()
{
    Node* temp = head;
    while(temp != NULL)
    {

        cout<<temp->data<<" ";
        temp = temp->next;
    }




}
void addOne()
{
     Node* pre = NULL;
     Node* nxt;
    nxt = head;
    while(nxt->next != NULL)
    {
        if(nxt->next->data == 9 && nxt->data != 9)
        {
            pre = nxt;
        }
        nxt = nxt->next;

    }

    if(nxt->data == 9)
    {
        nxt->data = 0;
        if(pre != NULL)
        {
            pre->data++;
            pre = pre->next;

            while(pre->next != NULL)
            {
                pre->data = 0;
                pre = pre->next;
            }
        }
        else{
                Node* temp;
            temp = head;
            temp->data = 1;
            Node* node1 = new Node(0);
            temp = temp->next;
            while(temp->next != NULL)
            {
                temp->data = 0;
                temp = temp->next;

            }
            temp->next = node1;


        }

    }
    else
    nxt->data++;




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
    addOne();
    cout<<endl;
    printList();
    return 0;
}
