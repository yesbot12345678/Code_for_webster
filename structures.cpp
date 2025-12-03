#include <iostream>
using namespace std;
struct skibidi
{
char a;
int b;
};
struct skib2 
{
float a;
string b;
} skibidi2;
int main()
{
skibidi news = { 'A', 42 };
skib2 news2 = { 3.14, "Hello, World!" };
cout << news.a << " " << news.b << endl;
cout << news2.a << " " << news2.b << endl;
}