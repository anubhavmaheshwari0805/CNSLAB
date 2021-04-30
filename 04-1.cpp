#include<iostream>
using namespace std;

int mod26(int num) {
	if(num<0)
		return 26+num%26;
	else return num%26;
}
string encrypt(string pt, string key) {
	string ct=pt;
	int i=0,l=key.size();
	for(i=0;i<pt.size();i++)
		ct[i]=mod26((pt[i]-'A')+(key[i%l]-'A'))+'A';
	return ct;
}
string decrypt(string ct, string key) {
	string pt=ct;
	int i=0,l=key.size();
	for(i=0;i<pt.size();i++)
		pt[i]=mod26((ct[i]-'A')-(key[i%l]-'A'))+'A';
	return pt;
}
int main() {
	cout<<"Enter the key (A-Z) : ";
	string key;
	cin>>key;
	cout<<"Enter the plaintext (A-Z) : ";
	string plaintext;
	cin>>plaintext;
	string ciphertext;
	ciphertext=encrypt(plaintext,key);
	cout<<"Vigenere Encrypted Text : "<<ciphertext<<endl;
	string decryptedtext;
	decryptedtext=decrypt(ciphertext,key);
	cout<<"Vigenere Decrypted Text : "<<decryptedtext<<endl;
	return 0;
}