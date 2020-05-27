# Datastructure Implementation

### Welcome to the Datastructure.

Data Structures are a specialized means of organizing and storing data in computers in such a way that we can perform operations on the stored data more efficiently. Data structures have a wide and diverse scope of usage across the fields of Computer Science and Software Engineering. Data can be stored sequentially or hierarchically. In these lessons, we are going to study ** List, Stack, Queue, and Tree **data structure. Except for the tree all the data structures are sequential data structure meaning that they store the data sequentially.

### We talk about data-structure as
1. Mathematical/Logical models (Abstract view) (Just define the data models and data operations but no implementation)
2. Implementation (Here we "actually" implement the ADT, there can be multiple ways to implement the ADT)
3. Operations and Cost


There is no such thing as the best data structure and it depends totally on factors like 
1. Most frequent operation
2. Memory requirements
3. Performance(time) requirements

## List as Abstract data type
#### Logical view
1. Store a given number of elements of a data of a given data type
2. Write/modify element at a position
3. Read element at a position

#### Implementation
##### Array (**List_ADT_using_Array.cpp**)
We can implement this using array. we just have to write the specific operation on top of the array to get complete functionality. For the sake of current implementation we will use the following operations.

#### Operations
```
1. Add element at start                O(n)
2. Add element at end                  O(n)
3. Add element at some position        O(n)
4. Remove element at start             O(n)
5. Remove element at end               O(n)
6. Remove element at some position     O(n)
7. Modify element at some position     O(1)
8. Read element at some position       O(1)
9. Display whole list                  O(n)
10. Reverse list                       O(n)
11. Display capacity, size, position   O(1)
```
first we will define an array of **some large** size. When the array is **full** we will create a new larger array, copy the previous array into the new array and free the memory for the previous array. The best policy is to double the size. The drawback of this implementation is a large amount of space will be unallocated.

#### Psuedo code for the operations
1. Adding the element:
* Check whether the index value is valid or not
* If the index is valid check whether the place is available or not
* If place not available then create a new array of double the size and copy the element in new array finally deallocate the memory
* Now go to the index and move all the element after that index by 1 place
* Now assign the value to the user given index
* Update the privates variable accordingly

2. Removing the element:
* Check whether the index value is valid or not
* If the index is valid check whether the array is sufficiently filled or not
* If more than 50% of array is empty create a new array of half the size and copy all the elements in the new array
* Now go to the index and start swapping/ moving the values by one position and delete the value at last position
* Update the privates variable accordingly

3. Modify the element:
* Check whether the index value is valid or not
* If the index is valid just go to the index position and update the value

4. Read the element:
* Check whether the index value is valid or not
* If the index is valid then return the value at that index

5. Display the list and variables:
* Iterate through the list and display the elements
* Set a public method which can return the private variables

6. Reverse the list:
This operation can be done by multiple ways i used a two-pointer technic to implement it. 
* Write the swap function
* Assign a pointer to the last and first index and recursively or iteratively update the values.


##### Linkedlist (**List_ADT_using_linkedlist.cpp**)
So in this implementation we use the structures which store the data and the address. we arrange them in such a way that the address of the next element is stored in the address field of the current structure. Generally we refer to these structures as nodes. We are planning to implement the following operations using the nodes.

#### Operations
```
1. Add element at start                O(1)
2. Add element at end                  O(n)
3. Add element at some position        O(n)
4. Remove element at start             O(1)
5. Remove element at end               O(n)
6. Remove element at some position     O(n)
7. Modify element at some position     O(n)
8. Read element at some position       O(n)
9. Display whole list                  O(n)
10. Reverse list                       O(n)
11. Display capacity, size, position   O(1)
```
#### Psuedo code for the operations
1. Adding the element:
* Check whether the index value is valid or not (which can be checked by maintaining a variable which stores the current size so you dont have to iterate the linked list)
* If the index is valid then create a node with value and address field as NULL.
* Iterate through the linklist reach **index-1** node. 
* Copy the address from that address field of **index-1** node and save the same in newly created nodes address field
* Now copy the address of the newly created node and store it in the address field of **index-1** node
* Update the privates variable accordingly

