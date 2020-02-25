/* **********************************************************************
                    Queue ADT using Array
********************************************************************** */
#include<iostream>
using namespace std;

template <class T>
class QueueArray
{
    public:
        QueueArray(int size=5);
        ~QueueArray();
        void enqueue(T var);
        void dequeue();
        void front();
        void isEmpty();
        void disp();
    private:
        int size;
        T* arr;
        int front_index;
        int rear_index;
        int no_of_ele;
};

template <class T>
QueueArray<T>::QueueArray(int isize)
{
    size = isize;
    arr = new T[size];
    front_index = -1;
    rear_index = -1;
}

template <class T>
QueueArray<T>::~QueueArray()
{
    delete arr;
    arr = NULL;
}

template <class T>
void QueueArray<T>::enqueue(T var)
{
    if(front_index==-1 and rear_index == -1)
    {
        front_index = 0;
        rear_index = 0;
        arr[rear_index] = var;
        no_of_ele++;
    }
    else if((rear_index+1)%size == front_index)
    {
        cout<<"Queue is full \n";
    }
    else
    {
        rear_index = (rear_index+1)%size;
        arr[rear_index] = var;
        no_of_ele++;
    }
}

template <class T>
void QueueArray<T>::disp()
{
    int temp = front_index;
    while(temp!=rear_index)
    {
        cout<<arr[temp]<<"--";
        temp = (temp+1)%size;
    }
    cout<<"front is: "<<front_index<<"  rear is: "<<rear_index<<"\n";
}

template <class T>
void QueueArray<T>::dequeue()
{
    if(front_index == rear_index)
    {
        arr[front_index] = 0;
        front_index =-1;
        rear_index =-1;
        no_of_ele--;
    }
    else if(front_index ==-1 and rear_index ==-1)
    {
        cout<<"Que is empty \n";
    }
    else
    {
        arr[front_index] = 0;
        front_index = (front_index+1)%size;
        no_of_ele--;
    }
}

template <class T>
void QueueArray<T>::front()
{
    cout<<"Front is now: "<<arr[front_index]<<"\n";
}

template <class T>
void QueueArray<T>::isEmpty()
{
    if(front_index ==-1 and rear_index ==-1)
    {
        cout<<"Queue is empty \n";
    }
}


/* **********************************************************************
                    Queue ADT using LinkedList
********************************************************************** */


template <class N>
struct Node
{
    N data;
    Node * adr_of_next;
};

template <class L>
class QueueLinkedlist
{
    public:
        QueueLinkedlist();
        ~QueueLinkedlist();
        void enqueue(L var);
        void dequeue();
        void frontEleRearEle();
        void isEmpty();
        void disp();
    private:
        void createNewNode(L var);
        int num_of_ele;
        Node<L> *front;
        Node<L> *rear;
        Node<L> *new_node;
        Node<L> *temp_node;
};

template <class L>
QueueLinkedlist<L>::QueueLinkedlist()
{
    front = NULL;
    rear = NULL;
    num_of_ele = 0;
}

template <class L>
QueueLinkedlist<L>::~QueueLinkedlist()
{
    while(front!=NULL)
    {
        delete front;
        front = front->adr_of_next;
    }
}

template <class L>
void QueueLinkedlist<L>::createNewNode(L ivar)
{
    L var = ivar;
    new_node = new Node<L>();
    new_node->data = var;
    new_node->adr_of_next = NULL;
}

template <class L>
void QueueLinkedlist<L>::enqueue(L ivar)
{
    L var = ivar;
    createNewNode(var);
    if(front == NULL and rear == NULL)
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->adr_of_next =new_node;
        rear = new_node;
    }
    num_of_ele++;
}

template <class L>
void QueueLinkedlist<L>::disp()
{
    temp_node = front;
    while(temp_node!= NULL and temp_node->adr_of_next!=NULL)
    {
        cout<<"["<<temp_node->data<<"|"<<temp_node->adr_of_next<<"]"<<" -- ";
        temp_node = temp_node->adr_of_next;
    }
    cout<<"   Number of element: "<<num_of_ele<<"   front: "<<front<<"   rear: "<<rear<<"\n";
}

template <class L>
void QueueLinkedlist<L>::dequeue()
{
    if(front == NULL and rear == NULL)
    {
        cout<<"Queue is empty \n";
    }
    else if(front == rear)
    {
        // delete front;
        front = NULL;
        rear = NULL;
        num_of_ele--;
    }
    else
    {
        temp_node = front;
        delete front;
        front = temp_node->adr_of_next;
        num_of_ele--;
    }
}

template <class L>
void QueueLinkedlist<L>::frontEleRearEle()
{
    cout<<"Front is pointing at: "<<front<<" Value:"<<front->data<<"   Rear is pointing at: "<<rear<<" Value:"<<rear->data<<"\n";
}

template <class L>
void QueueLinkedlist<L>::isEmpty()
{
    num_of_ele==0 ? cout<<"List isempty \n" : cout<<"List is not empty \n";
}

int main()
{
    QueueArray<int> a1;
    QueueLinkedlist<int> l1;
    return 0;
}
