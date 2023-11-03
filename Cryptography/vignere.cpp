#include<iostream>
#include<string.h>
using namespace std;

int main(){
	char msg[100],key[100],ch;
	int msgLen,keyLen,i,j;
	cout<<"____VIGENERE CIPHER___\n";
	cout<<"\nENTER THE MESSAGE : ";
	cin.getline(msg,100);
	cout<<"\nENTER THE KEY : ";
	cin.getline(key,100);
	msgLen=strlen(msg);
	keyLen=strlen(key);
	char newkey[msgLen],encryMsg[msgLen],decryMsg[msgLen];
	cout<<"\nGENERATING NEW KEY";
	for(i=0,j=0;i<msgLen;i++,j++){
		if(j==keyLen)
			j=0;
		newkey[i]=key[j];
	}
	newkey[i]='\0';
	cout<<"\nKEY : "<<newkey;
	for(i=0;i<msgLen;i++){
		encryMsg[i]=((msg[i]+newkey[i])%26)+'A';
	}
	encryMsg[i]='\0';
	cout<<"\nENCRYPTED MESSAGE: "<<encryMsg;
	for(i=0;i<msgLen;i++){
		decryMsg[i]=(((encryMsg[i]-newkey[i])+26)%26)+'A';
	}
	decryMsg[i]='\0';
	cout<<"\nDECRYPTED MESSAGE: "<<decryMsg;
	return 0;
}
