#include <iostream>
#include <string>

using namespace std;

template <typename T>
class greaterThan
{
	public:
		bool operator() (const T& x,const T& y) const
		{
			return x > y;
		}
};

int main()
{
	greaterThan<int> f;
	int a,b;
	
	cout << "Please enter two numbers to compare" << endl;
	cin >> a >> b;
	
	if(f(a,b))
		cout << a << ">" << b << endl;
	else
		cout << a << "<=" << b << endl;
		
	string strA = "walk", strB = "crawl";
	
	greaterThan<string> z;
	if(z(strA,strB))
		cout << strA << ">" << strB << endl;
	else
		cout << strA << "<=" << strB << endl;
	
	return 0;
}
