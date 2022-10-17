#include"BigDecimalInt.h"
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
    string x = anotherDec.getstr();
    bool xPos = false,numPos = false;
    if (x[0] != '-'){
        xPos = true;
    }
    if (num[0] != '-'){
        numPos = true;
    }
    if (numPos && (!xPos)){
        x.erase(x.begin());
        return num + x;
    }
    if ((!numPos) && xPos){
        if (x[0] == '+'){
            x[0] = '-';
        }
        else{
            x = '-' + x;
        }
        return num + x;
    }
}



bool BigDecimalInt::operator>(BigDecimalInt anotherDec){
    string x = anotherDec.getstr();
    if(x[0] == '-' && num[0] != '-'){
        return true;
    }
    if(x[0] != '-' && num[0] == '-'){
        return false;
    }
    int sz1 = num.size(), sz2 = x.size();
    bool isPositive = (x[0] != '-');
    if(x[0] == '-' || x[0] == '+'){
        x.erase(x.begin());
        sz2--;
    }
    if(num[0] == '-' || num[0] == '+'){
        num.erase(num.begin());
        sz1--;
    }
    if(sz1 == sz2){
        for(int i =0 ; i< sz1 ; ++i){
            if(x[i] > num[i]){
                return (!isPositive);
            }
            else if(x[i] < num[i]){
                return(isPositive);
            }
            return false;
        }
    }
    else{
        return(sz2 < sz1) && (!isPositive);
    }
}


bool BigDecimalInt::operator<(BigDecimalInt anotherDec){
    string x = anotherDec.getstr();
    if(x[0] == '-' && num[0] != '-'){
        return false;
    }
    if(x[0] != '-' && num[0] == '-'){
        return true;
    }
    int sz1 = num.size(), sz2 = x.size();
    bool isPositive = (x[0] != '-');
    if(x[0] == '-' || x[0] == '+'){
        x.erase(x.begin());
        sz2--;
    }
    if(num[0] == '-' || num[0] == '+'){
        num.erase(num.begin());
        sz1--;
    }
    if(sz1 == sz2){
        for(int i = 0 ; i< sz1 ; ++i){
            if(x[i] > num[i]){
                return (isPositive);
            }
            else if(x[i] < num[i]){
                return(!isPositive);
            }
            return false;
        }

    }
    else{
        return(sz2 > sz1) && (isPositive);
    }


}

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

BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {

    for(int i = 0; i < num.length(); i++){
        num[i] = anotherDec.num[i];

    }

}

int BigDecimalInt::sign(){
    string s = "";
    if(num[0] == '-'){
        for(int i = 1; i< num.length(); i++){
            s += num[i];

        }
        num = s;
        return -1;

    }
    else if (num[0] == '+'){
        for(int i = 1; i< num.length(); i++) {
            s += num[i];
        }
        num = s;
        return 1;

    }
    else{
        return 0;
    }

}


int BigDecimalInt::size() {
    return num.length();
}



 ostream& operator<<(ostream& out, BigDecimalInt b){
    out << b.num;

}

