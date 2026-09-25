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
void selectSort(Student[], int);
void getMinimum(Student[], int, double &, int &);
void getMaximum(Student[], int, double &, int &);
double calculateMean(Student[], int);


int main() {

    ifstream fin;
    fin.open(INPUT_FILE);

    //Display error if input file could not be read
    if(!fin.good()){
        cout << "Input File could not be opened!" << endl;
        return -1;
    }

    //Create student array and add from file
    Student students[MAX_SIZE];

    int addedStudents = 0;
    
    for (int i = 0; i < MAX_SIZE; i++){

        fin >> students[i].ID;
        fin >> students[i].score;
        addedStudents++;
    }
    fin.close();

    cout << "Read " << addedStudents << " student records." << endl;
    //Sorts data
    selectSort(students, addedStudents);
    //Output Time
    ofstream fout;
    fout.open(OUTPUT_FILE);

    if(!fout.good()){
        cout << "Output File could not be opened!" << endl;
        return -1;
    }

    //Output sorted results to output file
    for (int i = 0; i < addedStudents; i++) {
        fout << students[i].ID << " "
             << students[i].score << endl;
    }

    fout.close();

    cout << "Sorted results written to " << OUTPUT_FILE << endl;

    //Getting score statistics
    double minScore;
    int minID;
    double maxScore;
    int maxID;

    getMinimum(students, addedStudents, minScore, minID);
    getMaximum(students, addedStudents, maxScore, maxID);

    double mean = calculateMean(students, addedStudents);

    //test
    cout << minScore << " " << minID << endl;
    cout << maxScore << " " << maxID << endl;
    cout << mean << endl;

    return 0;
}

//Definitions

//Function for selection sort
void selectSort(Student students[], int addedStudents){

    int min;

    for(int i = 0; i < addedStudents - 1; i++){

        min = i;

        for(int j = i + 1; j < addedStudents; j++){

            if(students[j].ID < students[min].ID) {

                min = j;
            }
        }

        Student tempStudent = students[i];
        students[i] = students[min];
        students[min] = tempStudent;
    }
}

//Function for getting the minimum score
void getMinimum(Student students[], int addedStudents, double &minScore, int &minID) {

    minScore = students[0].score;
    minID = students[0].ID;

    for (int i = 1; i < addedStudents; i++) {
        if(students[i].score < minScore){

            minScore = students[i].score;
            minID = students[i].ID;
        }
    }
}

//Function for getting the maximum score
void getMaximum(Student students[], int addedStudents, double &maxScore, int &maxID) {

    maxScore = students[0].score;
    maxID = students[0].ID;

    for (int i = 1; i < addedStudents; i++) {
        if(students[i].score > maxScore){

            maxScore = students[i].score;
            maxID = students[i].ID;
        }
    }
}

//Function for calculating the mean
double calculateMean(Student students[], int addedStudents){

    double addedTotal = 0;

    for (int i = 0; i < addedStudents; i++) {
        addedTotal += students[i].score;
    }

    return addedTotal / addedStudents;
}

