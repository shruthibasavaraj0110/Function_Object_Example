#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class greaterThan
{
	public:
		bool operator() (const T& x,const T& y) const
		{
			return x>y;
		}
};

template <typename T>
class lessThan
{
	public:
		bool operator() (const T& x,const T& y)const
		{
			return x<y;
		}
};

//use insertion sort to order v using function object comp

template <typename T, typename Compare>
void insertionSort(vector<T>& v, Compare comp)
{
	int i,j,n=v.size();
	T temp;
	
	for(i=1;i<n;i++)
	{
		j = i;
		temp = v[i];
		
		while(j>0 && comp(temp,v[j-1]))
		{
			v[j] = v[j-1];
			j--;
		}
		
		v[j] = temp;
		
	}

}

template <typename T>
void writeVector(const vector<T>& v)
{
	int i, n = v.size();
	
	for(i=0; i<n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}



int main()
{
	int arr[] = {2,1,7,8,12,15,3,5};
	int arrSize = sizeof(arr) / sizeof(int);
	
	vector<int> v(arr,arr+arrSize);
	
	//Put the vector in ascending order
	insertionSort(v,lessThan<int>());
	//output it
	writeVector(v);
	
	//Put the vector in descending order
	insertionSort(v, greaterThan<int>());
	//output it
	writeVector(v);
	
	return 0;
	
}
