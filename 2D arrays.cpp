
#include <iostream>
#include <array>
using namespace std;
int main() { // main func strart
int box[5][5] = { };
for (int r = 0; r < 5; r++) { // row loop input start
for (int c = 0; c < 5; c++) { // assign var input start
cout << "Enter a number: \n";
cin >> box[r][c];
} // assign var input end
} // row loop input end
for (int r = 0; r < 5; r++) { // row loop output start
for (int c = 0; c < 5; c++) { // assign var output start
cout << box[r][c];
} // assign var output end
} // row loop output end
return 0;
} // main func end