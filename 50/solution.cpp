#include <iostream>

using namespace std;

double myPow(double x, int n)
{
    double result = 1;

    for (int i = 0; i < abs(n); i++)
    {
        result *= x;
    }
    if (n < 0)
    {
        cout << result << endl;
        return 1 / result;
    }
    return result;
}

int main()
{
    cout << myPow(2, -2147483600) << endl;
}
