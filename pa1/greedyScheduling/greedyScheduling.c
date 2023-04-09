// C program to print a list of jobs sorted according to time
// Sorting is done using insertion sort
// Jobs are stored in sorted order using linked list
// Authors:
// Naishal Patel @naishal
// Yipeng Huang @yipenghuang0302

#include <stdio.h>
#include <stdlib.h>

struct node {
    int time; // The time of the job, this is the index by which we will sort
    int endTime;
    char job; // The letter name of the job
    struct node* next;
};

struct node* sorted_list_of_jobs = NULL;

int getCount(struct node* head)
{
    int count = 0; // Initialize count
    struct node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void sorted_insert (unsigned int time, unsigned int endTime, char job) {

    // Allocate node
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    // (*new_node).time = time;
    new_node->time = time;
    // (*new_node).job = job;
    new_node->job = job;
    new_node->endTime = endTime;
    // Special case for empty list or if new node should be at front
    if ( sorted_list_of_jobs == NULL || endTime < sorted_list_of_jobs->endTime ) {

        new_node->next = sorted_list_of_jobs;
        sorted_list_of_jobs = new_node;

    } 
    
    else {

        struct node* current_node = sorted_list_of_jobs;

        // Locate the node before the point of insertion
        // Compare values of time
        while ( current_node->next!=NULL && current_node->next->endTime <= endTime ) {
            current_node = current_node->next;
        }

        if(new_node->time <= current_node-> endTime){
            free(new_node);
            return;
        } 
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Driver program to test above functions
int main(int argc, char* argv[])
{
    // First peek at how many jobs and timeslots there are
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buf[256];

    // Read the number of jobs to be scheduled
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of jobs failed");
        exit(EXIT_FAILURE);
    }
    int jobcount = atoi(buf);

    // Next read the maximum number of timeslots
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of timeslots failed");
        exit(EXIT_FAILURE);
    }
    // int timeslots = atoi(buf) // unused metadata

    // Now read the rest of the file
    for ( int line=0; line<jobcount; line++ ) {

        if (!fgets(buf, 256, fp)) {
            perror("reading a line for a job failed");
            exit(EXIT_FAILURE);
        }

        char job;
        unsigned int time;
        unsigned int endTime;
        if (!sscanf(buf, "%c %d %d", &job, &time, &endTime)) {
            perror("parsing a line for a job failed");
            exit(EXIT_FAILURE);
        }

        // add job and time to sorted linked list
        sorted_insert ( time, endTime, job );

    }

    
    struct node* current_node = sorted_list_of_jobs;

    int c = getCount(sorted_list_of_jobs);

    if(c == 2){
        while (current_node!=NULL) {
            struct node* temp = current_node;
            printf( "%c\n", temp->job );
            current_node = temp->next;
            free(temp);
        }
    }

    //struct node* temp = current_node->next;
    else{
        while (current_node!=NULL){
        struct node* temp = current_node->next;
        printf("%c\n", current_node->job );
        if(current_node->endTime >= temp->time ){
            current_node = temp->next;
        }
        else{
            current_node = current_node->next;
        }
    }   
    }
    

    
    fclose(fp);

    exit(EXIT_SUCCESS);
    
}

/*#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Selection sort based approach to sorting jobs

int main(int argc, char* argv[]) {

    // First peek at how many jobs and timeslots there are
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buf[256];

    // Read the number of jobs to be scheduled
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of jobs failed");
        exit(EXIT_FAILURE);
    }
    int jobcount = atoi(buf);

    // Next read the maximum number of timeslots
    if (!fscanf(fp, "%s\n", buf)) {
        perror("reading the number of timeslots failed");
        exit(EXIT_FAILURE);
    }
    int timeslots = atoi(buf);

    // We've read the number of timeslots so close the file and start over
    fclose(fp);

    char jobList[jobcount];
    int i = 0;
    char *p = NULL;

    unsigned int slot = 1;
    while ( slot<timeslots) {

        FILE* fp = fopen(argv[1], "r");
        if (!fp) {
            perror("fopen failed");
            exit(EXIT_FAILURE);
        }

        char buf[256];

        // First read the number of jobs to be scheduled
        if (!fscanf(fp, "%s\n", buf)) {
            perror("reading the number of jobs failed");
            exit(EXIT_FAILURE);
        }

        // Next read the maximum number of timeslots
        if (!fscanf(fp, "%s\n", buf)) {
            perror("reading the number of timeslots failed");
            exit(EXIT_FAILURE);
        }
        
        // Now read the rest of the file
        for ( int line=0; line<jobcount; line++ ) {
            
            if (!fgets(buf, 256, fp)) {
                perror("reading a line for a job failed");
                exit(EXIT_FAILURE);
            }

            char job;
            unsigned int time;
            unsigned int end;
            if (!sscanf(buf, "%c %d %d", &job, &time, &end)) {
                perror("parsing a line for a job failed");
                exit(EXIT_FAILURE);
            }

            if ( time==slot ) {
                if(jobList[0]==NULL){
                    jobList[0] = job;
                    i++;
                }
                if()
                
                //printf("array = %c ", jobList[i]);
                //printf("position = %d\n", i);
                //printf("%c ", job);
                //printf("%d ", time);
                //printf("%d\n", end);
                //slot = slot+(end-time)+1;
            }

            
        }
        slot++;

        fclose(fp);

    }
        for(p = jobList; p < jobList + jobcount; p++){
            printf("%c\n", *p);
        }
    exit(EXIT_SUCCESS);
}*/