#include <iostream>
#include <fstream> // For file handling
#include <string>
using namespace std;

int main() {
    int numStudents;
    string name;
    int marks;

    // Step 1: Write data to the file
    ofstream outFile("students.txt");

    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    // Input the number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input each student's name and marks, then write them to the file
    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter the name of student " << i+1 << ": ";
        cin >> name;
        cout << "Enter the marks of " << name << ": ";
        cin >> marks;

        // Write name and marks to the file
        outFile << name << " " << marks << endl;
    }

    outFile.close(); // Close the output file

    // Step 2: Read data from the file
    ifstream inFile("students.txt");

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\nReading data from the file:\n";
    while (inFile >> name >> marks) {
        // Display the content from the file
        cout << "Name: " << name << ", Marks: " << marks << endl;
    }

    inFile.close(); // Close the input file

    return 0;
}
