#include "util.h"
#include "search.h"
#include <cstdlib>
 
int main(int argc, char **argv) {
    /*
    Converting the string passed through command line into a 'long int';
    Must use this 'int' to determine how many tests cases shall be executed.
    */
    if(argc != 3) { //If user do not input only the necessary inputs.
    	cerr << "Inputs on command line not defined correctly!" << endl;
    	return -1;
    }
    istringstream ss(argv[1]);//Minimun space alocated my array may have.
    int menor; //Minimum array size.
    if (!(ss >> menor)) {           //Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[1] << '\n';
        return -2;
    }

    istringstream zs(argv[2]);//Binary representing the Search algorithms wished to use.
    string bin; //Pass this value as a string to 'bin'.
    if(bin.size() != 7) { //As I have 7 Search Algorithms.
    	cerr << "Invalid number " << argv[2] << ". Must have width 7!" << endl;
    	return -3;
    }
    for(int j=0; j<7; ++j) {
    	if(bin[j] != '1' || bin[j] != '0') {
    		cerr << "Invalid number " << argv[2] << ". Must be in Binary form!" << endl;
    		return -4;
    	}
    }


    cout << "Lower value alocated to our array :" << menor << endl;
    long int *A =(long int*) calloc(10000000, sizeof(long int));
    for(int i=0; i<10000000; i++) {
    	A[i] = i+5;
    }

    long int* (**Func)(long int*, long int*, long int) = Pointer_to_Func();

    for(int i=0; i<25; ++i) {
    	chrono::duration<double> time;
    	for(int j=0; j<100; ++j) {
    		//for(int k=0; k<7; ++k) {
    			auto start = chrono::high_resolution_clock::now();
    			Func[2](A, A+(menor+i*(MAXT-menor)/25), -4);
    			auto end = chrono::high_resolution_clock::now();
    			time += end-start;
    		//}
    	}
    	chrono::duration<double> media = time/100;
    	cout << "Test with " << menor+i*(MAXT-menor)/25 << " space alocated: ";
    	cout << "    " << setprecision(6) << media.count()*pow(10,7) << endl;
    }

	/*Defining 'Func' as an array that stores all my search algorithms.
    Func is a pointer of functions.
    */
    //long int A[] = calloc(pow(10,10), sizeof(long int));

	/*Use Argv to know how many test cases I must try
	Look pdf for more details*/


    //long int A[] = {0,1,3,4,6,7,8,9,10,20,25,28};
    //long int values[] = {0,2,3,4,6,7,8,28,9,10,5,1,25,22};
    // long int A[] = {0,1,2,3,4,5,6,7,8,9,15};
    // long int values[] = {0,1,2,3,4,5,6,7,8,9,-4,22,13};
    // cout << "Array = [ ";
    // for(auto& it : A) {
    //     cout << it << " ";
    // }
    // cout << "]" << endl;
    // for(auto &e : values) {
    //     auto r = Func[3](begin(A), end(A), e);

    //     if(r != end(A)) {
    //         cout << ">>> Found \"" << e << "\" at position " << distance(begin(A),r) << ".\n";
    //     }
    //     else {
    //         cout << ">>> Value \"" << e << "\" not found in array!\n";
    //     }
    // }
    return 0;
}