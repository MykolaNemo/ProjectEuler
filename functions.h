#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "limits.h"
#include "division.h"
#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>

std::string subtractBigInteger(std::string num1, std::string num2);

template<typename T>
void printVector(const std::vector<T>& v)
{
    for(const auto& e : v)
    {
        std::cout<<e<<",";
    }
    std::cout<<std::endl;
}

inline bool isEven(const long long& number)
{
    return (number % 2 == 0);
}

inline bool isPrime(const long long& number)
{
  if(number <= 1)
  {
    return false;
  }

  if((number == 2) || (number == 3) || (number == 5) || (number == 7))
  {
    return true;
  }

  const std::string stringNumber(std::to_string(number));
  {
      const char& lastChar = stringNumber[stringNumber.length()-1];
      if((lastChar == '0') || (lastChar == '2') || (lastChar == '4') ||
         (lastChar == '5') || (lastChar == '6') || (lastChar == '8'))
      {
          return false;
      }
  }

  {
    int sum = 0;
    for(const auto& digitChar : stringNumber)
    {
        sum += digitChar - '0';
    }
    if((sum % 3 == 0) || (sum % 9 == 0))
    {
      return false;
    }
  }

  {
    long long divisor = static_cast<int>(std::sqrt(number));
    long long third = number/3;
    while(divisor >= 7)// less than 7 is already checked
    {
      if(number % divisor == 0)
      {
        return false;
      }
      if(divisor > third)
      {
        divisor = third;
      }
      else
      {
        --divisor;
      }
    }
  }
  return true;
}

long long nextPrime(long long number)
{
  if(number == LLONG_MAX)
  {
    throw std::exception();
  }

  if(isEven(number))
  {
    number++;
  }
  else if(isPrime(number))
  {
    number+=2;
  }

  while(number < LLONG_MAX)
  {
    if(isPrime(number))
    {
      return number;
    }
    number+=2;
  }
  throw std::exception();
}

bool isPalindrome(std::string s)
{
  while(s.length() > 1)
  {
    if(s[0] != s[s.length()-1])
    {
      return false;
    }
    s = s.substr(1, s.length()-2);
  }
  return true;
}

bool isPalindrome(int number)
{
  if(number < 10)
  {
    return true;
  }
  else if(number < 100)
  {
    return (number/10) == (number%10);
  }
  else if(number%10 == 0)
  {
    return false;
  }

  return isPalindrome(std::to_string(number));
}

bool isNumber(const std::string& s)
{
  if(s.empty()) return false;
  for(int i = 0; i < s.size(); ++i)
  {
    if(s[i] < '0' || s[i] > '9')
    {
      if((s[i] != '-') || (i != 0))
      {
        return false;
      }
    }
  }
  return true;
}

bool isNegative(const std::string& s)
{
  if(isNumber(s))
  {
    return (s[0] == '-');
  }
  std::cout<<"isNegative: not a number"<<std::endl;
  throw std::exception();
}

void sanitizeNumber(std::string& num)
{
  if(!isNumber(num)) return;
  if(!isNegative(num))
  {
    while((num.length() > 1) && (num[0] == '0'))
    {
      num.erase(num.begin());
    }
  }
  else
  {
    while((num.length() > 2) && (num[1] == '0'))
    {
      num.erase(num.begin()+1);
    }
  }
}

bool compareLess(std::string num1, std::string num2)
{
  bool reverse = false;
  {
    bool negative1 = isNegative(num1);
    bool negative2 = isNegative(num2);
    if(negative1 && negative2)
    {
      num1.erase(num1.begin());
      num2.erase(num2.begin());
      reverse = true;
    }
    else if(negative1 && !negative2)
    {
      return true;
    }
    else if(!negative1 && negative2)
    {
      return false;
    }
  }

  sanitizeNumber(num1);
  sanitizeNumber(num2);

  if(num1.length() != num2.length())
  {
    bool result = (num1.length() < num2.length());
    return reverse ? !result : result;
  }
  else
  {
    for(size_t pos = 0; pos < num1.length(); ++pos)
    {
      if(num1[pos] < num2[pos])
      {
        return reverse ? false : true;
      }
      else if(num1[pos] == num2[pos])
      {
        continue;
      }
      else
      {
        return reverse ? true : false;
      }
    }
  }
  return false;
}

