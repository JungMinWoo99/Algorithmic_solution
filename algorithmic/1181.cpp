#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class String
{
private:
	char str[51];

public:
	static bool compareString(String* b, String* a)
	{
		return (strlen(a->str) > strlen(b->str) || ((strlen(a->str) == strlen(b->str)) && (strcmp(a->str, b->str) > 0)));
	}

	static bool isSameString(String* b, String* a)
	{
		return strcmp(a->str,b->str)==0;
	}

	static void sortStringContainer(vector<String *> &str_vector)
	{
		sort(str_vector.begin(), str_vector.end(), String::compareString);
	}

	static void removeOverlapString(vector<String *> &str_vector){
		std::vector<String*>::iterator it;
		it=unique(str_vector.begin(),str_vector.end(),isSameString);
		//unique 사용후 반드시 resize과정이 필요
		str_vector.resize(std::distance(str_vector.begin(),it));
	}
	
	static void inputStringContainer(vector<String *> &str_vector, int input_num)
	{
		for (int i = 0; i < input_num; i++)
		{
			String *str_input = new String;
			str_input->inputString();
			str_vector.push_back(str_input);
		}
	}

	static void printStringContainer(vector<String *> &str_arr)
	{
		for (int i = 0; i < str_arr.size(); i++)
			str_arr[i]->printString();
	}

	void inputString()
	{
		cin >> this->str;
	}

	void printString()
	{
		cout << this->str << '\n';
	}
};

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<String*> input_vector;
	int input_num;
	cin >> input_num;

	String::inputStringContainer(input_vector,input_num);

	if (input_num == 1)
	{
		input_vector[0]->printString();
		return 0;
	}

	String::sortStringContainer(input_vector);

	String::removeOverlapString(input_vector);

	String::printStringContainer(input_vector);

	return 0;
}