#include <stdio.h>
#include <stdlib.h>

struct Vertex {
    int data;
    struct Vertex *parent;
};

struct Edge {
    struct Vertex *start;
    struct Vertex *end;
    int weight;
};

struct Vertex parent[100];