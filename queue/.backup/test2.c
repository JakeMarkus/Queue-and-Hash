/* test2.c --- 
 * 
 * 
 * Author: Jacob R. Markus, Jia (James) Chen, Eren Berke Saglam
 * Created: Sun Jan 22 19:51:45 2023 (-0500)
 * Version: 
 * 
 * Description: Test file for qremove.
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
                                                                                                             
                                                                                                             
static void printTestStruct(void* ts)                                                                        
{                                                                                                            
  if(ts != NULL){                                                                                            
  testStruct_t* ts1 = (testStruct_t*)ts;                                                                     
  printf("Test Struct: {price: %i, year: %i}\n", ts1->price, ts1->year);                                     
  return;                                                                                                    
  }                                                                                                          
  printf("Input pointer point to NULL.\n");                                                                  
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
  printf("Test1: Remove an element that does exist in the input queue.\n");                                  
                                                                                                             
  queue_t* queue1 = qopen();                                                                                 
                                                                                                             
  testStruct_t* c1 = make_test_struct(2000, 2005);                                                           
                                                                                                             
  testStruct_t* c2 = make_test_struct(3000, 2010);                                                           
                                                                                                             
  qput(queue1, c1);                                                                                          
  qput(queue1, c2);                                                                                          
                                                                                                                                                                                   
                                                                                                             
  testStruct_t* c3 = make_test_struct(2000, 2005);                                                           
                                                                                                             
  testStruct_t* p2;                                                                                          
                                                                                                             
  p2 = qremove(queue1, searchfn, c3);                                                                        
	printf("print out the removed element\n");             
  printTestStruct(p2);                                                                         printf("Print out the rest of the queue.\n");              
  qapply(queue1, printTestStruct);                                                                                               
  qclose(queue1);                                                                                            
                                                                                                             
  free(c1);                                                                                                  
  free(c2);
	free(c3);

	printf("Test2: Remove an element that doesn't exist in in the input queue\n");


	 queue_t* queue2 = qopen();                                                                                 
                                                                                                             
  testStruct_t* c4 = make_test_struct(2000, 2005);                                                           
                                                                                                             
  testStruct_t* c5 = make_test_struct(3000, 2010);                                                           
                                                                                                             
  qput(queue2, c4);                                                                                          
  qput(queue2, c5);                                                                                          
                                                                                                                                                                               
                                                                                                             
  testStruct_t* c6 = make_test_struct(2001, 2006);                                                           
                                                                                                             
  testStruct_t* p3;                                                                                          
                                                                                                             
  p3 = qsearch(queue2, searchfn, c6);                                                                        
                                                                                                 printf("print out the removed element\n");             
  printTestStruct(p3);                                                                                       
   printf("Print out the rest of the queue.\n");                                               qapply(queue2, printTestStruct);                                                               
                                                                                                 
  qclose(queue2);                                                                                            
                                                                                                             
  free(c4); //why?                                                                                           
  free(c5);                                                                                                  
                                                                                                             
  free(c6);                                                                                                  
                                                                                                             
  printf("Test2.c finished compiling.\n"); 
}
