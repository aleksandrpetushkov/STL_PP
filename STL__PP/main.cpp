#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "gtest/gtest.h"

using namespace std;


template<class K> ostream & operator<<(ostream &output, const vector<K> &val)
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
		output << i << ". element - " << elem << endl;
		++i;
	}
	return output;

	// range based for разобраться что это такое и как использовать переопределить все через auto - сделано;
	// ВАЖНО КАК ПЕРЕОПРЕДЕЛИТЬ КОНСТАНТНЫЙ ВЕКТОР (const vector) и можно ли это сделать вообще. если передавать по указателю
	// как передавать аргумент в функцию все способы рассказать. ответы: по значению, по ссылке по указателю.


	//тесты,
}

template<class K, class T> ostream & operator<<(ostream &output, const map<K, T> &val) 
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
		output << i << ". element - " "key: " << elem.first << " value: " << elem.second << endl;
		++i;
	}
	return output;
}

template <class K> ostream & operator<<(ostream &output, const set<K> val)
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
		output << i << ". element - " << elem << endl;
	}
	return output;
}

TEST(FactorialTest, HandlesPositiveInput) 
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
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
	

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();
}