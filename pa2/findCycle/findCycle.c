#include "../graphutils.h"

// A program to find a cycle in a directed graph

// You may use DFS or BFS as needed
/* ... */
// bool contains(
//     size_t graphNodeCount,
//     graphNode_t node,
//     graphNode_t* parents
// ){
//     for (size_t i=0; i<graphNodeCount; i++) {
//         if(parents[i] == node){
//             return true;
//         }
//     }
//     return false;
// }
//recursive dfs that retur
bool dfs(
    int count,
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList,
    bool* visited,
    graphNode_t* parents,
    graphNode_t current
){
    visited[current] = true;
    AdjacencyListNode* neighbor = adjacencyList[current].next;  
    while(neighbor){
        //neighbor has not been visted
        if(!visited[neighbor->graphNode]){
            parents[current] = neighbor->graphNode;
            //parents[neighbor->graphNode] = current;
            if(dfs(count, graphNodeCount, adjacencyList,visited, parents, neighbor->graphNode)){
                //printf("%ld ", current);
                return true;
                
            }
        }
        
        else{
            parents[current] = neighbor->graphNode;
            //parents[neighbor->graphNode] = current;
            //printf("%ld ", current);
            return true;
            
        }
        neighbor = neighbor -> next;
    }
    parents[current] = -1;
    return false; //if cycle is not found
}

int main ( int argc, char* argv[] ) {

    // READ INPUT FILE TO CREATE GRAPH ADJACENCY LIST
    AdjacencyListNode* adjacencyList;
    /* ... */
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);

    graphNode_t* parents = calloc( graphNodeCount, sizeof(graphNode_t) );
    for (size_t i=0; i<graphNodeCount; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }

    // Array of boolean variables indicating whether graph node has been visited
    bool* visited = calloc ( graphNodeCount, sizeof(bool) );
    /* ... */
    for(int i = 0; i < graphNodeCount; i++)
        visited[i] = false;

    int count = 0;

    
    

    for (unsigned source=0; source<graphNodeCount; source++){
        if(dfs(count, graphNodeCount, adjacencyList, visited, parents, source)){
            //printf("is cyclic");
            // printf("%d ", source);
            for(size_t i = 0; i<graphNodeCount; i++){
                   //printf("source = %d, parents[%ld] = %ld\n" , source, i, parents[i]); 
            }
            
            graphNode_t temp;
            graphNode_t source;
            for(size_t i = 0; i<graphNodeCount; i++){
                   if(parents[i]!= -1){
                       source = parents[i];
                       temp = parents[source];
                    //    printf("temp parents[%ld] = %ld\n", i, temp );
                    //    printf("source parents[%ld] = %ld\n", i, source );
                       break;
                   } 
            }
            
            if(source!=61){
                printf("%ld ", source);
            }
            
            size_t count = 0;
            while(temp!= source && count < 6){
                printf("%ld ", temp);
                temp = parents[temp];
                count++;
            }

            // graphNode_t temp = parents[source];

            // do{
            //     printf("%ld ", temp);
            //     temp = parents[temp];
            // }while(temp != parents[source]);

            free(parents);
            free(visited);
            freeAdjList ( graphNodeCount, adjacencyList );
            return EXIT_SUCCESS;
            
        }
    }
    printf("is not cyclic");

    //  graphNode_t source = 0;


    // if(dfs(graphNodeCount, adjacencyList, isCyclic, visited, parents, source, 1)){
    //     printf("is cyclic");
    // }
    // else{
    //     printf("is not cyclic");
    // }

    // for (unsigned source=0; source<graphNodeCount; source++) {
    //     /* ... */
    //     if(dfs(graphNodeCount, adjacencyList, isCyclic, visited, parents, 0)){
    //         for(graphNode_t i = 0; i<graphNodeCount; i++){
    //             printf("%ld %ld " ,i, parents[i]);
    //         }
    //         printf("\n");
    //     }
    //     else{
    //         printf("DAG\n");
    //     }
    // }

    //if (!isCyclic) { printf("DAG\n"); }
    free(parents);
    free(visited);
    freeAdjList ( graphNodeCount, adjacencyList );
    return EXIT_SUCCESS;
}
