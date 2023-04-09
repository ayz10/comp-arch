#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to determine whether an undirected graph is a tree

// A recursive function that returns true if no cycles found
bool isTreeDFS (
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList,
    bool* visited,
    graphNode_t parent,
    graphNode_t current
) {

    // First see if current node has already been visited, indicating a cycle found
    /* ... */
    // if(visited[current] == true){
    //     return false;
    // }

    // Current node was not already visited, so now mark it as visited
    /* ... */
    visited[current] = true;

    // Now iterate through each of the neighboring graph nodes
    AdjacencyListNode* neighbor = adjacencyList[current].next;
    while (neighbor) {
        //neighbor->graphNode!=parent
        if (!visited[neighbor->graphNode]) {
            // If the neighbor nodes is not the parent node (the node from which we arrived at current), call DFS
            /* ... */
            isTreeDFS(graphNodeCount, adjacencyList, visited, current, neighbor->graphNode);
                //return false;
            
        }
        else if (neighbor->graphNode!=parent){
               return false; 
        }
        neighbor = neighbor->next;
    }

    // All DFS searches from current node found no cycles, so graph is a tree from this node
    return true;
}

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList = NULL;
    /* ... */
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);

    // Array of boolean variables indicating whether graph node has been visited
    bool* visited = calloc ( graphNodeCount, sizeof(bool) );
    /* ... */
    for(int i = 0; i < graphNodeCount; i++)
        visited[i] = false;

    /* ... */
    graphNode_t source = 0;

    if(isTreeDFS(graphNodeCount, adjacencyList, visited, source, 1)){
        printf("yes");
    }
    else{
        printf("no");
    }
    freeAdjList(graphNodeCount, adjacencyList);
    // isTreeDFS(graphNodeCount, adjacencyList, visited, source, source);

    // printf(isTreeDFS ? "yes" : "no");

    return EXIT_SUCCESS;
}
