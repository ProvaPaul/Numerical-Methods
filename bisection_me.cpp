#include<bits/stdc++.h>
using namespace std;
//#define fast ios_base::sync_with_stdio(0);cin.tie(0)

vector<double> v ;

void parse(string s){
    int i = 0 ;
    int sign = 1 ;
    int num = 0 ;
    int var = 0 ;
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


double f(double x)
{
    return (v[0]*x*x)+(v[1]*x)+(v[2]);
}

void bisection(double a,double b)
{
    double c;
    int n=0;
    while((b-a)>=0.0001)
    {
        c=(a+b)/2;
        n++;

        if (f(c)==0)
            break;


        if (f(a)*f(c)<0)
            {
                b=c;
            }
        else
            {
                a=c;
            }
    }

    cout<<"root is: "<<c<<endl;
    cout<<"iteration "<<n<<endl;
}

int main()
{
    string equn;
    cout<<"f(x)=";
    cin>>equn;
    parse(equn);
    cout<<"a= "<<v[0]<<" "<<"b= "<<v[1]<<" "<<"c= "<<v[2]<<endl;
    double a=v[0];
    double b=v[1];
    double d=v[2];
    double number,range;
    number=pow(b/a,2)-2*(d/a);
    //double a=5.000000;
    //double b=6.000000;
    range=sqrt(number);
    double x1,x2,x3;

    for(double i=(-range);i<=range;i++)
    {
        x1=f(i);

        if (x1>0)
        {
            x2=i;
        }
        else
        {
           x3=i;
           break;
        }
    }
    cout<<x2<<x3<<endl;
    bisection(x2,x3);
    return 0;
}
