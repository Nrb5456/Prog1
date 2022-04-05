#include "../std_lib_facilities.h"

template<typename T> void write(const T& t)
{
  	for(auto& n : t)
    	cout<< n <<" ";
  	cout<<"\n";
}

template<typename T> void add(T& t, int n)
{
  	for(auto& x : t)
    	x = x + n;
}

template<typename Iter1, typename Iter2> Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  	while(f1!=e1)
    {
      *f2 = *f1;
      ++f1; ++f2;
    }
    return f2;
}

int main(){

	array<int, 10> array1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
	vector<int> v1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	array<int, 10> array2; 
	for(int i = 0; i < 10; ++i)
    	array2[i] = array1[i];
	vector<int> v2 = v1;
	list<int> l2 = l1;

	add(array1, 2);
	add(v1, 3);
	add(l1, 5);	

	write(array1);
	write(v1);
	write(l1);

	vector<int> v3(10);
  	my_copy(array2.begin(),array2.end(),v3.begin());
  	write(v3);

  	array<int,10> array4;
  	my_copy(l2.begin(),l2.end(),array4.begin());
  	write(array4);

  	vector<int>::iterator vit;
    vit = find(v3.begin(), v3.end(), 3);
    if (vit != v3.end())
        cout << "Found at: " << distance(v3.begin(), vit) << '\n';
    else
        cout << "Not found..\n";

    list<int>::iterator lit;
    lit = find(l2.begin(), l2.end(), 27);
    if (lit != l2.end())
        cout << "Found at: " << distance(l2.begin(), lit) << '\n';
    else
        cout << "Not found..\n";

	return 0;
}