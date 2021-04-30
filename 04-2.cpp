#include<iostream>
using namespace std;
char vigenere_table[26][26];
int mod26(int num) {
	if(num<0)
		return 26+num%26;
	else return num%26;
}
void construct_VT() {
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			vigenere_table[i][j]=char('A'+mod26(i+j));
	cout<<"Vigenere Table :\n";
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++)
			cout<<vigenere_table[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
string encrypt(string pt, string key) {
	string ct=pt;
	int i=0,l=key.size();
	for(i=0;i<pt.size();i++)
		ct[i]=vigenere_table[int(pt[i]-'A')][int(key[i%l]-'A')];
	return ct;
}
string decrypt(string ct, string key) {
	string pt=ct;
	int i,j,l=key.size();
	for(i=0;i<pt.size();i++) {
		for(j=0;j<26;j++) {
			if(ct[i]==vigenere_table[j][int(key[i%l]-'A')])
				pt[i]=char('A'+j);
		}
	}
	return pt;
}
int main() {
	cout<<"Enter the key (A-Z) : ";
	string key;
	cin>>key;
	cout<<"Enter the plaintext (A-Z) : ";
	string plaintext;
	cin>>plaintext;
	
	construct_VT();
	
	string ciphertext;
	ciphertext=encrypt(plaintext,key);
	cout<<"Vigenere Encrypted Text : "<<ciphertext<<endl;
	string decryptedtext;
	decryptedtext=decrypt(ciphertext,key);
	cout<<"Vigenere Decrypted Text : "<<decryptedtext<<endl;
}