/* test4.c --- 
 * 
 * 
 * Author: Eren Berke Saglam
 * Created: Thu Jan 26 10:25:45 2023 (-0500)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct testStruct {
	int price;
	int year;
} testStruct_t;

static testStruct_t* make_test_struct(int price, int year) {
	testStruct_t* car;

	if ( ! ( car = (testStruct_t*) malloc(sizeof(testStruct_t)))) {
		printf("error: malloc failed allocating test struct");
		return NULL;
	}

	car->price = price;
	car->year = year;

	return car;
}

static void printTestStruct(testStruct_t* ts) {
	printf("Test Struct: {x: %i, y: %i}\n", ts->price, ts->year);
}

static bool searchfn(void* elementp, const void* keyp) {

  testStruct_t* car = (testStruct_t*) elementp;

	testStruct_t* car1 = (testStruct_t*) keyp;

	if (car->price == car1-> price) {
		if (car->year == car1->year) {
			return true;
		}
	}

	return false;
}


int main() {
	queue_t* queue1 = qopen();

	testStruct_t* c1 = make_test_struct(2000, 2005);

	testStruct_t* c2 = make_test_struct(3000, 2010);

	qput(queue1, c1);
	qput(queue1, c2);

	printf("Searching the queue: \n");

	testStruct_t* c3 = make_test_struct(2000, 2005);

	testStruct_t* p2;

	p2 = qsearch(queue1, searchfn, c3);

	printTestStruct(p2);

	qclose(queue1);

	free(c1);
	free(c2);
	free(c3);

}
