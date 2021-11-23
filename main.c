#include <stdio.h>
#include "graph_reader.h"
#include "graph_adapter.h"
#include "stack.h"


void resolve_component(struct TGAdjacencyMatrix *mtx, int start_vtx, int *marks, int curr_mark) {
    struct MStack *stack = malloc(sizeof(struct MStack));
    init(stack);
    push(stack, start_vtx);

    int (*matrix)[mtx->node_count] = (int (*)[mtx->node_count]) mtx->mtx_data;

    marks[start_vtx] = curr_mark;

    while (!empty(stack)) {
        int vtx = pop(stack);
        for (int i = 0; i < mtx->node_count; ++i)
            if (!marks[i] && matrix[vtx][i]) {
                push(stack, i);
                marks[i] = curr_mark;
            }
    }

    free(stack);
}

int arr_first_empty(int *arr, int count) {
    int id = 0;
    while (*arr++ && count--) ++id;
    return id;
}

int main() {
    struct TGEdgeList *edges, *e2;

    FILE *in = fopen("../in.txt", "r");
    edges = readTGEdgeList(in);
    fclose(in);
    struct TGAdjacencyMatrix *mtx = constructTGAMatrix(edges);
    int *marks = malloc(sizeof(int) * mtx->node_count);
    for (int i = 0; i < mtx->node_count; ++i) {
        marks[i] = 0;
    }

    int curr_vtx, curr_mark = 1, max_mark = 1;
    while ((curr_vtx = arr_first_empty(marks, mtx->node_count)) < mtx->node_count)
        resolve_component(mtx, curr_vtx, marks, max_mark++);

    while (curr_mark <= max_mark) {
        int *curr_mark_ptr = marks;
        for (int i = 0; i < mtx->node_count; ++i)
            if (*curr_mark_ptr++ == curr_mark)
                printf("%d ", i);
        curr_mark++;
        printf("\n");
    }

    return 0;
}
