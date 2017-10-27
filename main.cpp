#include <iostream>
#include "queue.h"

using namespace std;

int main(){
	queue_s queue;
	push(&queue, 3);
	int i;
	int result = pop(&queue, &i);
	result = pop(&queue, &i);
	clear(&queue);
	return 0;
}
