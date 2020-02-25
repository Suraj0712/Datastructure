/* **********************************************************************
                    Stack ADT using Array
********************************************************************** */
#include<iostream>
using namespace std;

template <class T>
class StackArray
{
    public:
        StackArray();
        ~StackArray();
        void push(T var);
        void pop();
        void top();
        void isEmpty();
        void disp();
    private:
        T* stack;
        int top_index;
        int max_size;
};

template <class T>
StackArray<T>::StackArray()
{
    max_size = 10;
    stack = new T[max_size];
    top_index = -1;
}

template <class T>
StackArray<T>::~StackArray()
{
    delete [] stack;
}

template <class T>
void StackArray<T>::push(T var)
{
    if(top_index>=max_size-1)
    {
        cout<<"stack overflow \n";
    }
    else
    {
        top_index++;
        stack[top_index] = var;
    }
}

template <class T>
void StackArray<T>::pop()
{
    if (top_index == -1)
    {
        cout<<"stack is empty \n";
    }
    else
    {
        stack[top_index] = 0;
        top_index--;
    }
}

template <class T>
void StackArray<T>::top()
{
    if (top_index == -1)
    {
        cout<<"stack is empty \n";
    }
    else
    {
        cout<<"element at the top is: "<<stack[top_index]<<"\n";
    }

}

template <class T>
void StackArray<T>::isEmpty()
{
    if(top_index == -1)
    {
        cout<<"Stack is empty \n";
    }
    else
    {
        cout<<"Stack is not empty \n";
    }
}
template <class T>
void StackArray<T>::disp()
{
    for(int i=0; i<=top_index; i++)
    {
        cout<<stack[i]<<"--";
    }
    cout<<"\n";
}

/* **********************************************************************
                    Stack ADT using linkedlist
********************************************************************** */


template <typename N>
struct Node
{
    N data;
    Node *adr_of_nxt;

};

template <typename S>
class StackLinkedList
{
    public:
        StackLinkedList();
        ~StackLinkedList();
        void push(S var);
        void pop();
        void top();
        void isEmpty();
        void disp();
    private:
        int top_index;
        Node<S>* head;
        Node<S>* new_node;
        Node<S>* temp_node;
        void createNode(S var);
};

template <class S>
StackLinkedList<S>::StackLinkedList()
{
    top_index = -1;
    head = new Node<S> ();
    head->adr_of_nxt = NULL;
}

template <class S>
StackLinkedList<S>::~StackLinkedList()
{
    while(head->adr_of_nxt)
    {
        delete head;
        head = head->adr_of_nxt;
    }
}

template <class S>
void StackLinkedList<S>::createNode(S var)
{
    new_node = new Node<S>();
    new_node->data = var;
    new_node->adr_of_nxt = NULL;
}

template <class S>
void StackLinkedList<S>::push(S var)
{
    createNode(var);
    temp_node = head->adr_of_nxt;

    head->adr_of_nxt = new_node;
    new_node->adr_of_nxt = temp_node;

    top_index++;
}

template <class T>
void StackLinkedList<T>::disp()
{
    temp_node = head;
    cout<<"<<<---- ";
    while(temp_node->adr_of_nxt!=NULL)
    {
        temp_node = temp_node->adr_of_nxt;
        cout<<temp_node->data<<"--";
    }
    cout<<"   no of ele: "<<top_index+1<<"\n";
}

template <class S>
void StackLinkedList<S>::pop()
{
    if(top_index == -1)
    {
        cout<<"Nothing to remove \n";
    }
    else
    {
        temp_node = head->adr_of_nxt;
        head->adr_of_nxt = temp_node->adr_of_nxt;
        delete temp_node;
        temp_node = NULL;
        top_index--;
    }
}

template <class S>
void StackLinkedList<S>::top()
{
    if(top_index!=-1)
    {
        cout<<"Value stored at top location is "<<(head->adr_of_nxt)->data<<"\n";
    }
    else
    {
        cout<<"Nothing at top list is empty \n";
    }
}

template <class S>
void StackLinkedList<S>::isEmpty()
{
    top_index!=-1 ? cout<<"List not empty \n" : cout<<"List empty \n";
}

int main()
{
    StackArray<float> s_float;
    StackLinkedList<int> s1_int;
    return 0;
}
