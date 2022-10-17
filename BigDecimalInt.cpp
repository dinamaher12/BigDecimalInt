#include"BigDecimalInt.h"
#include<bits/stdc++.h>

string BigDecimalInt::getstr(){
    return num;
}

BigDecimalInt::BigDecimalInt(string decStr) {
    num = decStr;
}

BigDecimalInt::BigDecimalInt(long long int decInt) {
    num = to_string(decInt);

}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){
    string x = anotherDec.getstr(), result="";
    int m=0;
    string k=x;
    if(x[0]!='-'& num[0]!='-' || x[0]=='-'& num[0]=='-'){
        if(x[0]=='-'& num[0]=='-'){
            x.erase(x.begin());num.erase(num.begin());
        }
        while (x.size()>num.size()){
            num='0'+num;
        }
        for(int i=0;i<num.size();i++){

        }
        while (x.size()<num.size()){
            x='0'+x;
        }
        for(int i=0;i<x.size();i++){
        }
        for(int i=x.size()-1;i>=0;i--){
            m=(x[i]-'0')+(num[i]-'0')+m;

            result =char((m%10)+'0')+result;

            m/=10;
        }
        if(m==1){
            result='1'+result;
        }
        if(k[0]=='-'){
            result='-'+result;
        }
    /*
    if(x[0]!='-'& num[0]=='-'){
        if(x[0]!='-'& num[0]=='-'){
            num.erase(num.begin());
        }
        while (x.size()>num.size()){
            num='0'+num;
        }
        for(int i=0;i<num.size();i++){
            cout<< num[i];
        }
        cout<<endl;
        while (x.size()<num.size()){
            x='0'+x;
        }
        for(int i=0;i<x.size();i++){
            cout<< x[i];
        }
        cout<<endl;
        for(int i=x.size()-1;i>=0;i--){
            m=(num[i]-'0')-(x[i]-'0')+m;
            cout<<m;
            cout<<endl;
            result =char((m%10)+'0')+result;
            cout<<result;
            cout<<endl;
            m/=10;
            cout<<m;
            cout<<endl;
        }
        if(m==1){
            result='1'+result;
        */
    }

    return result;
}


BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){

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
