# Datastructure Implementation

### Welcome to the Datastructure.

Data Structures are a specialized means of organizing and storing data in computers in such a way that we can perform operations on the stored data more efficiently. Data structures have a wide and diverse scope of usage across the fields of Computer Science and Software Engineering.

### We talk about data-structure as
1. Mathematical/Logical models (Abstract view) (Just define the data models and data operations but no implementation)
2. Implementation (Here we "actually" implement the ADT, there can be multiple ways to implement the ADT)
3. operations and costs


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




















 

