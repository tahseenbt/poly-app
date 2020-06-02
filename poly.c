/*
Module to add, display and evaluate a polynomial in the form of a linked list
**********************
* Author                Dept.           Date            Notes
************************************************************************
* Tahseen T.            Comp. Science.  Apr 14 2020     Final version with all functions implemented.
*/
#include <stdlib.h>
#include <stdio.h>
#include "poly.h"
#include "utils.h" // use the utils module

struct PolyTerm *head; // initialize the head of the linked list
int addPolyTerm(int c, int e) {
	// adds a given set of coefficient and exponent to their proper position in the linked list
    struct PolyTerm *temp = head; // create another pointer pointing to the head
    if (head == NULL) { // if it's the first term
        head = (struct PolyTerm *) malloc(sizeof(struct PolyTerm)); // allocate the memory for it in the heap
        head->coeff = c; // store the coefficient
        head->expo = e; // store the exponent
        head->next = NULL; // make the next term be null
        return 1; // return 1 on correct execution
    }
    else if (head->expo > e) { // if the exponent to be added is smaller than the current term's exponent
        struct PolyTerm *new = (struct PolyTerm *) malloc(sizeof(struct PolyTerm)); // allocate memory for the new term to be added
        new->coeff = c;
        new->expo = e;
        new->next = head;
        head = new; // make this new term the head
        return 1;
    }
    else if (head->expo <= e) { // if the exponent to be added is bigger than or equal to the current term's exponent
        while (head->next != NULL) { // loop through the terms
            if (head->expo == e) { // if the exponents are equal, add the coefficients
                head->coeff += c;
                head = temp;
                return 1;
            }  
            if (head->next->expo <= e) {
                head = head->next; // move on to the next term
            }
            else { // if the term is in the right place, break out of the loop
                break;
            }
        }
        struct PolyTerm *new = (struct PolyTerm *) malloc(sizeof(struct PolyTerm)); // allocate memory for the new term to be added
        new->coeff = c;
        new->expo = e;
        new->next = head->next; 
        head->next = new; // insert the new term in between head and head->next
        head = temp; // reset the pointer to the head
        return 1;
    }
    return -1;
}

void displayPolynomial() {
	// traverses through the linked list and prints out the polynomial to the screen
    struct PolyTerm *temp = head;
    while (temp->next != NULL) {
        if (temp->next->coeff >0) { // if the next term has a positive coefficient, print the + sign
            printf("%dx%d+",temp->coeff,temp->expo);
        }
        else { // or else don't print the + sign
            printf("%dx%d",temp->coeff,temp->expo);
        }
        temp = temp->next;
    }
    printf("%dx%d\n",temp->coeff,temp->expo); // print the last term
}

int evaluatePolynomial(int x) {
	// evaluates the polynomial for the given set of x values
    int res = 0;
    struct PolyTerm *temp = head; // create a pointer to point to the head of the list
    while (temp!= NULL) { // traverse through the list and compute the terms
        res+=temp->coeff*(powi(x,temp->expo));
        temp = temp->next;
    }
    return res; // return the result
}

