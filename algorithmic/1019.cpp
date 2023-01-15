#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

class BookPageNumberCounter
{
private:
    int book_page;
    vector<int> book_page_digit;
    array<int, 10> num_counter{
        0,
    };

    void inputSeparatedDigits(int number_to_separate)
    {
        while (number_to_separate != 0)
        {
            int digit = number_to_separate % 10;
            book_page_digit.push_back(digit);
            number_to_separate /= 10;
        }
    }

public:
    BookPageNumberCounter(int book_page)
    {
        this->book_page = book_page;
        inputSeparatedDigits(book_page);
    }

    void countDigit()
    {
        int book_page_len = book_page_digit.size();
        for (int k = 0; k < book_page_len; k++)
        {
            int digit = book_page_digit[k];
            for (int i = 0; i < 10; i++)
            {
                int forward_num = book_page / (int)pow(10, k + 1);
                int backward_num = book_page % (int)pow(10, k);

                if (i == 0)
                {
                    if(k == (book_page_len - 1))
                        continue;
                    else if (i == digit)
                        num_counter[i] += (forward_num-1) * pow(10, k) + (backward_num + 1);
                    else if (i < digit)
                        num_counter[i] += (forward_num) * pow(10, k);
                }
                else
                {
                    if (i == digit)
                        num_counter[i] += forward_num * pow(10, k) + (backward_num + 1);
                    else if (i > digit)
                        num_counter[i] += forward_num * pow(10, k);
                    else if (i < digit)
                        num_counter[i] += (forward_num + 1) * pow(10, k);
                }
            }
        }
    }

    void printDigitNum()
    {
        for (int i = 0; i < 10; i++)
            cout << num_counter[i] << ' ';
    }
};

int main(void)
{
    int N;
    cin >> N;
    BookPageNumberCounter main(N);
    main.countDigit();
    main.printDigitNum();

    return 0;
}