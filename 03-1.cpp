#include<iostream>
#include<math.h>
using namespace std;
#define N 20
int key[N][N],pt[N][N],en[N][N],de[N][N];

int getkeypt(int n) {
	int i,j,k,nc;
   	cout<<"Enter "<<n<<" order matrix for key :\n";
   	for(i = 0; i < n; i++)
   		for(j = 0; j < n; j++)
      		cin>>key[i][j];
   	string mes;
   	cout<<"\nEnter the Plaintext (A-Z) : ";
   	cin>>mes;
   	if(mes.length()%n==0)
   		nc=mes.length()/n;
   	else
   		nc=int(floor(mes.length()/n))+1;
   	j=0;
	k=0;
	for(i = 0;i<mes.length(); i++) {
   		pt[j][k]=int(mes[i])-int('A');
   		j=(j+1)%n;
   		if(j==0)
   		k++;
	}
	int c=0;
	if(mes.length()%n!=0) {
		while(j!=n) {
			pt[j][k]=25-c;
			j++;
			c++;
		}
	}
	return nc;
}
void displaymat(int mat[N][N],int n,int nc) {
	int i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<nc;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}
int mod(int num) {
	if(num<0)
		return 26+num%26;
	else
		return num%26;
}
void encrypt(int n,int nc) {
	int i,j,k;
   	for(i = 0; i < n; i++)
   		for(j = 0; j < nc; j++) {
   			for(k = 0; k < n; k++)
   				en[i][j] = en[i][j] + key[i][k] * pt[k][j];
   			en[i][j]=mod(en[i][j]);
   		}
   	cout<<"Encrypted Message : ";
	for(i=0;i<nc;i++)
   		for(j=0;j<n;j++)
   			cout<<char(en[j][i]+'A');
   	cout<<endl;
}
int cofactor(int mat[N][N],int p,int q,int n);
int det(int mat[N][N],int n) {
	if(n==1)
		return mat[0][0];
	else {
		int i,sum=0;
		for(i=0;i<n;i++) {
			sum+=mat[0][i]*cofactor(mat,0,i,n);
		}
		return sum;
	}
}
int cofactor(int mat[N][N],int p, int q, int n) {
	if(n==2) {
		return (((p+q)%2==0)?1:-1)*mat[!p][!q];
	}
	else {
		int j,k,r=0,c=0,nmat[N][N];
		for(j=0;j<n;j++) {
			for(k=0;k<n;k++) {
				if(j!=p&&k!=q) {
					nmat[r][c++]=mat[j][k];
					if(c==n-1) {
						c=0;
						r++;
					}
				}
			}
		}
		return (((p+q)%2==0)?1:-1)*det(nmat,n-1);
	}
}
void inversemat(int mat[N][N],int *nmat, int n) {
	int d=det(mat,n);
	if(d==0) {
		cout<<"Matrix is non invertible\n";
		exit(0);
	}
	int inde=1;
	while(mod(d*inde)!=1) {
		inde+=1;
	}
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) {
			nmat[j*N+i]=mod(cofactor(mat,i,j,n)*inde);
		}
}
void decrypt(int n,int nc) {
   	int i, j, k;
   	int invkey[N][N];
	int *matp;
	matp=&invkey[0][0];
	inversemat(key,matp,n);
   	for(i = 0; i < n; i++)
   		for(j = 0; j < nc; j++) {
   			for(k = 0; k < n; k++)
   				de[i][j] = de[i][j] + invkey[i][k]*en[k][j];
   			de[i][j]=mod(de[i][j]);
   		}
   	cout<<"Decrypted Message : ";
	for(i=0;i<nc;i++)
   		for(j=0;j<n;j++)
   			cout<<char(de[j][i]+'A');
   	cout<<endl;
}
int main() {
	//getting key matrix and plaintext
	int n,nc;
	cout<<"Enter number of rows of key matrix : ";
   	cin>>n;
	nc=getkeypt(n);
	//Displaying Matrices
	cout<<"Plaintext Matrix : "<<endl;
	displaymat(pt,n,nc);
	cout<<"Key Matrix : "<<endl;
	displaymat(key,n,n);
	//encryption
	encrypt(n,nc);
	cout<<"CipherText Matrix : "<<endl;
	displaymat(en,n,nc);
	//decryption
	decrypt(n,nc);
	cout<<"Decrypted Plaintext Matrix : "<<endl;
	displaymat(de,n,nc);
}
