//BREADTH FIRST SEARCH

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[++front];
}

bool is_empty_queue() {
    return front == rear;
}

void breadth_first_search(int start_vertex, int total_vertices) {
    int i, current_vertex;

    enqueue(start_vertex);
    visited[start_vertex] = true;

    while (!is_empty_queue()) {
        current_vertex = dequeue();
        printf("%d ", current_vertex);

        for (i = 1; i <= total_vertices; i ++) {
            if (adjacency_matrix[current_vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int i, j, total_vertices, start_vertex;

    printf("Enter the total number of vertices: ");
    scanf("%d", &total_vertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= total_vertices; i++) {
        for (j = 1; j <= total_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start_vertex);

    printf("The BFS traversal is: ");
    breadth_first_search(start_vertex, total_vertices);

    return 0;
}


//SAMPLE INPUT AND OUTPUT

//Enter the total number of vertices : 7
//Enter the adjacency matrix :
//0 1 1 1 1 0 0
//1 0 0 1 0 1 0
//1 0 0 0 0 0 1
//1 1 0 0 0 1 0
//1 0 0 0 0 0 1
//0 1 0 1 0 0 0
//0 0 1 0 1 0 0
//Enter the starting vertex : 1
//The BFS traversal is : 1 2 3 4 5 6 7