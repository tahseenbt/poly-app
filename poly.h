/*
Header file of the poly module.
**********************
* Author                Dept.           Date            Notes
************************************************************************
* Tahseen T.            Comp. Science.  Apr 14 2020     Final version with all required functions and variables listed.
*/
struct PolyTerm { // given structure of the linked list
int coeff ;
int expo ;
struct PolyTerm *next ;
};
extern struct PolyTerm *head; // make the head global
int addPolyTerm(int c, int e);
void displayPolynomial();
int evaluatePolynomial(int x);
