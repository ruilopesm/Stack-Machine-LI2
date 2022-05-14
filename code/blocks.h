#ifndef BLOCKS_H
#define BLOCKS_H

void map(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void map_array(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void map_string(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void fold(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void filter(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void filter_array(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

void filter_string(STACK_ELEM x, STACK_ELEM y, STACK_ELEM *result, GLOBALS *g);

int compare_on(STACK_ELEM x,STACK_ELEM y,STACK *temp, char *block,GLOBALS *g);

int compare_arrays(STACK *x, STACK *y);

void sort_on(STACK_ELEM block,STACK_ELEM *array,GLOBALS *g);

void while_operation(STACK *s, STACK_ELEM x, GLOBALS *g);

int truthy_value(STACK_ELEM x);

int is_arg(STACK_ELEM x);

#endif
