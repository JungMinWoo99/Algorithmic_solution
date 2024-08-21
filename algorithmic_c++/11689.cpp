#include <iostream>
#include <vector>
#include <queue>
#include<array>

using namespace std;

class GCDFinder
{
private:
    long long n;

public:
    GCDFinder(long long n) : n(n)
    {
    }

    long long countAnswer()
    {
        return EulerPhiFunc();
    }

    long long EulerPhiFunc()
    {
        if(n==1)
            return n;
        long long num = n;
        long long coprime_counter=n;
        for (long long i = 2; i*i <= num; i++){
            if(num%i==0){
                coprime_counter *= (1.0 - 1.0 / i);
                while(num%i==0)
                    num/=i;
            }
        }
        if(num!=1)
            coprime_counter *= (1.0 - 1.0 / num);
        return coprime_counter;
    }
};

int main(void)
{
    long long n;
    cin >> n;
    GCDFinder main(n);
    cout << main.countAnswer() << endl;

    return 0;
}