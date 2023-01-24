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

	
queue_t* qopen(void)
{
	queue_t* qp;
	
	if ( ! ( qp = (queue_t*) malloc(sizeof(queue_t)))) {
    printf("[Error: malloc failed allocating queue]\n");
    return NULL;
  }

	qp->front = NULL;
	qp->back = NULL;

	return qp;
}

static data_node_t* make_data_node(*void info) {
	data_node_t* dn;
	
	if ( ! ( dn = (data_node_t*) malloc(sizeof(data_node_t)))) {
    printf("[Error: malloc failed allocating data node]\n");
    return NULL;
  }

	dn->next = NULL;
	dn->info = info; 

	return dn;
}


int32_t qput(queue_t *qp, void *elementp) {
	data_node_t* dn = make_data_node(elementp);

	if(dn != NULL)
		{
			qp->back->next = dn;
			qp->back = dn;
			
			return 0;
		}
	else
		{
			return 1;
		}
}

void* qget(queue_t *qp)
{

	data_node* toReturn = qp->front;
	qp->front = toReturn->next;

	toReturn->next = NULL;
	
	return toReturn;
}

void qclose(queue_t *qp) {


  for(*data_node curr_dat = qget(qp); curr_dat != NULL; curr_dat = qget(gp))
		{
			free(curr_dat);
		}
	free(qp);
}

void qapply(void (*fn)(queue_t *qp)) {

  for (data_node_t* curr_node = qp->front; curr_node != NULL; curr_node=curr_node->next){
    fn(curr_node->info);
  }

}


void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){
	
	for (data_node_t* curr_node = qp->front; curr_node != NULL; curr_node=curr_node->next){

		if(searchfn(curr_node->info, skeyp)){
				return curr_node->info;
			}
  }

	return NULL;

}


static void middle_remove(data_node_t* first, data_node_t* second){

	first->next = second->next->next;
	second->next = NULL; 
}
void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){

	if(qp->front == NULL)
		{
			return NULL;
		}
	if (searchfn(qp->front->info, skeyp))
		{
			data_node_t* foundNode = qp->front;
			
			qp->front = qp->front->next;
			foundNode->next = NULL;
			void* finfo = foundNode->info;
			free(foundNode);
			
			return finfo;

		}
			
	for (data_node_t* curr_node = qp->front; curr_node->next != NULL; curr_node=curr_node->next){

    if(searchfn(curr_node->next->info, skeyp)){

			data_node_t* foundNode = curr_node->next;
			curr_node->next = foundNode->next;
			foundNode->next = null;
		 	void* finfo = foundNode->info;
			free(foundNode);
			
		  return finfo;
      }
  }

  return NULL;


}

void qconcat(queue_t *q1p, queue_t* q2p)
{
	q1p->back->next = q2p->front;
	q1p->back = q2p->back;

	free(q2p);
	
}
	


	




	
