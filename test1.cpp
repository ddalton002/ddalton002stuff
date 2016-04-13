#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
    double f, c =20;
    f=(9/5);
    cout << f << endl;
    f = f*c;
    cout << f << endl;
    f = f + 32;
    cout << f << endl;
    f= (9/5) * c + 32;
    cout << f << endl;
    double a = 1.5;
    cout << a << endl;
    a = (3/2);
    cout << a << endl;
    double b = (3.0/2.0);
    cout << b << endl;
    return 0;
}


/*int bintodec(string binary, unsigned int i = 0)
{
    int tot = 0;
    if (i < binary.length())
    {
        if (binary[i] == '1')
            tot = pow(2, i);
        else if (!binary[i] == '0')
            throw "String is not formatted in binary";
        return tot + bintodec(binary, ++i);
    }
    return tot;
}
http://stackoverflow.com/questions/26701548/recursion-binary-to-decimal-completely-stuck#
    */