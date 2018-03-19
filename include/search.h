#ifndef SEARCH_H
#define SEARCH_H
//Here we keep our search algorithms.

long int* lsearch(long int *first,long int *last,long int value);					//Iterative Linear search;
long int* i_bsearch(long int *first,long int *last,long int value);					//Iterative Binary Search;
long int* r_bsearch(long int *first,long int *last,long int value);					//Recursive Binary Search;
long int* i_tsearch(long int *first,long int *last,long int value);					//Iterative Ternary Search;
long int* r_tsearch(long int *first,long int *last,long int value);					//Recursive Ternary Search;
long int* fib_search(long int *first,long int *last,long int value);				//Fibonacci Search;
long int* jsearch(long int *first,long int *last,long int value);					//Jump Search;

#endif