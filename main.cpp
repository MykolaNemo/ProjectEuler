#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <fstream>
#include <array>
#include <sstream>
#include <set>
#include "functions.h"

using namespace std;

namespace{
/*
int id1();
int id2();
long long id3();
int id4();
int id5();
int id6();
long long id7();
long long id8();
long long id9();
long long id10();
long long id11();
long long id12();
std::string id13();
long long id14();
long long id15();
long long id16();
int id17();
int id18();
int id19();
int id20();
long long id21();
long long id22();
long long id23();
string id24();
int id25();
void id26();
void id27();
void id28();
void id29_1();
void id29_2();
void id30();
void id31();
void id32();
void id33();*/
void id34();
void id35();
void id36();
void id37();
void id38();
void id39();
void id40();
void id41();
void id42();
void id43();
void id44();
void id46();
void id47();
}
/***********************************************************/


int main()
{
  id47();
  return 0;
}

namespace{
/***********************************************************/

void id47()
{
#LIST PRIME NUMBERS AND TRY MULTIPLY THEM
//    std::vector
//    for(int i =)

    long long n = 647;
    int lineCounter = 0;
    long long firstNumber = 0;
    while(true)
    {
        std::cout<<n<<std::endl;
        long long temp = n;
        std::set<long long> factors;
        while(temp > 1)
        {
          long long prime = 2;
          while(temp % prime != 0)
          {
            prime = nextPrime(prime);
          }
          factors.insert(prime);
          if(factors.size() == 4)
          {
              break;
          }
          temp = temp/prime;
        }
        if(factors.size() >= 4)
        {
            lineCounter++;
            if(firstNumber == 0)
            {
                firstNumber = n;
            }
        }
        else
        {
            lineCounter = 0;
            firstNumber = 0;
        }
        if(lineCounter == 4)
        {
            std::cout<<"Result: "<<firstNumber<<std::endl;
            return;
        }
        n++;
    }
}

void id46()
{
    std::vector<long long> squares = {1};
    std::vector<long long> primes = {2};
    long long n = 9;
    while(true)
    {
        n+=2;
        if(!isPrime(n))
        {
            while(n > primes.back())
            {
                primes.push_back(nextPrime(primes.back()));
            }

            while(n > squares.back())
            {
                int size = squares.size();
                squares.push_back((size+1)*(size+1));
            }
            int ok = false;
            for(int p = 0; p < primes.size(); ++p)
            {
                if(primes[p] > n) break;
                for(int s = 0; s < squares.size(); ++s)
                {
                    if(2*squares[s] > n) break;
                    if(primes[p] + 2*squares[s] > n) break;

                    if(n == primes[p] + 2*squares[s])
                    {
                        ok = true;
                        break;
                    }
                }
                if(ok)
                {
                    break;
                }
            }
            if(!ok)
            {
                std::cout<<"Result: "<<n<<std::endl;
                return;
            }
        }
    }
}

void id45()
{
    std::map<long long, bool> mapT;
    std::map<long long, bool> mapP;
    std::map<long long, bool> mapH;
    long long  n = 285;
    while(true)
    {
        n++;
        long long numT = n*(n+1)*0.5;
        long long numP = n*(3*n-1)*0.5;
        long long numH = n*(2*n-1);
        mapP.insert({numP, true});
        mapH.insert({numH, true});

        auto it = mapP.find(numT);
        if(it == mapP.end()) continue;

        it = mapH.find(numT);
        if(it == mapH.end()) continue;

        std::cout<<"Result: "<<numT<<std::endl;
        return;
    }
}

void id44()
{
//    int n = 0;
    std::vector<long> pentagonals;
    std::map<long, int> pentagonalsMap;
    for(int n = 1; n < 3000; ++n)
    {
        pentagonals.push_back(n * (3*n-1) * 0.5);
        pentagonalsMap[n * (3*n-1) * 0.5] = n;
    }
    auto isPentagonal = [](long num)->bool{
        for(int n = 1; n <= 3*num-1; ++n)
        {
            if(n*(3*n-1)*0.5 > num)
            {
                break;
            }
            if(num == n*(3*n-1)*0.5)
            {
                return true;
            }
        }
        return false;
    };

    int minI = pentagonals[pentagonals.size()-1];
    int minJ = pentagonals[pentagonals.size()-1];
    int minDiff = -1;
    for(int i = 0; i < pentagonals.size()-1; ++i)
    {
//        std::cout<<i<<std::endl;
        for(int j = i+1; j < pentagonals.size(); ++j)
        {
            long sum = pentagonals[j] + pentagonals[i];
            long diff = pentagonals[j] - pentagonals[i];
            auto it = pentagonalsMap.find(sum);
            auto it2 = pentagonalsMap.find(diff);
//            auto it = std::find(pentagonals.begin(), pentagonals.end(), sum);
//            auto it2 = std::find(pentagonals.begin(), pentagonals.end(), diff);
            if((it != pentagonalsMap.end() && it2 != pentagonalsMap.end()) || (isPentagonal(sum) && isPentagonal(diff)))
            {
                if(minDiff == -1)
                {
                    minI = pentagonals[i];
                    minJ = pentagonals[j];
                    minDiff = pentagonals[j] - pentagonals[i];
                }

                if(minDiff > (pentagonals[j] - pentagonals[i]))
                {
                    minI = pentagonals[i];
                    minJ = pentagonals[j];
                    minDiff = pentagonals[j] - pentagonals[i];
                }
            }
        }
    }
    std::cout<<minDiff<<std::endl;
}

void id43()
{
    std::vector<int> divs = {2, 3, 5, 7, 11, 13, 17};

    unsigned long long sum = 0;
    std::vector<std::string> v = permutations("1234567890");
    for(auto& num : v)
    {
        if(num[0] =='0')
        {
            continue;
        }
        bool ok = true;
        for(int i = 1; i <= 7; ++i)
        {
            std::string s = num.substr(i,3);
            if(std::stol(s) % divs[i-1] != 0)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            sum += std::stoll(num);
        }
    }
    std::cout<<"Result: "<<sum<<std::endl;
}

void id42()
{
    std::ifstream infile("p042_words.txt");
    std::vector<std::string> words;

    std::string word;
    while(std::getline(infile, word, ','))
    {
        words.push_back(word.substr(1,word.length()-2));
    }

    auto isTriangle = [](int num)->bool{
        for(int n = 1; n <= num+1; ++n)
        {
            if(num == n*(n+1)*0.5)
            {
                return true;
            }
        }
        return false;
    };

    int count = 0;
    for(std::string& word : words)
    {
        int value = 0;
        for(auto& c : word)
        {
            value += c -'A'+1;
        }
        if(isTriangle(value))
        {
            count++;
        }
    }
    std::cout<<"Result: "<<count<<std::endl;
}

void id41()
{
    std::vector<std::string> v = permutations("1234567");
    long long max = 0;
    for(std::string& num : v)
    {
        long long n = std::stol(num);
        if(isPrime(n))
        {
            if(n > max)
            {
                max = n;
            }
        }
    }
    std::cout<<"Result: "<<max<<std::endl;
}

void id40()
{
    std::string s;
    for(int i = 1; i < 1000000; ++i)
    {
        s += std::to_string(i);
        if(s.size() >= 1000000)
        {
            break;
        }
    }
    std::cout<<(s[0] -'0')* (s[9] -'0') * (s[99] -'0') * (s[999] -'0')
            * (s[9999] -'0') * (s[99999] -'0') * (s[999999] -'0')<<std::endl;
}

void id39()
{
    int maxCount = 0;
    int maxP = 0;
    for(int p = 4; p <= 1000; ++p)
    {
        int count = 0;
        for(int a = 1; a <= 998; ++a)
        {
            for(int b = a; b <= 998; ++b)
            {
                if((a + b) >= p)
                {
                    break;
                }
                if((a*a + b*b) == ((p - a - b)*(p - a - b)))
                {
                    count++;
                }
            }
        }
        if(count > maxCount)
        {
            maxCount = count;
            maxP = p;
        }
    }
    std::cout<<maxP<<": "<<maxCount<<std::endl;
}

void id38()
{
    std::vector<int> numbers;
//    std::vector<int> v1;
//    std::vector<int> v2;
    for(int a = 1; a <= 9999; ++a)
    {
        std::string s = std::to_string(a);
        int n = 1;
        while(s.size() < 9)
        {
            n++;
            s += std::to_string(a*n);
        }
        if((n > 1) && (s.size() == 9))
        {
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            bool ok = true;
            for(int i = 1; i <= 9; ++i)
            {
                if((temp[i-1] -'0') != i)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                numbers.push_back(std::stoi(s));
//                v1.push_back(a);
//                v2.push_back(n);
            }
        }
    }
//    for(int i = 0; i <numbers.size(); ++i)
//    {
//        std::cout<<numbers[i]<<" "<<v1[i]<<" "<<v2[i]<<std::endl;
//    }
    if(!numbers.empty())
    {
        std::sort(numbers.begin(), numbers.end());
        std::cout<<"Result: "<<numbers[numbers.size()-1]<<std::endl;
    }
}

void id37()
{
    std::vector<long long> primes;
    long long i = 11;
    while(primes.size() != 11)
    {
        long long num = i;
        bool ok = true;
        while(num > 0)
        {
            if(!isPrime(num))
            {
                ok = false;
                break;
            }
            else
            {
                num = num/10;
            }
        }
        if(ok)
        {
            auto s = std::to_string(i);
            while(s.size() > 0)
            {
                if(!isPrime(std::stol(s)))
                {
                    ok = false;
                    break;
                }
                else
                {
                    s.erase(s.begin());
                }
            }
        }
        if(ok)
        {
            primes.push_back(i);
        }
        i+=2;
    }
    long long sum = 0;
    for(auto& num : primes)
    {
        std::cout<<num<<"\n";
        sum += num;
    }
    std::cout<<"Result: "<<sum<<std::endl;
}

void id36()
{
    int sum = 0;
    for(int num = 1; num < 1000000; num+=2)
    {
        if(isPalindrome(num) && isPalindrome(toBinary(num)))
        {
            sum += num;
        }
    }
    std::cout<<"Result: "<<sum<<std::endl;
}

void id35()
{
    int count = 13;
    std::map<int, bool> cache;
    for(int num = 101; num < 1000000; num+=2)
    {
        if(isPrime(num))
        {
            bool ok = true;
            std::string s = std::to_string(num);
            for(int i = 0; i < s.size()-1; ++i)
            {
                s.push_back(s[0]);
                s = s.substr(1, s.size()-1);
                if(!isPrime(std::stoi(s)))
                {
                    ok = false;
                    break;
                }
            }
            if(ok) count++;
        }
    }
    std::cout<<"Result: "<<count<<std::endl;
}

void id34()
{
    std::vector<long long> factorials;
    for(int i = 0; i <= 9; ++i)
    {
        factorials.push_back(factorial(i));
    }
    long long sumResult = 0;
    for(int i = 10; i <= 9999999; ++i)
    {
        int num = i;
        long long sum = 0;
        while(num > 0)
        {
            int digit = num % 10;
            sum += factorials[digit];
            num /= 10;
        }
        if(sum == i)
        {
            sumResult += sum;
        }
    }
    std::cout<<"Result: "<<sumResult<<std::endl;
}

#if 0
void id33()
{
    std::vector<std::pair<int,int>> pairs;
    for(int a = 10; a <= 99; ++a)
    {
        std::string sa = std::to_string(a);
        for(int b = a+1; b <= 98; ++b)
        {
            if(a % 10 == 0 && b % 10 == 0)
            {
                continue;
            }
            std::string sb = std::to_string(b);
            for(int i = 0; i < sa.size(); ++i)
            {
                for(int j = 0; j < sb.size(); ++j)
                {
                    if(sa[i] == sb[j])
                    {
                        std::string aTemp = sa;
                        aTemp.erase(aTemp.begin()+i);
                        std::string bTemp = sb;
                        bTemp.erase(bTemp.begin()+j);
                        double da = (double)a;
                        double db = (double)b;
                        double dsa = (double)(aTemp[0]- '0');
                        double dsb = (double)(bTemp[0]- '0');
                        if(std::abs(da/db - dsa/dsb) < 0.0000001)
                        {
                            pairs.push_back({a,b});
                        }
                    }
                }
            }
        }
    }
    for(auto [a,b] : pairs)
    {
        std::cout<<a<<" "<<b<<std::endl;
    }

    int above = 1;
    int below = 1;
    for(auto [a,b] : pairs)
    {
        below *= b;
        above *= a;
    }

    std::cout<<above<<"/"<<below<<std::endl;
    int i = std::min(above,below);
    while(i > 2)
    {
        if(above % i != 0)
        {
            --i;
            continue;
        }
        if(below % i != 0)
        {
            --i;
            continue;
        }
        above /= i;
        below /= i;
        i = std::min(above,below);
    }
    std::cout<<above<<"/"<<below<<std::endl;
}

void id32()
{
    std::set<int> products;
    for(int a = 1; a <= 1678; ++a)
    {
        std::string as = std::to_string(a);
        for(int b = a+1; b <= 5432; ++b)
        {
            std::string bs = std::to_string(b);
            int c = a*b;
            std::string s = std::to_string(c) + as + bs;
            if(s.size() == 9)
            {
                std::sort(s.begin(), s.end());
                int ok = true;
                for(int n = 1; n <=9; ++n)
                {
                    if((s[n-1]-'0') != n)
                    {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                {
                    products.insert(c);
                }
            }
        }
    }
    int sum = 0;
    for(auto p : products)
    {
        sum += p;
    }
    std::cout<<"Result: "<<sum<<std::endl;
}
void id31()
{
    std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<std::vector<int>> matrix;
    for(int target = 1; target <= 200; ++target)
    {
        std::vector<int> v;
        for(int i = 0; i < coins.size(); ++i)
        {
            if(i == 0)
            {
                v.push_back(1);
            }
            else if(coins[i] > target)
            {
                v.push_back(v[i-1]);
            }
            else
            {
                int newTarget = target - coins[i];
                if(newTarget == 0)
                {
                    v.push_back(v[i-1]+1);
                }
                else
                {
                    v.push_back(v[i-1] + matrix[newTarget-1][i]);
                }
            }
        }
        matrix.push_back(v);
    }
    std::cout<<"Result: "<<matrix[matrix.size()-1][coins.size()-1]<<std::endl;
}

void id30()
{
  int result = 0;
  for(int i = 2; i <= 999999; ++i)
  {
    int sum = 0;
    int temp = i;
    while(temp > 0)
    {
      sum += std::pow(temp % 10, 5);
      if(sum > i)
      {
        break;
      }
      temp = temp/10;
    }
    if(temp == 0 && sum == i)
    {
      std::cout<<i<<" -> "<<sum<<std::endl;
      result += sum;
    }
  }
  std::cout<<"Result: "<<result<<std::endl;
}

//fast one
void id29_2()
{
  std::set<std::string> numbers;
  for(int a = 2; a <= 100; ++a)
  {
    for(int b = 2; b <= 100; ++b)
    {
      numbers.insert(std::to_string(b * log(a)));
    }
  }
  std::cout<<"Result: "<<numbers.size()<<std::endl;
}

//slow one
void id29_1()
{
  std::set<std::string> numbers;
  for(int a = 2; a <= 100; ++a)
  {
    std::string sa = std::to_string(a);
    for(int b = 2; b <= 100; ++b)
    {
      std::string s = "1";
      for(int i = 0; i < b; ++i)
      {
        s = multiplyBigInteger(s, sa);
      }
      numbers.insert(s);
    }
  }
  std::cout<<"Result: "<<numbers.size()<<std::endl;
}

void id28()
{
    constexpr int sum = []()->int{
        int sum = 0;
        for(int i = 3; i <= 1001; i += 2)
        {
            sum += 4*i*i - 6*i + 6;
        }
        return sum;
    }()+1;
    std::cout<<"Result: "<<sum<<std::endl;
}

void id27()
{
  int resultA = 0;
  int resultB = 0;
  int max = 0;
  for(int a = -999; a <= 999; ++a)
  {
    for(int b = -1000; b <= 1000; ++b)
    {
      int count = 0;
      int n = 0;
      while(n < INT_MAX)
      {
        if(isPrime(n*n + a*n + b))
        {
          count++;
          n++;
        }
        else
        {
          break;
        }
      }
      if(count > max)
      {
        max = count;
        resultA = a;
        resultB = b;
      }
    }
  }
  std::cout<<"max = "<<max<<"\n";
  std::cout<<"a = "<<resultA<<"\n";
  std::cout<<"b = "<<resultB<<"\n";
  std::cout<<"result = "<<resultA*resultB<<"\n";
}

void id26()
{
  int max = 0;
  int result = 1;
  for(int number = 9967; number <= 9967; ++number)
  {
    int num1 = 1;
    int num2 = number;
    std::cout<<num1/num2<<".";
    std::vector<int> numbers;
    num1 = num1%num2;
    bool cycle = false;
    while(num1 != 0)
    {
      while(num1 < num2)
      {
        num1*=10;
      }

      auto cycleIt = std::find(numbers.begin(), numbers.end(), num1);
      if(cycleIt != numbers.end())
      {
        cycle = true;
        auto it = numbers.begin();
        while(it != cycleIt)
        {
          std::cout<<(*it)/num2;
          it++;
        }

        int count = 0;
        std::cout<<"(";
        while(cycleIt != numbers.end())
        {
          std::cout<<(*cycleIt)/num2;
          cycleIt++;
          count++;
        }
        if(count > max)
        {
          max = count;
          result = num2;
        }
        std::cout<<")";
        break;
      }
      numbers.push_back(num1);
      num1 = num1%num2;
    }
    if(cycle == false)
    {
      auto it = numbers.begin();
      while(it != numbers.end())
      {
        std::cout<<(*it)/num2;
        it++;
      }
    }
    std::cout<<std::endl;
  }
  std::cout<<"Answer: "<<result<<" cicle: "<<max<<std::endl;
}

int id25()
{
    std::string n1 = "1";
    std::string n2 = "1";
    std::string next;
    int index = 2;
    do
    {
        index++;
        next = addBigInteger(n1, n2);
        n1 = n2;
        n2 = next;
    }
    while(next.length() < 1000);
    return index;
}

std::string id24()
{
    auto v = permutations("0123456789");
    std::sort(v.begin(), v.end());
    return v[999999];
}

//Can be improved if merge findDivisors and findAbudant functions
long long id23()
{
    std::map<int, bool> sums;
    for(int i = 0; i < 28123*2; ++i)
    {
        sums[i] = false;
    }
    {
        std::vector<int> abudantNumbers = findAbudantNumbers(0, 28123);
        const size_t s = abudantNumbers.size();
        for(int i = 0; i < s; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                int abSum = abudantNumbers[i] + abudantNumbers[j];
                if(abSum <= 28123)
                {
                    sums[abSum] = true;
                }
                else
                {
                    break;
                }
            }
        }
    }
    {
        long long result = 0;
        for(int i = 1; i <= 28123; ++i)
        {
            if(!sums[i])
            {
                result += i;
            }
        }
        return result;
    }
}

long long id22()
{
    std::ifstream infile("p022_names.txt");
    std::vector<std::string> names;

    std::string name;
    while(std::getline(infile, name, ','))
    {
        names.push_back(name.substr(1,name.length()-2));
    }
    std::sort(names.begin(), names.end());

    long long sum = 0;
    for(int i = 0; i < names.size(); ++i)
    {
        int score = 0;
        for(const char& c : names[i])
        {
            score += c - 'A' + 1;
        }
        sum += score*(i+1);
    }
    return sum;
}

long long id21()
{
    std::vector<long long> amicable;
    for(int num1 = 1; num1 < 10000; ++num1)
    {
        if(std::find(amicable.begin(), amicable.end(), num1) != amicable.end())
        {
            continue;
        }
        std::vector<long long> v = findDivisors(num1);
        v.erase(std::remove(v.begin(), v.end(), num1), v.end());

        long long num2 = sumVector<long long>(v);
        if(num2 < 10000 && num2 != num1)
        {
            v = findDivisors(num2);
            v.erase(std::remove(v.begin(), v.end(), num2), v.end());
            if(sumVector<long long>(v) == num1)
            {
                amicable.push_back(num1);
                amicable.push_back(num2);
            }
        }
    }
    return sumVector<long long>(amicable);
}

int id20()
{
    std::string result = "1";
    for(int i = 2; i < 100; ++i)
    {
        result = multiplyBigInteger(result, std::to_string(i));
    }
    int sum = 0;
    for(int i = 0; i < result.size(); ++i)
    {
        sum += result[i] - '0';
    }
    return sum;
}

int id19()
{
    constexpr std::array<int, 12> months = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year = 1901;
    int month = 1;
    [[maybe_unused]]int day = 1;
    int dayOfWeek = 2;
    int result =0;
    for(int y = year; y <= 2000; ++y)
    {
        for(int m = month; m <= 12; ++m)
        {
            int numberOfDays = ((m!=2) ? months[m-1] : (isLeapYear(year) ? 29 : 28));
            dayOfWeek += numberOfDays;
            while(dayOfWeek > 7)
            {
                dayOfWeek-=7;
            }
            if(dayOfWeek == 7)
            {
                result++;
            }
        }
    }

    return result;
}

int id18()
{
    std::ifstream infile("input18.txt");
    std::vector<std::vector<int>> nums;

    std::string line;
    while(std::getline(infile, line))
    {
        std::istringstream tokenizer(line);
        std::vector<int> v;
        std::string s;

        while(tokenizer >> s)
        {
          v.push_back(std::stoi(s));
        }
        nums.push_back(v);
    }

    if(nums.size() > 1)
    {
        for(int row = nums.size() - 2; row >= 0; --row)
        {
            std::vector<int>& v = nums[row];
            for(int elem = v.size() - 1; elem >= 0; --elem)
            {
                int rightElem = nums[row+1][elem+1];
                int leftElem = nums[row+1][elem];
                if(rightElem > leftElem)
                {
                    v[elem] += rightElem;
                }
                else
                {
                    v[elem] += leftElem;
                }
            }
        }
    }
    return nums[0][0];
}

int id17()
{
  std::vector<int> onesLength = {3,3,5,4,4,3,5,5,4};
  std::vector<int> tensLength = {3,6,6,5,5,5,7,6,6};
  std::vector<int> teensLength = {6,6,8,8,7,7,9,8,8};
  int hundred = 7;
  int AND = 3;
  int thousand = 8;

  int result = onesLength[0] + thousand;
//  int result = 0;
  for(int Hundreds = 0; Hundreds <= 9; ++Hundreds) //hundred
  {
    for(int Tens = 0; Tens <= 9; ++Tens) //tens
    {
      for(int Ones = 0; Ones <= 9; ++Ones) //ones
      {
        if((Hundreds == 0) && (Tens == 0) && (Ones == 0))
        {
          continue;
        }

        if(Hundreds > 0)
        {
            result += onesLength[Hundreds-1] + hundred;
            if(Tens > 0 || Ones > 0)
            {
                result += AND;
            }
        }
        std::cout<<"h: "<<result<<"\n";

        if(Tens > 0)
        {
            if(Tens > 1)
            {
                result += tensLength[Tens-1];
            }
            else if((Tens == 1) && (Ones == 0))
            {
                result += tensLength[0];
            }
            else if((Tens == 1) && (Ones > 0))
            {
                result += teensLength[Ones-1];
            }
        }
        std::cout<<"t: "<<result<<"\n";

        if(Ones > 0)
        {
            if(Tens != 1)
            {
                result += onesLength[Ones-1];
            }
        }
        std::cout<<"o: "<<result<<"\n";
      }
    }
  }
  return result;
}

long long id16()
{
  std::string num = "2";
  for(int i = 1; i < 1000; ++i)
  {
    num = addBigInteger(num, num);
  }

  long long result = 0;
  for(int i = 0; i < num.size(); ++i)
  {
    result += (num[i] - '0');
  }
  return result;
}

long long id15()
{
    int w = 20;
    int h = 20;

    std::map<long long, long long> map;
    for(int i = 1; i <= h+1; ++i)
    {
        map[i] = 0;
    }
    map[h+1] = 1;

    for(int i = 1; i < w; ++i)
    {
        std::map<long long, long long> tempmap = map;
        for(auto [key, value] : tempmap)
        {
            for(long long k = 1; k < key; ++k)
            {
                map[k] = map[k]+value;
            }
        }
    }
    long long result = 0;
    for(auto [key, value] : map)
    {
        std::cout<<key<<": "<<value<<"\n";
        result += key*value;
    }
    return result;
}

long long id14()
{
    long long result = 0;
    std::map<long long, long long> cache;
    long long maxChain = 0;
    for(int i = 1; i < 1000000; ++i)
    {
        std::vector<long long> chain;
        long long num = i;
        chain.push_back(num);
        long long count = 1;
        while (num != 1)
        {
            auto it = cache.find(num);
            if(it != cache.end())
            {
                chain.pop_back();
                count += it->second - 1;
                break;
            }

            if(isEven(num))
            {
                num /= 2;
            }
            else
            {
                num = 3*num+1;
            }
            chain.push_back(num);
            count++;
        }
        for(int j = 0; j < chain.size(); ++j)
        {
            cache[chain[j]] = count-j;
        }
        if(count > maxChain)
        {
            maxChain = count;
            result = i;
        }
    }
    return result;
}

std::string id13()
{
  std::ifstream infile("input13.txt");
  std::vector<std::string> nums;
  std::vector<int> result;

  std::string line;
  while(std::getline(infile, line))
  {
    nums.push_back(line);
  }

  int sum = 0;
  int prevSum = 0;
  for(int i = 49; i >= 0; --i)
  {
    sum = prevSum;
    for(int j = 0; j < nums.size(); ++j)
    {
      std::string s;
      s += nums[j][i];
      sum += std::stoi(s);
    }
    result.push_back(sum%10);
    prevSum = sum/10;
  }
  while(prevSum > 0)
  {
    result.push_back(prevSum%10);
    prevSum = prevSum/10;
  }
  std::string resultString;
  for(size_t i = result.size()-1; i >= result.size()-10; --i)
  {
    resultString += std::to_string(result[i]);
  }
  return resultString;
}

long long id12()
{
  int triangleNumber = 0;
  int index = 1;
  std::vector<long long> v;
  while(true)
  {
    triangleNumber += index;
    index++;
    v = findDivisors(triangleNumber, 501);
    if(v.size() > 500)
    {
        return triangleNumber;
    }
  }
}

long long id11()
{
  std::ifstream infile("input11.txt");
  std::vector<std::vector<int>> nums;

  std::string line;
  while(std::getline(infile, line))
  {
    std::istringstream tokenizer(line);
    std::vector<int> v;
    std::string s;

    while(tokenizer >> s)
    {
      v.push_back(std::stoi(s));
    }
    nums.push_back(v);
  }

  auto calculate4RightUp = [&nums](int row, int col)->int{
    if((row >= 3) && (col <= 16))
    {
      return nums[row][col] * nums[row-1][col+1] * nums[row-2][col+2] * nums[row-3][col+3];
    }
    return 0;
  };

  auto calculate4Right = [&nums](int row, int col)->int{
    if(col <= 16)
    {
      return nums[row][col] * nums[row][col+1] * nums[row][col+2] * nums[row][col+3];
    }
    return 0;
  };

  auto calculate4RightDown = [&nums](int row, int col)->int{
    if((row <= 16) && (col <= 16))
    {
      return nums[row][col] * nums[row+1][col+1] * nums[row+2][col+2] * nums[row+3][col+3];
    }
    return 0;
  };

  auto calculate4Down = [&nums](int row, int col)->int{
    if(row <= 16)
    {
      return nums[row][col] * nums[row+1][col] * nums[row+2][col] * nums[row+3][col];
    }
    return 0;
  };

  long long max = 0;
  for(int row = 0; row < 20; ++row)
  {
    for(int col = 0; col < 20; ++col)
    {
      long long result;
      result = calculate4RightUp(row, col);
      max = (result>max) ? result : max;

      result = calculate4Right(row, col);
      max = (result>max) ? result : max;

      result = calculate4RightDown(row, col);
      max = (result>max) ? result : max;

      result = calculate4Down(row, col);
      max = (result>max) ? result : max;
    }
  }
  return max;
}

long long id10()
{
  // Sieve of Eratosthenes

  long long sum = 0;
  int limit = 2000000;

  std::map<int, bool> list;
  for(int i = 2; i < limit; ++i)
  {
    list.insert({i,true});
  }

  int prime = 2;
  while(prime < limit)
  {
    while((list[prime] != true) && (prime < limit))
    {
      prime++;
    }
    if(prime >= limit)
    {
      break;
    }

    int index = 2*prime;
    while(index < limit)
    {
      list[index] = false;
      index += prime;
    }

    sum += prime;
    prime++;
  }
  return sum;
}

long long id9()
{
  for(int a = 1; a < 998; ++a)
  {
    for(int b = 1; b < 998; ++b)
    {
        if(a+b > 999)
        {
          break;
        }

        if(a*a + b*b == (1000-a-b)*(1000-a-b))
        {
          return a*b*(1000-a-b);
        }
    }
  }
  return 0;
}

long long id8()
{
  std::string number = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";

  std::vector<short> numbers;

  long long maxResult = 1;
  for(int n = 0; n < 13; ++n)
  {
    std::string s;
    s += number[n];
    short integer = std::stoi(s);
    numbers.push_back(integer);
    maxResult *= integer;
  }

  for(int pos = 1; pos < number.length()-12; ++pos)
  {
    numbers.erase(numbers.begin());

    std::string s;
    s += number[pos+12];
    numbers.push_back(std::stoi(s));

    long long result = 1;
    for(int n = 0; n < numbers.size(); ++n)
    {
      result *= numbers[n];
    }

    if (result > maxResult)
    {
      maxResult = result;
    }
  }

  return maxResult;
}

long long id7()
{
  int count = 2;
  long long number = 3;
  while(count < 10001)
  {
    number+=2;
    if(isPrime(number))
    {
      count++;
    }
  }
  return number;
}

int id6()
{
  int sum = 0;
  long sumOfSquares = 0;
  for(int i = 1; i <= 100; ++i)
  {
    sum += i;
    sumOfSquares += i*i;
  }
  return sum*sum - sumOfSquares;
}

int id5()
{
  int n = 2520;
  for(int i = 11; i <= 20; ++i)
  {
    if((n % i) != 0)
    {
      n += 20;
      i = 10;
      continue;
    }
  }
  return n;
}

int id4()
{
  int max = 0;
  for(int i = 100; i < 1000; ++i)
  {
    for(int j = i; j < 1000; ++j)
    {
      auto num = i*j;
      if(num > max && isPalindrome(num))
      {
        max = num;
      }
    }
  }
  return max;
}

long long id3()
{
  std::vector<long long> factors;
  long long number = 600851475143;
  while(number > 1)
  {
    long long prime = 2;
    while(number % prime != 0)
    {
      prime = nextPrime(prime);
    }
    factors.push_back(prime);
    number = number/prime;
  }

  long long max = factors[0];
  for(long long f : factors)
  {
    if(f > max)
    {
      max = f;
    }
  }
  return max;
}

int id2()
{
  int number1 = 1;
  int number2 = 2;
  int sum = 2;

  int next = number1 + number2;
  while(next < 4000000)
  {
    if((next % 2) == 0)
    {
      sum += next;
    }
    number1 = number2;
    number2 = next;
    next = number1 + number2;
  }
  return sum;
}

int id1()
{
  int sum = 0;
  for(int i = 1; i < 1000; ++i)
  {
    if(((i / 3)*3 == i) || ((i / 5)*5 == i))
    {
      sum += i;
    }
  }
  return sum;
}
#endif
}
