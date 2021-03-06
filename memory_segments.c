#include <stdio.h>
#include <stdlib.h>

int global_var;

int global_initialized_var = 5;

void function() {
    int stack_var;
    printf("the function's stack_var is at adress 0x%08x\n", stack_var);
}

int main() {
    int stack_var;
    static int static_initialized_var = 5;
    static int static_var;

    int *heap_var_ptr;

    heap_var_ptr = (int *) malloc(4);

    // These are in the data segment 
    printf("global_initialized_var is at adress 0x%08x\n", &global_initialized_var);
    printf("static_initialized_var is at adress 0x%08x\n", &static_initialized_var);
   
    // These are in the bss segment
    printf("static_var is at adress 0x%08x\n", &static_var);
    printf("global_var is at adress 0x%08x\n", &global_var);

    // This is in the heap
    printf("heap_var is at adress 0x%08x\n", heap_var_ptr);

    // These are in the stack
    printf("stack_var is at adress 0x%08x\n", &stack_var);
    function();
}
