#include <iostream>
#include <exception>

using namespace std;

constexpr int TERMS_COUNT = 5;

double func(double x)
{
    return (2 * x * x - 23 * x + 110) / (x - 2);
}

double a_n(size_t n, double a_1, double (*funcptr)(double))
{
    double result = a_1;
    for (size_t i = 0; i < n - 1; i++)
    {
        result = funcptr(result);
    }

    return result;
}

void print_terms(double a_1, double (*funcptr)(double), size_t terms_count) {

    int n = 1;
    
    for (size_t i = 0; i < terms_count; i++) {
        cout << "a_";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter again a numeric value.\n";
            i--;
            continue;
        }

        if (n < 1) {
            cout << "Invalid index n! Enter again n >= 1." << endl;
            i--;
            continue;
        }
        
        cout << " = " << a_n(n, a_1, funcptr) << endl;
    }
}

void print_lim(double a_1)
{
    cout << "\nlim = ";

    if (a_1 < 2)
    {
        cout << "-inf" << endl;
    }
    else if (a_1 == 2)
    {
        cout << "invalid" << endl;
    }
    else if ((a_1 > 2 && a_1 < 6) || (a_1 > 11))
    {
        cout << "+inf" << endl;
    }
    else if ((a_1 == 6) || (a_1 == 11))
    {
        cout << "11" << endl;
    }
    else if ((a_1 > 6 && a_1 < 6.5) || (a_1 == 6.5) || 
        (a_1 > 6.5 && a_1 < 10) || (a_1 == 10) ||
        (a_1 > 10 && a_1 < 11))
    {
        cout << "10" << endl;
    }
}

int main()
{
    cout << "a_n+1 = f(x) = (2x^2 - 23x + 110) / (x - 2), a_1 != 2" << endl;

    double a_1 = 0;
    cout << "a_1 = ";
    cin >> a_1;

    print_lim(a_1);
    print_terms(a_1, func, TERMS_COUNT);
}