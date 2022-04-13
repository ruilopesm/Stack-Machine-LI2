#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

STACK *create_stack() {
    STACK *s = malloc(sizeof(STACK));
    s->sp = 0;
    s->size = 100;
    s->stc = calloc(sizeof(int), s->size);

    return s;
}

int increase_stack(STACK *s) {
    if ((s->stc = realloc(s->stc, sizeof(s->stc) * 2)) == NULL) {
        return 1;
    }
    s->size *= 2;

    return 0;
}

void print_stack(STACK *s) {
    for (int i = 0; i < s->sp; i++) {
        printf("%d", s->stc[i]);
    }
    putchar('\n');
}

void free_stack(STACK *s) {
    free(s->stc);
    free(s);
}

int push(STACK *s, int elem) {
    if (s->sp == s->size) {
        if (increase_stack(s)) {
            return 1;
        }
    }
    s->stc[s->sp] = elem;
    s->sp++;
    
    return 0;
}

int pop(STACK *s, int *elem) {
    if (s->sp == 0) {
        return 1;
    }
    s->sp--;
    *elem = s->stc[s->sp];

    return 0;
}
