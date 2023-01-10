#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

void inputIntArray(int *arr, int arr_size);
void sortIntArray(int *arr, int arr_size);
int findPrimeNumFromMaxNum(int *prime_num_arr, int max_num);
int countPrimeNumFromIntArray(int *prime_num_arr,int *int_arr, int prime_num_arr_size, int int_arr_size);
bool isPrime(int *prime_num_arr, int arr_size, int num);

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int *input_arr;
	int input_arr_size;
	int *prime_num_arr;
	int prime_num_cnt;
	int max_num;
	int answer = 0;

	cin >> input_arr_size;

	input_arr = new int[input_arr_size];
	prime_num_arr = new int[input_arr_size];

	inputIntArray(input_arr, input_arr_size);

	sortIntArray(input_arr, input_arr_size);

	max_num=input_arr[input_arr_size-1];

	prime_num_cnt=findPrimeNumFromMaxNum(prime_num_arr,max_num);
	answer=countPrimeNumFromIntArray(prime_num_arr,input_arr,prime_num_cnt,input_arr_size);
	

	cout << answer<<endl;

	return 0;
}

void inputIntArray(int *arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		cin >> arr[i];
	return;
}

void sortIntArray(int *arr, int arr_size)
{
	sort(arr, arr + arr_size);
	return;
}

int findPrimeNumFromMaxNum(int *prime_num_arr, int max_num)
{
	int prime_num_cnt = 0;
	prime_num_arr[prime_num_cnt++] = 2;
	prime_num_arr[prime_num_cnt++] = 3;

	for (int i = 4; i <= max_num; i++)
	{
		if(isPrime(prime_num_arr,prime_num_cnt,i))
			prime_num_arr[prime_num_cnt++] = i;
	}

	return prime_num_cnt;
}

int countPrimeNumFromIntArray(int *prime_num_arr,int *int_arr, int prime_num_arr_size, int int_arr_size){
	int cnt=0;
	for (int i = 0; i < int_arr_size; i++)
	{
		for (int n = 0; n < prime_num_arr_size; n++)
		{
			if (int_arr[i] == prime_num_arr[n])
			{
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

bool isPrime(int *prime_num_arr, int arr_size, int num)
{
	for (int n = 0; n < arr_size; n++)
	{
		if (num % prime_num_arr[n] == 0)
			return false;
	}
	return true;
}