2. Removing the element:
* Check the validity of the index
* If the index is valid then Iterate through the linklist reach **index-1** node. 
* Now store the value in the address field of that node in some temporary variable we need this value to access the address of **index+1** and **index** node.
* Replace the value of address filed of **index-1** with the address field of **index** node 
* Now deallocate the memory assigned to the **index** node
* Update the privates variable accordingly

3. Modify the element:
* Check whether the index value is valid or not
* Iterate through the linklist reach **index-1** node. 
* Update the data field of the **index** node using the address field of **index-1** node with a given value.

4. Read the element:
* Check whether the index value is valid or not
* Iterate through the linklist reach **index-1** node. 
* Return the data field of the **index** node using the address field of **index-1** node.

5. Display the list and variables:
* Iterate through the list till the address stored in the address field of the node is not NULL
* Set a public method which can return the private variables

6. Reverse the list:
There are multiple approaches to reverse the linked list. i will be discussing the optimal approach which reverses the list in **constant space and time**. to reverse the linked list we just need to move the address field of a current node into the address field of the node which 2 location away from the current node.
* Create three different pointers as prev, cur and next and initialize cur to the head and others to NULL
* Use while loop with termination condition based on the value of current==NULL
* Assign next pointer value of cur->next
* Change the value of cur->next with prev
* Now update the prev and cur pointers with cur and next respectively
* Finally assign the head pointer to prev and we are done.

## Stack as Abstract data type
#### Logical view
1. The stack is a collection with a property that an item in a stack can be inserted or removed from the one end generally referred to as a top
2. The stack is also referred to as a Last In First Out (LIFO). That means the most recently added item in the stack has to go out first
3. We need Push, Pop, Top and IsEmpty functionality for this ADT
4. Also, we need to perform all these operations in **constant time** O(1)

#### Operations
```
1. Insert the element (Push)                        O(1)
2. Remove the element (Pop)                         O(n)
3. Return the value of accessible element (Top)     O(1)
4. Check for the stack status (IsEmpty)             O(1)
5. Display stack                                    O(n)
```
#### Implementation 
##### Array (**Stack_ADT_using_Array_Linkedlist.cpp**)
So to implement the stack using the array first we need to create an array of some size. as we push the element is added at the higher index. the problem with this implementation is array might exhaust. we can handle this case by throwing the exception or implementing the array as a dynamic array. We will also maintain a variable that stores the index of top to do the push, pop, and top operation.

#### Psuedo code for the operations
1. Push:
* Check whether the **top+1** is a valid index or not
* If it's not valid then return stack overflow message or create a dynamic array
* update the value at index position
* Update top and the privates variable accordingly

2. Pop:
* Check whether the index value is valid or not
* Assign the NULL value to the index location of the array
* Update top and the privates variable accordingly

3. Top:
* Check whether the index value is valid or not
* If the index is valid to return the value stored at the index position of the array

4. isEmpty:
* Return the value based on the top variable

5. Display the list and variables
* Iterate through the array and display the elements
* Set a public method which can return the private variables

#### Linkedlist (**Stack_ADT_using_Array_Linkedlist.cpp**)
To implement the Stack using the Linked list in constant time we need to use some clever tricks. So while adding the element rather than iterating over the array and updating the last node we will update the head and add the nodes on the head. and this will enable us to perform the operations in constant time.

#### Psuedo code for the operations
1. Push:
* Create the node with the data part filled with value and address part with the head
* Update the head value with the address of the new node
* Update top and the privates variable accordingly

2. Pop:
* Store the value of head in a temp variable. Update the head value to the address stored in the address part of the head node
* Deallocate the memory by deleting the head node
* Update top and the privates variable accordingly

3. Top:
* Return the value stored at the head

4. isEmpty:
* Return the value based on the value of head

5. Display the list and variables
* Iterate through the linkedlist and display the elements
* Set a public method which can return the private variables

## Queue as Abstract data type
#### Logical view
1. The queue is a collection with a property that an item can be inserted from only one position called as rear and removed from one position called as a front
2. The queue is also referred to as a First In First Out (FIFO). That means the most recently added item in the stack has to go out last
3. We need Push, Pop, Top and IsEmpty functionality for this ADT
4. Also, we need to perform all these operations in **constant time** O(1)

