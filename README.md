# Datastructure Implementation

### Welcome to the Datastructure.

Data Structures are a specialized means of organizing and storing data in computers in such a way that we can perform operations on the stored data more efficiently. Data structures have a wide and diverse scope of usage across the fields of Computer Science and Software Engineering.

### We talk about data-structure as
1. Mathematical/Logical models (Abstract view) (Just define the data models and data operations but no implementation)
2. Implementation (Here we "actually" implement the ADT, there can be multiple ways to implement the ADT)
3. operations and costs


## List as Abstract data type
#### Logical view
1. Store a given number of elements of a data of a given data type
2. Write/modify element at a position
3. Read element at a position

#### Implementation (**List_ADT_using_Array.cpp**)
##### Array
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
first we will define an array of **some large** size. When the array is **full** we will create a new larger array, copy the previous array into the new array and free the memory for the previous array. The best policy is to double the size. The drawback of this implementation is large amount of space will be unallocated.


