///                Faculty of Computers and Information
/// Course:        CS213 - Programming II  - 2018
/// Title:         Assignment II - Task 3
/// Purpose:       Developing a class that can hold unlimited decimal integer values and performs arithmetic operations on them
/// Instructor:    Dr. Mohammad El-Ramly
/// Author:        Peter Malak
/// ID :           20170079
/// Group :        G3
/// Date:          30 October 2018



#include "BigDecimalInt.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

using namespace std;

BigDecimalInt::BigDecimalInt()
{
    strcpy(num, "");
}

BigDecimalInt::BigDecimalInt(char NUM[1000])
{
    strcpy(num, NUM);
}


/// operator +
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    if(anotherDec.num[0] != '-' && num[0] != '-'){   ///In this case num1 + num2 and both of them are +ve

        int sum, carry_of_sum = 0, res; /// sum is the result of the addition .. res will be stored in it the value of sum if there is a carry_of_sum
                                 /// i.e if sum = 13 then res = 3 (sum % 10) and carry_of_sum = 1 (sum / 10)
        string result; /// In this string the final value of the sum the will be stored but in reverse order because the following loop
                       /// begins with the last number

        for(int i = strlen(num) - 1; i >= 0; i--){
            sum = carry_of_sum + int(num[i] - 48) + int(anotherDec.num[i] - 48);

            if(sum > 9){
                res = sum % 10;
                result.push_back(char(res + 48));
                carry_of_sum = sum / 10;
            }
            else{
                result.push_back(char(sum + 48));
                carry_of_sum = 0;
            }
        }

        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }

        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;

    }

    else if (anotherDec.num[0] == '-' && num[0] != '-'){   ///In this case num1 + num2 but num1 is +ve while num2 is -ve

        int sub, reminder = 0; /// sub is the result of the operation ..
        string result;  /// In this string the final value of the operatiom will be stored but in reverse order because the following loop
                       /// begins with the last number
        for(int i = strlen(num) - 1; i >= 0; i--){
            if(int(num[i] - 48) < int(anotherDec.num[i+1] - 48)){
                sub = (int(num[i] - 48) + 10) - int(anotherDec.num[i+1] - 48) - reminder;
                reminder = (int(num[i] - 48) + 10) / 10;
                result.push_back(char(sub + 48));
            }
            else{
                sub = int(num[i] - 48) - int(anotherDec.num[i+1] - 48) - reminder;
                reminder = 0;
                result.push_back(char(sub + 48));
            }
        }
        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }
        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;

    }

    else if(anotherDec.num[0] == '-' && num[0] == '-'){ ///In this case both num1 and num2 are -ve
        int sum, carry_of_sum = 0, res; /// sum is the result of the addition .. res will be stored in it the value of sum if there is a carry_of_sum
                                 /// i.e if sum = 13 then res = 3 (sum % 10) and carry_of_sum = 1 (sum / 10)
        string result; /// In this string the final value of the sum the will be stored but in reverse order because the following loop
                       /// begins with the last number

        for(int i = strlen(num) - 1; i >= 1; i--){
            sum = carry_of_sum + int(num[i] - 48) + int(anotherDec.num[i] - 48);

            if(sum > 9){
                res = sum % 10;
                result.push_back(char(res + 48));
                carry_of_sum = sum / 10;
            }
            else{
                result.push_back(char(sum + 48));
                carry_of_sum = 0;
            }
        }
        result.push_back('-');

        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }

        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;
    }

    else if(num[0] == '-' && anotherDec.num[0] != '-'){ ///In this case num1 is -ve and num is +ve

        if(num[1] > anotherDec.num[0]){/// --> -(num1 - num2)
            int sub, reminder = 0; /// sub is the result of subtraction..
            string result; /// In this string the final value of the subtraction will be stored but in reverse order because the following
                           /// loop begins with the last number

            int j = strlen(anotherDec.num) - 1;
            for(int i = strlen(num) - 2; i > 0; i--){
                if(int(num[i+1] - 48) < int(anotherDec.num[i] - 48)){
                    sub = (int(num[i] - 48) + 10) - int(anotherDec.num[j] - 48) - reminder;
                    reminder = (int(num[i] - 48) + 10) / 10;
                    result.push_back(char(sub + 48));
                    j--;
                }
                else{
                    sub = int(num[i] - 48) - int(anotherDec.num[j] - 48) - reminder;
                    reminder = 0;
                    result.push_back(char(sub + 48));
                    j--;
                }
            }
            result.push_back('-');
            string RESULT;  /// In this string we will store the final value of the operation in the correct order
            for(int i = result.length() - 1; i >= 0; i--){
                RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
            }
            BigDecimalInt Result;
            for(int i = 0; i < RESULT.length() + 1; i++){
                Result.num[i] = RESULT[i];
            }
            return Result;
        }
        else if(num[1] < anotherDec.num[0]){ /// --> num2 - num1
            int sub, reminder = 0; /// sub is the result of subtraction..
            string result; /// In this string the final value of the subtraction will be stored but in reverse order because the following
                           /// loop begins with the last number

            int j = strlen(num) - 1;
            for(int i = strlen(anotherDec.num) - 1; i > 0; i--){
                if(int(anotherDec.num[i] - 48) < int(num[j] - 48)){
                    sub = (int(anotherDec.num[i] - 48) + 10) - int(num[j] - 48) - reminder;
                    reminder = (int(anotherDec.num[i] - 48) + 10) / 10;
                    result.push_back(char(sub + 48));
                    j--;
                }
                else{
                    sub = int(anotherDec.num[i] - 48) - int(num[i] - 48) - reminder;
                    reminder = 0;
                    result.push_back(char(sub + 48));
                    j--;
                }
            }
            string RESULT;  /// In this string we will store the final value of the operation in the correct order
            for(int i = result.length() - 1; i >= 0; i--){
                RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
            }
            BigDecimalInt Result;
            for(int i = 0; i < RESULT.length() + 1; i++){
                Result.num[i] = RESULT[i];
            }
            return Result;
        }
        else if(num[1] == anotherDec.num[0]){   /// In this case num1(-ve) = num2(+ve) --> Zero
            int j = 0;
            int k = 0;
            BigDecimalInt Result;
            for(int i = 1; i < strlen(num) + 1; i++){
                if(num[i] == anotherDec.num[j]){
                    Result.num[k] = '0';
                    j++;
                    k++;
                }
            }
            return Result;
        }
    }
}


