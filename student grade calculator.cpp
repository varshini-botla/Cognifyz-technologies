#include <iostream>

using namespace std;

int main() {
    int numSubjects;
    double totalGrades = 0.0;
    
    // Prompt user to enter the number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;
    
    // Validate number of subjects
    if (numSubjects <= 0) {
        cout << "Number of subjects must be greater than zero." << endl;
        return 1;
    }
    
    // Array to store grades
    double grades[numSubjects];
    
    // Prompt user to enter grades for each subject
    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter grade for subject " << (i + 1) << ": ";
        cin >> grades[i];
        
        // Validate grade input
        if (grades[i] < 0 || grades[i] > 100) {
            cout << "Invalid grade input. Grades must be between 0 and 100." << endl;
            return 1;
        }
        
        // Accumulate total grades
        totalGrades += grades[i];
    }
    
    // Calculate average grade
    double averageGrade = totalGrades / numSubjects;
    
    // Display average grade
    cout << "Average grade: " << averageGrade << endl;
    
    return 0;
}

