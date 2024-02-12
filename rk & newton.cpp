#include<bits/stdc++.h>
using namespace std;

//x+y
//x^4-x^3+x
vector<double> v;

void parse(string s) {
    int num = 0;
    int sign = 1;

    for (char c : s) {
        if (c == '-') {
            sign = -1;
        } else if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (isalpha(c)) {
            if (num == 0) {
                num = 1; // Default to 1 if no coefficient is specified
            }
            v.push_back(sign * num);
            num = 0;
            sign = 1;
        }
    }
    if (num != 0) {
        v.push_back(sign * num);
    }
}

void parse2(string s){
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


double f(double x,double y)
{
    return v[0]*x + v[1]*y;
}
double func(double x)
{
	return x*x*x*x - x*x*x + x;
}
double derivFunc(double x)
{
	return 4*x*x*x - 3*x*x + 1;
}

void rungeKutta(double x0,double y0,double h)
{

    double k1, k2, k3, k4;

    double y = y0;
    double x=x0;
    for (int i=0; i<2; i++)
    {
        k1 = h*f(x, y);
        k2 = h*f(x + 0.5*h, y + 0.5*k1);
        k3 = h*f(x+ 0.5*h, y + 0.5*k2);
        k4 = h*f(x + h, y + k3);


        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);


        x = x + h;
        cout << "The value of y at x using r k method = "<<x<< " is : "<<y<<endl;
    }

}
void newtonRaphson(double x)
{
	double h = func(x) / derivFunc(x);
	while (abs(h) >= 0.0001)
	{
		h = func(x)/derivFunc(x);
		x = x - h;
	}

	cout << "The value of the root using newton raphson method is : " << x;
}

void newtonraphson()
{
     string equ;
     cout<<"Enter equation for Newton Raphson"<<endl;
     cin>>equ;
     parse2(equ);
     cout<<v[0]<<" "<<v[1]<<" "<<"1"<<endl;
     double x0 =-2;
	 newtonRaphson(x0);
}
void rk()
{
    string equ;
    cout<<"enter equation for R-k method"<<endl;
    cin>>equ;

    parse(equ);

    cout << "Coefficients: ";
     for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    double x0 =0, y = 1, h = 0.1;
    rungeKutta(x0,y,h);
}

int main()
{
    cout<<fixed<<setprecision(7);
    int ch;
    cout<<"1.Newton raphson"<<endl;
    cout<<"2.R-K method"<<endl;
    cin>>ch;
    if (ch==1)
    {
        newtonraphson();
    }
    else
    {
        rk();
    }

    return 0;
}
