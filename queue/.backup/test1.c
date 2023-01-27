/* test1.c --- 
 * 
 * 
 * Author: Jacob R. Markus
 * Created: Sun Jan 22 19:51:40 2023 (-0500)
 * Version: 
 * 
 * Description: 
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

static void printTestStruct(TestStruct_t* ts)
{
	printf("Test Struct: {x: %i, y: %i, c: %f}\n", ts->x, ts->y, ts->c);
}

int main()
{

	queue_t* myQueue = qopen();

	
	TestStruct_t* e1 = make_test_struct(1, 101, 3.14159);
	
	TestStruct_t* e2 = make_test_struct(2, 753, 2.718);
	
	TestStruct_t* e3 = make_test_struct(3, 1776, 1.618);

	
	qput(myQueue, e1);
	qput(myQueue, e2);
	qput(myQueue, e3);

	
	printf("Printing Queue: \n");
	qapply(myQueue, printTestStruct);

	printf("Popping from Queue: \n");

	TestStruct_t* popped = qget(myQueue);
	
	printTestStruct(popped);
	free(popped);
	
	printf("Printing Queue: \n");
	qapply(myQueue, printTestStruct);
	printf("Closing Queue!\n");

	qclose(myQueue);
	return 0;
	
}