/// operator -
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    if(num[0] != '-' && anotherDec.num[0] != '-'){   /// both of num1 and num2 are +ve
        int sub, reminder = 0; /// sub is the result of subtraction..
        string result; /// In this string the final value of the subtraction will be stored but in reverse order because the following loop
                       /// begins with the last number

        for(int i = strlen(num) - 1; i >= 0; i--){
            if(int(num[i] - 48) < int(anotherDec.num[i] - 48)){
                sub = (int(num[i] - 48) + 10) - int(anotherDec.num[i] - 48) - reminder;
                reminder = (int(num[i] - 48) + 10) / 10;
                result.push_back(char(sub + 48));
            }
            else{
                sub = int(num[i] - 48) - int(anotherDec.num[i] - 48) - reminder;
                reminder = 0;
                result.push_back(char(sub + 48));
            }
        }
        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }
        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;
    }

    else if(num[0] != '-' && anotherDec.num[0] == '-'){   /// num1 is +ve while num2 is -ve --> num1 + num2
        int sum, carry_of_sum = 0, res;    /// sum is the result of the operation .. res will be stored in it the value of sum if there is a carry_of_sum
        string result;    /// In this string the final value of the operation the will be stored but in reverse order because the following
                          /// loop begins with the last number
        for(int i = strlen(num) - 1; i >= 0; i--){
            sum = carry_of_sum + int(num[i] - 48) + int(anotherDec.num[i+1] - 48);

            if(i == 0 && sum > 9){
                res = sum % 10;
                carry_of_sum = sum / 10;
                result.push_back(char(res + 48));
                result.push_back(char(carry_of_sum + 48));
                break;
            }

            if(sum > 9){
                res = sum % 10;
                result.push_back(char(res + 48));
                carry_of_sum = sum / 10;
            }
            else{
                result.push_back(char(sum + 48));
                carry_of_sum = 0;
            }
        }

        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }

        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;
     }

     else if(num[0] == '-' && anotherDec.num[0] != '-'){    ///In this case num1 is -ve while num2 is +ve --> -(num1 + num2)
        int sum, carry_of_sum = 0, res; /// sum is the result of the addition .. res will be stored in it the value of sum if there is a carry_of_sum
                                 /// i.e if sum = 13 then res = 3 (sum % 10) and carry_of_sum = 1 (sum / 10)
        string result; /// In this string the final value of the sum the will be stored but in reverse order because the following loop
                       /// begins with the last number

        for(int i = strlen(num) - 1; i > 0; i--){
            sum = carry_of_sum + int(num[i] - 48) + int(anotherDec.num[i-1] - 48);

            if(sum > 9){
                res = sum % 10;
                result.push_back(char(res + 48));
                carry_of_sum = sum / 10;
            }
            else{
                result.push_back(char(sum + 48));
                carry_of_sum = 0;
            }
        }
        result.push_back('-');

        string RESULT;  /// In this string we will store the final value of the operation in the correct order
        for(int i = result.length() - 1; i >= 0; i--){
            RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
        }

        BigDecimalInt Result;
        for(int i = 0; i < RESULT.length() + 1; i++){
            Result.num[i] = RESULT[i];
        }
        return Result;
     }

     else if(num[0] == '-' && anotherDec.num[0] == '-'){    /// Both of num1 and num2 are -ve
        if(num[1] > anotherDec.num[1]){
            int sub, reminder = 0; /// sub is the result of subtraction..
            string result; /// In this string the final value of the subtraction will be stored but in reverse order because the following loop
                        /// begins with the last number

            for(int i = strlen(num) - 1; i >= 1; i--){
                if(int(num[i] - 48) < int(anotherDec.num[i] - 48)){
                    sub = (int(num[i] - 48) + 10) - int(anotherDec.num[i] - 48) - reminder;
                    reminder = (int(num[i] - 48) + 10) / 10;
                    result.push_back(char(sub + 48));
                }
                else{
                    sub = int(num[i] - 48) - int(anotherDec.num[i] - 48) - reminder;
                    reminder = 0;
                    result.push_back(char(sub + 48));
                }
            }
            result.push_back('-');
            string RESULT;  /// In this string we will store the final value of the operation in the correct order
            for(int i = result.length() - 1; i >= 0; i--){
                RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
            }
            BigDecimalInt Result;
            for(int i = 0; i < RESULT.length() + 1; i++){
                Result.num[i] = RESULT[i];
            }
            return Result;
        }
        else if(num[1] < anotherDec.num[1]){
            int sub, reminder = 0; /// sub is the result of subtraction..
            string result; /// In this string the final value of the subtraction will be stored but in reverse order because the following loop
                        /// begins with the last number

            for(int i = strlen(num) - 1; i >= 1; i--){
                if(int(anotherDec.num[i] - 48) < int(num[i] - 48)){
                    sub = (int(anotherDec.num[i] - 48) + 10) - int(num[i] - 48) - reminder;
                    reminder = (int(anotherDec.num[i] - 48) + 10) / 10;
                    result.push_back(char(sub + 48));
                }
                else{
                    sub = int(anotherDec.num[i] - 48) - int(num[i] - 48) - reminder;
                    reminder = 0;
                    result.push_back(char(sub + 48));
                }
            }

            string RESULT;  /// In this string we will store the final value of the operation in the correct order
            for(int i = result.length() - 1; i >= 0; i--){
                RESULT.push_back(result[i]);    /// Storing the final value of the operation to be in the correct order
            }
            BigDecimalInt Result;
            for(int i = 0; i < RESULT.length() + 1; i++){
                Result.num[i] = RESULT[i];
            }
            return Result;
        }
        else if(num[1] == anotherDec.num[1]){   /// In this case num1(-ve) = num2(-ve) --> Zero
            int k = 0;
            BigDecimalInt Result;
            for(int i = 1; i < strlen(num) - 1; i++){
                if(num[i] == anotherDec.num[i]){
                    Result.num[k] = '0';
                    k++;
                }
            }
            return Result;
        }
    }
}

std::ostream& operator<< (ostream& out, BigDecimalInt Dec)
{
    if(Dec.num[0] == '0'){
        for(int i = 1; i < strlen(Dec.num) - 1; i++){
            cout << Dec.num[i];
        }
    }
    else{
        cout << Dec.num;
    }
    return out;
}

