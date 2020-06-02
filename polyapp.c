#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h" // use the utils module
#include "poly.h" //use the poly module
/*
Program to implement a simple application that
constructs a polynomial expression and evaluates it for certain predetermined values.
**********************
* Author                Dept.           Date            Notes
************************************************************************
* Tahseen T.            Comp. Science.  Apr 13 2020     Initial version.
* Tahseen T.            Comp. Science.  Apr 14 2020     Final version with all functions implemented.
*/

int main(int argc, char **argv) {
	FILE *file = fopen(argv[1], "r"); // open the file from the argument provided
	char a[20];
	int co;
	int exp;
	if (file == NULL) return(0); // if file is empty, return 0
	fgets(a,20,file); // read the first line of the file
	do {
		parse(a, &co, &exp); // parse the line in the file
		addPolyTerm(co,exp); // use the function in poly.c to keep updating the polynomial linked list
	}
	while (fgets(a,20,file) != NULL); // keep reading until EOF is reached
	displayPolynomial(); // use the function to display the polynomial to the screen
	int j = -2;
	while (j<=2) { // loop from -2 to 2 to evaulate the polynomial for these values of x
		printf("for x=%d, y=%d\n",j,evaluatePolynomial(j));
		j++;
	}
}
