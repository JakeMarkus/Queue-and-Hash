/* list.c ---  
0;136;0c * 
 * Author: Eren Berke Saglam, James Chen, Jake Markus
 * Created: Fri Jan 20 18:35:06 2023 (-0500)
 * Version: 
 * 
 * Description: Stores a list of cars by implementing the list.h interface
 * 
 */

#include "list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAXREG 10

//do we need a constructor called list()?
//i thought about this when trying to test the lapply function
//maybe I'm wrong and thought like Java

/*

typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;

} car_t;
*/

car_t* make_car(char* platep, double price, int year) {
	car_t* cp;

	if ( ! ( cp = (car_t*) malloc(sizeof(car_t)))) {
		printf("[Error: malloc failed allocating car]\n");
		return NULL;
	}

	cp->next = NULL;
	strcpy(cp->plate,platep);
	cp->price=price;
  cp->year=year;

	return cp;
}

static car_t* front = NULL;

int32_t lput(car_t *cp) {
	if (front == NULL) {
		front = cp;
		return 0;
	}

	else {
		cp->next = front;
		front = cp;
		return 0;
	}
}

car_t* lget() {

	if (front == NULL) {
		return NULL;
	}

	car_t* to_return = front;

	front = front->next;

	to_return->next = NULL;

	return to_return;

}

void lapply(void (*fn)(car_t *cp)) {

	car_t* curr_carp;
	for (curr_carp = front; curr_carp != NULL; curr_carp=curr_carp->next){
		fn(curr_carp);
	}
	
}


car_t* lremove(char* platep){
	if(front == NULL){
		return NULL;
	}
	if(strcmp(front->plate, platep) == 0){
		car_t* to_return1 = lget();
		return to_return1;
	}
		
	car_t* curr_carp;
	for(curr_carp = front; curr_carp != NULL; curr_carp=curr_carp->next){
		//if we use "->", then the object on the left of "->" do not need "*"
		if (strcmp(curr_carp->next->plate, platep) == 0){
			car_t* to_return2;

			to_return2 = curr_carp->next;

			
			curr_carp->next=curr_carp->next->next;

			to_return2->next=NULL;

			return to_return2;
		}
	}

	return NULL;
}

void changeProdDate(car_t *cp1){
	int prodYear = cp1->year;
	prodYear+=1;
	cp1->year = prodYear;
}

void print(car_t* car){

	if (car != NULL) {
	printf("Car{ Plate:  %s, Price: %f, Year: %i }\n", car->plate, car->price, car->year);
	}

	else {
		printf("NULL CAR\n");
			}
}

void printCar(car_t* c)
{
	printf("This car is at: %p\n", (void *) c);
}


void releaseCar(car_t* c)
{

	printf("Car %p free!\n", (void * ) c);
	
	if (c != NULL){
		free(c);
		}

	c = NULL;
}
	


int main(void) {
	
	car_t *c1 = make_car("12636721", 10000, 2010);
 
  
	printf("Test1: put() to an empty list.\n");
	int putEmpty = lput(c1);
	car_t *got_car = lget();
	printf("Here is the first car:\n");
	print(got_car);
	printf("The return value of lput is: %d\n", putEmpty);
	releaseCar(got_car);
	
	printf("Test2: put() to a non-empty list.\n");
	car_t *c2 = make_car("12639191", 5000, 1922);
  car_t *c3 = make_car("17827899", 50000, 2020);
	lput(c2);
	int putNonEmpty = lput(c3);
	car_t *got_car2 = lget();
	printf("Here is the first car:\n");
	print(got_car2);
	printf("The return value of lput is: %d\n", putNonEmpty);
	releaseCar(got_car2);
	
	printf("Test3: get() from an non-empty list.\n");
	car_t *got_car3 = lget();
	printf("Return value of lget is: ");
	print(got_car3); 
  releaseCar(got_car3);
	
	printf("Test4: get() from an empty list.\n");
	car_t *got_car4 = lget();
	printf("Return value of lget is: ");
	print(got_car4); 
	releaseCar(got_car4);
	
	printf("Test5: apply() a function to an empty list.\n");
	lapply(changeProdDate);
	
  car_t *got_void = lget();
	print(got_void);

	releaseCar(got_void); //Good null pointer test case
	
	printf("Test5 ended\n");
	
	

	
	printf("Test6: apply() a function to a non-empty list.\n");
	car_t *c4 = make_car("100001", 10, 2023);
	car_t *c5 = make_car("100002", 11, 2024);
	lput(c4);
	lput(c5);
	lapply(changeProdDate);
	car_t *got_car5 = lget();
	printf("Return value of lget is: ");  
  print(got_car5);
	car_t *got_car6=lget();
	printf("Return value of lget is: ");
	print(got_car6);

	releaseCar(got_car5);
	releaseCar(got_car6);

	
	printf("Test7: remove() from an empty list\n");
	car_t * removeFromEmpty = lremove("12345");
	print(removeFromEmpty);
  releaseCar(removeFromEmpty); //Good null pointer test case for
	
	printf("Test8: remove() from a non-empty list at the end\n");
	car_t *c6=make_car("1",1,1);
	
	car_t *c7=make_car("2",2,2);
	
	car_t *c8=make_car("3",3,3);
	
	car_t *c9=make_car("4",4,4);

	car_t *c10=make_car("5",5,5);

	lput(c6);

	lput(c7);
	
	lput(c8);
	
	lput(c9);
	lput(c10);

	//lapply(printCar);
	//lapply(print);

	
	car_t *remove_last = lremove("1");
	print(remove_last);

	releaseCar(remove_last);
	
	printf("Test9: remove() from non-empty list at the beginning\n");
	car_t *remove_beginning = lremove("5");
	print(remove_beginning);

	releaseCar(remove_beginning);
	
	printf("Test10:remove() from non-empty list somewhere in the middle.\n");
	car_t *remove_middle = lremove("3");
	print(remove_middle);
	
	free(remove_middle);

	printf("WITH THE FINAL LIST: \n");

			printf("Address of c7 is %p\n", (void*)&c7);
		printf("Adress of c9 is %p\n", (void*)&c9);

		//lapply(printCar);
		//lapply(print);
		releaseCar(c7);
		releaseCar(c9);
		//lapply(releaseCar);
}

		
	





	
