#include<iostream>
using namespace std;

string encrypt(string plaintext,int key)
{
	int i;
	string ciphertext=plaintext;
	for(i=0;plaintext[i]!='\0';i++)
	{
		if(plaintext[i]>='a'&&plaintext[i]<='z')
			ciphertext[i]=(plaintext[i]-'a'+key)%26+'a';
		else if(plaintext[i]>='A'&&plaintext[i]<='Z')
			ciphertext[i]=(plaintext[i]-'A'+key)%26+'A';
		else
			ciphertext[i]=plaintext[i];
	}
	return ciphertext;
}
string decrypt(string ciphertext,int key)
{
	int i;
	string plaintext=ciphertext;
	for(i=0;ciphertext[i]!='\0';i++)
	{
		if(ciphertext[i]>='a'&& ciphertext[i]<='z')
			plaintext[i]=(ciphertext[i]-'z'-key)%26+'z';
		else if(ciphertext[i]>='A'&&ciphertext[i]<='Z')
			plaintext[i]=(ciphertext[i]-'Z'-key)%26+'Z';
		else
			plaintext[i]=ciphertext[i];
	}
	return plaintext;
}
int main()
{
	string plaintext,ciphertext;
	int key,option;
	cout<<"Select option : Encrypt(1) or Decrypt(2) or 0 : ";
	cin>>option;
	while(option)
	{
		if(option==1)
		{
			cout<<"Enter plaintext : ";
			cin>>plaintext;
			cout<<"Enter key : ";
			cin>>key;
			ciphertext=encrypt(plaintext,key);
			cout<<"Encrypted Caesar Ciphertext : "<<ciphertext<<endl;
			string ptext=decrypt(ciphertext,key);
			cout<<"Decrypted Caesar Plaintext : "<<ptext<<endl;
		}
		else if(option==2)
		{
			cout<<"Enter Ciphertext : ";
			cin>>ciphertext;
			cout<<"Enter key : ";
			cin>>key;
			plaintext=decrypt(ciphertext,key);
			cout<<"Decrypted Caesar Plaintext : "<<plaintext<<endl;
			string ctext=encrypt(plaintext,key);
			cout<<"Encrypted Caesar Ciphertext : "<<ctext<<endl;
		}
		else
			cout<<"ERROR! : Incorrect Option\n";
		cout<<"Select option : Encrypt(1) or Decrypt(2) or 0 : ";
		cin>>option;
	}
	cout<<"Exiting... \n";
	return 0;
}
