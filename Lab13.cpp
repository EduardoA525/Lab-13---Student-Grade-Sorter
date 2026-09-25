//Eduardo Avila
//COMSC - 210 - 5293
//Lab 13 - Student Grade Sorter

#include <iostream>
#include <fstream>
#include <cmath>
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
void selectSortScore(Student [], int); //for finding median of score
void getMinimum(Student[], int, double &, int &);
void getMaximum(Student[], int, double &, int &);
double calculateMean(Student[], int);
double calculateMedian(Student[], int);
void getMedianID(Student[], int, double, int &);
double calculateDeviation(Student[], int, double);

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

    cout << "\nRead " << addedStudents << " student records." << endl;
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

    cout << "Sorted results written to " << OUTPUT_FILE << "\n" << endl;

    //Getting score statistics
    double minScore;
    int minID;
    double maxScore;
    int maxID;

    getMinimum(students, addedStudents, minScore, minID);
    getMaximum(students, addedStudents, maxScore, maxID);

    double mean = calculateMean(students, addedStudents);
    double median = calculateMedian(students, addedStudents);

    int medianID;
    getMedianID(students, addedStudents, median, medianID); //Associates ID with median

    double deviation = calculateDeviation(students, addedStudents, mean);

    //Summary Output
    cout << "--- Summary Statistics ---" << endl;
    cout << "Minimum Score: " << minScore << " (Student ID: " << minID << ")" << endl;
    cout << "Maximum Score: " << maxScore << " (Student ID: " << maxID << ")" << endl;
    cout << "Mean Score: " << mean << endl;
    cout << "Median Score: " << median << " (Student ID: " << medianID << ")" << endl;
    cout << "Standard Deviation: " << deviation << endl;

    return 0;
}

//Definitions

//Function for selection sort by ID
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

//Function for selection sort by score
void selectSortScore(Student students[], int addedStudents){
    
    int min;

    for(int i = 0; i < addedStudents - 1; i++){

        min = i;

        for(int j = i + 1; j < addedStudents; j++){

            if(students[j].score < students[min].score) {

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

//Function for calculating median -- solving the ID grab later
double calculateMedian(Student students[], int addedStudents){

    //Creates new array for copy sorted by scores
    Student studentsScore[MAX_SIZE];

    for (int i = 0; i < addedStudents; i++) {
        studentsScore[i] = students[i];
    }

    //Sorts by score
    selectSortScore(studentsScore, addedStudents);

    //Calculates median for even number since there is no real middle
    int middle1 = addedStudents / 2 - 1;
    int middle2 = addedStudents / 2;

    double middleScore1 = studentsScore[middle1].score;
    double middleScore2 = studentsScore[middle2].score;

    double median = (middleScore1 + middleScore2) / 2;

    return median;
}

//Function for associating ID with the first median score
void getMedianID(Student students[], int addedStudents, double median, int &medianID)
{
    for (int i = 0; i < addedStudents; i++) {
        if (students[i].score == median) {
            medianID = students[i].ID;
            return;
        }
    }
}

//Function to find standard deviation
double calculateDeviation(Student students[], int addedStudents, double mean){

    double sum = 0;

    for(int i = 0; i < addedStudents; i++){
        double diff = students[i].score - mean;
        sum += diff * diff;
    }

    double variance = sum / addedStudents;
    double deviation = sqrt(variance);

    return deviation;
}