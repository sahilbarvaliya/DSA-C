#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 8
#define TRUE 1
#define FALSE 0

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
    int visited[MAX_VERTICES];
} GraphType;

typedef int element;

typedef struct QueueNode {
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q) {
    q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

void enqueue(LinkedQueueType* q, element item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = item;
    temp->link = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(LinkedQueueType* q) {
    QueueNode* temp = q->front;
    element item;
    if (is_empty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    else {
        item = temp->data;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return item;
    }
}

void graph_init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++) {
        g->visited[v] = FALSE;
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "Graph has no more space!\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "Graph has no %d or %d vertex!\n", u, v);
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void bfs_list(GraphType* g, int v) {
    GraphNode* w;
    LinkedQueueType q;
    init(&q);
    g->visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        for (w = g->adj_list[v]; w; w = w->link)
            if (!g->visited[w->vertex]) {
                g->visited[w->vertex] = TRUE;
                printf("%d ", w->vertex);
                enqueue(&q, w->vertex);
            }
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    for (int i = 0; i < 8; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 5);
    insert_edge(g, 1, 3);
    insert_edge(g, 2, 4);
    insert_edge(g, 2, 6);
    insert_edge(g, 3, 1);
    insert_edge(g, 3, 5);
    insert_edge(g, 3, 0);
    insert_edge(g, 3, 7);
    insert_edge(g, 4, 2);
    insert_edge(g, 4, 6);
    insert_edge(g, 4, 7);
    insert_edge(g, 5, 1);
    insert_edge(g, 5, 3);
    insert_edge(g, 5, 6);
    insert_edge(g, 6, 4);
    insert_edge(g, 6, 2);
    insert_edge(g, 6, 5);
    insert_edge(g, 6, 7);
    insert_edge(g, 7, 3);
    insert_edge(g, 7, 6);
    insert_edge(g, 7, 4);
    printf("BFS\n");
    bfs_list(g, 0);
    printf("\n");
    free(g);
    return 0;
}

