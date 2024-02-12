//Guess Shidal

#include<bits/stdc++.h>
using namespace std;
/*

27x+6y-z=85
6x+15y+2z=72
x+y+54z=110

*/

double A[4][4] ,X[4] ;

void string_to_coefficient(string s , int i){
    int num = 0 ;
    int sign = 1 ;
    int idx = 0 ;
    if(s[0] == '-'){
        sign = -1 ;
        idx = 1 ;
    }
    for(int j = idx ; j < s.length() ; j++){
        if(s[j] <= '9' && s[j] >= '0'){
            num = num*10 + (s[j] - '0') ;
        }
        else if(s[j] == 'x'){
            if(num == 0) num = 1 ;
            A[i][1] = sign*num ;
            num = 0 ;
        }
        else if(s[j] == 'y'){
            if(num == 0) num = 1 ;
            A[i][2] = sign*num ;
            num = 0 ;
        }
        else if(s[j] == 'z'){
            if(num == 0) num = 1 ;
            A[i][3] = sign*num ;
            num = 0 ;
        }

    }
    X[i] = num ;
}

int main(){
    string s1 , s2 , s3;
    cin >> s1 >> s2 >> s3;
    string_to_coefficient(s1 , 1) ;
    string_to_coefficient(s2 , 2) ;
    string_to_coefficient(s3 , 3) ;

   // cout << "\nCoefficient : \n" ;
    // for(int i = 1 ; i <= 3 ; i++){
    //     for(int j = 1 ; j <= 3 ; j++){
    //         cout << A[i][j] << " " ;
    //     }
    //     cout << "\t" << X[i] << endl ;
    // }

    int a1 = A[1][1],a2 = A[1][2],a3 = A[1][3],d1 = X[1];
    int b1 = A[2][1],b2 = A[2][2],b3 = A[2][3],d2 = X[2];
    int c1 = A[3][1],c2 = A[3][2],c3 = A[3][3] ,d3 = X[3];

    // cout<<a1<<" "<<a2<<" "<<a3<<" "<<d1<<endl;
    // cout<<b1<<" "<<b2<<" "<<b3<<" "<<d2<<endl;
    // cout<<c1<<" "<<c2<<" "<<c3<<" "<<d3<<endl;
    double x = d1*1.0/a1;
    double y = (d2-a2*x)/15.0;
    double z = (d3-x-y)/54.0;

    cout<<x<<" "<<y<<" "<<z<<endl;

    int tt = 12;
    double xn,yn,zn;
    int i=0;
    while(tt--){
    i++;
    xn = (d1*1.0-6*y+z)/a1;
    yn = (d2*1.0-b1*xn-b3*z)/b2;
    zn = (d3-xn-yn)/c3;

    cout<<"Step: "<<i<<" "<<xn<<" "<<yn<<" "<<zn<<endl;

    x = xn;
    y = yn;
    z = zn;

    }
    cout<<"Final Roots:"<<" ";
    cout<<xn<<" "<<yn<<" "<<zn<<endl;
}
