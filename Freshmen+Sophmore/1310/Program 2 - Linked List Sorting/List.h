#ifndef LIST_H
#define LIST_H

// LIBRARIES
#include <iostream>
using namespace std;

// LIST CLASS + LINKED LIST DEFINITION 
template <typename T>
class List                                              // Class for each node
{
    private: 
        struct listNode                                 // A Node
        {
            T value;                                    // Value held by each node
            struct listNode* next;                             // Pointer to next node in linked list
            struct listNode* prev;                             // Pointer to the previous node in linked list
        };

        listNode* head;                                 // Front of linked list
        listNode* tail;                                 // Back of linked list

    // CLASS FUNCTIONS
    public:
        List();                                         // Constructor, sets pointers to null
        ~List();                                        // Destructor, deletes all nodes
        void print();                                   // Calls private print function
        void append(T);                                 // Adds value to end of list
        void mergesort();                               // call private merge sort, resets head and tail
    private:
        void print(listNode*);                          // Prints out every value in linked list
        listNode* mergesort(listNode*, listNode*);      // handles recursion 
        listNode* merge(listNode*, listNode*);          // merges two partitions together
        listNode* split(listNode*, listNode*);          // splits linked list into two 
};

// FUNCTION DEFINTIONS 

template <typename T>
// List() is a constructor that makes an empty list, and sets the pointers to NULL 
List<T>::List()
{
    head = NULL;
    tail = NULL;
} 

template <typename T>
// ~List() is a destructor that deletes all nodes by traversing through the linked list
List<T>::~List()
{
    listNode* currentNode;                  // Node used to go through the linked list
    listNode* nextNode;                     // Node that points to next node, as to not lose reference

    currentNode = head;                     // Begin at the start of the linked list

    while(currentNode != NULL)              // Loop until we are not at the end of the list
    {
        nextNode = currentNode->next;           // Set our next node
        delete currentNode;                     // delete the current node
        currentNode = nextNode;                 // change current node to the next node in the list
    }
}

template <typename T>
// print() will call the private print(node) function 
void List<T>::print()
{
    print(head);
}

template <typename T>
// append(newValue) will take a value, put it into a node and add it to the end of the list or first in list if empty
void List<T>::append(T newValue)
{
    listNode* newNode;              // Create the new node to be appended
    newNode = new listNode;         // Allocates the new node
    newNode->value = newValue;   // Set our parameter to our new nodes value
    newNode->next = NULL;
    newNode->prev = NULL;

    cout << &(this->head);

    if(!(this->head))                       // If linked list is empty, set it to head and tail
    {
        head = newNode;
        tail = newNode;
    }   
    else                            // If not empty, set it as the new tail
    {   
        tail->next = newNode;           // Put node after old tail
        newNode->prev = tail;           // Set its previous to the old tail

        tail = newNode;                 // Make it the new tail 
    }
}

template <typename T>
// public function for using private mergeSort(). It will call other mergeSort and will reassign the head and tail to the newly sorted list 
void List<T>::mergesort()
{
    head = mergesort(head, tail);   // Final mergesort will return the head of the newly sorted list, so we can just set the head to it.

    listNode* tempPtr = head;       // Make a temporary pointer to traverse the linked list
    while(tempPtr->next != NULL)    // While the next node exist
    {
        tempPtr = tempPtr->next;        // shift right
    }

    tail = tempPtr;                 // After tempPtr>next == NULL, we have found the final node and can assign it to tail. 
}

template <typename T>
// print(nodePtr) will print out the nodes values starting from the node sent to it from the public print() function
void List<T>::print(listNode* currentNode)
{
    cout << "\n\nCounty List: " << endl;
    while(currentNode)                          // While not null, still in the list
    {
        cout << *(currentNode->value) << endl;         // Print out the value
        currentNode = currentNode->next;            // Go to the next node
    }
}

template <typename T>
// mergeSort(firstNode, lastNode) will handle the base and recursive cases for merge sort. It calls other functions to carry out non-base case operations
typename List<T>::listNode* List<T>::mergesort(listNode* first, listNode* last)
{
    // Base Case
    if(!first || !first->next || !last)                     // if our linked list is empty or one element in length
    {
        return first;                                       // Can no longer be partitioned
    }
    
    // Recursive Case
    listNode* firstPart = first;                        // Set the first partition to the leftmost element (the head)
    listNode* secondPart = split(first, last);          // Set the second partition to element right after the middle point (split() function returns this)

    firstPart = mergesort(firstPart, secondPart->prev); // mergeSort the left partition
    secondPart = mergesort(secondPart, last);           // mergeSort the right partition

    return merge(firstPart, secondPart);                // merge together and return the sorted linked list
}

template <typename T>
// merge(firstPartition, SecondPartition) will go through two split partitions until they are properly sorted in descending order 
typename List<T>::listNode* List<T>::merge(listNode* firstPart, listNode* secondPart)
{
    if(!firstPart)                                              // If we have nothing remaining in our first partition
    {
        return secondPart;                                          // send our second partition
    }
    
    if(!secondPart)                                             // If we have nothing remaining in our second partition
    {
        return firstPart;                                           // send our first partition
    }

    // Now we know that both partitions have elements within them. We must now compare them to find out which one contains a larger value. 
    if(*(firstPart->value) > *(secondPart->value))                    // if our first partition has data larger than the second partition
    {
        firstPart->next = merge(firstPart->next, secondPart);       // Recursively call merge to get the next large value that will go after our current node
        firstPart->next->prev = firstPart;                          // set our newly sorted next nodes prev to our current first partitions node (the one that will be left of it in order)
        firstPart->prev = NULL;                                     // this will be the new head of this partition 
        return firstPart;                                           // return the new head of this partition 
    }
    else                                                        // if our second partition has data larger or equal too our first partition 
    {
        secondPart->next = merge(firstPart, secondPart->next);      // Recursively call merge to get the next large value that will go after our current node
        secondPart->next->prev = secondPart;                        // set our newly sorted next nodes prev to our current second partitions node (the one that will be left of it in order)
        secondPart->prev = NULL;                                    // this will be the new head of this partition 
        return secondPart;                                          // return the new head of this partition 
    }
}

template <typename T>
// split(firstNode, lastNode) will be send a partition of the linked list, find its midpoint and then split it. Returns the head of the left partition
typename List<T>::listNode* List<T>::split(listNode* first, listNode* last)
{
    listNode* middleNode;
    listNode* left;
    listNode* right;
    listNode* temp;
    bool flag = true;

    left = first;                       // left side of the partition
    right = last;                       // right side of the partition

    while(flag)                             // While they are not the same address
    {
        if(left == right)
        {
            flag = false;
            break;
        }

        right = right->prev;                // Shift right over one

        if(right == left)
        {
            flag = false;
            break;
        }

        left = left->next;                  // shift left over one
    }

    middleNode = right;                  // Left and Right are now in middle, set it to middle 

    temp = right->next;

    middleNode->next = NULL;            // Sever link from middle node to the next node in the linked list, its now split in 2

    return temp;                        // return the right parition right after the middle node was, where we partitioned the list (second partition head)
}


#endif 