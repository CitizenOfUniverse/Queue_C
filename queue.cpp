#include "stddef.h"
#include "queue.h"
#include <stdlib.h>

// Deletes the front element and returns its data
int pop(queue_s* queue, int* ret_data){
	if (queue->size == 0){//Queue is empty...
		//Element of queue was not deleted - so, return 0
		return 0;
	}
	else{//...or contains only one element
		node_s* newtop = queue->first->next;//Saving next node
		*ret_data = queue->first->data;//Saving data of the now front
		free(queue->first);//Deleting the now front
		queue->size--;//Decreasing the size of the queue
		queue->first = newtop;//Setting new front
		return 1;//Returning data
	}
}

// Pushes one element to the queue
void push(queue_s* queue, int data){
	node_s* newtop = (node_s*)malloc(sizeof(node_s));//Allocating memory for a new element
	newtop->data = data;//Adding data
	if (queue->size == 0){
		queue->last = queue->first = newtop;//First and last nodes in 1-element queue are similar
		queue->size++;//Incrementing size
	}
	else{
		queue->last->next = newtop;//Adding an address to an old top
		queue->last = newtop;//Setting new top to stack structure
		queue->size++;//Increasing size of stack
	}
	return;
}

// Returns size of the queue
long size(queue_s* queue){
	return queue->size;
}
void clear(queue_s* queue){
	for (int i = 0; i < queue->size; i++){
		node_s* deleting = queue->first;
		queue->first = queue->first->next;
		free(deleting);
		queue->size--;
	}
	return;
}