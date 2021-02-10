
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

void reverseList()
{
    Node* curr = head;
    Node* pre = NULL,*next = NULL;


    while(curr != NULL)
    {

        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;


    }
    head = pre;




}

void mulBy3()
{
    reverseList();
    int c = 0;
    int n;

    Node* temp = head;
    while(temp->next != NULL)
    {
        n = temp->data*3 + c;
        c = n/10;
        n = n % 10;
        temp->data = n;
        temp = temp->next;
    }

    n = temp->data*3 + c;
    c = n/10;
    n = n % 10;
    temp->data = n;
        if(c != 0)
        {
            Node* node = new Node(c);
            temp->next = node;


        }
            reverseList();


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
    cout<<endl;

   // reverseList();


    mulBy3();
    printList();
    cout<<endl;

    return 0;
}
