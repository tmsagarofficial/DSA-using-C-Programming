//DEPTH FIRST SEARCH

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

void depth_first_search(int start_vertex, int total_vertices) {
	int i;

	visited[start_vertex] = true;


	printf("%d ", start_vertex);

	for (i = 1; i <= total_vertices; i++) {
		if (adjacency_matrix[start_vertex][i] == 1 && !visited[i]) {
			depth_first_search(i, total_vertices);
		}
	}
}

void main() {
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

	printf("The DFS traversal is: ");
	depth_first_search(start_vertex, total_vertices);


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
//The DFS traversal is : 1 2 4 6 3 7 5