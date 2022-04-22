// [2022/04/18 10:30]

/** Data Structure 
 * that may have features of stack, queue etc.
 * 
 * @author Ilgar Roshen [951f5add73cadbd9738c6bdc387f0699, a52c3cb021210b2e62da5ef3b4d455f2f3b4d455f2]
 * 7ed5af0df37ca8b2279938f8cb884fbe
 * 7c13cb85b19ea240922fa2c1aa8716c2
 * c7aebb3d6a04572ed48f8495eedd4088
 * bc537c061e8b2d3460a7cd32b941b4f8
 * 919eeb47f6814fc0f4ef479d92c91d5a
 * d30197117050d5ed7f071cd3ade4c7a8
 * 322b83c0c3deb76c56ba4e649234b8bd
 * 
 * @version 1.0.0 2022/04/18
 * 
 */
#include <stdlib.h>
#include <stdio.h>

/** Meta data
 * 
*/
struct LinkedListMeta
{
    unsigned int length;
};

/** Linked List Node
 * 
 * NOTE: the "data" should have generic type 
 */
struct LinkedListNode
{
    char *data;
    struct LinkedListNode *prev;
    struct LinkedListNode *next;
};

// Types : Node
typedef struct LinkedListNode LinkNode;

// Global : First Node
LinkNode *firstNode = NULL;

// Global : First Node
LinkNode *lastNode = NULL;

// Number of Nodes in the [ LinkedList ] Chain
unsigned int numberOfChains = 0;

/** Create Node
 * 
 */
LinkNode *createNode()
{
    // create pointer
    LinkNode *node = NULL;

    // alocate memory - create Node [ object ]
    node = (LinkNode *)malloc(sizeof(LinkNode));

    // count the number of Nodes
    numberOfChains++;

    // pointer [ address ] to the Node object
    return node;
}

/** Add [ or link ] a Node [ to the chain ]
 * 
 */
LinkNode *add(char *data)
{
    // create a node
    LinkNode *newNode = createNode();

    // set the value
    (*newNode).data = data;

    // initialize if the chain does not have any node
    if (firstNode == NULL)
    {
        // link it as the First one
        firstNode = newNode;

        // and link it as the Last one
        lastNode = newNode;

        // exit with the new Node [ object ] which is both First and Last one
        return newNode;
    }

    // attach to the tail [ side ] of the chain
    (*lastNode).next = newNode;

    // link to the previous node [ latest node becomes previous to this one ]
    (*newNode).prev = lastNode;

    // initialize a link to the next node as NULL
    // which also defines this Node [ object ] as the [ latest ] last one
    (*newNode).next = NULL;

    // this - new Node [object]
    return newNode;
}

/** Clear the memory used by these LinkNode objects
 * 
*/
void cleanUpMemory()
{
    // check if the list is empty
    if (firstNode == NULL)
    {
        // exit it empty
        return;
    }

    // set [ these local position ] pointers to the first Node [ start position ]
    LinkNode *currentNode = firstNode;
    LinkNode *nodeToDelete = firstNode;
    // loog through the Chain to delete each Node
    for (unsigned int i = 0; i < numberOfChains; i++)
    {
        // store the current Node [ pointer ]
        nodeToDelete = currentNode;
        // update the current Node [ pointer ] - now, it points to the next one
        currentNode = (*nodeToDelete).next;
        // delete the Node
        free(nodeToDelete);
    }
}

// entry [ for testing etc. ]
int main()
{
    // create a node with LinkNode type
    // LinkNode *link = createNode();

    // create a string
    char str[] = "Hi there";
    // create [ and add ] a node with the string 
    LinkNode *link = add(str);

    // log
    printf("Address of the ChainLink: %x", &link);

    // ~garbage-collection
    cleanUpMemory();

    // success
    return 0;
}