std::string addBigInteger(std::string num1, std::string num2)
{
  if(!isNumber(num1) || !isNumber(num2))
  {
    std::cout<<"sumBigInteger: not a number"<<std::endl;
    return std::string();
  }

  bool negativeResult = false;
  {
    bool negative1 = isNegative(num1);
    bool negative2 = isNegative(num2);
    if(negative1 && negative2)
    {
      negativeResult = true;
      num1.erase(num1.begin());
      num2.erase(num2.begin());
    }
    else if(!negative1 && negative2)
    {
      num2.erase(num2.begin());
      return subtractBigInteger(num1, num2);
    }
    else if(negative1 && !negative2)
    {
      num1.erase(num1.begin());
      return '-' + subtractBigInteger(num2, num1);
    }
  }

  {
    int l1 = num1.length();
    int l2 = num2.length();
    if(l1 > l2)
    {
      for(int i = 0; i < (l1 - l2); ++i)
      {
        num2 = '0' + num2;
      }
    }
    else if(l2 > l1)
    {
      for(int i = 0; i < l2 - l1; ++i)
      {
        num1 = '0' + num1;
      }
    }
  }

  std::string result;
  {
    short carry = 0;
    for(int i = num1.size() - 1; i >= 0; --i)
    {
      int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
      int base = sum%10;
      result = std::to_string(base) + result;
      carry = sum/10;
    }
    if(carry > 0)
    {
      result = std::to_string(carry) + result;
    }
  }

  while((result.size() > 1) && (result[0] == '0'))
  {
    result.erase(result.begin());
  }
  if(negativeResult)
  {
    result = '-' + result;
  }
  return result;
}

std::string subtractBigInteger(std::string num1, std::string num2)
{
  if(!isNumber(num1) || !isNumber(num2))
  {
    std::cout<<"subtractBigInteger: not a number"<<std::endl;
    return std::string();
  }

  {
    bool negative1 = isNegative(num1);
    bool negative2 = isNegative(num2);
    if(negative1 && negative2)
    {
      num1.erase(num1.begin());
      num2.erase(num2.begin());
      return subtractBigInteger(num2, num1);
    }
    else if(!negative1 && negative2)
    {
      num2.erase(num2.begin());
      return addBigInteger(num1, num2);
    }
    else if(negative1 && !negative2)
    {
      num1.erase(num1.begin());
      return '-' + addBigInteger(num1, num2);
    }
  }

  bool negativeResult = false;
  if(compareLess(num1, num2))
  {
    auto t = num1;
    num1 = num2;
    num2 = t;
    negativeResult = true;
  }

  //num1 is longer-equal than num2
  int l1 = num1.length();
  int l2 = num2.length();
  if(l1 != l2)
  {
    for(int i = 0; i < std::abs(l1 - l2); ++i)
    {
      num2 = '0' + num2;
    }
  }

  std::string result;
  {
    int carry = 0;
    for(int i = l1 - 1; i >= 0; --i)
    {
      int digit1 = num1[i] - '0';
      int digit2 = num2[i] - '0';
      int sub = (digit1 - digit2) + carry;
      if(sub < 0)
      {
        sub += 10;
        carry = -1;
      }
      else
      {
        carry = 0;
      }
      result = std::to_string(sub) + result;
    }
    if(carry != 0)
    {
      result = std::to_string(carry) + result;
    }
  }
  while((result.size() > 1) && (result[0] == '0'))
  {
    result.erase(result.begin());
  }
  if(negativeResult)
  {
    result = '-' + result;
  }
  return result;
}

std::string multiplyBigInteger(std::string num1, std::string num2)
{
    int length1 = num1.length();
    int length2 = num2.length();

    std::vector<std::string> intermidiates;
    int nulls = 0;
    for(int e2 = length2 - 1; e2 >= 0; --e2)
    {
        int int2 = num2[e2] - '0';
        std::string mulStr;
        int carry = 0;
        for(int e1 = length1 - 1; e1 >= 0; --e1)
        {
            int int1 = num1[e1] - '0';
            int mul = int1*int2 + carry;
            mulStr = std::to_string(mul%10) + mulStr;
            carry = mul/10;
        }
        if(carry > 0)
        {
            mulStr = std::to_string(carry) + mulStr;
        }
        for(int i = 0; i < nulls; ++i)
        {
            mulStr += '0';
        }
        intermidiates.push_back(mulStr);
        nulls++;
    }

    std::string result = "0";
    for(int i = 0; i < intermidiates.size(); ++i)
    {
        result = addBigInteger(result, intermidiates[i]);
    }
    return result;
}

bool isLeapYear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 400 == 0)
        {
            return true;
        }
        else if(year % 100 > 0)
        {
            return true;
        }
    }
    return false;
}

