
#include <iostream>
#include <array>
using namespace std;
int main(){ // main function start
for (int i = 0; i <= 100; i++) { // incerment 1 start
cout << i << endl;
} // increment 1 end
system("pause");
system("cls");
for (int i = 0; i <= 100; i += 2) { // increment 2 start
cout << i << endl;
} // increment 2 end
system("pause");
system("cls");
for (int i = 0; i < 100; i += 3) { // increment 3 start
cout << i << endl;
} // increment 3 end
system("pause");
system("cls");
for (int i = 0; i <= 100; i += 5) { // increment 5 start
cout << i << endl;
} // increment 5 end
system("pause");
system("cls");
int myArray[10];
for(int i = 0; i < 10; i++) { // array start
cout << "Enter number: \n";
cin >> myArray[i];
} // array end
for(int i = 0; i < 10; i++) { // array output start
cout << myArray[i] << endl;
} // array output end
system("pause");
} // main function end
 