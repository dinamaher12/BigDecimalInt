#ifndef P2_BIGDECIMALINT_H
#define P2_BIGDECIMALINT_H
#include<bits/stdc++.h>

using namespace std;
class BigDecimalInt{
private:
    string num;

public:
    // constructor
    BigDecimalInt(string decStr); // rejects bad inputs


    BigDecimalInt(long long int decInt);
    string getstr();

    BigDecimalInt operator+(BigDecimalInt anotherDec);

    BigDecimalInt operator-(BigDecimalInt anotherDec);

    bool operator<(BigDecimalInt anotherDec);

    bool operator>(BigDecimalInt anotherDec);

    bool operator==(BigDecimalInt anotherDec);

    BigDecimalInt operator=(BigDecimalInt anotherDec); // lsa msh 3arfa

    int size();

    int sign();

    friend ostream& operator<<(ostream& out, BigDecimalInt b);
};



#endif //P2_BIGDECIMALINT_H
