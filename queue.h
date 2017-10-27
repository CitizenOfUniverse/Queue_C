#include "node.h"
#include "stddef.h"

// Queue descriptor
struct queue_s{
	node_s* first = NULL;//Address of the stack's top
	node_s* last = NULL;//Address of the stack's top
	long size = 0;//Size of the stack
};
int pop(queue_s* queue, int* ret_data);//Deletes the top element and returns its data
void push(queue_s* queue, int data);//Pushes one element to the queue
long size(queue_s* queue);//Returns size of the queue
void clear(queue_s* queue);
