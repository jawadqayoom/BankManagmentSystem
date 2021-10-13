#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
#include<conio.h>

using namespace std ;

char ch;

class   SIGNUP_C{
	private:
		  string User_name , str1 , str2;
		  char Pass[9];
		  int a=0;
	
	public:
		void input_Name(){
			system("cls");
            ofstream name("Cname.txt");
              
			 cout << "Enter Your USER Name Here : ";
             cin >> User_name;

        name << User_name;
       
        name.close();
		}

		void input_Pass(){
			system("cls"); 
            int count;
			cout << "Password must be of 9 characters " << endl;

			ofstream pass("Cpass.txt");

			cout<<"Enter Your Password Here : "; 
			
            while(Pass[a] !='\r' )
			{
							
			 Pass[a] = getch() ;
			
			if(Pass[a]!='\r')
			{
				cout << "*" ;
			}
			
            else 
			  break;
			  a++; 
		}
        for(a=9 ; a>=0 ; a-- )
        {
            str1 = Pass[a] ;
			str2=str1 + str2 ;
            
        }
		pass << str2 ; 
       pass.close();

		cout << endl;
	} 

};

class Bank{
	private:
		  int Bank_Balance;
		  int Withdraw;
		  int Deposite;
		  char key;
	public:
		Bank(): Bank_Balance(0) , Deposite(0) , Withdraw(0) { };

		  void input_deposite()
		  {
			  system("cls");
		    cout << "Enter the ammount you want to deposite : " ;
		  	cin >> Deposite ;
		  	 if(Deposite<=0)
			  {
			  	cout << "Pls Enter the valid ammount \nEnter any key to continue " << endl;
			  	key = getch(); 
			  	input_deposite();
			  }
		  	
		  }
		  void input_Withdraw()
		  {
			  system("cls");
			  cout << "Enter the ammount you want to withdraw : " ;
		  	  cin >> Withdraw;
			  if (Withdraw>Deposite)
			  {
			  	cout << "Sorry you have insufficient balance " << endl;
			  	key = getch();
			  	input_Withdraw();
			  }
			  else if(Withdraw<=0)
			  {
			    cout << "Pls Enter the valid ammount \nEnter any key to continue " << endl;
			  	key = getch();
			  	input_Withdraw();
			  }
		  	
		  }
		  void balance_check(){
		  	system("cls");
		  	Bank_Balance = Deposite-Withdraw;
		  	cout << "Your current Balance is : " << Bank_Balance << endl;
		  }
		  	     
	
};

void login()
{
	    int a=0 , choice[2];
	    string uname , str1 , str2;
		char upass[9] , ch;
		Bank B1;
		string about="HI Welcome to MY BANK.This Bank allows to create the account and then you can  signin to draw out the different ACCOUNT OPERATIONS";
     	ifstream File_Cname ("Cname.txt");
		ifstream File_Cpass ("Cpass.txt");
		
		string cname , cpass  ;

		getline(File_Cname , cname);
		getline(File_Cpass , cpass);


		

		cout << "Enter your username here : ";
		cin >> uname;
		
		cout << "Password must be of 9 characters " << endl;
		cout << "Enter your pass here : " ;
		 
		 while(upass[a]!='\r' )
		 {
						
			 upass[a] = getch() ;
			
			if(upass[a]!='\r')
			{
				cout << "*" ;
			}
			else 
			break;

			a++; 
		}
		for(int i=9 ; i>=0 ; i--)
		{
			str1=upass[i];
			str2=str1+str2;
		}

			if(uname==cname && str2==cpass)
			{
				cout << "\nYOU HAVE BEEN LOGGED IN AS CUSTOMER " << endl ;
	
	        while(true)
	{
		cout << "Select the option " << endl;
		
		system("cls");
		
		cout << "(1)-DEPOSiTE\n(2)-WITHDRAW\n(3)-BALANCE CHECK\n(4)-EXIT" << endl;
		
		cin  >> choice[1];
		
		if(choice[1]==1)
		
		B1.input_deposite();
	    
		else if(choice[1]==2)
		
		B1.input_Withdraw();
	    
		else if(choice[1]==3)
		
		B1.balance_check();
		
		else if(choice[1]==4)
	
         exit(0);
        
        else 
		
		cout << "INVAILD CHOICE " << endl;
		
		cout<<"DO YOU WISH TO CONTINUE ? (Y\\N) " << endl;
		
		cin >> ch ;
		
		if(ch=='n' || ch=='N')
		
		break;
    }
	}
		else  
		{
			while(ch!='\r')
			{
			  system("cls");
			  cout << "\n***************************\n" << endl ;
              cout << "Invalid username or passs ! " << endl ;
			  cout << "\n***************************\n" << endl ;
			  cout << "\npress enter to login again OR press 'e' to exit " ;
              ch = getch();
			  if(ch!='\r' && ch == 'e' )
			  {
				  system("cls");
				  cout << "\t\t***************************  " << "THANKS FOR USING OUR SERVICES " << "********************\n";
			      cout << "\n\t\t\t\t***************************  " << "PLEASE VISIT US AGAIN " << "********************\n";
				  exit(0);
			  }
			}
			system("cls");
			login();
		}   

}

void starline1()
{
	cout << "\t\t*************************************************************************************************\n" ;
}

int main()
{
	int choice[3];
 	string about="This Bank allows to create the account and then you can  signin to draw out the different ACCOUNT OPERATIONS\n" ;
    SIGNUP_C C1;
    
	 starline1() ;
	 cout << "\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
	 cout << "\t\t*\t\t\t\tHI WELCOME TO MY BANK\t\t\t\t\t\t* " << endl ;
	 cout << "\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*" << endl;
	 starline1() ;
    
	cout << "\n\n\t\t" << about << "\n\n" ;

	cout << "\t\t**************************** MAIN MENU ***************************\n" << endl;
	
	cout << "\t\tPLEASE SELECT THE FOLLOWING \n " ;
	cout << "\t\t(1)-CUSTOMER SIGNUP \t(2)-LOGIN \t(3)EXIT \n\n\t\tEnter your choice here : ";
    
	cin >> choice[0];
	
	if(choice[0]==1) 
	{
		C1.input_Name();
		C1.input_Pass();
		cout << "\nSIGNUP SUCESSFULLY AS CUSTOMER " << endl;
        main();
	}
	else if(choice[0]==2)
	{
	   system("cls");
       login();
	
	}

	
	else if(choice[0]==3)
		{
			system("cls");
			cout << "\t\t***************************  " << "THANKS FOR USING OUR SERVICES " << "********************\n";
			cout << "\n\t\t\t\t***************************  " << "PLEASE VISIT US AGAIN " << "********************\n";
         exit(0);
		}

	else 
	
	{
		starline1();
		cout << "Invalid choice please enter the correct number " << endl ;
		starline1();
		
		getch();
		
		main();
	}
    
    
    
	

}
