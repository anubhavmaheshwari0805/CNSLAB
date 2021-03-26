#include<iostream>
using namespace std;

char table[5][5];
string uniquechar(string key)
{
	string nkey=key;
	int i=0,j,k=0;
	while(key[i]!='\0')
	{
		for(j=0;j<i;j++)
		{
			if(key[j]==key[i])
			break;
		}
		if(j==i)
		{
			nkey[k]=key[i];
			k++;
		}
		i++;
	}
	nkey.resize(k);
	return nkey;
}
string removekey(string alpha, string key)
{
	string nalpha=alpha;
	int i=0,j,k=0;
	while(alpha[i]!='\0')
	{
		for(j=0;j<key.size();j++)
		{
			if(key[j]==alpha[i])
			break;
		}
		if(j==key.size())
		{
			nalpha[k]=alpha[i];
			k++;
		}
		i++;
	}
	nalpha.resize(k);
	return nalpha;
}
void createtable(string key)
{
	string alphabet="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string nkey=uniquechar(key);
    string nalpha=removekey(alphabet,nkey);
	int i,j,k=0,l=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(nkey[k]!='\0')
            {
                table[i][j]=nkey[k];
                k++;
            }
            else if(nalpha[l]!='\0')
            {
                table[i][j]=nalpha[l];
                l++;
			}
        }
    }
}
string upper(string str)
{
	int i=0;
	while(str[i]!='\0')
	{
		str[i]=toupper(str[i]);
		i++;
	}
	return str;
}
string removespaces(string str)
{
	int i=0,j=0;
	while(str[i+j]!='\0')
	{
		if(str[i+j]==' ')
		j++;
		str[i]=str[i+j];
		i++;		
	}
	str.resize(i);
	return str;
}
int searchrow(char ch)
{
	int i,j;
	if(ch=='j')
	ch='i';
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ch==table[i][j])
			return i;
		}
	}
}
int searchcol(char ch)
{
	int i,j;
	if(ch=='j')
	ch='i';
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ch==table[i][j])
			return j;
		}
	}
}
string encrypt(string pt,string key)
{
	if(pt.size()%2!=0)
	{
		pt.resize(pt.size()+1);
		pt[pt.size()-1]='X';
	}
	int i=1;
	while(pt[i]!='\0')
	{
		if(pt[i]==pt[i-1])
		pt[i]='X';
		i++;
	}
	string ct=pt;
	char ch1,ch2;
	int a[2],b[2];
	for(i=0;i<pt.size()/2;i++)
	{
		a[0]=searchrow(pt[2*i]);
		a[1]=searchcol(pt[2*i]);
		b[0]=searchrow(pt[2*i+1]);
		b[1]=searchcol(pt[2*i+1]);
		if(a[0]==b[0])
		{
			ct[2*i]=table[a[0]][(a[1]+1)%5];
			ct[2*i+1]=table[b[0]][(b[1]+1)%5];
		}
		else if(a[1]==b[1])
		{
			ct[2*i]=table[(a[0]+1)%5][a[1]];
			ct[2*i+1]=table[(b[0]+1)%5][b[1]];
		}
		else
		{
			ct[2*i]=table[a[0]][b[1]];
			ct[2*i+1]=table[b[0]][a[1]];
		}
	}
	return ct;
}
int main()
{
	string plaintext,ciphertext,key;
	cout<<"Enter Plain Text : ";
	getline(cin,plaintext);
	plaintext=removespaces(plaintext);
	cout<<"Enter Key : ";
	cin>>key;
	plaintext=upper(plaintext);
	key=upper(key);
	createtable(key);
	ciphertext=encrypt(plaintext,key);
	cout<<"Key Square Table (5*5) :"<<endl;
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Encrypted PlayFair CipherText : "<<ciphertext<<endl;
    return 0;
}
