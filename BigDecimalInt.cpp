#include"BigDecimalInt.h"
#include<bits/stdc++.h>
using namespace std;

string BigDecimalInt::getstr(){
    return num;
}

void BigDecimalInt::setstr(string s){
    num = s;
}

BigDecimalInt::BigDecimalInt(string decStr) {
    num = decStr;
}

BigDecimalInt::BigDecimalInt(int decInt) {

}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){
    string x = anotherDec.getstr();
    string result="";
    int m=0;
    string k=x;
    if(x[0]!='-' && num[0]!='-' || x[0]=='-' && num[0]=='-'){
        if(x[0]=='-'&& num[0]=='-'){
            num.erase(num.begin());
            x.erase(x.begin());
        }
        while(x.size()>num.size()){
            num='0'+num;
        }
        while(x.size()<num.size()){
            x='0'+x;
        }
        for(int i=x.size()-1;i>=0;i--){
            m=(x[i]-'0')+(num[i]-'0')+m;
            result=char((m%10)+'0')+result;
            m/=10;
        }
        if(m==1){
            result='1'+result;
        }
        if(k[0]=='-'){
            result='-'+result;
        }
        return result;
    }
    else if (x[0] == '-'){
        x.erase(x.begin());
        anotherDec.setstr(x);
        return this->operator-(anotherDec);
    }
    else{
        num.erase(num.begin());
        swap(num,x);
        anotherDec.setstr(x);
        return this->operator-(anotherDec);
    }
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
        anotherDec.setstr(x);
        return this->operator+(anotherDec);
    }
    if ((!numPos) && xPos){
        if (x[0] == '+'){
            x[0] = '-';
        }
        else{
            x = '-' + x;
        }
        anotherDec.setstr(x);
        return this->operator+(anotherDec);
    }
    string t = num;
    if (x[0] == '-' || x[0] == '+'){
        x.erase(x.begin());
    }
    if (t[0] == '-' || t[0] == '+'){
        t.erase(t.begin());
    }
    anotherDec.setstr(x);
    if (this->operator<(anotherDec)){
        while(x.size() > t.size()){
            t = '0' + t;
        }
        int slider;
        int a,b;
        for (int i = x.size() - 1;i >= 0;--i){
            slider = i + 1;
            a = x[i] - '0';
            b = t[i] - '0';
            if (a < b){
                if (x[slider] != '0'){
                    x[slider] = (char)(x[slider] - 1);
                }
                else{
                    while(x[slider] == '0'){
                        x[slider] = '9';
                        slider++;
                        if (x[slider] != '0'){
                            x[slider] = (char)(x[slider] - 1);
                        }
                    }
                }
                a += 10;
                a -= b;
                x[i] = (char)(a + '0');
            }
            else{
                x[i] = (char)((a - b) + '0');
            }
        }
        while(x[0] == '0'){
            x.erase(x.begin());
        }
        x = '-' + x;
        anotherDec.setstr(x);
        return anotherDec;
    }
    else{
        while(t.size() > x.size()){
            x = '0' + x;
        }
        int borrow,slider;
        int a,b;
        for (int i = x.size() - 1;i >= 0;--i){
            slider = i + 1;
            a = t[i] - '0';
            b = x[i] - '0';
            if (a < b){
                if (t[slider] != '0'){
                    t[slider] = (char)(t[slider] - 1);
                }
                else{
                    while(t[slider] == '0'){
                        t[slider] = '9';
                        slider++;
                        if (t[slider] != '0'){
                            t[slider] = (char)(t[slider] - 1);
                        }
                    }
                }
                a += 10;
                a -= b;
                x[i] = (char)(a + '0');
            }
            else{
                x[i] = (char)((a - b) + '0');
            }
        }
        anotherDec.setstr(x);
        return anotherDec;
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
        for(int i = 0;i < sz1;++i){
            if(x[i] > num[i]){
                return (!isPositive);
            }
            else if(x[i] < num[i]){
                return(isPositive);
            }
        }
        return false;
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
        for(int i = 0 ; i < sz1 ; ++i){
            if(x[i] > num[i]){
                return (isPositive);
            }
            else if(x[i] < num[i]){
                return(!isPositive);
            }
        }
        return false;
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

