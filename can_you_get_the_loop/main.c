#include "stdlib.h"

typedef struct node_t Node;
struct node_t {
  const Node* next;
};

#define INIT_MEM_SIZE 1024

int loop_size(const Node* node) {
    size_t mem_size = INIT_MEM_SIZE;
    int* node_mem = calloc(mem_size, sizeof(int));
    Node* curr_node = node;
    size_t leftmost_node_addr = (size_t)node;

    for (int i=1; ;++i) {

        // if ((size_t)curr_node < leftmost_node_addr) {
        //     int* temp = calloc(i, sizeof(int));
        //     memcpy(node_mem, ))
        // }

        size_t offset = ((size_t)curr_node - leftmost_node_addr) / sizeof(size_t);

        if (node_mem[offset]){
            int res = i - node_mem[offset];
            free(node_mem);
            return res;
        }
        else {
            node_mem[offset] = i;
        }

        curr_node = curr_node->next;

        if (mem_size == offset + 1) {
            mem_size *= 2;
            Node** p;
            p = realloc(node_mem, (mem_size * 2) * sizeof(Node*));
            node_mem = p;
        }
    }

    free(node_mem);

    return 0;
}

int main(int argc, char** argv) {
    Node n4, n3, n1, n2;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n4;

    Node* startNode = &n1;        
    int actual = loop_size(startNode);
    //1
}