std::vector<long long> findDivisors(long long num, int max = 0)
{
    long long count = 0L;
    std::vector<long long> v;
    long long limit = num;
    for(long long i = 1L; i <= limit; ++i)
    {
        if(num % i == 0L)
        {
            v.push_back(i);
            count++;
            if(max > 0 && count == max)
            {
                break;
            }

            long long anotherOne = num/i;
            if(anotherOne > i)
            {
                v.push_back(anotherOne);
                count++;
                if(max > 0 && count == max)
                {
                    break;
                }
                limit = anotherOne-1L;
            }
        }
    }
    return v;
}

template<typename T>
long long sumVector(const std::vector<T>& v)
{
    long long sum = 0;
    for(auto& n : v)
    {
        sum += n;
    }
    return sum;
}

//A number n is called abundant if the sum of its proper divisors exceeds n.
std::vector<int> findAbudantNumbers(int from, int to)
{
    std::vector<int> v;
    for(int i = from; i <= to; ++i)
    {
        std::vector<long long> divisors = findDivisors(i);
        divisors.erase(std::remove(divisors.begin(), divisors.end(), i), divisors.end());
        int sum = 0;
        for(const auto &d : divisors)
        {
            sum += static_cast<int>(d);
            if(sum > i)
            {
                v.push_back(i);
                break;
            }
        }
    }
    return v;
}

std::vector<std::string> permutations(const std::string& input)
{
    const auto swap = [](char& a, char& b){
        char t = a;
        a = b;
        b = t;
    };

    std::vector<std::string> result;
    const std::function<void(size_t, std::string&)> generate =
    [&generate, &swap, &result](size_t k, std::string& input){
        if (k == 1)
        {
            result.push_back(input);
        }
        else
        {
            for (int i = 0; i < k; ++i)
            {
                generate(k - 1, input);
                if (isEven(k))
                {
                    swap(input[i], input[k-1]);
                }
                else
                {
                    swap(input[0], input[k-1]);
                }
            }
        }
        return "";
    };

    std::string temp = input;
    generate(input.length(), temp);

    return result;
}

long long factorial(const int& num)
{
  if(num == 0)
  {
    return 1;
  }
  long long f = 1;
  for(int i = 2; i <= num; ++i)
  {
    f*=i;
  }
  return f;
}

long long combinationsC(int n, int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

std::vector<std::vector<int>> combinationsContainerC(const std::vector<int>& container, int k)
{
    const int n = container.size();

    std::vector<std::vector<int>> result;
//    if(k == 2)
    {
        std::vector<std::vector<int>> Sets;
        for(int i1 = 1; i1 <= k; ++i1)
        {
            std::vector<int> Set;
            for(int i2 = k-i1; i2 <= n-i1; ++i2)
            {
                Set.push_back(container[i2]);
            }
//            printVector<int>(Set);
//            std::cout<<std::endl;
            Sets.push_back(Set);
        }

        int setSize = Sets[0].size();
        for(int position = 0; position < std::pow(setSize, k); ++position)
        {
            std::vector<int> positions;
            int temp = position;
            do
            {
                positions.push_back(temp%setSize);
                temp = temp/setSize;
            }
            while(positions.size() < Sets.size());
//            printVector<int>(positions);

            std::vector<int> toResult;
            for(int i = 0; i < positions.size(); ++i)
            {
                int numberToAdd = Sets[positions.size()-i-1][positions[i]];
                if(std::find(toResult.begin(), toResult.end(), numberToAdd) == toResult.end())
                {
                    toResult.push_back(numberToAdd);
                }
                else
                {
                    toResult.clear();
                    break;
                }
            }
            if(!toResult.empty())
            {
                std::sort(toResult.begin(),toResult.end());
                if(std::find(result.begin(), result.end(), toResult) == result.end())
                {
                    result.push_back(toResult);
                }
            }
        }
    }
    return result;
}

std::string toBinary(int num)
{
    std::string binary;
    do
    {
        binary += (num % 2 == 0) ? '0' : '1';
        num /= 2;
    }
    while(num > 0);
    return binary;
}

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> list;
    size_t searchBegin = 0;
    size_t pos = str.find(delim);
    while(true)
    {
        list.push_back(str.substr(searchBegin, pos-searchBegin));

        size_t newPos = str.find(delim, pos+delim.size());
        if(newPos == std::string::npos)
        {
            list.push_back(str.substr(pos+delim.size(), str.size()-(pos+delim.size())));
            break;
        }
        searchBegin = pos+delim.size();
        pos = newPos;
    }
    return list;
}

#endif // FUNCTIONS_H
