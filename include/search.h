#ifndef SEARCH_H
#define SEARCH_H
//Here we keep our search algorithms.

long int* lsearch(long int *first,long int *last,long int value, long int *counter);					//Iterative Linear search;
long int* i_bsearch(long int *first,long int *last,long int value, long int *counter);					//Iterative Binary Search;
long int* r_bsearch(long int *first,long int *last,long int value, long int *counter);					//Recursive Binary Search;
long int* i_tsearch(long int *first,long int *last,long int value, long int *counter);					//Iterative Ternary Search;
long int* r_tsearch(long int *first,long int *last,long int value, long int *counter);					//Recursive Ternary Search;
long int* fib_search(long int *first,long int *last,long int value, long int *counter);					//Fibonacci Search;
long int* jsearch(long int *first,long int *last,long int value, long int *counter);					//Jump Search;

#endif