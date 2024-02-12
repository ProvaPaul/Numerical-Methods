#include<bits\stdc++.h>
using namespace std;
double f(double x)
{
    return (1*x*x)+(-4*x)+(-10);
}

void secant(double x1,double x2)
{
    double n,xm,x0,c;
   // if (f(x1)*f(x2)<0)
        do{
            x0=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
            c=f(x0)*f(x1);
            x1=x2;
            x2=x0;
            n++;
            if (c==0)
                break;
            xm=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
        }while((xm-x0)>=0.000001);

        cout<<x0<<endl;
        cout<<"iterations "<<n<<endl;
    //cout<<"no solutions"<<endl;
}

int main()
{
    double x1=5,x2=6;
    secant (x1,x2);
    return 0;
}
