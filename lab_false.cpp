#include<bits/stdc++.h>
using namespace std;
bool flg;
vector<double> v;

void parse(string s){
    int i = 0;
    int sign = 1;
    int num = 0;
    int var = 0;
    if(s[0] == '-'){
        sign = -1 ;
        i = 1 ;
    }
    for(; i < s.length() ; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0') ;
        }
        else{
            if(num == 0) num = 1 ;
            v.push_back(sign*num) ;
            num = 0 ;
            sign = 1 ;
            if(var == 0){
                var = 1 ;
                i += 3;
            }
            else{
                i++ ;
            }
            if(s[i] == '-'){
                sign = -1 ;
            }
        }
    }
    v.push_back(sign*num) ;
}

double f(double x){
    return (v[0]*x*x+v[1]*x+v[2]); //fnc here
}

void Bisection(double a, double b){
    if(f(a)*f(b) >= 0) return;
    else{
        int i=0;
        double c;
        while(abs((b-a)/(1.0*b)) >= 0.0001){
            c = (a*f(b)-b*f(a))/(1.0*(f(b)-f(a)));
            i++;
            if(f(c) == 0){
                break;
            }
            else if(f(c)*f(a) < 0) b = c;
            else if(f(c)*f(b) < 0) a = c;
        }
        flg = 1;
        cout << "Root: " << c << "\n" << "Iteration: " << i << endl;
    }
}

int main(){
    string str; cin >> str;
    cout << "f(x) = " << str << endl;
    parse(str);
    cout << "a = " << v[0] << endl;
    cout << "b = " << v[1] << endl;
    cout << "c = " << v[2] << endl;
    for(int i = -5; i < 10; i++){
        double a, b;
        a = i, b = i+1;
        Bisection(a, b);
        if(flg){
            cout << "Range : " << a << ' ' << b << endl;
            break;
        }
    }
    if(!flg) cout << "No solution" << endl;
}