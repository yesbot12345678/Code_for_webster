
#include <iostream>
#include <cstdlib>
using namespace std;

int main() { 

  int equationtype = 0;
  float answer = 0;

  while(true){

  system("clear");

  start:

  int equationtype ;
  cout << "Enter The Type Of Equation You Want To Do: \n";
  cout << "1. Addition\n";
  cout << "2. Subtraction\n";
  cout << "3. Multiplication\n";
  cout << "4. Division\n";
  cout << "5. Exit Program\n";

  cin >> equationtype;

  system("clear");

  if(equationtype == 5){
  cout << "You Have Exited The Program.\n";
  exit(0);
  }

  if (equationtype == 1) {

    cout << "You Chose Addition\n";

    float numA;

    cout << "Enter An Integer For A: ";

    if (!(cin >> numA)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For A: ";
      cin >> numA;

    }

    float numB;

    cout << "Enter An Integer For B: ";

    if (!(cin >> numB)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For B: ";
      cin >> numB;

    }
    answer = numA + numB;

    cout << "A + B = " << answer << "\n";

    cout << "Press Enter to Exit.\n";
    cin.ignore();
    cin.get();
    system("clear");
  }

  if (equationtype == 2){

      float numA;

      cout << "Enter An Integer For A: ";

    if (!(cin >> numA)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For A: ";
      cin >> numA;

    }

      float numB;

      cout << "Enter An Integer For B: ";

    if (!(cin >> numB)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For B: ";
      cin >> numB;

    }

    answer = numA - numB;

    cout << "A - B = " << answer << "\n";

    cout << "Press Enter to Exit.\n";
    cin.ignore();
    cin.get();
    system("clear");

  }

  if (equationtype == 3) {

    float numA;

    cout << "Enter An Integer For A: ";

    if (!(cin >> numA)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For A: ";
      cin >> numA;

    }

    float numB;

    cout << "Enter An Integer For B: ";

    if (!(cin >> numB)) {
      cout << "You Did Not Enter A Valid Number.\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For B: ";
      cin >> numB;

    }

  answer = numA * numB;

  cout << "A * B = " << answer << "\n";

  cout << "Press Enter to Exit.\n";
  cin.ignore();
  cin.get();
  system("clear");

}

  if (equationtype == 4 ){

    float numA;

    cout << "Enter An Integer For A: ";

    if (!(cin >> numA)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For A: ";
      cin >> numA;

    }

    float numB;

    cout << "Enter An Integer For B: ";

    if (!(cin >> numB)) {
      cout << "You Did Not Enter A Valid Number\n";
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Enter An Integer For B: ";
      cin >> numB;

    }

  answer = numA / numB;

  cout << "A / B = " << answer << "\n";

  cout << "Press Enter to Exit.\n";
  cin.ignore();
  cin.get();
  system("clear");

  }

 

  }

  if (equationtype > 5 or equationtype < 1){
    cout << "You Did Not Enter A Valid Option\n";
    goto start;
  }


    }

 

 

 

 

 