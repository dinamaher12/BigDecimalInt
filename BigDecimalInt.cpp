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



bool BigDecimalInt::operator>(BigDecimalInt anotherDec){

    if(num.length() == anotherDec.num.length()){
        for(int i = 0; i<num.length(); i++){

            if(num[i] > anotherDec.num[i]){
                return 1;

            }
            else if(num[i] < anotherDec.num[i]){
                return 0;

            }

        }
    }

    else if(num.length() > anotherDec.num.length()){
        return 1;
    }
    else if(num.length() < anotherDec.num.length()){
        return 0;
    }


}



// belongs to me
bool BigDecimalInt::operator<(BigDecimalInt anotherDec){

    if(num.length() == anotherDec.num.length()){
        for(int i = 0; i<num.length(); i++){
            if(num[i] < anotherDec.num[i]){
                return 1;

            }
            else if(num[i] > anotherDec.num[i]){
                return 0;

            }

        }
    }

    if(num.length() < anotherDec.num.length()){
        return 1;
    }
    else if(num.length() > anotherDec.num.length()){
        return 0;
    }

}

bool BigDecimalInt::operator==(BigDecimalInt anotherDec){
    for(int i = 0; i < num.length(); i++){
        if(num[i] == anotherDec.num[i]){
            continue;
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

