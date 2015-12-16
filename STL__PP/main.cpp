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

template <class K> ostream & operator<<(ostream &output, const  set<K>& val)
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
		++i;
	}
	return output;
}

TEST(Vector, Output)
{
	ostringstream test_str;

	vector <int> test = { 1, 2, 3 };

	test_str << test;

	EXPECT_EQ("1. element - 1\n2. element - 2\n3. element - 3\n", string(test_str.str()));
}



TEST(Map, Output)
{
	ostringstream test_str;

	map <int, int> test;
	test[1] = 3;
	test[3] = 1;
	test[2] = 5;

	test_str << test;

	EXPECT_EQ("1. element - key: 1 value: 3\n2. element - key: 2 value: 5\n3. element - key: 3 value: 1\n", string(test_str.str()));
}
//*
TEST(Set, Output)
{
	ostringstream test_str;

	set <int> test = { 1, 2, 3 };
	test_str << test;

	EXPECT_EQ("1. element - 1\n2. element - 2\n3. element - 3\n", string(test_str.str()));
}
//*/

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

	//Const Vector
	const vector<int> *_cvector; //const pointer
	//_cvector = new vector<int>; /
	vector<int> i;  
	i.push_back(5);
	i.push_back(6);
	i.push_back(7);
	i.push_back(8);
	_cvector = &i;
	cout << "Const pointer:\n";
	cout << (*_cvector) << endl;

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();
}