#include<iostream>
using namespace std;

string encrypt(string p, int key, int n) {
    string c=p;
    int i,j,k=-1;
    char table[key][n];
    for(i=0;i<key;i++) {
        for(j=0;j<n;j++) {
            table[i][j]=' ';
        }
    }
    j=0;
    for(i=0;i<n;i++) {
        table[j][i]=p[i];
        if(j==0||j==key-1)
            k*=-1;
        j=j+k;
    }
    k=0;
    for(i=0;i<key;i++) {
        for(j=0;j<n;j++) {
            if(table[i][j]!=' ')
                c[k++]=table[i][j];
        }
    }
    return c;
}
string decrypt(string c,int key, int n) {
    string d=c;
    int i,j,k;
    char table[key][n];
    for(i=0;i<key;i++) {
        for(j=0;j<n;j++) {
            table[i][j]='\n';
        }
    }
    j=0;
    k=-1;
    for(i=0;i<n;i++) {
        table[j][i]='\0';
        if(j==0||j==key-1)
            k*=-1;
        j=j+k;
    }
    k=0;
    for(i=0;i<key;i++) {
        for(j=0;j<n;j++) {
            if(table[i][j]=='\0')
                table[i][j]=c[k++];
        }
    }
    j=0;
    k=-1;
    for(i=0;i<n;i++) {
        d[i]=table[j][i];
        if(j==0||j==key-1)
            k*=-1;
        j+=k;
    }
    return d;
}
int main() {
    string pt;
    cout<<"Enter the plaintext without space (A-Z) : ";
    cin>>pt;
    int key;
    cout<<"Enter the key (depth) : ";
    cin>>key;
    int n=0;
    while(pt[n]!='\0') n++;
    string ct=encrypt(pt,key,n);
    cout<<"Encrypted Text : "<<ct<<"\n";
    string dt=decrypt(ct,key,n);
    cout<<"Decrypted Text : "<<dt<<"\n";
}