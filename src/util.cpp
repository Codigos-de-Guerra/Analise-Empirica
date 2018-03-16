#include "util.h"
#include "search.h"
extern int __dso_handle;

long int* (**Pointer_to_Func(void))(long int*, long int*, long int) {
	//Function that receives no parameter, but returns a long int* with (long int*, long int*, long int) as parameters.
	//This shall return my array of pointers of search algorithms.
	long int* (**func)(long int*, long int*, long int) = (long int*(**)(long int*, long int*, long int)) calloc(7, sizeof(*func));
	func[0] = &lsearch;
	func[1] = &i_bsearch;
	func[2] = &r_bsearch;
	func[3] = &i_tsearch;
	func[4] = &r_tsearch;
	func[5] = &fib_search;
	func[6] = &jsearch;

	return func;
}

chrono::duration<double>* ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int)) {
	chrono::duration<double> *time;//Array will store average time spent on each execution.
	time = new chrono::duration<double>[7];
	for(int i=0; i<7; i++) {
		if(bin[i] == '1') {//Determine if certain search algorithm shall be executed.
			chrono::duration<double> *tempos;
			tempos = new chrono::duration<double>[101];
			/*
			Array to calculate the average of time spent on 100 searchs of the same type.
			*/
			auto x = chrono::high_resolution_clock::now();
			tempos[0] = x-x; //Initiate with null value.

			for(int l=1; l<101; ++l) {
				auto start = chrono::high_resolution_clock::now();	//Time before search.
				Func[0](first, last, -4);//Executing search algorithm.
				auto end = chrono::high_resolution_clock::now();	//Time after search.
				chrono::duration<double> diff = end-start;			//Difference of time.

				tempos[l] = tempos[l-1] + (diff-tempos[l-1])/l;		//Updating average.
			}

			time[i] = tempos[100]; //Passing the average value.
			//cout << setw(18) << left << scientific << setprecision(8) << time[i].count() << "   ";
			delete[] tempos;
		}
		else {
			auto start = chrono::high_resolution_clock::now();
			time[i] = start-start; //Atribute a null value.
		}
	}
	return time;
}