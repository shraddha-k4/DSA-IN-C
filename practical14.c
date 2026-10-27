
#include <stdio.h>

#define MAX 20
#define INF 999999

int graph[MAX][MAX];
int vertices;

/* Dijkstra's Shortest Path Algorithm */
void dijkstra(int source)
{
    int distance[MAX], visited[MAX];
    int i, j, min, u;

    for (i = 0; i < vertices; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[source] = 0;

    for (i = 0; i < vertices - 1; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < vertices; j++)
        {
            if (!visited[j] && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < vertices; j++)
        {
            if (graph[u][j] > 0 && !visited[j] &&
                distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < vertices; i++)
    {
        if (distance[i] == INF)
            printf("To vertex %d: Unreachable\n", i);
        else
            printf("To vertex %d: %d\n", i, distance[i]);
    }
}

/* Prim's Minimum Spanning Tree Algorithm */
void prim()
{
    int key[MAX], parent[MAX], visited[MAX];
    int i, j, min, u, total = 0;

    for (i = 0; i < vertices; i++)
    {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    key[0] = 0;

    for (i = 0; i < vertices; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < vertices; j++)
        {
            if (!visited[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }

        if (u == -1)
        {
            printf("\nMST cannot be formed because the graph is disconnected.\n");
            return;
        }

        visited[u] = 1;

        for (j = 0; j < vertices; j++)
        {
            if (graph[u][j] > 0 && !visited[j] &&
                graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }

    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    printf("Edge\tWeight\n");

    for (i = 1; i < vertices; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, key[i]);
        total += key[i];
    }

    printf("Total MST Weight = %d\n", total);
}

int main()
{
    int i, j, choice, source, weight;

    printf("Enter number of vertices (1-%d): ", MAX);
    scanf("%d", &vertices);

    if (vertices < 1 || vertices > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("\nEnter the weighted adjacency matrix:\n");
    printf("Enter 0 if there is no edge.\n");
    printf("Enter positive weights for edges.\n");

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &weight);

            if (weight < 0)
            {
                printf("Negative weights are not allowed.\n");
                return 1;
            }

            graph[i][j] = weight;
        }
    }

    /* Check matrix symmetry for an undirected graph */
    for (i = 0; i < vertices; i++)
    {
        for (j = i + 1; j < vertices; j++)
        {
            if (graph[i][j] != graph[j][i])
            {
                printf("Enter a symmetric matrix for an undirected graph.\n");
                return 1;
            }
        }
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Dijkstra's Shortest Path\n");
        printf("2. Prim's Minimum Spanning Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter source vertex (0 to %d): ",
                       vertices - 1);
                scanf("%d", &source);

                if (source < 0 || source >= vertices)
                    printf("Invalid source vertex!\n");
                else
                    dijkstra(source);
                break;

            case 2:
                prim();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
