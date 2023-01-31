/* t0;136;0c * 
 * 
 * Author: Jacob R. Markus, James Chen, Eren Berke Saglam
 * Created: Sun Jan 22 19:51:40 2023 (-0500)
 * Version: 
 * 
 * Description: This test file tests qput, qget, and qapply that we wrote, respectively.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hash.h"

typedef struct testStruct{

	char* name;
	int x;
	int y;
	float c; 
} TestStruct_t;


static TestStruct_t* make_test_struct(int a, int b, float f, char* n)
{
	TestStruct_t* toR;
	if ( ! ( toR = (TestStruct_t*) malloc(sizeof(TestStruct_t)))) {
    printf("[Error: malloc failed allocating test struct]\n");
    return NULL;
  }

	toR->name = n;
	
	toR->x = a;
	toR->y = b;
	toR->c = f;

	return toR;

}

static void printTestStruct(void* ts)
{
	if (ts == NULL)
		{
			printf("NULL POINTER\n");
		}
	else
		{
	TestStruct_t* ts1 = (TestStruct_t*)ts;
	printf("Test Struct: {name: %s, x: %i, y: %i, c: %f}\n", ts1->name, ts1->x, ts1->y, ts1->c);
		}
}

static  bool compare(void* elementp, const void* searchkeyp){

  TestStruct_t* ts = (TestStruct_t*) elementp;

	char* str1 = (char*) searchkeyp;
	return strcmp(ts->name, str1) == 0;
	
}

int main()
{
	const int TABLE_SIZE = 10;

	hashtable_t* table = hopen(TABLE_SIZE);

	char* name1 = "Trajan";
	char* name2 = "Romulus";
	char* name3 = "Washington";
	
	TestStruct_t* e1 = make_test_struct(1, 101, 3.14159, name1);
	
	TestStruct_t* e2 = make_test_struct(2, 753, 2.718, name2);
	
	TestStruct_t* e3 = make_test_struct(3, 1776, 1.618, name3);


	
	hput(table, e1, name1, strlen(name1));
	hput(table, e2, name2, strlen(name2));
	hput(table, e3, name3, strlen(name3));

	
	printf("Printing Queue:(Test qput) \n");
	happly(table, printTestStruct);

	printf("Searching for a struct with name Trajan\n");

	TestStruct_t* found = hsearch(table, compare, name1, strlen(name1));


	printTestStruct(found);


	printf("Searching for a non-existent struct with name non-existent name: Marc Antony! \n");


	char* badname = "Marc Antony";
	
	TestStruct_t* found2 = hsearch(table, compare, badname, strlen(badname));

	printTestStruct(found2);
	printf("Test1 finished!\n");

	hclose(table);

	free(e1);
	free(e2);
	free(e3);
	
	return 0;	
}
