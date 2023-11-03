#include<bits/stdc++.h>
#include<iostream>
#include<typeinfo>
using namespace std;
string decrypt();
string encrypt(string text,int key)
{
    cout<<"\nENCRYPTION"<<endl;
    string cipher;
    for(auto x: text)
    {
        //cout<<typeid(x).name()<<endl;
        if(int(x) ==32)
            cipher.push_back(x);
        else {
            int temp = int(x);
            temp+=key;
            if(temp>122) {
                temp=temp-122;
                temp=temp+96;
            }
            cipher.push_back(char(temp));
        }

    }
    return cipher;
    
}
void decrypt(string cipher)
{
    cout<<"\nDECRYPTION"<<endl;
    int key=0,temp=0;
    cout<<"Key\t\tText"<<endl;
    while(key<27) {
        string text;
        for(auto x:cipher){
            temp=int(x);
            if(temp!=32){
                temp-=key;
                if(temp<97){
                    temp=97-temp;
                    temp=123-temp;
                }
            }
        text.push_back(char(temp));
        }
    cout<<key<<"\t\t"<<text<<endl;
    key++;
    }
}
int main()
{
    string text,cipher;
    int key =3;
    cout<<"Enter Text"<<endl;
    getline(cin, text);
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    cout<<text<<endl;
    key = (rand()% 26)+1;//%26 gives 0-25
    cout<<"Key Chosen:"<<key<<endl;
    cipher= encrypt(text,key);
    cout<<"Cipher Text:"<<cipher<<endl;
    decrypt(cipher);
    return 0;
}