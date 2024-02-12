#include<bits/stdc++.h>
using namespace std;

float a[3][3];
float b[3];
int p = 0;

void Coefficients(string s)
{
    string str;
    int c = 0, q = 0, i;

    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            str.clear();
            for (int j = c; j < i; j++)
                str += s[j]; // separated number in string form

            int n = 0; // converted string to int
            stringstream num(str);
            num >> n;
            if (n == 0)
                n = 1;

            if (q == 0)
                a[p][q] = n; // storing co-efficients in a[][]
            else if (q > 0)
            {
                if (s[c - 1] == '+')
                    a[p][q] = n;
                else if (s[c - 1] == '-')
                    a[p][q] = ((-1) * n);
            }
            q++;
            c = i + 2;
        }
    }

    str.clear(); // storing values in b[]
    for (int j = c; j < i; j++)
        str += s[j];

    int n = 0;
    stringstream num(str);
    num >> n;
    b[p] = n;
    p++;
}

float x, y = 0, z = 0;

void luDecomposition()
{

    float l[3][3], u[3][3], y[3], x[3];

    for (int i = 0; i < 3; i++) // initializing l[][]
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                l[i][j] = 1;
            else
                l[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) // initializing u[][]
    {
        for (int j = 0; j < 3; j++)
            u[i][j] = 0;
    }

    for (int i = 0; i < 3; i++) // finding l[][] and u[][]
    {
        for (int j = 0; j < 3; j++)
        {
            if (i <= j)
            {
                float sum = 0;
                for (int k = 0; k < i; k++)
                    sum += l[i][k] * u[k][j];
                u[i][j] = a[i][j] - sum;
            }
            else
            {
                float sum = 0;
                for (int k = 0; k < j; k++)
                    sum += l[i][k] * u[k][j];
                l[i][j] = (a[i][j] - sum) / u[j][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) // finding y[]
    {
        float sum = 0;
        for (int j = 0; j < i; j++)
            sum += l[i][j] * y[j];
        y[i] = b[i] - sum;
    }

    for (int i = 2; i >= 0; i--) // finding x[]
    {
        float sum = 0;
        for (int j = i + 1; j < 3; j++)
            sum += u[i][j] * x[j];
        x[i] = (y[i] - sum) / u[i][i];
    }


    cout<<"Solution: \n";
    cout << "X: " << x[0] << endl;
    cout << "Y: " << x[1] << endl;
    cout << "Z: " << x[2] << endl;
}
int main()
{
    int n;
    cout<<"Enter number of equations:"<<endl;
    cin>>n;
    vector<string> eqn(n);
    cout<<"Enter equations:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>eqn[i];
    }
    for (int i = 0; i < n; i++)
        Coefficients(eqn[i]);
    
    luDecomposition();
    return 0;
}
