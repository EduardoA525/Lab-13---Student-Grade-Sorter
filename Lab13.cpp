/*
Implement a student grade sorter using selection sort. 
Read student data from the input file into a C++ array of structs. 
Each struct must contain the student ID and exam score. 
Sort the array by student ID in ascending order using selection sort, 
then write the sorted results to an output file. 
Display statusing in the console along with the summary statistics below.
*/

/*
Sample Output
Read 150 student records
Sorted results written to 210-lab-13-grades-sorted.txt

--- Summary Statistics ---
Minimum Score: 63 (Student ID: 304130512)
Maximum Score: 93.5 (Student ID: 304355461)
Mean Score: 80.5333
Median Score: 80.5 (Student ID: 304367391)
Standard Deviation: 6.48554
*/

//Eduardo Avila
//COMSC - 210 - 5293
//Lab 13 - Student Grade Sorter

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 150;
const string INPUT_FILE = "210-lab-13-grades.txt";
const string OUTPUT_FILE = "210-lab-13-grades-sorted.txt";

struct Student {

    int ID;
    double score;
};

//prototypes


int main() {

    ifstream fin;
    fin.open(INPUT_FILE);

    //Display error if input file could not be read
    if(!fin.good()){
        cout << "Input File could not be opened!" << endl;
        return -1;
    }



    return 0;
}