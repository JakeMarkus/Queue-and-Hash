/* test3.c --- 
 * 
 * 
 * Author: Jia(James) Chen, Eren Berke Saglam, Jacob R. Markus
 * Created: Thu Jan 26 10:26:22 2023 (-0500)
 * Version: 
 * 
 * Description: This c file is testing void qconcat(queue_t *q1p, queue_t *q2p)
 * 
 * 
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct testStruct{                                               
  int x;                                                                 
  int y;                                                                 
  float c;                                                               
} TestStruct_t;

static TestStruct_t* make_test_struct(int a, int b, float f)             
{                                                                        
  TestStruct_t* toR;                                                     
  if ( ! ( toR = (TestStruct_t*) malloc(sizeof(TestStruct_t)))) {        
    printf("[Error: malloc failed allocating test struct]\n");           
    return NULL;                                                         
  }                                                                      
                                                                         
  toR->x = a;                                                            
  toR->y = b;                                                            
  toR->c = f;                                                            
                                                                         
  return toR;                                                            
                                                                         
}

static void printTestStruct(void* ts)
{
	TestStruct_t* ts1 = (TestStruct_t*)ts;
	printf("Test Struct: {x: %i, y: %i, c: %f}\n", ts1->x, ts1->y, ts1->c);
}
/*
void printQueueFandB(queue_t* qp){                                                                                      
  queue_mod_t* i1 = (queue_mod_t*) (qp);                                                                                
  if(i1->front == NULL){                                                                                                
    printf("the queue is empty");                                                                                       
    return;                                                                                                             
  }                                                                                                                     
  printf("Front of the queue:\n");
	printTestStruct(i1->front->info);
	printf("Back of the queue:\n");  
  printTestStruct(i1->back->info);
}
*/

int main(void){
	printf("Test1, when both queues are empty.\n");
	queue_t* firstQueue=qopen();
	queue_t* secondQueue=qopen();
	qconcat(firstQueue, secondQueue);
	qapply(firstQueue, printTestStruct);
	qclose(firstQueue);
	printf("End of test1\n");

	printf("Test2, when the second queue is empty.\n");
	queue_t* thirdQueue=qopen();
	queue_t* fourthQueue=qopen();
	TestStruct_t* test2Struct = make_test_struct(1, 2, 3.0);
	qput(thirdQueue, test2Struct);
	qconcat(thirdQueue, fourthQueue);
	void* test2Get = qget(thirdQueue);
	printTestStruct(test2Get);
	qclose(thirdQueue);
	free(test2Get);
	//free(test2Struct);
	printf("End of test2\n");

	
	printf("Test3, when the first queue is empty.\n");
	queue_t* fifthQueue=qopen();
	queue_t* sixthQueue=qopen();
	TestStruct_t* test3Struct = make_test_struct(4, 5, 6.0);
	qput(sixthQueue, test3Struct);
	qconcat(fifthQueue, sixthQueue);
	void* test3Get = qget(fifthQueue);
	printTestStruct(test3Get);
	qclose(fifthQueue);
	free(test3Get);
	//free(test3Struct);
	printf("End of test3\n");
	printf("Finished compiling test3.c\n");

	
	
	
}
