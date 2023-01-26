/* test3.c --- 
 * 
 * 
 * Author: Jia Chen-2, Eren Berke Saglam, Jake Markus
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

//1, when both qu

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

static void printTestStruct(TestStruct_t* ts)
{
	printf("Test Struct: {x: %i, y: %i, c: %f}\n", ts->x, ts->y, ts->c);
}

int main(void){
	queue_t* firstQueue=qopen();
	queue_t* secondQueue=qopen();
	qconcat(firstQueue, secondQueue);
	
}
