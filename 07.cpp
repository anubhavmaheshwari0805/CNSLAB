#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a,int b) {
    int t;
    if(b==0)
        return a;
    return gcd(b,a%b);
}
/*int modmul(int m,int e,int n) {
    int c=m;
    for(int i=1;i<e;i++)
        c=fmod(c*m,n);
    return c;
}*/
int modmul(int m,int e,int n) {
    int rev = 0;
    int c=0;
    while (e > 0)
    {
        rev <<= 1;
        if (e & 1 == 1)
            rev ^= 1;
        e >>= 1;
        c++;        
    }
    int d=1;
    while(c>0) {
        d=fmod(d*d,n);
        if(rev&1==1)
            d=fmod(d*m,n);
        rev>>=1;
        c--;
    }
    return d;
}
main() {
    int p,q;
    cout<<"Enter 2 prime numbers for key generation : ";
    cin>>p>>q;
    int n=p*q;
    int phi=(p-1)*(q-1);
    int e=2;
    while(e<phi) {
        if(gcd(phi,e)==1)
            break;
        else
            e++;
    }
    int d=1;
    while((e*d)%phi!=1)
        d++;
    cout<<"e="<<e<<" d="<<d<<" n="<<n<<endl;
    int msg,en,dec;
    cout<<"Enter Message : ";
    cin>>msg;
    en=modmul(msg,e,n);
    cout<<"Encrypted Message : "<<en<<"\n";
    dec=modmul(en,d,n);
    cout<<"Decrypted Message : "<<dec<<"\n";
}