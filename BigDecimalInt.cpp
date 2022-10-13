#include "BigDecimalInt.h"
#include<bits/stdc++.h>
using namespace std;

BigDecimalInt::BigDecimalInt(string decStr) {
    num = decStr;
}

BigDecimalInt::BigDecimalInt(int decInt) {

}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){

}


BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){

}



bool BigDecimalInt::operator<(BigDecimalInt anotherDec){

}


bool BigDecimalInt::operator>(BigDecimalInt anotherDec){


}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec){

}

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {


}

int BigDecimalInt::sign() {

}


int BigDecimalInt::size() {
    return num.length();
}


// to print the class
 ostream& operator<<(ostream& out, BigDecimalInt b){
    out << b.num;

}

