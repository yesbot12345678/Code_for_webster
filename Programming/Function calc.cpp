

#include <iostream>

using namespace std;

double add(double a, double b){ // addition function

    return a + b;

} // addition function ends here

double subtract(double a, double b){ // subtraction function

    return a - b;

} // subtraction function ends here

double multiply(double a, double b){ // multiplication function

    return a * b;

} // multiplication function ends here

double divide(double a, double b){ // division function

    return a / b;

} // division function ends here

int main() { // main function starts here

    int equationtype = 0;
double answer = 0;

    while (true) { // while loop starts here

        system("cls");

        int equationtype;

        cout << "Enter The Type Of Equation You Want To Do: \n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit Program\n";

        cin >> equationtype;

        system("cls");

        if (equationtype == 5) { // exit program start
            cout << "You Have Exited The Program.\n";
            exit(0);
        } // exit program end

        if (equationtype == 1) { // addition start

            cout << "You Chose Addition\n";

            double numA;
            double numB;

            cout << "Enter Number A: ";
            cin >> numA;

            cout << "Enter Number B: ";
            cin >> numB;

            double answer = add(numA, numB);

            cout << "A + B = " << answer << "\n";

            system("pause");


        } // addition end

        if (equationtype == 2) { // subtraction start

            cout << "You Chose Subtraction\n";

            double numA;
            double numB;

            cout << "Enter Number A: ";
            cin >> numA;

            cout << "Enter Number B: ";
            cin >> numB;

            double answer = subtract(numA, numB);

            cout << "A - B = " << answer << "\n";

            system("pause");
} // subtraction end

        if (equationtype == 3) { // multiplication start

            cout << "You Chose Multiplication\n";

            double numA;
            double numB;

            cout << "Enter Number A: ";
            cin >> numA;

            cout << "Enter Number B: ";
            cin >> numB;
            double answer = multiply(numA, numB);

            cout << "A * B = " << answer << "\n";

            system("pause");

        } // multiplication end

        if (equationtype == 4) { // division start

            cout << "You Chose Division\n";

            double numA;
            double numB;

            cout << "Enter Number A: ";
            cin >> numA;

            cout << "Enter Number B: ";
            cin >> numB;

            if (numB == 0) { // division by zero check start

                cout << "Error: Division by zero is not allowed.\n";

                system("pause");

cout << "Enter New Value For B: ";
cin >> numB;

            } // division by zero check end

            double answer = divide(numA, numB);

            cout << "A / B = " << answer << "\n";

            system("pause");

} // division end

} // while loop ends here

} // main function ends here