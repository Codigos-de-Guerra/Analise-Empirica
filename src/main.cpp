#include "util.h"
#include "search.h"
#include "write.h"
 
int main(int argc, char **argv) {
/*------------------------------------------------------------------------------------------------*/
                               /*Arguments of line Section */
    if(argc != 5) { //If user do not input only the necessary inputs.
    	cerr << "Inputs on command line not defined correctly!" << endl;
    	return -1;
    }
    istringstream xs(argv[1]);		//Maximun space alocated my array may have.
    int maior;						//Maximun array size.
    if(!(xs >> maior)) {			//Treating the possible error from user part, of not inputing a valid number.
    	cerr << "Invalid number " << argv[1] << endl;
    	return -2;
    }

    istringstream ss(argv[2]);      //Minimun space alocated my array may have.
    int menor;                      //Minimum array size.
    if (!(ss >> menor)) {           //Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[2] << endl;
        return -3;
    }

    istringstream cs(argv[3]);      //Number of tests case.
    int num_test;                   //Case tests.
    if(!(cs >> num_test)) {         //Treating the possible error from user part, of not inputing a valid number.
        cerr << "Invalid number " << argv[3] << endl;
        return -4;
    }

    istringstream zs(argv[4]);      //Binary representing the Search algorithms wished to use.
    string bin;                     //Pass this value as a string to 'bin'.
    zs >> bin;                      //Through string stream, receives the second value on command line.
    if(bin.size() != 7) {           //As I have 7 Search Algorithms.
    	cerr << "Invalid number " << argv[4] << ". Must have width 7!" << endl;
    	return -5;
    }
    for(int j=0; j<7; ++j) {		//Checks if string('number') inputted, is formated only by '1's or '0's.
    	if(bin[j] != '1' && bin[j] != '0') {
    		cerr << "Invalid number " << argv[4] << ". Must be in Binary form!" << endl;
    		return -6;
    	}
    }
    cout << endl;

/*------------------------------------------------------------------------------------------------*/
                                      /* Array Section */
    cout << "Initializing Array...." << endl;
    long int *A;
    A = new long int[300000000];
    for(int i=0; i<300000000; i++) {
    	A[i] = i+5;
    }
    cout << "\033[1;32mFinished Array!\033[0m" << endl << endl;

/*------------------------------------------------------------------------------------------------*/
                             /* Calculating Algorithms Section */
    /* Declaration of 'Func' as my array of pointers to functions. */
    Ptr_Func *Func = Pointer_to_Func(); 

    chrono::duration<double> **tt = new chrono::duration<double>*[num_test+1];
    for(int i=0; i<num_test+1; i++) {
    	tt[i] = new chrono::duration<double>[7];
    }
    
    int **steps = new int*[num_test+1];
    for(int i=0; i<num_test+1; i++) {
    	steps[i] = new int[7];
    }

    cout << "Calculating Searching Times...." << endl;
    for(int i=0; i<=num_test; ++i) {
        if((i != 0 && i != num_test) && i % (num_test/5) == 0) {       		//Just printing a response to know if the program still is running.
            cout << "Calculated... " << i*100/num_test << "%." << endl;
        }
    	for(int j=0; j<7; j++) {
    		if(bin[j] == '1') {
    			tt[i][j] = ExecFunc(A, A+(menor+i*(maior-menor)/num_test), Func[j], steps[i][j]);
    		}
    	}
    }

/*------------------------------------------------------------------------------------------------*/
    								/* Making output files */
    ofstream ofsT;
    ofstream ofsS;
    TimeFile(menor, maior, num_test, bin, tt, ofsT, "out/Tempo(s).txt");
    StepFile(menor, maior, num_test, bin, steps, ofsS, "out/Passos.txt");

    ofsT.close();
    ofsS.close();

/*------------------------------------------------------------------------------------------------*/
                                /* Printing Chart Section */
    cout << "Print chart with array sizes and respectively executions times and iterations? (y or n)." << endl;
    char qq;
    cin >> qq;
    cout << endl;


    if(qq == 'y' || qq == 'Y') {
        printTerminal(menor, maior, num_test, bin, tt, steps);
    }
    else if(qq == 'n' || qq == 'N') {
        cout << "Program finished successfully!" << endl;
    }
    else {
        cerr << "You were supposed to insert 'y' or 'n'. Are you idiot?" << endl;
    }

/*------------------------------------------------------------------------------------------------*/
    						/* Cleaning previous space alocated */
    for(int i=0; i<num_test+1; i++) {
    	delete[] tt[i];
    }
    for(int i=0; i<num_test+1; i++) {
    	delete[] steps[i];
    }
    delete[] Func;
    delete[] steps;
    delete[] tt;
    delete[] A;

    return 0;
}