#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>
using namespace std;

int mulmod(int a, int b, int mod)
{
    int x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

int modulo(int base, int exponent, int mod)
{
    int x = 1;
    int y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

bool Miller(int p,int iteration)
{
    if (p < 2)
        return false;
    if (p != 2 && p % 2==0)
        return false;
    int s = p - 1;
    while (s % 2 == 0)
        s /= 2;
    for (int i = 0; i < iteration; i++)
    {
        int a = rand() % (p - 1) + 1, temp = s;
        int mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
            return false;
    }
    return true;
}

int computeTotient(int n)
{
    int x=0;
    int phi[n+1];
    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (int i = 2*p; i<=n; i += p)
               phi[i] = (phi[i]/p) * (p-1);
        }
    }
      cout << "Totient of " << n << " is "<< phi[n] <<endl<<endl;
      x = phi[n];
      return x;
}

void convert(int number) {
	char bin32[] = "00000000000000000000000000000000";
	for (int pos = 31; pos >= 0; --pos)
    {
        if (number%2)
            bin32[pos] = '1';
        number /= 2;
    }
    cout<<bin32<<endl;
}

int xGCD(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}

int RandomBits(void);

int main()
{
    srand(time(0));
    int iteration = 20;
    int p,q,n,d,t,x,y,g;
    int e = 3;

    cout<<"line: 125"<<endl;
    p = RandomBits();
    q = RandomBits();

    if(p==q)
        q = RandomBits();

    cout<<"line 132"<<endl;
    while(Miller(p, iteration)==false)
    {
        cout<<p<<" (p) is not prime \n"<<endl;
        p = RandomBits();
    }
    cout<<p<<" (p) is probably prime \n"<<endl;

    cout<<"line 140"<<endl;
    while(Miller(q, iteration)==false)
    {
        cout<<q<<" (q) is not prime \n"<<endl;
        q = RandomBits();
    }
    cout<<q<<" (q) is probably prime \n"<<endl;


    cout<<"line 149"<<endl;
    cout<<"p: "<<p<<endl<<"q: "<<q<<endl;

    n = p*q;
    cout<<"n: "<<n<<endl<<endl;

    cout<<"line 155"<<endl;
    t=computeTotient(n);

    g = xGCD(t,e,x,y);

    while(xGCD(t,e,x,y) != 1)
        e++;
        xGCD(t,e,x,y);


    cout<<"Chosen e: "<<e<<" is relatively prime with totient "<<t<<endl;

    d = modInverse(e, n);

    cout<<"Multiplicative inverse of n: "<<n<<" and e: "<<e<<" is d: "<<d<<endl<<endl;

    cout<<"line 171"<<endl;
    cout<<"p = "<<p<<" q = "<<q<<" n = "<<n<<" e = "<<e<<" d = "<<d<<endl;
    cout<<"p = ";convert(p);
    cout<<"q = ";convert(q);
    cout<<"n = ";convert(n);
    cout<<"e = ";convert(e);
    cout<<"d = ";convert(d);

    return 0;
}

int RandomBits(void)
{
    int bit[5][32];
    int exp = 0;
    int num[7];
    num[6] = 1;
    num[0] = 1;

    for(int k = 4; k>=0; k--)
    {
            cout<<"b_";
            cout<<k;
            cout<<"    ";
            for(int j = 0; j<32;j++)
            {
                    bit[k][j] = rand()%2;
                    cout<<bit[k][j];
                    }
                cout<<"    "<<bit[k][31]<<endl;
            num[k+1] = bit[k][31];
    }

    for(int i=6; i>=0; i--)
    {
        if(num[i]==1)
        {
            exp += pow(2.0, i);
        }else{
        ;}

    }
    cout<<"Number: "<<exp<<"    ";
    for(int i=0; i<25; i++)
        cout<<0;
    for(int i=6; i>=0; i--)
        cout<<num[i];

    cout<<"\n \n";
    return exp;
}
