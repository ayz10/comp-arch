#include <stdlib.h>
#include <stdio.h>

// A program to perform a LEVEL ORDER (BREADTH-FIRST) TRAVERSAL of a binary search tree

// BINARY SEARCH TREE

typedef struct BSTNode BSTNode;
struct BSTNode {
    int key;
    struct BSTNode* left; // nodes with smaller key will be in left subtree
    struct BSTNode* right; // nodes with larger key will be in right subtree
};

struct BSTNode* newNode(int item){
    struct BSTNode* temp = malloc(sizeof(struct BSTNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Add new data to the BST using recursion
/* ... */
struct BSTNode* insert(struct BSTNode* node, int key){
    if(node == NULL){
        return newNode(key);
        //printf("new BST");
    }
    if(key < node->key){
        node->left = insert(node->left, key);
        //printf("inserted %d to the left", key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
        //printf("inserted %d to the right", key);
    }
    return node;
}
// Delete the BST using recursion
/* ... */
void delete_bst(struct BSTNode* node){
    if(node!= NULL){
        delete_bst(node->left);
        delete_bst(node->right);
        free(node);
    }
}

// LINKED LIST IMPLEMENTATION OF QUEUE

// queue needed for level order traversal
/* ... */
typedef struct QueueNode QueueNode;
struct QueueNode {
    struct BSTNode* data; //UNSURE IF SHOULD BE POINTER OR NOT
    struct QueueNode* next; // pointer to next node in linked list
};
struct Queue {
    struct QueueNode* front; // front (head) of the queue
    struct QueueNode* back; // back (tail) of the queue
};

typedef struct Queue Queue;


// Append a new QueueNode to the back of the Queue
void enqueue ( Queue* queue, BSTNode* data ) {
  /* ... */
    QueueNode* queueNode = malloc(sizeof(QueueNode));
    queueNode -> data = data;
    queueNode -> next = NULL; // At back of the queue, there is no next node.

    if (queue->back==NULL) { // If the Queue is currently empty
        queue->front = queueNode;
        queue->back = queueNode;
    } else {
        queue->back->next = queueNode;
        queue->back = queueNode;
    }

    return;
}

// Remove a QueueNode from the front of the Queue
struct BSTNode* dequeue ( Queue* queue ) {

    if (queue->front==NULL) { // If the Queue is currently empty
        return '\0';
    } else {

        // The QueueNode at front of the queue to be removed
        QueueNode* temp = queue->front;
        struct BSTNode* data = temp->data;

        queue->front = temp->next;
        if (queue->back==temp) { // If the Queue will become empty
            queue->back = NULL;
        }

        free(temp);
        return data;
    }
}


int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE BINARY SEARCH TREE
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }
    BSTNode* root = NULL;
    int key;
    while ( fscanf(fp, "%d", &key)!=EOF ) {
        root = insert (root, key);
    }
    fclose(fp);

    // USE A QUEUE TO PERFORM LEVEL ORDER TRAVERSAL
    Queue queue = { .front=NULL, .back=NULL };
    BSTNode* currBSTNode = root;
    do {
        /* ... */
        printf("%d ", currBSTNode->key);
        if(currBSTNode->left){
            enqueue(&queue, currBSTNode->left);
        }
        if(currBSTNode->right){
            enqueue(&queue, currBSTNode->right);
        }
        currBSTNode = dequeue(&queue);
    } while ( currBSTNode!=NULL );

    delete_bst(root);
    return EXIT_SUCCESS;
}
