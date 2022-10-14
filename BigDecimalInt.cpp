#include "BigDecimalInt.h"
#include<bits/stdc++.h>
using namespace std;

string BigDecimalInt::getstr(){
    return num;
}

BigDecimalInt::BigDecimalInt(string decStr) {
    num = decStr;
}

BigDecimalInt::BigDecimalInt(int decInt) {

}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){

}


BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){

}


// doesnot work with negative
bool BigDecimalInt::operator>(BigDecimalInt s){
    string x = s.getstr();
    if (x[0] == '-' && num[0] != '-'){
        return true;
    }
    if (x[0] != '-' && num[0] == '-'){
        return false;
    }
    int sz1 = num.size(),sz2 = x.size();
    bool isPositive = (x[0] != '-');
    if (x[0] == '-' || x[0] == '+'){
        x.erase(x.begin());
        sz2--;
    }
    if (num[0] == '-' || num[0] == '+'){
        num.erase(num.begin());
        sz1--;
    }
    if (sz1 == sz2){
        for (int i = 0;i < sz1;++i){
            if (x[i] > num[i]){
                return (!isPositive);
            }
            else if(x[i] < num[i]){
                return (isPositive);
            }
        }
        return false;
    }
    else
    {
        return (sz2 < sz1) && (!isPositive);
    }

}
//////////////////////////////////////////////////////////


// doesnot work with negative
bool BigDecimalInt::operator<(BigDecimalInt s){
    string x = s.getstr();
    if (x[0] == '-' && num[0] != '-'){ // if num is positive and x is negative return false
        return false;
    }
    if (x[0] != '-' && num[0] == '-'){ // if num is negative and x is positive return true
    if (x[0] != '-' && num[0] == '-'){ // if num is negative and x is positive return true
        return true;
    }
    int sz1 = num.size(),sz2 = x.size();
    bool isPositive = (x[0] != '-');// check if the two numbers are positive or negative
    if (x[0] == '-' || x[0] == '+'){// remove signs from x
        x.erase(x.begin());
        sz2--;
    }
    if (num[0] == '-' || num[0] == '+'){// remove signs from num
        num.erase(num.begin());
        sz1--;
    }
    if (sz1 == sz2){
        for (int i = 0;i < sz1;++i){
            if (x[i] > num[i]){
                return (isPositive);
            }
            else if(x[i] < num[i]){
                return (!isPositive);
            }
        }
        return false;// returns false because the two numbers are equal
    }
    else
    {
        return (sz2 > sz1) && (isPositive);
        /*
            if sz2 is greater than sz1 and the number is positive
            it will return true else it will return false
        */
    }
}
/////////////////////////////////////////////////////////////

// works with negative nums
bool BigDecimalInt::operator==(BigDecimalInt anotherDec){
    for(int i = 0; i < num.length(); i++){
        if(num[i] == anotherDec.num[i]){
            continue;
        }
        else if(num[i] == -anotherDec.num[i]){
            return 0;
        }
        else{
            return 0;
        }
    }
    return 1;

}

// still not done
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {


}

// still not done
int BigDecimalInt::sign(){

}


int BigDecimalInt::size() {
    return num.length();
}


// to print the class
 ostream& operator<<(ostream& out, BigDecimalInt b){
    out << b.num;

}

