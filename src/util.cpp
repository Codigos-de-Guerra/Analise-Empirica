#include "util.h"
#include "search.h"

long int* (**Pointer_to_Func(void))(long int*, long int*, long int) {
	//Function that receives no parameter, but returns a long int* with (long int*, long int*, long int) as parameters.
	//This shall return my array of pointers of search algorithms.
	long int* (**func)(long int*, long int*, long int) = (long int*(**)(long int*, long int*, long int)) calloc(6, sizeof(*func));
	func[0] = &lsearch;
	func[1] = &i_bsearch;
	func[2] = &r_bsearch;
	func[3] = &i_tsearch;
	func[4] = &r_tsearch;
	func[5] = &jsearch;

	return func;
}

void ExecFunc(long int *first, long int *last, string bin, long int* (**Func)(long int*, long int*, long int)) {
	chrono::duration<double> time[7];//Vector will store my times of executions.
	for(int i=0; i<6; i++) {
		if(bin[i] == '1') {//Determine if certain search algorithm shall be executed.
			for(int l=0; l<100; ++l) {
				auto start = chrono::high_resolution_clock::now();
				Func[i](first, last, -4);//Executing search algorithm.
				auto end = chrono::high_resolution_clock::now();
				chrono::duration<double> diff = end-start;
				time[i] += diff;
			}
			cout << setw(21) << setfill(' ') << "Algorithm " << i+1 << ":     " << time[i].count() << endl;
		}
		else {
			auto start = chrono::high_resolution_clock::now();
			time[i] = start-start;
		}
	}
}

// void create_vet(vector<long int> &vet, long int tam) {
// 	for(int i=0; i<tam;)
// }