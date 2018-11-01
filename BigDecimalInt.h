///                Faculty of Computers and Information
/// Course:        CS213 - Programming II  - 2018
/// Title:         Assignment II - Task 3
/// Purpose:       Developing a class that can hold unlimited decimal integer values and performs arithmetic operations on them
/// Instructor:    Dr. Mohammad El-Ramly
/// Author:        Peter Malak
/// ID :           20170079
/// Group :        G3
/// Date:          30 October 2018


#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#include <iostream>

using namespace std;

class BigDecimalInt
{

private:
    char num[1000];

public:
    BigDecimalInt();
    //BigDecimalInt(string r);
    BigDecimalInt (char NUM[]);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    friend ostream& operator<< (ostream& out, BigDecimalInt Dec);

};

#endif // BIGDECIMALINT_H
