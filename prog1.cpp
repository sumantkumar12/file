#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<fstream>
//#include<curses.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void reverse(char *s,char *r)
{
int j,len=0;
while(s[len]!='\0')
len++;
for(j=len-1;j>=0;j--)
r[len-j-1]=s[j];
r[len]='\0';
}
int main()
{
char name[10][20],rev[10][20],input[20],output[20],str[20],rstr[20];
int i,n,len;
fstream ifile,ofile;
//curscr;
cout<<"enter the number of names to read "<<endl;
cin>>n;
cout<<"enter the names"<<endl;
for(i=0;i<n;i++)
{
scanf("%s",name[i]);
}
for(i=0;i<n;i++)
{
reverse(name[i],rev[i]);
}
cout<<"the names and its reverese order are"<<endl;
for(i=0;i<n;i++)
cout<<name[i]<<setw(25)<<rev[i]<<endl;
cout<<"enter the filename which contain list of names"<<endl;
cin>>input;
ifile.open(input,ios::in);
if(!ifile)
{
cout<<"file doesnot exist";
//getch();
exit(1);
}
cout<<"enter the filename to store names in reverse order"<<endl;
cin>>output;
ofile.open(output,ios::out);
if(!ofile)
{
cout<<"file doesnot exit";
//getch();
exit(1);
}
while(!ifile.eof())
{
ifile.getline(str,20,'\n');
reverse(str,rstr);
ofile<<rstr<<endl;
}
//getch();
return 0;
}
