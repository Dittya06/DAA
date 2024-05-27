/* C program for Tower of Hanoi*/
/*Application of Recursive function*/
#include <stdio.h>
void hanoifun(int n, char fr, char tr, char ar)//fr=from rod,tr =to rod, ar=aux rod
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", fr, tr);
        return;
    }
    hanoifun(n-1, fr, ar, tr);
    printf("\n Move disk %d from rod %c to rod %c", n, fr, tr);
    hanoifun(n-1, ar, tr, fr);
}

int main()
{
    int n = 3; // n immplies the number of discs
    hanoifun(n, 'A', 'C', 'B');  // A, B and C are the name of rod
    return 0;
}


//Merge sort
#include<stdio.h>

void merge(int a[50],int lb,int mid,int ub)
{
	int i=lb,j=mid+1,b[50],k=lb;//k=0
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];	
	while(j<=ub)
		b[k++]=a[j++];	
	/*i=lb;
	for(j=0;j<k;j++)
	{
		a[i]=b[j];
		i++;	
	}*/
	k=lb;
	while(k<=ub)
	{
		a[k]=b[k];
		k++;	
	}
	return;
}

void merge_sort(int a[50],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(a,lb,mid);
		merge_sort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
	return;
}

int main()
{
    int n,i,a[50];

    printf("\nEnter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}


/*  C Program to implement Quick Sort using recursion  */

#include <stdio.h>

void quicksort (int [], int, int);

int main()
{
    int list[50];
    int size, i;

    printf("How many elements u want to Sort :: ");
    scanf("%d", &size);

    printf("\nEnter the elements below to be sorted :: \n");

    for (i = 0; i < size; i++)
    {
        
        scanf("%d", &list[i]);
    }

    quicksort(list, 0, size - 1);

    printf("\nAfter implementing Quick sort, Sorted List is :: \n\n");

    for (i = 0; i < size; i++)
    {
        printf("%d  ", list[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
}

/*BFS    */
#include <stdio.h>

#define MAX_NODES 100

void addEdge(int u, int v, int adjMatrix[MAX_NODES][MAX_NODES]) //node value starts from 1
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = -1;
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void BFS (int startNode, int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	static int visited[MAX_NODES];
	int queue[MAX_NODES], current, front = 0, rear = 0, i;
	
	visited[startNode] = 1;
	queue[rear++] = startNode;
	
	printf("BFS Traversal starting from node %d: ",startNode+1);
	
	while(front != rear)
	{
		current = queue[front++];
		printf("%d ",current + 1);
		
		for(i = 0; i < nodes; i++)
		{
			if(adjMatrix[current][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}	
}

int main()
{
    int i, nodes, edges, u, v;
    static int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node) (node value starts from 1):\n"); //node value starts from 1
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u-1, v-1, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);
    
    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &u);
    BFS(u-1, nodes, adjMatrix);
    
    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 5
Enter the edges (format: from_node to_node) (node value starts from 1):
1 2
1 3
1 4
3 4
3 5
Adjacency Matrix:
  0   1   1   1   0
 -1   0   0   0   0
 -1   0   0   1   1
 -1   0  -1   0   0
  0   0  -1   0   0
Enter the starting node for BFS traversal: 1
BFS Traversal starting from node 1: 1 2 3 4 5
--------------------------------
Process exited after 28.34 seconds with return value 0
Press any key to continue . . .
*/


/*DFS*/
#include <stdio.h>

#define MAX_NODES 100

void addEdge(int u, int v, int adjMatrix[MAX_NODES][MAX_NODES]) //node value starts from 1
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = -1;
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void DFS(int startNode, int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	static int visited[MAX_NODES];
	int stack[MAX_NODES], current, top=-1, i;
	
	visited[startNode] = 1;
	stack[++top] = startNode;
	
	printf("DFS Traversal starting from node %d: ",startNode+1);
	
	while(top != -1)
	{
		current = stack[top--];
		printf("%d ",current + 1);
		
		for(i = 0; i < nodes; i++)
		{
			if(adjMatrix[current][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				stack[++top] = i;
			}
		}
	}
}

int main()
{
    int i, nodes, edges, u, v;
    static int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node) (node value starts from 1):\n"); //node value starts from 1
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u-1, v-1, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    printf("\nEnter the starting node for DFS traversal: ");
    scanf("%d", &u);
    DFS(u-1, nodes, adjMatrix);
    
    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 5
Enter the edges (format: from_node to_node) (node value starts from 1):
1 2
1 3
1 4
3 4
3 5
Adjacency Matrix:
  0   1   1   1   0
 -1   0   0   0   0
 -1   0   0   1   1
 -1   0  -1   0   0
  0   0  -1   0   0

Enter the starting node for DFS traversal: 1
DFS Traversal starting from node 1: 1 4 3 5 2
--------------------------------
Process exited after 16.56 seconds with return value 0
Press any key to continue . . .
*/



// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

//void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main() {
  int Graph[MAX][MAX], i, j, n, u;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;

  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}


/*job sequence*/
//Job sequencing problem

#include<stdio.h>

struct job
{
	int seq;
	int profit;
	int deadline;
};
typedef struct job job;

void job_sort(job a[50],int n)
{
	int i,j,flag;
	job t;
	
	for(i=0; i<n-1; i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j].profit < a[j+1].profit)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag == 0)
			return;
	}
}

int max_deadline(job a[50],int n)
{
	int i,max_dead=a[0].deadline;
	for(i=1;i<n;i++)
	{
		if(a[i].deadline > max_dead)
			max_dead=a[i].deadline;
	}	
	
	return max_dead;
}

void job_sequence(job a[50],int n,int max)
{
	int i,j,k,total_profit=0;
	job m[50];
	
	for(i=0;i<=max;i++)
	{
		m[i].seq=0;
		m[i].profit=0;
		m[i].deadline=i;
	}
	
	for(i=0;i<n;i++)
	{
		k=a[i].deadline;
		if(m[k].seq == 0)
		{
			m[k].seq=a[i].seq;
			m[k].profit=a[i].profit;
			total_profit+=m[k].profit;
		}
		else
		{
			for(j=1;j<k;j++)
			{
				if(m[j].seq==0)
				{
					m[j].seq=a[i].seq;
					m[j].profit=a[i].profit;	
					total_profit+=m[j].profit;	
					break;	
				}
			}
		}
	}
	
	printf("Job sequence:");
    	printf("\nHour  :");
	for(i=1;i<=max;i++)
	{
		printf("%5d",i);
	}
   	printf("\nJob   :");
	for(i=1;i<=max;i++)
	{
		printf("%5d",m[i].seq);
	}
    	printf("\nProfit:");
	for(i=1;i<=max;i++)
	{
		printf("%5d",m[i].profit);
	}
	printf("\nNet profit = %d",total_profit);
}

int main()
{
	int i,n,max;
	job a[50];
	
	printf("Enter the no. of jobs: ");
	scanf("%d",&n);
	
	printf("Enter the details of job:\n");
	for(i=0;i<n;i++)
	{
		a[i].seq=i+1;
		printf("Job %d profit: ",i+1);
		scanf("%d",&a[i].profit);
		printf("Job %d deadline: ",i+1);
		scanf("%d",&a[i].deadline);		
	}
	
	job_sort(a,n);
	max=max_deadline(a,n);
	job_sequence(a,n,max);
	
	return 0;
}
/*
Output:
------
Enter the no. of jobs: 5
Enter the details of job:
Job 1 profit: 10
Job 1 deadline: 2
Job 2 profit: 15
Job 2 deadline: 2
Job 3 profit: 10
Job 3 deadline: 1
Job 4 profit: 5
Job 4 deadline: 3
Job 5 profit: 1
Job 5 deadline: 3
Job sequence:
Hour  :    1    2    3
Job   :    1    2    4
Profit:   10   15    5
Net profit = 30
*/

/*Bellmanford*/
#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX_NODES 100

struct Edge {
    int src, dest, weight;
};

void addEdge_dir(int u, int v, int weight, struct Edge edges[], int *E) {
    edges[*E].src = u;
    edges[*E].dest = v;
    edges[*E].weight = weight;
    (*E)++;
}

void addEdge_undir(int u, int v, int weight, struct Edge edges[], int *E) {
    edges[*E].src = u;
    edges[*E].dest = v;
    edges[*E].weight = weight;
    (*E)++;
    
    edges[*E].src = v;  // Adding the reverse edge for undirected graph
    edges[*E].dest = u;
    edges[*E].weight = weight;
    (*E)++;
}

void displayEdges(int E, struct Edge edges[]) {
    int i;
    printf("Edges:\n");
    for (i = 0; i < E; ++i) {
        printf("(%d, %d) weight %d\n", edges[i].src+1, edges[i].dest+1, edges[i].weight);
    }
}

void bellmanFord(int V, int E, struct Edge edges[], int start) {
    int i, j, distance[V], parent[V], u, v, w;
    for (i = 0; i < V; ++i) {
        distance[i] = INF;
        parent[i] = -1; // Initialize parent array to -1
    }
    distance[start] = 0;

    for (i = 1; i < V; ++i) {
        for (j = 0; j < E; ++j) {
            u = edges[j].src;
            v = edges[j].dest;
            w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u; // Update parent vertex
            }
        }
    }

    // Check for negative weight cycles
    for (i = 0; i < E; ++i) {
        u = edges[i].src;
        v = edges[i].dest;
        w = edges[i].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances and paths
    printf("Vertex\tDistance from Start\tPath\n");
    for (i = 0; i < V; ++i) {
        printf("%d\t%d\t\t\t", i + 1, distance[i]);
        int current = i;
        while (current != start) {
            printf("%d <- ", current + 1);
            current = parent[current];
        }
        printf("%d\n", start + 1);
    }
}



int main() {
    int V, E, start, ch, src, dest, weight, i;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX_NODES];
    printf("1. Directed Graph\n2. Un-directed Graph\nEnter your choice: ");
    scanf("%d", &ch);

    int totalEdges = 0;

    switch (ch) {
        case 1:
            printf("Enter the edges (format: source destination weight) (node value strats from 1):\n");
            for (i = 0; i < E; ++i) {
                scanf("%d %d %d", &src, &dest, &weight);
                addEdge_dir(src-1, dest-1, weight, edges, &totalEdges);
            }
            break;
        case 2:
            printf("Enter the edges (format: source destination weight) (node value strats from 1):\n");
            for (i = 0; i < E; ++i) {
                scanf("%d %d %d", &src, &dest, &weight);
                addEdge_undir(src-1, dest-1, weight, edges, &totalEdges);
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    displayEdges(totalEdges, edges);

    printf("Enter the starting vertex: "); //node value starts from 1
    scanf("%d", &start);

    bellmanFord(V, totalEdges, edges, start-1);

    return 0;
}

/*
Output:
------
Enter number of vertices: 5
Enter number of edges: 8
1. Directed Graph
2. Un-directed Graph
Enter your choice: 1
Enter the edges (format: source destination weight) (node value strats from 1):
1 2 10
2 4 1
1 3 5
3 2 3
3 4 9
3 5 2
5 1 2
5 4 6
Edges:
(1, 2) weight 10
(2, 4) weight 1
(1, 3) weight 5
(3, 2) weight 3
(3, 4) weight 9
(3, 5) weight 2
(5, 1) weight 2
(5, 4) weight 6
Enter the starting vertex: 1
Vertex  Distance from Start     Path
1       0                       1
2       8                       2 <- 3 <- 1
3       5                       3 <- 1
4       9                       4 <- 2 <- 3 <- 1
5       7                       5 <- 3 <- 1
*/


/*nQUeen*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 30

int position[SIZE]={0}; /*position[3]=2 means the third queen is on the second column  
/*The index represents the row(the queen), the value represents the column*/

int place(int k){ /*returns 1 if the place is safe */
	int i;
	for(i=1;i<k;i++){ /*from the first row to the current row-1*/
	    if((position[i]==position[k])||((abs(position[i]-position[k])==abs(i-k)))) /*if same column or same diagonal*/
	    	return 0;
	}
	return 1;
}
void print_sol(int n){ /*This funciton prints the solution*/
	int i,j;
	printf("\n\n The solution: \n" );	
	for(i=1;i<=n;i++){
	    for(j=1;j<=n;j++){
	        if(position[i]==j) /*If the ith queen is stored at the current column j*/
	            printf("Q\t");
	        else
	            printf("*\t");
	        }
	    printf("\n");
	}
}
int queen(int k, int n){ /*k is number of current queen and n is the total queens number*/
	if (k==0) /*No valid solution condition*/
		return 0;
	position[k]=position[k]+1; /*Move to the next column*/
	while((position[k]<=n)&&!place(k)){ /*if we still have columns left and the place is not valid keep checking the next columns*/
	    position[k]++;
	}
	if(position[k]<=n){ /*if the queen is safely placed*/
	    if(k==n){ /*if all queens are placed print solution*/
	        print_sol(n);
	        return 1;
	    }
	    else{
	        /*Move to the next queen*/
			position[++k]=0; /*Start from the leftmost column*/
	        queen(k,n);
	    }
	}
	else
	    queen(k-1,n); /*backtrack to change the previous queen's place*/
}
/***Recursive function to calculate factorial***/

int main(){
	int n;
	printf("Enter the number of Queens:\n");
	scanf("%d",&n);
	if(!queen(1,n)) /*1 is for the first queen*/
		printf("\n No valid solution!\n");
	return 0;
}

/*
Output:
------
Enter the number of Queens:
8


 The solution: 
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*/


/*Graph colouring*/
#include <stdio.h>

#define MAX_NODES 100

// Function to print the solution
void printSolution(int color[], int nodes)
{
    int i;
    printf("Solution Exists: Following are the assigned colors\n");
    for (i = 0; i < nodes; i++)
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int v, int graph[MAX_NODES][MAX_NODES], int color[], int c, int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// A recursive utility function to solve the graph coloring problem
int graphColoringUtil(int graph[MAX_NODES][MAX_NODES], int m, int color[], int v, int nodes)
{
    int c;

    // Base case: If all vertices are assigned a color then return true
    if (v == nodes)
        return 1;

    // Consider this vertex v and try different colors
    for (c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is safe
        if (isSafe(v, graph, color, c, nodes))
        {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, nodes))
                return 1;

            // If assigning color c doesn't lead to a solution then remove it (backtrack)
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return 0;
}

// This function solves the m Coloring problem using backtracking. It returns false if the m colors cannot be assigned, otherwise it returns true and prints the assignments of colors to all vertices.
int graphColoring(int graph[MAX_NODES][MAX_NODES], int m, int nodes)
{
    // Initialize all color values as 0. This initialization is needed for the correct functioning of isSafe()
    int color[MAX_NODES] = {0};

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, color, 0, nodes))
    {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution(color, nodes);
    return 1;
}

// Function to display the adjacency matrix
void displayMatrix(int graph[MAX_NODES][MAX_NODES], int nodes)
{
    int i,j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}

int main()
{
    int nodes, edges, u, v, i;
    int graph[MAX_NODES][MAX_NODES] = {0};  // Initialize the graph with no edges

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node) (node value starts from 1): \n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int m; // Number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Display the adjacency matrix
    displayMatrix(graph, nodes);

    // Solve the m-coloring problem
    graphColoring(graph, m, nodes);

    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 4
Enter number of edges in the graph: 3
Enter the edges (format: from_node to_node) (node value starts from 1): 
1 2
2 3
3 4
Enter the number of colors: 5
Adjacency Matrix:
  0   1   0   0 
  1   0   1   0 
  0   1   0   1 
  0   0   1   0 
Solution Exists: Following are the assigned colors
Vertex 1 ---> Color 1
Vertex 2 ---> Color 2
Vertex 3 ---> Color 1
Vertex 4 ---> Color 2
*/

/*MAtrix multiplication*/
#include<stdio.h>
#include<limits.h>

int N;

void PrintOptimalParens(int s[][N], int i, int j);

void MatrixChainOrder(int p[])
{
    int n = N - 1;
    int m[n+1][n+1], s[n+1][n+1];
    int i, l, j, k, q;

    // Initialize the diagonal of m to 0
    for(i=1; i<=n; i++)
        m[i][i] = 0;

    // Compute the matrix chain order
    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i; k<j; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                    printf("m[%d][%d] = %d split at k = %d\n", i, j, q, k);
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);
    PrintOptimalParens(s, 1, n);
}

void PrintOptimalParens(int s[][N], int i, int j)
{
    if(i == j)
        printf(" A%d ", i);
    else
    {
        printf("(");
        PrintOptimalParens(s, i, s[i][j]);
        PrintOptimalParens(s, s[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int i;
    printf("Enter number of dimensions: ");
    scanf("%d", &N);
    int p[N];
    printf("Enter dimensions:\n");
    for(i=0; i<N; i++)
        scanf("%d", &p[i]);
    MatrixChainOrder(p);
    return 0;
}

/*
Output:
------
Enter number of dimensions: 7
Enter dimensions:
30
35
15
5
10
20
25
m[1][2] = 15750 split at k = 1
m[2][3] = 2625 split at k = 2
m[3][4] = 750 split at k = 3
m[4][5] = 1000 split at k = 4
m[5][6] = 5000 split at k = 5
m[1][3] = 7875 split at k = 1
m[2][4] = 6000 split at k = 2
m[2][4] = 4375 split at k = 3
m[3][5] = 2500 split at k = 3
m[4][6] = 6250 split at k = 4
m[4][6] = 3500 split at k = 5
m[1][4] = 14875 split at k = 1
m[1][4] = 9375 split at k = 3
m[2][5] = 13000 split at k = 2
m[2][5] = 7125 split at k = 3
m[3][6] = 5375 split at k = 3
m[1][5] = 28125 split at k = 1
m[1][5] = 27250 split at k = 2
m[1][5] = 11875 split at k = 3
m[2][6] = 18500 split at k = 2
m[2][6] = 10500 split at k = 3
m[1][6] = 36750 split at k = 1
m[1][6] = 32375 split at k = 2
m[1][6] = 15125 split at k = 3
Minimum number of scalar multiplications: 15125
(( A1 ( A2  A3 ))(( A4  A5 ) A6 ))
*/

/* Fractional KAnpsack*/
//Fractional Kanpsack

#include<stdio.h>

struct obj
{
    int seq;
    int profit;
    int weight;
    float pw_ratio;
};
typedef struct obj obj;

struct obj_knapsack
{
    int seq;
    int weight;
    float profit;
    float fraction;
};
typedef struct obj_knapsack obj_knapsack;

void obj_sort(obj a[50],int n)
{
	int i,j,flag;
	obj t;
	
	for(i=1; i<=n; i++)
	{
		flag=0;
		for(j=1;j<=n-i;j++)
		{
			if(a[j].pw_ratio < a[j+1].pw_ratio)
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=1;
			}
		}
		if(flag == 0)
			return;
	}
}

void knapsack_filling(obj a[50],int n,int m)
{
    obj_knapsack x[50];
    int rem_capacity=m,i,k,net_weight=0;
	float net_profit=0.0;

	for(i=0;i<=n;i++)
	{
    	x[i].seq=i;
		x[i].profit=0.0;
		x[i].weight=0;
		x[i].fraction=0.0;
	}

	for(i=1;i<=n;i++)
	{
		if(rem_capacity == 0)
			break;

		k=a[i].seq;
		if(a[i].weight <= rem_capacity)
		{
			x[k].weight = a[i].weight;
			x[k].fraction = 1;
			x[k].profit = a[i].profit;
			rem_capacity -= a[i].weight;
		}
		else
		{
			x[k].weight = rem_capacity;
			x[k].fraction = rem_capacity/(float)a[i].weight;
			x[k].profit = a[i].profit*x[k].fraction;
			rem_capacity = 0;			
		}
		net_weight+=x[k].weight;
		net_profit+=x[k].profit;
	}

	printf("The Knapsack:");
	printf("\nObject  :");
	for(i=1;i<=n;i++)
	{
		printf("%7d",x[i].seq);
	}
	printf("\nFraction:");
	for(i=1;i<=n;i++)
	{
		printf("%7.2f",x[i].fraction);
	}
	printf("\nWeight  :");
	for(i=1;i<=n;i++)
	{
		printf("%7d",x[i].weight);
	}
	printf("\nProfit  :");
	for(i=1;i<=n;i++)
	{
		printf("%7.2f",x[i].profit);
	}

	printf("\nNet weight = %d\nNet profit = %.2f",net_weight,net_profit);
}

int main()
{
	obj bag[50];
	int capacity,i,n;

	bag[0].seq=0;
	bag[0].weight=0;
	bag[0].profit=0;
	bag[0].pw_ratio=0.0;

	printf("Enter the capacity of the knapsack: ");
	scanf("%d",&capacity);
	printf("Enter the number of objects: ");
	scanf("%d",&n);
	printf("Enter the object details...\n");
	for(i=1;i<=n;i++)
	{
		bag[i].seq=i;
		printf("Object %d weight = ",i);
		scanf("%d",&bag[i].weight);
		printf("Object %d profitt = ",i);
		scanf("%d",&bag[i].profit);
		bag[i].pw_ratio=bag[i].profit/(float)bag[i].weight;
	}

	obj_sort(bag,n);
	knapsack_filling(bag,n,capacity);

	return 0;
}

/*
Output:
------
Enter the capacity of the knapsack: 15
Enter the number of objects: 7
Enter the object details...
Object 1 weight = 2
Object 1 profitt = 10
Object 2 weight = 3
Object 2 profitt = 5
Object 3 weight = 5
Object 3 profitt = 15
Object 4 weight = 7
Object 4 profitt = 7
Object 5 weight = 1
Object 5 profitt = 6
Object 6 weight = 4
Object 6 profitt = 18
Object 7 weight = 1
Object 7 profitt = 3
The Knapsack:
Object  :      1      2      3      4      5      6      7
Fraction:   1.00   0.67   1.00   0.00   1.00   1.00   1.00
Weight  :      2      2      5      0      1      4      1
Profit  :  10.00   3.33  15.00   0.00   6.00  18.00   3.00
Net weight = 15
Net profit = 55.33
*/

/*01 Kanpsack*/
#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_WEIGHT 100

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int weights[], int profits[], int n, int W)
{
    int i, w;
    int K[n+1][W+1];
    int selectedItems[MAX_ITEMS] = {0};

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i-1] <= w)
                K[i][w] = max(profits[i-1] + K[i-1][w-weights[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    // Find items included in the knapsack
    int j = n, k = W;
    while (j > 0 && k > 0)
    {
        if (K[j][k] != K[j-1][k])
        {
            selectedItems[j-1] = 1;
            k -= weights[j-1];
        }
        j--;
    }

    // Print total profit and selected items
    printf("Total Profit: %d\n", K[n][W]);
    printf("Array specifying the Selected items(if selected then value at that index is 1 ,otherwise 0):\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", selectedItems[i]);
    }
    printf("\n");
}

int main()
{
    int n, W;
    int weights[MAX_ITEMS], profits[MAX_ITEMS];

    // Input number of items and weight of knapsack
   printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of the knapsack: ");
    scanf("%d", &W);

    // Input weights and profits of items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }
    printf("Enter the profits of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &profits[i]);
    }

    // Solve knapsack problem
    knapsack(weights, profits, n, W);
    return 0;
}

/*
Output:
------
Enter the number of items: 4
Enter the weight of the knapsack: 8
Enter the weights of the items:
2
3
4
5
Enter the profits of the items:
1
2
5
6
Total Profit: 8
Array specifying the Selected items(if selected then value at that index is 1 ,otherwise 0):
0 1 0 1 
*/

/*MAx min*/
//Finding max and min element in an array using divide and conquer method
#include<stdio.h>

typedef struct
{
	int max;
	int min;
}pair;

pair maxmindivcon(int a[50],int low, int high)
{
	pair result, left, right;
	int mid;
	
	if(low == high)
	{
		result.max = a[low];
		result.min = a[low];
		return result;
	}
	if(high == low+1)
	{
		if(a[low] < a[high])
		{
			result.max = a[high];
			result.min = a[low];
		}
		else
		{
			result.max = a[low];
			result.min = a[high];
		}
		return result;
	}
	mid = (low+high)/2;
	left = maxmindivcon(a,low,mid);
	right = maxmindivcon(a,mid+1,high);
	result.max = (left.max > right.max)?left.max:right.max;
	result.min = (left.min < right.min)?left.min:right.min;
	return result;
}

int main()
{
	int a[50],n,i;
	pair res;
	
	printf("\nEnter the no. of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("arr[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	
	
	printf("The array:\n");
	for(i=0;i<n;i++)
		printf("%3d",a[i]);
	
	res = maxmindivcon(a,0,n-1);
	printf("\nMaximum element = %d\nMinimum element = %d",res.max,res.min);
	
	return 0;
}


/* Heap Sort*/
//Heap Sort
#include<stdio.h>

void shiftDown(int numbers[],int root,int bottom)
{
    int flag,maxChild,temp;

    flag=1;
    while (((root)*2+1 <= bottom) && (flag==1))
    {
        if (root*2+1 == bottom)
            maxChild = root*2+1;
        else if (numbers[root*2+1] > numbers[root*2+2])
            maxChild = root*2+1;
        else
            maxChild = root*2+2;
        
        if(numbers[root] < numbers[maxChild])
        {
            temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            flag=0;
    }
}

void heapsort(int numbers[],int n)
{
    int i,temp;

    for(i=(n/2)-1;i>=0;i--)  //((n/2)-1) is the first non-leaf node from end
        shiftDown(numbers,i,n-1);
    
    for(i=n-1;i>=1;i--)
    {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        shiftDown(numbers,0,i-1);
    }
}

int main()
{
    int n,i,a[50];

    printf("\nEnter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}

