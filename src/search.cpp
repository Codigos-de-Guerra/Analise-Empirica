#include "util.h"

long int* lsearch(long int *first, long int *last, long int value) {
    while(first != last) {
        if(value == *first) {
            return first;
        }
        first++;
    }
    return last;
}

long int* i_bsearch(long int *first, long int *last, long int value) {
    long int *news = last;                                                             //Constant pointer to beyond my array size.
    while(first <= last) {
        long int pos = (last-first)/2;                                                 //Integer that represents the half of the current array size.
        auto m = first+pos;                                                            //Memory address to the middle of my current array size.
        if(value == *m) {
            return m;
        }
        else if(value < *m) {
            last = m-1;
        }
        else if(value > *m) {
            first = m+1;
        }
    }
    return news;
}

long int* r_bsearch(long int *first, long int *last, long int value) {
    long int mid_vector = (last - first)/2;
    auto m = first+mid_vector;
    //Creates a 'm' variable to keep track of the center of the current array size.
    if(first <= last) {
        if (*m == value) {
            return m;
        }
        else if(value < *m){
            auto s = r_bsearch(first,m-1,value);
            /*
            Checks if the found memory address really refers to or value.
            If it does, return it, otherwise, return outside the array.
            */
            if(value == *s) {
                return s;
            }
            else {
                return last;
            }
        }
        else {
            return r_bsearch(m+1,last,value);
        }
    }
    return last;
}

long int* i_tsearch(long int *first, long int *last, long int value) {
    long int *news = last;                          //Constant pointer to beyond my original array size.
    while(first <= last) {
        long int t1_marker = (last-first)/3;        //Index to the end of the first third from my array.
        auto m1 = first+t1_marker;                  //Memory address to the first third of the current array.

        long int t2_marker = 2*(last-first)/3;      //Index to the end of the second third from my array.
        auto m2 = first+t2_marker;                  //Address to the second third of the current array.
        if(value == *m1) {
            return m1;
        }
        else if(value == *m2) {
            return m2;
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
    return news;
}

long int* r_tsearch(long int *first, long int *last, long int value) {
    long int *news = last;                             //Constant pointer to beyond my original array size.
    while(first <= last) {
        long int t1_marker = (last-first)/3;           //Index to the end of the first third from array.
        auto m1 = first+t1_marker;                     //Address to the end of first third of my array.

        long int t2_marker = 2*(last-first)/3;         //Index to the end of the second third from array.
        auto m2 = first+t2_marker;                     //Address to the end of second third of the current array.
        if(value == *m1) {
            return m1;
        }
        else if(value == *m2) {
            return m2;
        }
        else {
            if(value < *m1) {
                auto s = r_tsearch(first, m1-1, value);
                /*
                Checks if the found memory address really refers to our value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *s) {
                    return s;
                }
                else {
                    return last;
                }
            }
            else if(value < *m2) {
                auto l = r_tsearch(m1+1, m2-1, value);
                /*
                Checks if the found memory address really refers to or value.
                If it does, return it, otherwise, return outside the array.
                */
                if(value == *l) {
                    return l;
                }
                else {
                    return last;
                }
            }
            else {
                return r_tsearch(m2+1, last, value);
            }
        }
    }
    return news;
}

long int* jsearch(long int *first, long int *last,long int value) {
    long int m=sqrt(distance(first,last));                          //Getting the value of blocks.
    long int k;
    for( k=0; k*m < distance(first,last); k++) {                    //Only checks those blocks that have a non-Null index value.
        if(value == *(first+(k*m))) {
            return first+k*m;
        }
        else if(value < *(first+(k*m))) {
            /*
            If k==0, then i could not execute the linear search,
            considering the (k-1)*m;
            */
            if(k==0) {
                return last;
            }
            auto l = lsearch(first+((k-1)*m)+1, first+(k*m), value);
            /*
            Checks if the returned address refers to a existing value in array;
            If it exists, return it, otherwise, return last.
            */
            if(l != first+(k*m)) {
                return l;
            }
            else {
                return last;
            }
        }
        else {
            continue;
        }
    }
    //Checks those values after the last completed block.
    auto result = lsearch(first+((k-1)*m),last, value);
    if(result != first+(k*m)) {
        return result;
    }
    return last;
}