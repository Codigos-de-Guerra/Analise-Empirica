#include "util.h"
#include "search.h"

Ptr_Func *Pointer_to_Func(void) {
	//Function that receives no parameter, but returns a long int* with (long int*, long int*, long int) as parameters.
	//This shall return my array of pointers of search algorithms.
	Ptr_Func *func = new Ptr_Func[7];

	//Addressing my pointers to search algorithms.
	func[0] = &lsearch;
	func[1] = &i_bsearch;
	func[2] = &r_bsearch;
	func[3] = &i_tsearch;
	func[4] = &r_tsearch;
	func[5] = &fib_search;
	func[6] = &jsearch;

	return func;
}

chrono::duration<double, micro> ExecFunc(long int *first, long int *last, Ptr_Func Func, long int &steps) {
	chrono::duration<double, micro> t_time;				//Array will store average time spent on each execution.

	chrono::duration<double, micro> *tempos;
	tempos = new chrono::duration<double, micro>[102];		//Temporaly array to calculate average time.
	/*
	Array to calculate the average of time spent on 100 searchs of the same type.
	*/
	long int counter = 0;
	auto x = chrono::steady_clock::now();
	tempos[0] = x-x;	 			//Initiate with null value.
	for(int l=1; l<101; ++l) {
		counter = 0;											//Resseting counter back to zero.
		chrono::steady_clock::time_point start, end;				//Respectively, before and after search is done.
		start = chrono::steady_clock::now();						//Time before search.

		/*Executes search algorithm and increments the counter based on it's iterations. */
		Func(first, last, pow(10,10), counter);

		end = chrono::steady_clock::now();							//Time after search.
		chrono::duration<double, micro> diff = end - start;		//Difference of time.
		tempos[l] = tempos[l-1] + (diff-tempos[l-1])/l;			//Updating average.

	}
	steps = counter;					//Passing iterations taken.
	t_time = tempos[100];				//Passing the average time spent on search.
	delete[] tempos;

	return t_time;
}