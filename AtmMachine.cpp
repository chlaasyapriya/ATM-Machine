#include<iostream>
#include <windows.h>
#include <cwchar>
using namespace std;
class BankAccount{
	string username,password;
	int money=0;
	public:
		void set_data(string a,string b)
		{
			username=a;
			password=b;
		}
		int check(string a,string b)
		{
		   if(username!=a || password!=b)
		    return 0;
		   return 1;		
		}
		void withDraw(int money)
		{
			if(this->money<money)
			 {
			 	cout<<"\nINSUFFICIENT BALANCE\n"<<endl;
			 }
			else
			{
				this->money-=money;
				cout<<"Rs."<<money<<" withdrawed"<<endl;
			} 
		}
		void depositMoney(int money)
		{
			this->money+=money;
		}
		void requestMoney()
		{
			cout<<this->money<<endl;
		}
		
};

void font()
{
	
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 10;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 20;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    
}
void smile()
{
	system("Color 20");
   int smiley;
   char ch;
   smiley = 1;
   ch = smiley;
   system("Color 20");
      cout<<"\t"<<ch<<endl;
      system("Color 20");
}
void screen()
{
	system("Color 07");
}

int main()
{
	font();
	
	int x,i=0,j,amount;
	char ch;
	BankAccount bnk[1000];
	string username,password;
	cout<<endl<<endl<<"                      WELCOME!!!"<<endl;
	while(1)
	{
		cout<<"\n1. Create a bank account\n2. Login using ID and password \n3. Exit"<<endl;
		cin>>x;
		system("CLS");
		switch(x)
		{
			case 1: cout<<"\nEnter the userID: "<<endl;
			        cin>>username;
			        cout<<"\nEnter the password: "<<endl;
			        cin>>password;
			        bnk[i++].set_data(username,password);
			        cout<<"Account created";
			        smile();
			        cout<<"Press Y to continue"<<endl;
			        cin>>ch;
			        screen();
			        system("CLS");
			        break;
			case 2: cout<<"\nEnter the user id: "<<endl;
			        cin>>username;
			        cout<<"\nEnter the password: "<<endl;
			        cin>>password;
					for(j=0;j<i;j++)
					{
					   if(bnk[j].check(username,password))
					    break;	
				    }
					if(j==i)
					{
						system("Color E4");
					  cout<<"\nINVALID USERNAME OR PASSWORD!"<<endl<<endl;
					  cout<<"Enter Y to go back"<<endl;
					  cin>>ch;
					  screen();
					  system("CLS");
					}
					else
					{
						int flag=0;
					  while(1)
					  {
					  	system("CLS");
					  cout<<"\n1. Withdraw money\n2. deposit money\n3. Request balance\n4. Logout"<<endl;
				      cin>>x;
				      system("CLS");
				      switch(x)
				      {
				      	case 1: cout<<"\nEnter the amount to withdraw: ";
				      	        cin>>amount;
				      	        bnk[j].withDraw(amount);
				      	        system("Color 20");
								cout<<"Enter Y to continue"<<endl;
				      	        cin>>ch;
				      	        screen();
				      	        system("CLS");
				      	        break;
				      	case 2: cout<<"\nEnter the amount to deposit: ";
				      	        cin>>amount;
				      	        bnk[j].depositMoney(amount);
				      	        system("Color 20");
				      	        cout<<"Rs."<<amount<<" deposited "<<endl;
								cout<<"Enter Y to continue"<<endl;
				      	        cin>>ch;
				      	        screen();
				      	        system("CLS");
				      	        break;        
				      	case 3: system("Color 30");
						        cout<<"Balance : Rs.";
						        bnk[j].requestMoney();
				      	        cout<<endl<<"Enter  Y to continue"<<endl;
				      	        cin>>ch;
				      	        screen();
				      	        break;
						case 4: flag=1;          
					  }
					  if(flag==1)
					   break;
					  }
					}
					break;
			case 3:system("Color E1");
			       cout<<endl<<endl<<"                  ****Thank you!!!****"<<endl;
			       int y=1;
				   char z= y;
				   cout<<"              ";
				   for(int i=0;i<10;i++)
				     cout<<z<<"  "; 
					cout<<endl<<endl; 
			       exit(1);		        
		}
	}
}
