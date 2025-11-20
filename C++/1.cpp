#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	string b(a,0,4);
	string c(a,5,2);
	cout<<c;
	return 0;
}
