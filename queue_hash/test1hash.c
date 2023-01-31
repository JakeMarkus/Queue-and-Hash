/* test1hash.c --- tests hopen, hclose, hput, and happly
 * 
 * 
 * Author: Eren Berke Saglam
 * Created: Tue Jan 31 10:16:03 2023 (-0500)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "queue.h"

typedef struct TestStruct {

	int x;
	char*  y;
	float c;
	
} TestStruct_t;


static TestStruct_t* make_test_struct(int a, char* b, float f) {                                                                                                                                                                                                                              
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
  printf("Test Struct: {x: %i, y: %s, c: %f}\n", ts1->x, ts1->y, ts1->c);                                                                                                                                                      
}


                                                                                                                                                                                                                               
static void doubleYear(void* ts)                                                                                                                                                                                               
{                                                                                                                                                                                                                              
  TestStruct_t* ts1 = (TestStruct_t*)ts;                                                                                                                                                                                       
  ts1-> y = "eren";                                                                                                                                                                                                          
}

int main() {

	hashtable_t* myHash = hopen(10);

	TestStruct_t* e1 = make_test_struct(1, "101", 3.14);
	TestStruct_t* e2 = make_test_struct(2, "75333", 2.71);

	

	hput(myHash, (void*) e1, e1->y, strlen(e1->y));

	hput(myHash, (void*) e2, e2->y, strlen(e2->y));

	happly(myHash, doubleYear);

	happly(myHash, printTestStruct);

	hclose(myHash);

	free(e1);
	free(e2);

}

	

	


	
