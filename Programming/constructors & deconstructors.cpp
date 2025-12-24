#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(string n) { //only name provided
            name = n;
        }
        Person(string n, int a) : name(n) { //name and age provided
            age = a;
        }
        void displayInfo() { //display name and age
            cout << "Name: " << name << ", Age: " << age << endl;
        }
        ~Person() { //destructor
            cout << "Destructor called for " << name << endl;
        }
};

int main(){
    Person person2("Bob", 30);
    person2.displayInfo();
    return 0;

}