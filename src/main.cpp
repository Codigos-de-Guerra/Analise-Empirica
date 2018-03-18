#include "util.h"
#include "search.h"
 
int main(int argc, char **argv) {
    /*
    Converting the string passed through command line into a 'long int';
    Must use this 'int' to determine how many tests cases shall be executed.
    */

/*------------------------------------------------------------------------------------------------*/
                               /*Arguments of line Section */
    if(argc != 4) { //If user do not input only the necessary inputs.
    	cerr << "Inputs on command line not defined correctly!" << endl;
    	return -1;
    }
    istringstream ss(argv[1]);      //Minimun space alocated my array may have.
    int menor;                      //Minimum array size.
    if (!(ss >> menor)) {           //Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[1] << endl;
        return -2;
    }

    istringstream cs(argv[2]);      //Number of tests case.
    int num_test;                   //Case tests.
    if(!(cs >> num_test)) {         ////Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[2] << endl;
        return -3;
    }

    istringstream zs(argv[3]);      //Binary representing the Search algorithms wished to use.
    string bin;                     //Pass this value as a string to 'bin'.
    zs >> bin;                      //Through string stream, receives the second value on command line.

    if(bin.size() != 7) {           //As I have 7 Search Algorithms.
    	cerr << "Invalid number " << argv[3] << ". Must have width 7!" << endl;
    	return -4;
    }
    for(int j=0; j<7; ++j) {
    	if(bin[j] != '1' && bin[j] != '0') {
    		cerr << "Invalid number " << argv[3] << ". Must be in Binary form!" << endl;
    		return -5;
    	}
    }
    cout << endl;
/*------------------------------------------------------------------------------------------------*/
                                      /* Array Section */
    cout << "Initialing Array...." << endl;
    long int *A; //=(long int*) calloc(10000000, sizeof(long int));
    A = new long int[100000000];
    for(int i=0; i<100000000; i++) {
    	A[i] = i+5;
    }
    cout << "\033[1;32mFinished Array!\033[0m" << endl << endl;
/*------------------------------------------------------------------------------------------------*/
                             /* Calculating Algorithms Section */
    long int* (**Func)(long int*, long int*, long int) = Pointer_to_Func(); //Array of pointers to functions.

    chrono::duration<double> **tt;
    tt = new chrono::duration<double>*[num_test+1];
    *tt = new chrono::duration<double>[7];

    cout << "Calculating Searching Times...." << endl;
    for(int i=0; i<=num_test; ++i) {
        /*if((i != 0 && i != 25) && i % 5 == 0) */cout << "Calculated... " << i << "%." << endl;
        *(tt+i) = ExecFunc(A, A+(menor+i*(MAXT-menor)/num_test), bin, Func);
    }
    cout << "\033[1;32mFinished all Calculations!\033[0m" << endl << endl;
    /* Something to test--------------
    long int kk = 85;
    auto rqew = Func[3](A, A+1000000, kk);
    if(rqew != A+1000001) {
        cout << ">>> Found \"" << kk << "\" at position " << distance(A, rqew) << ".\n";
    }
    else {
        cout << ">>> Value \"" << kk << "\" not found in array!\n";
    }
    Test until here----------------------- */

/*------------------------------------------------------------------------------------------------*/
                                /* Printing Chart Section */
    cout << "Print chart with executions times? (y or n)." << endl;
    char qq;
    cin >> qq;
    cout << endl;
    if(qq == 'y' || qq == 'Y') {
        cout << "#Size";
        string t[] = {"ILS", "IBS", "RBS", "ITS", "RTS", "FBS", "JS"};
        for(int i=0; i<7; ++i) {
            if(bin[i] == '1') {
                cout << setw(16) << right << t[i] << "     ";
            }
        }
        cout << endl << endl;
        for(int i=0; i<=num_test; ++i) {
            cout << setw(12) << left << menor+i*(MAXT-menor)/num_test;
            for(int j=0; j<7; ++j) {
                if(bin[j] == '1') {
                    cout << setw(18) << left << scientific << setprecision(8) << tt[i][j].count() << "   ";
                }
            }
            cout << endl;
        }
    }
    else if(qq == 'n' || qq == 'N') {
        cout << "Program finished successfully!" << endl;
    }
    else {
        cerr << "You were supposed to insert 'y' or 'n'. Are you idiot?" << endl;
    }

	/*Defining 'Func' as an array that stores all my search algorithms.
    Func is a pointer of functions.
    */

	/*Use Argv to know how many test cases I must try
	Look pdf for more details.*/


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
    delete[] Func;
    delete[] tt;
    delete[] A;
    return 0;
}