/* queue.c --- 
 * 
 * 
 * Author: Eren Berke Saglam
 * Created: Sun Jan 22 19:54:40 2023 (-0500)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "queue.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct data_node {
	data_node* next;
	void* info;

} data_node_t;
	

typedef struct queue {
	data_node* front;
	data_node* back;

} queue_t;

queue_t* qopen(void) {
	front = NULL;
	back = NULL;

	queue_t* qp;

	return qp;
		
}

void qclose(queue_t *qp) {
	free(qp);
}


	


	




	
