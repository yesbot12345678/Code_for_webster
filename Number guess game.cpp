
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{ // main func start
int yournum = 0;
    srand(time(0));
int randnum = rand() % 100 + 1; 
cout << "Guess a number between 1 and 100\n";
while (true)
{
if (yournum != randnum)
{ // guess start
cin >> yournum;
if (yournum < randnum)
{ // to low start
cout << "Number to low\n";
} // to low end
else if (yournum > randnum)
{ // to high start
cout << "Number to high\n";
} // to high end
} // guess end
else if (yournum == randnum)
{ // correct start
cout << "Your number is correct\n";
return 0;
} // correct end
}
} // main func end
 