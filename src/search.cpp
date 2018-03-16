#include "util.h"
extern int __dso_handle;

long int* lsearch(long int *first, long int *last, long int value) {
    while(first != last) {
        if(value == *first) {
            return first; //Element found.
        }
        first++;
    }
    return last; //Element not found.
}

long int* i_bsearch(long int *first, long int *last, long int value) {
    long int *news = last;                                                             //Constant pointer to beyond my array size.
    while(first <= last) {
        long int pos = (last-first)/2;                                                 //Integer that represents the half of the current array size.
        auto m = first+pos;                                                            //Memory address to the middle of my current array size.
        if(value == *m) {
            return m; //Element found.
        }
        else if(value < *m) {
            last = m-1;
        }
        else if(value > *m) {
            first = m+1;
        }
    }
    return news; //Element not found.
}

long int* r_bsearch(long int *first, long int *last, long int value) {
    long int mid_vector = (last - first)/2;
    auto m = first+mid_vector;
    //Creates a 'm' variable to keep track of the center of the current array size.
    if(first <= last) {
        if (*m == value) {
            return m; //Element found.
        }
        else if(value < *m){
            auto s = r_bsearch(first,m-1,value);
            /*
            Checks if the found memory address really refers to or value.
            If it does, return it, otherwise, return outside the array.
            */
            if(value == *s) {
                return s; //Element found.
            }
            else {
                return last; //Element not found.
            }
        }
        else {
            return r_bsearch(m+1,last,value);
        }
    }
    return last; //Element not found.
}

long int* i_tsearch(long int *first, long int *last, long int value) {
    long int *news = last;                          //Constant pointer to beyond my original array size.
    while(first <= last) {
        long int t1_marker = (last-first)/3;        //Index to the end of the first third from my array.
        auto m1 = first+t1_marker;                  //Memory address to the first third of the current array.

        long int t2_marker = 2*(last-first)/3;      //Index to the end of the second third from my array.
        auto m2 = first+t2_marker;                  //Address to the second third of the current array.
        if(value == *m1) {
            return m1; //Element found.
        }
        else if(value == *m2) {
            return m2; //Element found.
        }
        else {
            if(value < *m1) {
                last = m1-1;
            }
            else if(value < *m2) {
                first = m1+1;
                last = m2-1;
            }
            else {
                first = m2+1;
            }
        }
    }
    return news; //Element not found.
}

long int* r_tsearch(long int *first, long int *last, long int value) {
    long int *news = last;                             //Constant pointer to beyond my original array size.
    while(first <= last) {
        long int t1_marker = (last-first)/3;           //Index to the end of the first third from array.
        auto m1 = first+t1_marker;                     //Address to the end of first third of my array.

        long int t2_marker = 2*(last-first)/3;         //Index to the end of the second third from array.
        auto m2 = first+t2_marker;                     //Address to the end of second third of the current array.
        if(value == *m1) {
            return m1; //Element found.
        }
        else if(value == *m2) {
            return m2; //Element found.
        }
        else {
            if(value < *m1) {
                auto s = r_tsearch(first, m1-1, value);
                /*
                Checks if the found memory address really refers to our value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *s) {
                    return s; //Element found.
                }
                else {
                    return last; //Element not found.
                }
            }
            else if(value < *m2) {
                auto l = r_tsearch(m1+1, m2-1, value);
                /*
                Checks if the found memory address really refers to or value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *l) {
                    return l; //Element found.
                }
                else {
                    return last;//Element not found.
                }
            }
            else {
                return r_tsearch(m2+1, last, value);
            }
        }
    }
    return news; //Element not found.
}

long int* fib_search(long int *first, long int *last, long int value) {
    //Initializing Fibonacci sequence.
    long int fibT_2 = 0; //(t-2)'th Fibonacci number.
    long int fibT_1 = 1; //(t-1)'th Fibonacci number.
    long int fibT = fibT_1 + fibT_2; //t'th Fibonacci number.
    long int size = distance(first, last); //Array size.

    /*Finding smallest Fibonacci Number greater than or igual to array size. */
    while(fibT < size) {
        fibT_2 = fibT_1;
        fibT_1 = fibT;
        fibT = fibT_2 + fibT_1;
    }

    while(fibT > 1) {
        if(value == *(first+fibT_2-1)) {
            return first+fibT_2-1;
        }
        else if(value < *(first+fibT_2-1)) {
            fibT = fibT_2;
            fibT_1 = fibT_1 - fibT_2;
            fibT_2 = fibT - fibT_1; 
        }
        else if(value > *(first+fibT_2-1)) {
            first = first+fibT_2; //Alterate the index value, to keep the search.
            fibT = fibT_1;
            fibT_1 = fibT_2;
            fibT_2 = fibT - fibT_1;
        }
    }
    /*
    Since there might be a single element remaining for comparison,
    check if fibT_1 is 1. If Yes, compare value with that remaining element.
    If match, return address.
    */
    if(fibT_1 == 1 && value == *first) {
        return first; //Element found.
    }
    return last; //Element not found.
}

long int* jsearch(long int *first, long int *last,long int value) {
    long int m=sqrt(distance(first,last));                          //Getting the value of blocks.
    long int k;
    for( k=0; k*m < distance(first,last); k++) {                    //Only checks those blocks that have a non-Null index value.
        if(value == *(first+(k*m))) {
            return first+k*m; //Element found.
        }
        else if(value < *(first+(k*m))) {
            /*
            If k==0, then i could not execute the linear search,
            considering the (k-1)*m;
            */
            if(k==0) {
                return last; //Element not found.
            }
            auto l = lsearch(first+((k-1)*m)+1, first+(k*m), value);
            /*
            Checks if the returned address refers to a existing value in array;
            If it exists, return it, otherwise, return last.
            */
            if(l != first+(k*m)) {
                return l; //Element found.
            }
            else {
                return last; //Element not found.
            }
        }
        else {
            continue;
        }
    }
    //Checks those values after the last completed block.
    auto result = lsearch(first+((k-1)*m),last, value);
    if(result != first+(k*m)) {
        return result; //Element found.
    }
    return last; //Element not found.
}