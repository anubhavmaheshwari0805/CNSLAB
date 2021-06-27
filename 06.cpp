#include<iostream>
using namespace std;

int key1[8],key2[8];
void leftshift(int key[10],int step) {
    int i,temp[step];
    for(i=0;i<5;i++) {
        if(i<step)
            temp[i]=key[i];
        if(i<5-step)
            key[i]=key[i+step];
        else
            key[i]=temp[(i+step)%5];
    }
    for(i=5;i<10;i++) {
        if(i<5+step)
            temp[i-5]=key[i];
        if(i<10-step)
            key[i]=key[i+step];
        else
            key[i]=temp[(i+step)%10];
    }
}
void keygen(int key[10]) {
    int p10[] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6 };
    int p8[] = { 6, 3, 7, 4, 8, 5, 10, 9 };
    int key10[10];
    int i;
    for(i=0;i<10;i++)
        key10[i]=key[p10[i]-1];
    leftshift(key10,1);
    cout<<"Key 1 : ";
    for(i=0;i<8;i++) {
        key1[i]=key10[p8[i]-1];
        cout<<key1[i]<<" ";
    }
    leftshift(key10,2);
    cout<<"\nKey 2 : ";
    for(i=0;i<8;i++) {
        key2[i]=key10[p8[i]-1];
        cout<<key2[i]<<" ";
    }
    cout<<"\n";
}
void sboxf(int ans[4] ,int xoor[8]) {
	int sbox[2][2]={{0,1},{2,3}};
	int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
	int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}}; 
	int res[2];
    int i=0,j=0;
	res[0]=s0[sbox[xoor[0]][xoor[3]]][sbox[xoor[1]][xoor[2]]];
	res[1]=s1[sbox[xoor[4]][xoor[7]]][sbox[xoor[5]][xoor[6]]];
	for(j=0;j<2;j++) {
        switch(res[j]) {
            case 0 :ans[i++]=0;
					ans[i++]=0;
				    break;
			case 1 :ans[i++]=0;
					ans[i++]=1;
				    break;
			case 2 :ans[i++]=1;
					ans[i++]=0;
					break;
			case 3 :ans[i++]=1;
					ans[i++]=1;
					break;
        }
	}
}
void fk(int lr[8],int key[8]) {
    int ep[8]={4,1,2,3,2,3,4,1};
    int p4[4]={2,4,3,1};
    int i,afterepxor[8],aftersbox[4],afterp4[4];
    for(i=0;i<8;i++) {
        afterepxor[i]=lr[ep[i]+3];
        afterepxor[i]^=key[i];
    }
    sboxf(aftersbox, afterepxor);
    for(i=0;i<4;i++) {
        afterp4[i]=aftersbox[p4[i]-1];
        lr[i]^=afterp4[i];
    }
}
void encrypt(int pt[8]){
	int ip[8]={2,6,3,1,4,8,5,7};
    int inverseip[8]={4,1,3,5,7,2,8,6};
    int i=0,afterip[8],ct[8],temp[4];
	for(i=0;i<8;i++)
        afterip[i]=pt[(ip[i]-1)];
    fk(afterip,key1);
    for(i=0;i<8;i++) {
        if(i<4) {
            temp[i]=afterip[i];
            afterip[i]=afterip[i+4];
        }
        else
            afterip[i]=temp[i-4];
    }
    fk(afterip,key2);
    cout<<"Encrypted text : ";
    for(i=0;i<8;i++) {
        ct[i]=afterip[(inverseip[i]-1)];
        cout<<ct[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    int i=0,key[10],pt[8];
	cout<<"Enter the 10-bit Key : ";
	for(i=0;i<10;i++)
		cin>>key[i];
    cout<<"Enter the 8-bit PlainText : ";
	for(i=0;i<8;i++)
		cin>>pt[i];
	keygen(key);
    encrypt(pt);
}