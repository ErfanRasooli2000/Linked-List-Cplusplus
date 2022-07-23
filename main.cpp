#include<iostream>
using namespace std;


//Defines Node For Linked List
struct Node
{
    int data;
    Node* next;
};

Node* head;
Node* pointer;


//Inserts Number To End of The Linked List
void insertEnd(int x)
{
    Node* temp = new Node();
    temp->data = x;
    if(head==NULL)
    {
        head = temp;
        pointer = temp;
    }
    else
    {
        pointer->next = temp;
        pointer = temp;
    }
}


//Gets The Pointet of Given Number
Node* getPointer(int n)
{
    pointer = head;
    int counter = 0;

    while(counter!=n)
    {
        pointer = pointer->next;
        counter++;
    }

    return pointer;
}


//Inserts A Number To spescific Place Of List
void insertN (int n , int x)
{
    Node* temp = new Node();
    temp->data = x;
    Node* pointers = (Node*) getPointer(n-1);
    temp->next = pointers->next;
    pointers->next = temp;
}

//Gives The Value Of Spesific Number Of List
int getValue(int n)
{
    Node* pointers = getPointer(n); 
    return pointers->data;
}

//Inserts Number To First Of List
void insert(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}


//Prints The Full Array
void print()
{
    Node* temp = head; 
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//Returns List As Array
//Deletes The Spesific Index Of List
//Updates The Spesific Index Of List

int main()
{
    head = NULL;

    int n;
    int x;

    cout << "Lets Add Few To end" <<endl;
    cout << "How Many?" <<endl;
    cin >> n;
    cout << "Insert ALL" <<endl;

    for (int i=0 ; i<n ; i++)
    {
        cin >> x;
        insertEnd(x);
    }

    cout << "These Are The list" <<endl;
    print();

    cout << "Lets Add Few To First" <<endl;
    cout << "How Many?" <<endl;
    cin >> n;
    cout << "Insert ALL" <<endl;

    for (int i=0 ; i<n ; i++)
    {
        cin >> x;
        insert(x);
    }

    cout << "These Are The list" <<endl;
    print();

    cout << "Give Me Index To find:" <<endl;
    cin >> n;
    cout << getValue(n) << endl;

    cout << "Lets Add a Number To spesicific place:" << endl;
    cout << "where To Add?" << endl;
    cin >> n;
    cout << "what Number?" << endl;
    cin >> x;
    cout << "This is The Result:" << endl;
    insertN(n,x);
    print();
}