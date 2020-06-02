/*
Program to implement a simple application that
constructs a polynomial expression and evaluates it for certain predetermined values.
**********************
* Author                Dept.           Date            Notes
************************************************************************
* Tahseen T.            Comp. Science.  Apr 13 2020     Initial version.
* Tahseen T.            Comp. Science.  Apr 14 2020     Final version with all functions implemented.
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse(char s[20], int *c, int *e) {
	// a function which takes in a string and parses the
	// numbers into their respective variables.
	char *cur = strtok(s, " "); // tokenize the string by splitting them by spaces
	*c = (int) strtol(cur,NULL,10); // obtain the coefficient and store it in the integer pointer given as input
	cur = strtok(NULL, " "); // move on to the next token
	*e = (int) strtol(cur,NULL,10); // obtain the exponent and store it in the integer pointer given as input
}

int powi(int x, int exp) {
	// a function which takes two a base and an exponent as input and computes the value
	int i = 1;
	if (exp == 0) return 1; // if the power is 0, return 1
	int ret = x; 
	while (i != exp) { // while the counter is not equal to the exponent, keep multiplying the base by itself
		i++;
		ret *= x;
	}
	return ret;
}
