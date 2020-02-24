// List ADT using linked list

#include<iostream>
using namespace std;

template <class N>
struct Node
{
    N data;
    Node* adr_of_nxt;
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void addEleAtBeg(T var);
        void addEleAtEnd(T var);
        void addEleAtPos(T var, int index);
        void remEleAtBeg();
        void remEleAtEnd();
        void remEleAtPos(int index);
        void writeatnth(T var, int index);
        void readatnth(int index);
        void dispList();
        void reverseListitr();
        void accessPrivateVar();

    private:
        Node<T> *head;
        Node<T> *temp_node_adr;
        Node<T> *new_node_adr;
        int no_of_ele;
        void freeSpace();
        void createNode(T var);
};


template <class T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>();
    head->adr_of_nxt = NULL;

    new_node_adr = new Node<T>();
    new_node_adr->data = 0;
    new_node_adr->adr_of_nxt = NULL;

    temp_node_adr = new Node<T>();
    temp_node_adr->data = 0;
    temp_node_adr->adr_of_nxt = NULL;

    no_of_ele = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    freeSpace();
    cout<<"Distructor invoked"<<"\n";
}

template <class T>
void LinkedList<T>::dispList()
{
    cout<<"Linked list starts at: "<<head->adr_of_nxt<<"-->";
    temp_node_adr = head;

    while(temp_node_adr->adr_of_nxt !=NULL)
    {
        temp_node_adr = temp_node_adr->adr_of_nxt;
        cout<<"["<<temp_node_adr->data<<"|"<<temp_node_adr->adr_of_nxt<<"] "<<"-->";
    }
    cout<<"  #of ele: "<<no_of_ele<<" \n";
}

template <class T>
void LinkedList<T>::freeSpace()
{
    Node<T> *nxt_temp_adr;
    temp_node_adr = head;

    while(temp_node_adr!=NULL)
    {
        nxt_temp_adr = temp_node_adr->adr_of_nxt;
        delete temp_node_adr;
        temp_node_adr->data = 0;
        temp_node_adr = NULL;
        temp_node_adr = nxt_temp_adr;
    }
    head->adr_of_nxt = NULL;
}

template <class T>
void LinkedList<T>::createNode(T var)
{
    new_node_adr = new Node<T>();
    new_node_adr->data = var;
    new_node_adr->adr_of_nxt = NULL;
}

template <class T>
void LinkedList<T>::addEleAtBeg(T var)
{
    createNode(var);
    temp_node_adr = head->adr_of_nxt;
    new_node_adr->adr_of_nxt = temp_node_adr;
    head->adr_of_nxt = new_node_adr;

    temp_node_adr = NULL;
    no_of_ele++;
}

template <class T>
void LinkedList<T>::addEleAtEnd(T var)
{
    createNode(var);
    temp_node_adr = head;

    while(temp_node_adr->adr_of_nxt!=NULL)
    {
        temp_node_adr = temp_node_adr->adr_of_nxt;
    }
    new_node_adr->adr_of_nxt = NULL;
    temp_node_adr->adr_of_nxt = new_node_adr;
    no_of_ele++;
}

template <class T>
void LinkedList<T>::addEleAtPos(T var, int index)
{
    createNode(var);
    if(index == 0)
    {
        addEleAtBeg(var);
    }
    else if(index>no_of_ele and index<0)
    {
        cout<<"Index out of range \n";
    }
    else
    {
        temp_node_adr = head;
        for(int i=0; i<index; i++)
        {
            temp_node_adr = temp_node_adr->adr_of_nxt;
        }
        Node<T> *temp_var =  temp_node_adr->adr_of_nxt;
        temp_node_adr->adr_of_nxt = new_node_adr;
        new_node_adr->adr_of_nxt = temp_var;
        no_of_ele++;
    }
}

template <class T>
void LinkedList<T>::remEleAtBeg()
{
    if(no_of_ele!=0)
    {
        temp_node_adr = head->adr_of_nxt;
        head->adr_of_nxt = temp_node_adr->adr_of_nxt;
        delete temp_node_adr;
        temp_node_adr = NULL;
        no_of_ele--;
    }
    else
    {
        cout<<"nothing to remove the List is empty \n";
    }
}

template <class T>
void LinkedList<T>::remEleAtEnd()
{
    if(no_of_ele == 1)
    {
        remEleAtBeg();
    }
    else if(no_of_ele != 0)
    {
        temp_node_adr = head;
        Node<T> *temp_node_adr2 = NULL;
        while(temp_node_adr->adr_of_nxt!=NULL)
        {
            temp_node_adr2 = temp_node_adr;
            temp_node_adr = temp_node_adr->adr_of_nxt;
        }
        delete temp_node_adr;
        temp_node_adr->adr_of_nxt = NULL;
        temp_node_adr2->adr_of_nxt = NULL;
        no_of_ele--;
    }
    else
    {
        cout<<"nothing to remove the List is empty \n";
    }
}

template <class T>
void LinkedList<T>::remEleAtPos(int index)
{
    if(index>=no_of_ele and index<0)
    {
        cout<<"index out of range \n";
    }
    else if(index ==0)
    {
        remEleAtBeg();
    }
    else if(index == no_of_ele-1)
    {
        remEleAtEnd();
    }
    else
    {
        temp_node_adr = head;

        Node<T> *temp_node_adr2 = NULL;
        Node<T> *temp_node_adr1 = NULL;

        for(int i=0; i<=index; i++)
        {
            temp_node_adr1 = temp_node_adr;
            temp_node_adr = temp_node_adr->adr_of_nxt;
        }
        temp_node_adr2 = temp_node_adr->adr_of_nxt;
        cout<<"***"<<temp_node_adr1<<"\n";
        cout<<"***"<<temp_node_adr<<"\n";
        cout<<"***"<<temp_node_adr2<<"\n";       // temp_node_adr = temp_node_adr->adr_of_nxt;

        temp_node_adr1->adr_of_nxt = temp_node_adr2;
        delete temp_node_adr;
        temp_node_adr->adr_of_nxt = NULL;

        no_of_ele--;
    }
}

template <class T>
void LinkedList<T>::writeatnth(T var, int index)
{
    if(index<no_of_ele and index>=0)
    {
        temp_node_adr = head;
        for(int i=0; i<=index; i++)
        {
            temp_node_adr = temp_node_adr->adr_of_nxt;
        }
        cout<<temp_node_adr<<"@@@ \n";
        temp_node_adr->data = var;
    }
    else
    {
        cout<<"index out of range \n";
    }
}

template <class T>
void LinkedList<T>::readatnth(int index)
{
    if(index<no_of_ele and index>=0)
    {
        temp_node_adr = head;
        for(int i=0; i<=index; i++)
        {
            temp_node_adr = temp_node_adr->adr_of_nxt;
        }
        cout<<"Value stored at position: "<<index<<" = "<<temp_node_adr->data<<"\n";
    }
    else
    {
        cout<<"index out of range \n";
    }
}

template <class T>
void LinkedList<T>::accessPrivateVar()
{
    cout<<"Linked list contains: "<<no_of_ele<<" \nhead starts at: "<<head<<"\n";
}

template <class T>
void LinkedList<T>::reverseListitr()
{
    Node<T> *prev = NULL;
    Node<T> *curr = head->adr_of_nxt;
    Node<T> *next;

    int i = 0;
    while(curr!=NULL)
    {
        next = curr->adr_of_nxt;
        curr->adr_of_nxt = prev;
        prev = curr;
        curr = next;
    }
    head->adr_of_nxt = prev;
}

int main()
{
    LinkedList<int> obj;

    return 0;
}
