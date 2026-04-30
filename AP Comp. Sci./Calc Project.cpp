#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;



int addition(float numA, float numB){
  return numA + numB;
}
int subtraction(float numA, float numB){
  return numA - numB;
}
int multiplication(float numA, float numB){
    return numA * numB;
}
int division(float numA, float numB){
    if(numB == 0){
        cout << "You Cannot Divide By Zero\n";
        return 0;
    }
    return numA / numB;
}
int exponents(float numA, float numB){
    float answer = 1;
    for(int i = 0; i < numB; i++){
        answer *= numA;
    }
    return answer;
}
int squareroot(float numA){
    if(numA < 0){
        cout << "You Cannot Take The Square Root Of A Negative Number\n";
        return 0;
    }
    return sqrt(numA);
}
int areaofcircle(float radius){
    if(radius < 0){
        cout << "You Cannot Have A Negative Radius\n";
        return 0;
    }
    return M_PI * radius * radius;
}
int areaoftriangle(float base, float height){
    if(base < 0 || height < 0){
        cout << "You Cannot Have A Negative Base Or Height\n";
        return 0;
    }
    return 0.5 * base * height;
}
int areaofrectangle(float length, float width){
    if(length < 0 || width < 0){
        cout << "You Cannot Have A Negative Length Or Width\n";
        return 0;
    }
    return length * width;
}
    
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
  cout << "5. Exponents\n";
  cout << "6. Square Root\n";
  cout << "7. Area of a circle\n";
  cout << "8. Area of a triangle\n";
  cout << "9. Area of a rectangle\n";
  cout << "10. Exit Program\n";

  cin >> equationtype;

  system("clear");

  if(equationtype == 8){
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
    answer = addition(numA, numB);

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

    answer = subtraction(numA, numB);

    cout << "A - B = " << answer << "\n";

    cout << "Press Enter to Exit.\n";
    cin.ignore();
    cin.get();
    system("clear");

  }

  if (equationtype == 3) {

    cout << "You Chose Multiplication\n";

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

    answer = multiplication(numA, numB);

    cout << "A * B = " << answer << "\n";

    cout << "Press Enter to Exit.\n";
    cin.ignore();
    cin.get();
    system("clear");
    }

    if (equationtype == 4) {

        cout << "You Chose Division\n";

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

    answer = division(numA, numB);

    cout << "A / B = " << answer << "\n";

    cout << "Press Enter to Exit.\n";
    cin.ignore();
    cin.get();
    system("clear");
    }


}
