#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


template<class K> ostream & operator<<(ostream &output, vector<K> &val)
{
	int i(1);
	/*
	for (vector<K>::iterator iter = val.begin(); iter != val.end(); ++iter, ++i)
	{
		output << i << " element - " << (*iter) << endl;
	}
	//*/
	for(const auto& elem:val)
	{
		output << i << "element - " << elem << endl;
		++i;
	}
	return output;
}

template<class K, class T> ostream & operator<<(ostream &output, map<K, T> &val) 
{
	int i(1);
	/*
	for (map<K, T>::iterator iter = val.begin(); iter != val.end(); ++iter, ++i)
	{
		output <<i<<".element - " "key: " << iter->first << " value: " << iter->second<<endl;
	}
	//*/
	for (const auto& elem : val)
	{
		output << i << ".element - " "key: " << elem.first << " value: " << elem.second << endl;
		++i;
	}
	return output;
}

template <class K> ostream & operator<<(ostream &output, set<K> val)
{
	int i(1);

	/*
	for (set<K>::iterator iter = val.begin(); iter != val.end(); ++iter)
	{
		output << i << " element - " << (*iter) << endl;
	}
	//*/
	for (const auto& elem:val)
	{
		output << i << " element - " << elem << endl;
	}
	return output;
}

int main()
{
	cout << "vector:" << endl;
	vector<int> V;
	V.push_back(11);
	cout << V << endl;

	cout << "map:" << endl;
	map<int, int> M;
	M[1] = 2;
	cout << M << endl;

	cout << "set:" << endl;
	set<int> s;
	s.insert(11);
	cout << s << endl;
	
	cin.get();
}