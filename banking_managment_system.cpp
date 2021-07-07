#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include <cstdlib>
#include<cctype>
#include<iomanip>
using namespace std;
class Account{
public:
 int account_number;
 char first_name[20];
 char last_name[20];
 char type;
 float total_balance;
public:
 void set_account_details()
 {
 cout<<"\n\t\tEnter the Account Number: ";
 cin>>account_number;
 cout<<"\n\t\tEnter Your First Name: ";
 cin>>first_name;
 cout<<"\n\t\tEnter Your LastName: ";
 cin>>last_name;
 cout<<"\n\t\tEnter the type of the Account(c/s): ";
 cin>>type;
 cout<<"\n\t\tEnter the Initial Amount(>=500 for saving and >=1000 for current): ";
 cin>>total_balance;
 cout<<endl;
 }

 void show_account_details()
 {
 cout<<"\n\t\t BALANCE DETAILS \n";
 cout<<"\n\t\tAccount Number: "<<account_number<<endl;
 cout<<"\n\t\tFirst Name: "<<first_name<<endl;
 cout<<"\n\t\tLast Name: "<<last_name<<endl;
 cout<<"\n\t\tType of Account: "<<type<<endl;
 cout<<"\n\t\tCurrent Balance: "<<total_balance<<"Rs."<<endl;
 }
}a1;
int main()
{
int choice;
int a;
float b;
fstream f1,f2;
do{
 cout<<"\n\t\t------------------------------------------------------------------------------------"<<endl;
 cout<<"\n\t\t BANKING RECORD SYSTEM:- "<<endl;
 cout<<"\n\t\t------------------------------------------------------------------------------------"<<endl;
 cout<<"\n\n\t\t MAIN MENU "<<endl;
 cout<<"\n\n\t\t1. NEW ACCOUNT"<<endl;
 cout<<"\n\t\t2. DEPOSIT AMOUNT"<<endl;
 cout<<"\n\t\t3. WITHDRAW AMOUNT"<<endl;
 cout<<"\n\t\t4. BALANCE ENQUIERY"<<endl;
 cout<<"\n\t\t5. ALL ACOUNT HOLDER LIST"<<endl;
 cout<<"\n\t\t6. CLOSE AN ACCOUNT"<<endl;
 cout<<"\n\t\t7. MODIFY AN ACCOUNT"<<endl;
 cout<<"\n\t\t8. QUIT"<<endl;
 cout<<"\n\n\t\t Enter your choice(1-8).....";
 cin>>choice;
 switch(choice)
 {
 case 1:
 f1.open("account_file.dat",ios::out|ios::ate|ios::app);
 a1.set_account_details();
 f1.write((char*)&a1,sizeof(a1));
 cout<<"\n\t\tAccount Created.....";
 getch();
 f1.close();
 break;
 case 2:
 {
 int a_no,flag;
 float bal;
 f1.open("account_file.dat",ios::out|ios::ate|ios::in);
 cout<<"\n\t\tEnter the account number to deposit your amount : ";
 cin>>a_no;

 f1.seekg(0);
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 if(a_no == a1.account_number)
 {
 flag=1;
 break;
 }
 }
 if (flag==1)
 {
 f1.seekp(f1.tellp()-sizeof(a1));
 cout<<"\n\t\tEnter your Amount for Deposit :";
 cin>>bal;
 a1.total_balance = a1.total_balance+bal;
 f1.write((char*)&a1,sizeof(a1));
 cout<<"\n\t\tAmount Deposited successfully....";
 }
 else
 {
 cout<<"\n\t\tAccount Number "<<a_no<<" not found";
 break;
 }
 getch();
 f1.close();
 break;
 }
 case 3:
 {
 int a_no,flag;
 float bal;
 f1.open("account_file.dat",ios::out|ios::ate|ios::in);
 cout<<"\n\t\tEnter the account number to withdraw your amount : ";
 cin>>a_no;
 f1.seekg(0);
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 if(a_no == a1.account_number)
 {
 flag=1;
 break;
 }
 }
 if (flag==1)
 {
 f1.seekp(f1.tellp()-sizeof(a1));
 cout<<"\n\t\tEnter the amount you want to withdraw :";
 cin>>bal;
 a1.total_balance = a1.total_balance - bal;
 f1.write((char*)&a1,sizeof(a1));
 cout<<"\n\t\tAmount withdraw successfully....";
 }
 else
 {
 cout<<"\n\t\tAccount Number "<<a_no<<" not found!";
 break;
 }
 getch();
 f1.close();
 break;
 }
 case 4:
 {
 int flag=0;
 f1.open("account_file.dat",ios::in);
 if(!f1)
 {
 cout<<"\n\t\tFile could not be open Press any key to continue......";
 getch();
 break;
 }
 cout<<"\n\t\tEnter account number whose balance details you want: ";
 cin>>a;
 f1.seekg(0);
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 if (a == a1.account_number)
 {
 a1.show_account_details();
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"\n\t\tYour account number "<<a<<" not found.... ";
 }
 f1.clear();
 f1.close();
 getch();
 break;
 }
 case 5:
 {
 int c=1;
 f1.open("account_file.dat",ios::in);
 if(!f1){
 cout<<"\n\t\tFile could not be open Press any key to continue......";
 getch();
 break;
 }
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 cout<<"\n\n\t\t\t\t *****Record "<<c<<"*****:-"<<endl;
 a1.show_account_details();
 c=c+1;
 }
 f1.clear();
 f1.close();
 cout<<"\n\t\tPress any key to continue.....";
 getch();
 /* clrscr();*/
 break;
 }
 case 6:
 {
 int a_no,flag=0,rec;
 f1.open("account_file.dat",ios::in|ios::ate);
 /*if we want to know how many records are there in file then we will write the below line*/
 rec=f1.tellp()/sizeof(a1);
 f2.open("temp.dat",ios::out);
 cout<<"\n\t\tEnter Account number which needs to be deleted :";
 cin>>a_no;
 f1.seekg(0);
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 if (a_no!=a1.account_number)
 { flag++;
 f2.write((char*)&a1,sizeof(a1));
 }
 }
 f1.clear();
 f1.close();
 f2.close();

 remove("account_file.dat");
 rename("temp.dat","account_file.dat");
 if (rec==flag){
 cout<<"\n\t\tYour account number "<<a_no<<" not found!";
 }
 else{
 cout<<"\n\t\tRecord deleted successfully....";
 break;
 }
 getch();
 break;
 }
 case 7:
 {
 char f_n[20],l_n[20];
 int a_no,a,flag=0;
 int option;
 float bal;
 /*clrscr();*/
 f1.open("account_file.dat",ios::out|ios::ate|ios::in);
 /*When we open a file in ate mode then pointer position it at the end so we need to bring
that pointer at the beginning of file,
 so we will use seekg function.*/
 cout<<"\n\t\tEnter the account number whose details need to be updated: ";
 cin>>a_no;
 f1.seekg(0);
 while(f1.read((char*)&a1,sizeof(a1)))
 {
 if(a_no == a1.account_number)
 {
 flag=1;
 break;
 }
 }
 if (flag == 1)
 {
 f1.seekp(f1.tellp()-sizeof(a1));
 cout<<"\n\t\tWhat do you want to update: "<<endl;
 cout<<"\n\t\t1. first_name";
 cout<<"\n\t\t2. last_name";
 cout<<"\n\t\t3. Balance";
 cout<<"\n\t\t4. Account Number";
 cout<<"\n\t\tEnter your choice(1-4)....";
 cin>>option;
 switch(option)
 {
 case 1:
 cout<<"\n\t\tEnter first_name: ";

 cin>>f_n;
 strcpy(a1.first_name,f_n);
 break;
 case 2:
 cout<<"\n\t\tEnter last_name: ";
 cin>>l_n;
 strcpy(a1.last_name,l_n);
 break;
 case 3:
 cout<<"\n\t\tEnter balance: ";
 cin>>bal;
 a1.total_balance = bal;
 break;
 case 4:
 {
 int a_n;
 cout<<"\n\t\tEnter account_number: ";
 cin>>a_n;
 a1.account_number = a_n;
 break;
 }
 }
 f1.write((char*)&a1,sizeof(a1));
 cout<<"\n\t\tRecord updated successfully....";
 }
 else{
 cout<<"\n\t\tAccount Number "<<a_no<<" not found!";
 break;
 }
 getch();
 f1.close();
 /*clrscr();*/
 break;
 }
 case 8:
 cout<<"\n\t\t\tThanks For using banking record system\n\n";
 break;
 default:
 cout<<"\n\t\tPlease enter valid choice between(1-6).....";
 break;
 }
}
while(choice!=8);
}
