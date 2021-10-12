#include <iostream>
#include <string>
#include <vector>
#include <climits>


#define ENTP "Enter your password: "
#define ENTK "Enter the key: "
#define TRUE "Access is permited"
#define FALSE "Access is denied" 
#define YEAR 2021
#define MONTH 10


std::vector<int> str_to_ints(std::string s)
{
    s.resize(32, 'a');
    std::vector<int> v;
    for (char c : s)
        v.push_back(int(c));
    return v;
}

std::vector<int> str_to_ints(std::string s, size_t k)
{
    s.resize(32, 'a');
    std::vector<int> v;
    for (char c : s)
        v.push_back(int(c));
    return v;
}

std::vector<char> str_to_chars(std::string s)
{
    s.resize(32, 'a');
    std::vector<char> v;
    for (char c : s)
        v.push_back(c);
    return v;
}

int med(int m)
{
    return m / 2;
}

int sh(int n)
{
    return ((n >> 2) | (n << 1));
}

int sum(int &min, int &max)
{
    int m = min + max;
    int n = max - min;
    m += med(m);
    m += sh(n);
    return m;
}

std::vector<char> password_to_key(std::vector<int> v)
{
    std::string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?@#$%^:;*+=";
    std::string as = "lkjhcdtyukmvcdtyujhrtyujnkfdtyps";

    std::vector<int> a = str_to_ints(as, as.size());
    std::vector<char> u;

    int x, s, max = INT_MIN, min = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        switch (i % 3) {
        case 0:
        {
            x = v[i] ^ a[i] >> 3;
            u.push_back(al[((x >> 5) | (x << 2)) * YEAR % (MONTH * 7)]);
            if (x < min)
                min = x;
            if (x > max)
                max = x;
            break;
        }
        case 1:
        {
            x = v[i] ^ a[i] >> 3;
            u.push_back(al[((x >> 5) | (x << 2)) * YEAR % (MONTH * 7)]);
            if (x < min)
                min = x;
            if (x > max)
                max = x;
            break;
        }
        case 2:
        {
            x = v[i] ^ a[i] >> 3;
            u.push_back(al[((x >> 5) | (x << 2)) * YEAR % (MONTH * 7)]);
            if (x < min)
                min = x;
            if (x > max)
                max = x;
            break;
        }
        }
    }
    s = sum(min, max);
    return u;
}

int main()
{
    std::string aa11, bb11;
    std::cout << ENTP << "\n";
    std::cin >> aa11;

    std::cout << ENTK << "\n";
    std::cin >> bb11;

    std::vector<char> bb22 = str_to_chars(bb11);
    std::vector<char> aa22 = password_to_key(str_to_ints(aa11));

    if (aa22 == bb22)
        std::cout << TRUE;
    else
        std::cout << FALSE;

    return 0;
}
