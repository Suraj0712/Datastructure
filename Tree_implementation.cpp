/* **********************************************************************
                    Tree implementation
********************************************************************** */

#include <iostream>
#include <queue>
using namespace std;

template <class S>
struct Node
{
    Node *left;
    S data;
    Node *right;
};

template <class T>
class BST
{
    public:
        BST();
        ~BST();
        void insert(T var);
        void search(T var);
        void findMax();
        void findMin();
        void findMaxRec(){findMaxReci(root);}
        void findMinRec(){findMinReci(root);}
        void findHeightRec(){cout<<"Height of tree: "<<findHeightReci(root)<<"\n";};
        void bradthFirstSearch();
        void inorder(){cout<<"In order traversal: ";inorderRec(root); cout<<"\n";}
        void preorder(){cout<<"Pre order traversal: ";preorderRec(root); cout<<"\n";}
        void postorder(){cout<<"Post order traversal: ";postorderRec(root); cout<<"\n";}
        void deleteBST(){deleteBSTRec(root);};

    private:
        Node<T> *root;
        void createNode(T var);
        Node<T> *new_node;
        void insertRec(Node<T> *temp_root, T var);
        void searchRec(Node<T> *temp_node, T var);
        void findHeightRec(Node<T>* temp_root);
        void findMaxReci(Node<T>* temp_root);
        void findMinReci(Node<T>* temp_root);
        int findHeightReci(Node<T>* temp_root);
        int no_of_ele;
        void inorderRec(Node<T>* temp_root);
        void preorderRec(Node<T>* temp_root);
        void postorderRec(Node<T>* temp_root);
        void deleteBSTRec(Node<T>* temp_root);
};

template <class T>
BST<T>::BST()
{
    root = NULL;
    new_node = NULL;
    no_of_ele = 0;
}

template <class T>
BST<T>::~BST()
{
    deleteBST();
}

template <class T>
void BST<T>::deleteBSTRec(Node<T>* temp_root)
{
    if(temp_root==NULL)
    {
        return;
    }
    else
    {
        Node<T>* left = temp_root->left;
        Node<T>* right = temp_root->right;
        delete temp_root;
        deleteBSTRec(left);
        deleteBSTRec(right);
    }
}

template <class T>
void BST<T>::createNode(T var)
{
    new_node = new Node<T> ();
    new_node->data = var;
    new_node->left = NULL;
    new_node->right = NULL;
}

template <class T>
void BST<T>::insert(T var)
{
    no_of_ele++;
    insertRec(root, var);
}

template <class T>
void BST<T>::insertRec(Node<T>* temp_root, T data)
{
    if(temp_root == NULL)
    {
        createNode(data);
        root = new_node;
    }
    else
    {
        if(data<temp_root->data)
        {
            if(temp_root->left == NULL)
            {
                createNode(data);
                temp_root->left = new_node;
            }
            else
            {
                insertRec(temp_root->left, data);
            }
        }
        else if(data>temp_root->data)
        {
            if(temp_root->right==NULL)
            {
                createNode(data);
                temp_root->right = new_node;
            }
            else
            {
                insertRec(temp_root->right, data);
            }
        }
        else
        {
            cout<<"Duplicate element detected \n";
        }
    }
}

template <typename T>
void BST<T>::search(T var)
{
    searchRec(root,var);
}

template <typename T>
void BST<T>::searchRec(Node<T>* temp_root, T data)
{
    if(temp_root ==NULL)
    {
        cout<<"Tree has zero element \n";
    }
    else
    {
        if(data<temp_root->data)
        {
            if(temp_root->left == NULL)
            {
                cout<<"Element does not exist \n";
            }
            else
            {
                searchRec(temp_root->left, data);
            }
        }
        else if(data>temp_root->data)
        {
            if(temp_root->right == NULL)
            {
                cout<<"Element does not exist \n";
            }
            else
            {
                searchRec(temp_root->right, data);
            }
        }
        else
        {
            cout<<"Element Present\n";
        }
    }
}

template <class T>
void BST<T>::findMax()
{
    Node<T> * temp_root = root;
    if(temp_root ==NULL)
    {
        cout<<"Tree has zero element \n";
    }
    else
    {
        while(temp_root->right!=NULL)
        {
            temp_root = temp_root->right;
        }
        cout<<"Maximum element in BST is: "<<temp_root->data<<"\n";
    }
}

template <class T>
void BST<T>::findMin()
{
    Node<T> * temp_root = root;
    if(temp_root ==NULL)
    {
        cout<<"Tree has zero element \n";
    }
    else
    {
        while(temp_root->left!=NULL)
        {
            temp_root = temp_root->left;
        }
        cout<<"Minimum element in BST is: "<<temp_root->data<<"\n";
    }
}

template <class T>
void BST<T>::findMaxReci(Node<T>* temp_root)
{
    if(temp_root ==NULL)
    {
        cout<<"Tree has zero element \n";
    }
    else
    {
        if(temp_root->right==NULL)
        {
           cout<<"Maximum element in BST is: "<<temp_root->data<<"\n";
        }
        else
        {
            findMaxReci(temp_root->right);
        }
    }
}

template <class T>
void BST<T>::findMinReci(Node<T>* temp_root)
{
    if(temp_root ==NULL)
    {
        cout<<"Tree has zero element \n";
    }
    else
    {
        if(temp_root->left==NULL)

        {
           cout<<"Minimum element in BST is: "<<temp_root->data<<"\n";
        }
        else
        {
            findMinReci(temp_root->left);
        }
    }
}
template <class T>
int BST<T>::findHeightReci(Node<T>* temp_root)
{
    if(temp_root == NULL)
    {
        return -1;
    }
    else
    {
        return max(findHeightReci(temp_root->left),findHeightReci( temp_root->right))+1;
    }

}

template <class T>
void BST<T>::bradthFirstSearch()
{
    queue<Node<T>*> bfs_queue;
    Node<T> *temp_node = root;
    if(root == NULL)
    {
        cout<<"Tree is empty";
    }
    else
    {
        temp_node = root;
        cout<<"Level order traversal: ";
        bfs_queue.push(temp_node);
        while(!(bfs_queue.empty()))
        {
            temp_node=bfs_queue.front();
            if(temp_node->left!=NULL)
            {
                bfs_queue.push(temp_node->left);
            }
            if(temp_node->right!=NULL)
            {
                bfs_queue.push(temp_node->right);
            }
            cout<<bfs_queue.front()->data<<"--";
            bfs_queue.pop();
        }
        cout<<"\n";
    }
}

template <class T>
void BST<T>::preorderRec(Node<T>* temp_root)
{
    if(temp_root == NULL)
    {
        return;
    }
    else
    {
        cout<<temp_root->data<<"--";
        preorderRec(temp_root->left);
        preorderRec(temp_root->right);
    }
}

template <class T>
void BST<T>::inorderRec(Node<T>* temp_root)
{
    if(temp_root == NULL)
    {
        return;
    }
    else
    {
        inorderRec(temp_root->left);
        cout<<temp_root->data;
        inorderRec(temp_root->right);
    }
}

template <class T>
void BST<T>::postorderRec(Node<T>* temp_root)
{
    if(temp_root == NULL)
    {
        return;
    }
    else
    {
        postorderRec(temp_root->left);
        postorderRec(temp_root->right);
        cout<<temp_root->data<<"--";
    }
}

int main()
{
    BST<int> tree;
    return 0;
}
