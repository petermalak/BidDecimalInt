///                Faculty of Computers and Information
/// Course:        CS213 - Programming II  - 2018
/// Title:         Assignment II - Task 3
/// Purpose:       Developing a class that can hold unlimited decimal integer values and performs arithmetic operations on them
/// Instructor:    Dr. Mohammad El-Ramly
/// Author:        Peter Malak
/// ID :           20170079
/// Group :        G3
/// Date:          30 October 2018


#include <iostream>
#include "BigDecimalInt.h"

using namespace std;

int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3 = num1 + num2;
    BigDecimalInt num4 = num1 - num2;
    cout << "\n num1 = " << num1 << endl;
    cout << "\n num2 = " << num2 << endl;
    cout << "\n num1 + num2 = " << num3 << endl;
    cout << "\n num1 - num2 = " << num4 << endl;

    BigDecimalInt num5("333333333333333333333333333333");
    BigDecimalInt num6("-111111111111111111111111111111");
    BigDecimalInt num7 = num5 + num6;
    BigDecimalInt num8 = num5 - num6;
    cout << "\n num5 = " << num5 << endl;
    cout << "\n num6 = " << num6 << endl;
    cout << "\n num5 + num6 = " << num7 << endl;
    cout << "\n num5 - num6 = " << num8 << endl;
    return 0;
}
