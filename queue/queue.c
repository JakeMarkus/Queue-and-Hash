/* queue.c --- 
 * 
 * 
 * author: Eren Berke Saglam
 * Created: Sun Jan 22 19:54:40 2023 (-0500)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "queue.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data_node {
	struct data_node* next; //added "struct"
	void* info;

} data_node_t;
	
typedef struct queue {
	data_node_t* front; //data_node ->data_node_t
	data_node_t* back;
		
} queue_mod_t;


queue_t* qopen(void) {
	queue_mod_t* ip;
	
	if ( ! ( ip = (queue_mod_t*) malloc(sizeof(queue_mod_t)))) {
    printf("[Error: malloc failed allocating queue]\n");
    return NULL;
  }

	ip->front = NULL;
	ip->back = NULL;

	return (queue_t*)ip;
}

static data_node_t* make_data_node(void* info) {
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
	
	queue_mod_t* ip = (queue_mod_t*)(qp);
	
	data_node_t* dn = make_data_node(elementp);

	if(dn != NULL)
		{
						
			if (ip->front == NULL)
				{
					ip->front = dn;
					ip->back = dn;
				}

			
			if(ip->back != dn)
				{
					ip->back->next = dn;
				}

			ip->back = dn;
			 
			return 0;
		}
	else
		{
			return 1;
		}
}

static data_node_t* qgetNode(queue_t *qp) {

	queue_mod_t* ip = (queue_mod_t*) (qp);

	
	data_node_t* toReturn = ip->front;
	if (toReturn == NULL)
		{
			return NULL;
		}
	
	ip->front = toReturn->next;

	toReturn->next = NULL;
	
	return toReturn;
}


void* qget(queue_t *qp) {

	/*queue_mod_t* ip = (queue_mod_t*) (&qp);*/

	data_node_t* toReturn = qgetNode(qp);
	toReturn->next = NULL;
	
	void* stuffp = toReturn->info; 
	free(toReturn);
	
	return stuffp;
}


void qclose(queue_t *qp) {

	/*queue_mod_t* ip = (queue_mod_t*) (&qp);*/ 

  for(data_node_t* curr_dat = qgetNode(qp); curr_dat != NULL; curr_dat = qgetNode(qp))
		{
			free(curr_dat);
		}
	free(qp);
}

void qapply(queue_t *qp, void (*fn)(void* elementp)) {
	queue_mod_t* ip = (queue_mod_t*) (qp);

	for (data_node_t* curr_node = ip->front; curr_node != NULL; curr_node=curr_node->next){
    fn(curr_node->info);
  }
}


void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){

	queue_mod_t* ip = (queue_mod_t*) (qp);
	
	for (data_node_t* curr_node = ip->front; curr_node != NULL; curr_node=curr_node->next){

		if(searchfn(curr_node->info, skeyp)){
				return curr_node->info;
			}
  }

	return NULL;

}

/*
static void middle_remove(data_node_t* first, data_node_t* second){

	first->next = second->next->next;
	second->next = NULL; 
} */

void* qremove(queue_t *qp,
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp){

	queue_mod_t* ip = (queue_mod_t*) (qp);
	
	if(ip->front == NULL)
		{
			return NULL;
		}
	if (searchfn(ip->front->info, skeyp))
		{
			data_node_t* foundNode = ip->front;
			
			ip->front = ip->front->next;
			foundNode->next = NULL;
			void* finfo = foundNode->info;
			free(foundNode);
			
			return finfo;

		}
			
	for (data_node_t* curr_node = ip->front; curr_node->next != NULL; curr_node=curr_node->next){

    if(searchfn(curr_node->next->info, skeyp)){

			data_node_t* foundNode = curr_node->next;
			curr_node->next = foundNode->next;
			foundNode->next = NULL;
		 	void* finfo = foundNode->info;
			free(foundNode);
			
		  return finfo;
      }
  }

  return NULL;


}

void qconcat(queue_t *q1p, queue_t* q2p) {

	queue_mod_t* i1 = (queue_mod_t*) (q1p);
	queue_mod_t* i2 = (queue_mod_t*) (q2p);
	if(i2->front==NULL){
		free(q2p);
		return;
	}
	else{
		if(i1->front==NULL){
			i1->front = i2->front;
			i1->back=i2->back;
			free(q2p);
			return;
		}
		else{
 
		
	
	i1->back->next = i2->front;
	i1->back = i2->back;

	free(q2p);
		}
	}	
}
	


	




	