#### Operations
```
1. Insert the element (Push)                        O(1)
2. Remove the element (Pop)                         O(n)
3. Return the value of accessible element (Front)   O(1)
4. Check for the stack status (IsEmpty)             O(1)
5. Display stack                                    O(n)
```
#### Implementation 
##### Array (**Queue_ADT_using_Array_Linkedlist.cpp**)
We can implement the queue ADT simply by creating the array of some size and then updating the front and rear values accordingly. The problem with this implementation comes when the rear index reaches the max size of an array. Now although the space is available we won't be able to perform the required operations. The solution to this is to use a **Circular Buffer**. In the case of the circular buffer we will create a circular array where the end of the array is logically connected to the front of the array. Which can be achieved by changing the index update rule.

**index update: (next index = (current index+1)%size of array)**

#### Psuedo code for the operations
1. Push:
* Check whether space is available or not and return the exception if it's full. To check that we will see the value of the next index from rear and front. **(rear+1)/n == front** 
* If the array is empty we need to update the front and rear to the same value
* In other cases just update the rear index value at rear index
* Update top and the privates variable accordingly

2. Pop:
* Check whether the array is empty or not. If the array is empty return the exception 
* If there is only one element in the array update the replace the value with NULL and update both front and back to -1
* In other cases just update the make the value at front index as NULL and update the front index
* Update top and the privates variable accordingly

3. Front:
* Return the value stored at the front index of a circular array

4. isEmpty:
* Return the value based on the front and rear variable

5. Display the list and variables
* Iterate through the array from front to rear and display the elements
* Set a public method which can return the private variables

#### Linkedlist (**Queue_ADT_using_Array_Linkedlist.cpp**)
To implement the Queue using the LinkedList in constant time we need to use some clever tricks. The identity of the link list is the address of the first node and we will use this for removal or pop operation. in order to perform the push operation in the constant time we need to store the address of the last node in the LinkedList. so in order to implement the Queue in constant time we will need two variables that store the address of the first and last node in the linked list.

#### Psuedo code for the operations
1. Push:
* Create the node with the data part filled with value and address part with NULL
* UPdate the address stored in the address field of a front node with the address of the newly created node
* Update front with the address of the new node

2. Pop:
* Store the value of head in a temp variable. Update the head value to the address stored in the address part of the head node
* Deallocate the memory by deleting the head node
* Update rear with the temp variable

3. Front:
* Return the value stored at the front node

4. isEmpty:
* Return the value based on the value of front and rear

5. Display the list and variables
* Iterate through the linkedlist and display the elements
* Set a public method which can return the private variablesss

## Tree as Abstract data type
#### Logical view
1. The tree is the data structure where the collection of entities called node is linked together to simulate the hierarchy 
2. The tree is a nonlinear data structure
3. The tree can only be traversed in one direction
4. The tree is a recursive data structure

