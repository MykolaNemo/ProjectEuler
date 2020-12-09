#ifndef DIVISION_H
#define DIVISION_H

#include <string>
#include "functions.h"

bool compareLess(std::string s1, std::string num2);
std::string subtractBigInteger(std::string num1, std::string num2);
std::string addBigInteger(std::string num1, std::string num2);
std::string multiplyBigInteger(std::string num1, std::string num2);
bool isNumber(const std::string &s);
bool isNegative(const std::string &s);

struct DivideResult
{
    std::string base;
    std::string fraction;
    std::string recurralFraction;
};

std::string divideInteger(std::string num1, std::string num2)
{
    if(!isNumber(num1) || !isNumber(num2))
    {
      std::cout<<"divideInteger: not a number"<<std::endl;
      return std::string();
    }
    if(isNegative(num1) || isNegative(num2))
    {
      std::cout<<"divideInteger: negative number"<<std::endl;
      return std::string();
    }

    std::string result = "0";
    std::string temp = num1;
    while(compareLess(num2, temp) || (num2==temp))
    {
      result = addBigInteger(result, "1");
      temp = subtractBigInteger(temp, num2);
    }
    return result;
}

DivideResult manualDivide(std::string num1, std::string num2)
{
    DivideResult r;
    if(compareLess(num1, num2))
    {
        r.base = "0";
    }
    else
    {
        std::string temp1;
        int index = 0;
        while(index < num1.length())
        {
          temp1 = {num1[index]};
          while(compareLess(temp1, num2) && index < num1.length())
          {
            index++;
            temp1 += num1[index];
          }
          std::cout<<"temp: "<<temp1<<std::endl;
          if(!compareLess(temp1, num2))
          {
            auto divideTempRes = divideInteger(temp1, num2);
            r.base += divideTempRes;
            temp1 = subtractBigInteger(temp1, multiplyBigInteger(num2, divideTempRes));
          }
        }
    }

    return r;
}

#endif // DIVISION_H
