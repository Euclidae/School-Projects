#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string ID, Name, Surname, Course_code;
    double test_1, test_2;
};

int main() {
    ifstream in_file("marks.txt", ios::in);
    ofstream outfile("stats.txt");
    
    if (!in_file.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }
    
    if (!outfile.is_open()) {
        cout << "Error opening output file!" << endl;
        return 1;
    }
    
    Student student;
    int counter = 0;
    double test_1_average = 0.0;
    double highest_test_1 = -1;  
    double lowest_test_1 = 101;     
    // Read student records
    while (in_file >> student.ID >> student.Name >> student.Surname 
           >> student.Course_code >> student.test_1 >> student.test_2) {
        
        test_1_average += student.test_1;
        
        if (counter == 0) {  // First student - initialize min/max
            highest_test_1 = student.test_1;
            lowest_test_1 = student.test_1;
        } else {
            if (student.test_1 > highest_test_1) highest_test_1 = student.test_1;
            if (student.test_1 < lowest_test_1) lowest_test_1 = student.test_1;
        }
        
        ++counter;
    }
    
    // Calculate average
    if (counter > 0) {
        test_1_average /= counter;
    }
    
    // Write statistics to output file
    outfile << "Total Students: " << counter << endl;
    outfile << "Average Test1: " << fixed << setprecision(0) << test_1_average << endl;
    outfile << "Highest Test1: " << (int)highest_test_1 << endl;
    outfile << "Lowest Test1: " << (int)lowest_test_1 << endl;
    
    in_file.close();
    outfile.close();
    
    
    return 0;
}

