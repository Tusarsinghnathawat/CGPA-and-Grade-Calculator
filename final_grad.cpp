#include <iostream>
#include <vector>
using namespace std;

// Class to handle CGPA and Grade Calculation for a single subject
class Subject {
    private:
        float midsemMarks, endsemMarks, internalMarks;
        float subjectCGPA;
        string subjectGrade;

    public:
        // Function to input marks for a single subject
        void inputMarks() {
            cout << "Enter Mid-Semester Marks (out of 30): ";
            cin >> midsemMarks;
            cout << "Enter End-Semester Marks (out of 70): ";
            cin >> endsemMarks;
            cout << "Enter Internal Marks (out of 50): ";
            cin >> internalMarks;
        }

        // Function to calculate CGPA for a single subject
        void calculateCGPA() {
            // Total marks out of 150
            float totalMarks = midsemMarks + endsemMarks + internalMarks;

            // Calculation for CGPA (dividing by total maximum marks and multiplying by 10 for scale)
            subjectCGPA = (totalMarks / 150) * 10;
        }

        // Function to calculate the grade based on CGPA
        void calculateGrade() {
            if (subjectCGPA >= 9.0) {
                subjectGrade = "O (Outstanding)";
            } else if (subjectCGPA >= 8.5) {
                subjectGrade = "A+ (Excellent)";
            } else if (subjectCGPA >= 7.5) {
                subjectGrade = "A (Very Good)";
            } else if (subjectCGPA >= 6.5) {
                subjectGrade = "B+ (Good)";
            } else if (subjectCGPA >= 5.5) {
                subjectGrade = "B (Above Average)";
            } else if (subjectCGPA >= 4.5) {
                subjectGrade = "C (Average)";
            } else if (subjectCGPA >= 4.0) {
                subjectGrade = "P (Pass)";
            } else {
                subjectGrade = "F (Fail)";
            }
        }

        // Function to return the CGPA of the subject
        float getCGPA() {
            return subjectCGPA;
        }

        // Function to return the grade of the subject
        string getGrade() {
            return subjectGrade;
        }
};

// Class to handle the overall CGPA calculation
class CGPACalculator {
    private:
        vector<Subject> subjects;
        int numSubjects;
        float overallCGPA;

    public:
        // Constructor to initialize number of subjects
        CGPACalculator(int n) : numSubjects(n), overallCGPA(0) {
            subjects.resize(numSubjects);
        }

        // Function to input marks for all subjects
        void inputMarksForAllSubjects() {
            for (int i = 0; i < numSubjects; i++) {
                cout << "\nEnter marks for Subject " << i+1 << ":\n";
                subjects[i].inputMarks();
                subjects[i].calculateCGPA();
                subjects[i].calculateGrade();
            }
        }

        // Function to calculate the overall CGPA
        void calculateOverallCGPA() {
            float totalCGPA = 0;
            for (int i = 0; i < numSubjects; i++) {
                totalCGPA += subjects[i].getCGPA();
            }
            overallCGPA = totalCGPA / numSubjects;
        }

        // Function to display subject-wise grades and overall CGPA
        void displayResults() {
            cout << "\nSubject-wise CGPA and Grades:\n";
            for (int i = 0; i < numSubjects; i++) {
                cout << "Subject " << i+1 << " - CGPA: " << subjects[i].getCGPA()
                     << ", Grade: " << subjects[i].getGrade() << endl;
            }
            cout << "\nOverall CGPA: " << overallCGPA << endl;
        }
};

int main() {
    int numSubjects = 5;  // Assuming there are 5 subjects

    // Create a CGPACalculator object for the given number of subjects
    CGPACalculator student(numSubjects);

    // Input marks for all subjects
    student.inputMarksForAllSubjects();

    // Calculate overall CGPA
    student.calculateOverallCGPA();

    // Display subject-wise grades and overall CGPA
    student.displayResults();

    return 0;
}