#### Tree vocabulary
1. Nodes ->       The module we used to store the data and address
2. Edges ->       The link between the nodes
3. Root ->        The node from which the tree is recognized or in other words it is the base node of the tree
4. Children ->    Except the root node the all the nodes are children and every child node has a parent
5. Parent ->      The parent node is a node that is connected to the node and its level in the tree is 1 less than the child node.
6. Sibling ->     Children of the same parent
7. leaf ->        The nodes without children
8. Depth of node ->    Number of edges in the path from the root to a node
9. Height of node ->   Number of edges in **longest** path from the node to the leaf
10. Height of tree ->  height of root node
11. Binary Tree ->     A tree in which each node can at most 2 children
12. Strict/proper Binary Tree ->  Each node can have 2 or 0 children
13. complete binary tree ->       All levels except the last are completely filled and all nodes are as left as possible
14. Perfect binary tree ->        All the levels are completely filled (# of nodes = 2^height -1)
15. Balanced binary tree ->       The difference between left and right subtree for every node is not more than 1
16. Binary Search tree ->         A binary tree where for each node the value of the nodes in the left subtree is lesser than the value of all the nodes in the right subtree.

#### Operations
```
1. Insert the element                   O(log(n))
2. search the element                   O(log(n)) 
3. Remove the element                   O(log(n))
4. Find Max                             O(log(n))
5. Find Min                             O(log(n))
6. Find Height                          O(log(n))
7. Level order traversal                O(n)
8. Pre order traversal                  O(n)
9. In order traversal                   O(n)
10. Post order traversal                O(n)
```

** All the operation can be performed using recursion or iterative approach**

#### Implementation (BST)
##### Structure (**Tree_implementation.cpp**)

For the sake of simplicity, we are considering the binary search tree for the implementation and we are not considering the duplicate values during the tree creation. The same idea can be extended to implement any kind of tree. To implement the tree we need to create custom data modules called nodes which is the building block for the tree. The purpose of the node is to store the data and the address of its children and the purpose can be achieved by creating the node as a c++ structures. The advantage of using the tree data structure is a significant improvement in the insertion and search operations.

#### Psuedo code for the operations
1. Insert:
* If the tree is empty i.e. head is pointing to the NULL value we will create a new node and will point the head to the new node.
* Else will check for the data value and based on the data value we will try to navigate through the tree until we reach a node that is pointing to the NULL.
* As this will happen in recursion the program will eventually find the NULL node and at that time we will execute step 1.
* Iterative approach for the same can be implemented using a while loop to search the parent node and then we will execute step 1.

2. Search:
* Search operation is also similar to the insert operation except here we dont create a new node.
* We will use recursion or iterative algorithm to navigate through the tree based on the data part of the node.
* Will execute these steps until we find the node or come across a NULL node.

3. Remove:
* The remove operation is a bit tricky and we can perform this operation in more than one way.
* The remove operation first required us to locate the node in the tree.
* Now as we need to remove the element we need to replace it with some element that will maintain the BST structure intact.
* This we can do by replacing the data value of the node by **largest value from the left subtree or smallest value from the right subtree**
* Once we replace the data part of the Node we also need to delete the node which we used for the replacement.

4. Find Max
* Finding maximum is easy and can be achieved by recursion and iterative methods
* We know that in the binary tree all nodes on the left side will be smaller than the head so to find the largest element we just need to find the rightmost element in the tree

5. Find Min
* The minimum element in the binary tree will be a leftmost element it can be found by iterating on the left side of the tree until we reach the leaf node.

6. Find Height
* We can find the height of the tree recursively by finding the height of the left and right subtree.
* We will consider only the max value between left and right subtree
* Will stop the recursion call when the node is a leaf node
* As we know the height of the root when its empty is 0 so we will return -1 as during every recursion call we will update the height by +1

#### Tree traversal
7. Level order traversal
In the level order traversal, we visit the nodes of the tree level by level. Generally while traveling the node we travel from left to right. This traversal is also called a breadth-first search as we explore the tree horizontally. We can't travel the node just by storing the address of the current node as we will lose the information about other nodes. We will use **Queue** data structure to achieve the level order traversal.

* First, we will create to store the nodes
* Every time we will remove the node we will append the tree by its children
* The algorithm will run until the queue is empty. meaning that we have visited all the nodes

The next three algorithms are the variations of the depth-first search. The algorithms are called depth-first search because it explores the tree vertically. The only difference in the following three algorithms is in the order of reading the nodes. Conventionally we visit the left subtree before the right subtree which gives us three different possibilities fo the depth-first traversal.

8. Pre Order traversal (DLR)
In this traversal, we will first visit the node and read the data then we will explore the left subtree, and then we will explore the right subtree. Recursion is used for the implementation of this algorithm as the code is simple and easy to follow. In this traversal, we visit the node from the Root to leaf manner.

* We will first we will visit the node and read the data associated with the node.
* We will recursively call the preorder traversal for the left subtree
* Then we will recursively call the preorder traversal for the left subtree
* The algorithm will be terminated when we reach NULL node

9. In Order traversal (LDR)
In this traversal, we will first explore the left subtree then we will visit the node and read the data. Finally, we will explore the right subtree. Recursion is used for the implementation of this algorithm as the code is simple and easy to follow. The beauty of this traversal that it returns the sorted list of elements.

* We will recursively call the inorder traversal for the left subtree 
* Then we will visit the node and read the data associated with the node.
* Finally, we will recursively call the preorder traversal for the left subtree
* The algorithm will be terminated when we reach NULL node

10. Post Order traversal (LRD)
In this traversal, we will first explore the left subtree then we will explore the right subtree. Finally, we will visit the node and read the data. The algorithm will traverse the tree from leaf to root manner.

* We will recursively call the inorder traversal for the left subtree
* Then we will recursively call the preorder traversal for the left subtree 
* Finally, we will visit the node and read the data associated with the node.
* The algorithm will be terminated when we reach NULL node
