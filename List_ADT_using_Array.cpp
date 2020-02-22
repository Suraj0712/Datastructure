// List ADT implementation using array
#include <iostream>
using namespace std;

template <class T>
class Arraylist
{
    public:
        Arraylist(int isize=2);
        ~Arraylist();
        void addEleAtBeg(T var);
        void addEleAtEnd(T var);
        void addEleAtPos(T var, int index);
        void remEleAtBeg();
        void remEleAtEnd();
        void remEleAtPos(int index);
        void writeatnth(T var, int index);
        void readatnth(int index);
        void dispList();
        void dispNth(int index);
        void reverseListitr();
        void accessPrivateVar();
        template <class U>
        friend void reverseListrec(Arraylist<U> &obj);
    private:
        T* head;
        T* temp_head;
        int no_of_ele;
        int size;
        void moveElment(int index=0, bool forward=true);
        void createNewArray(bool expand);
        void copyElement(int index);
        void freeSpace();
};

template <class S>
S* reverseListreci(S* arr, int start, int end);

template <class U>
void reverseListrec(Arraylist<U> &obj);

template <class T>
Arraylist<T>::Arraylist(int isize)
{
    this->size = isize;
    head = new T[size];
    no_of_ele = 0;
    temp_head = NULL;
}

template <class T>
Arraylist<T>::~Arraylist()
{
    cout<<"Distructor invoked \n";
}

template <class T>
void Arraylist<T>::dispList()
{
    for(int i=0; i<size; ++i)
    {
        cout<<head[i]<<"--";
    }
    cout<<"\n";
}

template <class T>
void Arraylist<T>:: addEleAtBeg(T var)
{
    if(no_of_ele<(size-1))
    {
        moveElment();
        head[0] = var;
    }
    else
    {
        createNewArray(true);
        temp_head[0] = var;
        copyElement(1);
        freeSpace();
    }
    no_of_ele++;
}

template <class T>
void Arraylist<T>::moveElment(int index, bool forward)
{
    if(forward)
    {
        for(int i=no_of_ele-1; i>=index; i--)
        {
            head[i+1] = head[i];
        }
    }
    else
    {
        for(int i=index; i<=no_of_ele; i++)
        {
            head[i] = head[i+1];
        }
    }
}

template <class T>
void Arraylist<T>::createNewArray(bool expand)
{
    if(expand)
    {
        size = 2*size;
        temp_head = new T[size];
    }
    else
    {
        size = size/2;
        temp_head = new T[size];
    }

    for(int i=0; i<size;i++)
    {
        temp_head[i]=0;
    }
}

template <class T>
void Arraylist<T>::copyElement(int index)
{
    for(int i=index; i<no_of_ele; i++)
    {
        temp_head[i] = head[i-index];
    }
}

template <class T>
void Arraylist<T>::addEleAtEnd(T var)
{
    if(!(no_of_ele<(size-1)))
    {
        createNewArray(true);
        copyElement(0);
        freeSpace();
    }
    head[no_of_ele] = var;
    no_of_ele++;
}

template <class T>
void Arraylist<T>::addEleAtPos(T var, int index)
{
    if(index < 2*size)
    {
        if(!(no_of_ele<(size-1)))
        {
            createNewArray(true);
            copyElement(0);
            freeSpace();
        }
        moveElment(index, true);
        head[index] = var;
        no_of_ele++;
    }
    else
    {
        cout<<"element not updated Give the indx less than: "<<2*size<<" \n";
    }
}

template <class T>
void Arraylist<T>::freeSpace()
{
        delete [] head;
        head = temp_head;
        temp_head = NULL;
}

template <class T>
void Arraylist<T>::remEleAtBeg()
{
    moveElment(0,false);
    if(size*0.3>no_of_ele)
    {
        createNewArray(false);
        copyElement(0);
        freeSpace();
    }
    no_of_ele--;
}

template <class T>
void Arraylist<T>::remEleAtEnd()
{
    if(no_of_ele>=0)
    {
        head[no_of_ele] = 0;
        no_of_ele--;
    }
    else
    {
        cout<<"List is already empty please add some elements \n";
    }
}

template <class T>
void Arraylist<T>::remEleAtPos(int index)
{
    if(index>no_of_ele)
    {
        cout<<"invalid index for removal \n";
    }
    else
    {
        moveElment(index,false);
        head[no_of_ele] = 0;
        no_of_ele--;
    }
}

template <class T>
void Arraylist<T>::writeatnth(T var, int index)
{
    if(index<size)
    {
        head[index] = var;
    }
    else
    {
        cout<<"Current size is less than given index \n";
    }
}

template <class T>
void Arraylist<T>::readatnth(int index)
{
    if(index<no_of_ele)
    {
        cout<<"Value stored at location:"<<index<<" is ="<<head[index]<<"\n";
    }
    else
    {
        cout<<"given index is out of the range \n";
    }
}

template <class T>
void Arraylist<T>::reverseListitr()
{
    int start=0, end = no_of_ele-1;
    T temp;
    while(start<end)
    {
        temp = head[start];
        head[start] = head[end];
        head[end] = temp;
        start++;
        end--;
    }
}

template <class T>
void Arraylist<T>::accessPrivateVar()
{
    cout<<"Head is pointing to the address: "<<head<<"\nno of element in the array is: "<<no_of_ele<<"\nsize of array is: "<<size<<"\n";
}

template <class U>
void reverseListrec(Arraylist<U> &obj)
{
    int start = 0;
    U* head = reverseListreci(obj.head, start, obj.no_of_ele);
}

template <class S>
S* reverseListreci(S* arr, int start, int end)
{
    S temp;
    if(!(start<end))
    {
        return arr;
    }
    else
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        reverseListreci(arr, start+1, end-1);
    }
}

int main()
{
    Arraylist<int> obj;

    return 0;
}
