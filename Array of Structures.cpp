#include<iostream>

using namespace std;

struct student{
    string firstName;
    string lastName;
    int classGrade;
    double GPA;
};
int main()
{
    student students[2];

    for(int i = 0; i <1; i++) {
        cout << "Enter details for student " << (i + 1) << ":\n";
        cout << "First Name: ";
        cin >> students[i].firstName;
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Class Grade: ";
        cin >> students[i].classGrade;
        cout << "GPA: ";
        cin >> students[i].GPA;
    }
    system("clear");
    cout << "\nStudent Details:\n";
    for(int i = 0; i < 1; i++) {
        cout << "Student " << (i + 1) << ":\n";
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << "\n";
        cout << "Class Grade: " << students[i].classGrade << "\n";
        cout << "GPA: " << students[i].GPA << "\n\n";
    }
    return 0;
}