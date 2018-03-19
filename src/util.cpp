#include "util.h"
#include "search.h"

long int* (**Pointer_to_Func(void))(long int*, long int*, long int, long int*) {
	//Function that receives no parameter, but returns a long int* with (long int*, long int*, long int) as parameters.
	//This shall return my array of pointers of search algorithms.
	long int* (**func)(long int*, long int*, long int, long int*) = (long int*(**)(long int*, long int*, long int, long int*)) calloc(7, sizeof(*func));
	func[0] = &lsearch;
	func[1] = &i_bsearch;
	func[2] = &r_bsearch;
	func[3] = &i_tsearch;
	func[4] = &r_tsearch;
	func[5] = &fib_search;
	func[6] = &jsearch;

	return func;
}

chrono::duration<double, milli>* ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int, long int*)) {
	chrono::duration<double, milli> *t_time;				//Array will store average time spent on each execution.
	t_time = new chrono::duration<double, milli>[7];
	for(int i=0; i<7; i++) {
		if(bin[i] == '1') {									//Determine if certain search algorithm shall be executed.
			chrono::duration<double, milli> *tempos;
			tempos = new chrono::duration<double, milli>[102];
			/*
			Array to calculate the average of time spent on 100 searchs of the same type.
			*/
			auto x = chrono::high_resolution_clock::now();
			tempos[0] = x-x;	 	//Initiate with null value.

			for(int l=1; l<101; ++l) {
				chrono::steady_clock::time_point start, end;
				start = chrono::steady_clock::now();				//Time before search.

				Func[i](first, last, 2);							//Executing search algorithm.

				end = chrono::steady_clock::now();					//Time after search.

				chrono::duration<double, milli> diff = end - start;		//Difference of time.
				tempos[l] = tempos[l-1] + (diff-tempos[l-1])/l;			//Updating average.
			}

			t_time[i] = tempos[100]; //Passing the average value.
			delete[] tempos;
		}
		else {
			auto start = chrono::high_resolution_clock::now();
			t_time[i] = start-start; //Atribute a null value.
		}
	}
	return t_time;
}