using namespace std;
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>


const int admin_pass=7890;

const int m=100;

void DisplayMenu1(){
	cout<<"Please Select one of the Following :-\n"
		<<"1. Create Account\n"
		<<"2. Login into Existing Account\n"
		<<"3. Delete Your Account\n"
		<<"0. Exit. ";
}


void CreateAccount(int& acc, string number[], string name[], int pin[]){
	int temp1,temp2;
	bool con1=false;
	bool con2=false;
	cout<<"\n\nEnter the Account Number : ";
	cin>>number[acc];
	cout<<"Enter the Login Name for your Account : ";
	cin>>name[acc];
	cout<<"PLease Enter your 4-digit pin for your Account : ";
	do{
	cin>>temp1;
	if(temp1>=1000 && temp1<=9999){
		con1=true;
	}
	else{
		cout<<"Please Enter a Valid 4 digit pin : ";
	}
	}while(con1!=true);
	
	cout<<"Re-Enter your Pin : ";
	do{
		cin>>temp2;
		if(temp2==temp1){
			con2=true;
		}
		else{
			cout<<"Entered Pin does not match TRY-AGAIN : ";
		}
	}while(con2!=true);
	
	pin[acc]=temp1;
	
	cout<<"\nAccount Created Successfuly!\n\n";
	acc++;
}


void LoginToAcc(int acc,int& log, string number[], string name[], int pin[]){
	string tempstr;
	int tempint;
	int j;
	bool con=false;
	bool cond=false;
	
	do{
	cout<<"\n\nEnter the Login Name : ";
	cin>>tempstr;
	for(int i=0; i<acc; i++){
		if(tempstr==name[i]){
			j=i;
			con=true;
		}
	}
	if(con==false){
		cout<<"\nAccount Not Found Try Again!";
	}
	}while(con!=true);
	
	cout<<"Enter Your Pin : ";
	do{
	cin>>tempint;
	if(tempint==pin[j]){
		cout<<"\nLogin Successful.";
		cond=true;
	}
	else{
		cout<<"Invalid Pin, Re-Enter your Pin : ";
	}
	}while(cond!=true);
	 
	log=j;
	cout<<endl<<endl;
}


void DeleteAcc(int& acc,string number[], string name[], int pin[], int balance[]){
	string namestr;
	bool con=false;
	
	cout<<"\n\nEnter the name of the Account : ";
	cin>>namestr;
	for(int i=0; i<acc; i++){
		if(namestr==name[i]){
			con=true;
			for(int j=i; j<=acc; j++){
				number[j]=number[j+1];
				name[j]=name[j+1];
				pin[j]=pin[j+1];
				balance[j]=balance[j+1];
			}
			acc--;
			break;
		}
	}
	
	if(con==false){
		cout<<"Account not Found!!\n";
	}
	else{
		cout<<"Account Successfully Deleted\n";
	}
	cout<<endl<<endl;
}


void DisplayMenu2(){
	cout<<"\nPLease Select one of the Following :-\n"
		<<"1. Account Information\n"
		<<"2. Check Balance\n"
		<<"3. Deposit Money\n"
		<<"4. Withdraw Money\n"
		<<"5. Send Money\n"
		<<"0. Logout.\n";
}

void AccountInfo(int acc, int log, string number[], string name[], int pin[], int balance[]){
	cout<<"\n\n==========================================\n";
	cout<<"\t\tAccount Infromation : -\n";
	cout<<"==========================================\n";
	cout<<"Your Account Name is : \'"<<name[log]<<"\'\n";
	cout<<"Your Account Number is : \'"<<number[log]<<"\'\n";
	cout<<"Your Account Pin is : \'"<<pin[log]<<"\'\n";
	cout<<"Your Balance is : \'"<<balance[log]<<"\'\n";
	cout<<"==========================================\n\n";
}

void CheckBalance(int log, int balance[]){
	cout<<"\n\nYour Current available balance is : "<<balance[log]<<endl<<endl;
}

void DepositMoney(int log, string number[], string name[], int pin[], int balance[]){
	int j,amount;
	bool con=false;
	cout<<"\n\nEnter the amount you want to Deposit : ";
	cin>>amount;
	cout<<"\nYou are going to Deposit Rs."<<amount<<" in your Account, Enter pin to Confirm : ";
	do{
		cin>>j;
		if(j==pin[log]){
			con=true;
		}
		else{
			cout<<"Invalid Pin Try Again : ";
		}
	}while(con!=true);
	
	balance[log]+=amount;
	cout<<"\nAn Amount of Rs."<<amount<<" is successfuly transfered in your Account\nAnd your new Balance is : Rs."<<balance[log]<<endl<<endl;
}

void WithdrawMoney(int log, string number[], string name[], int pin[], int balance[]){
	int j,amount;
	bool con=false, cond=false;
	cout<<"\n\nEnter the amount you want to Withdraw : ";
	cin>>amount;
	if(amount<=balance[log]){
	cout<<"\nYou are going to Withdraw Rs."<<amount<<" from your Account, Enter pin to Confirm : ";
	do{
		cin>>j;
		if(j==pin[log]){
			con=true;
		}
		else{
			cout<<"Invalid Pin Try Again : ";
		}
	}while(con!=true);
	
	balance[log]-=amount;
	cout<<"\nAn Amount of Rs."<<amount<<" is successfuly withdrawn from your Account\nAnd now your new Balance is : Rs."<<balance[log]<<"\n\n";
	}
	
	else{
		cout<<"You do not have sufficient balance in your Account\n";
		cout<<"Your Current Balance is : "<<balance[log]<<endl<<endl;
	}
}

void SendMoney(int acc, int log, string number[], string name[], int pin[], int balance[]){
	int amount;
	int j,index;
	bool con=false, cond=false;
	string num;
	cout<<"\n\nEnter the amount you want to Send : ";
	cin>>amount;
	
	if(amount>balance[log]){
		cout<<"You do not have sufficient balance in your Account for this Transaction\n\n";
		return;
	}
	
	cout<<"Enter the Account number of the Reciever : ";
	cin>>num;
	
	for(int i=0; i<acc; i++){
		if(num==number[i]){
			index=i;
			con=true;
			break;
		}
	}
	
	if(con==false){
		cout<<"\nAccount not Found Exiting....\n\n";
		return;
	}
	
	cout<<"\nYou are about to Trasfer Rs."<<amount<<"TO : \n"
		<<"\tAccount Name :   "<<name[index]
		<<"\n\tAccount Number : "<<number[index]
		<<"\nEnter Pin to Confirm : ";
	do{
		cin>>j;
		if(j==pin[log]){
			cond=true;
		}
		else{
			cout<<"Invalid Pin Try Again : ";
		}
	}while(cond!=true);
	
	balance[log]-=amount;
	balance[index]+=amount;
	
	cout<<"You have successfuly Transfered Rs."<<amount<<" to "<<name[index];
	cout<<"\nYour new account balance is : "<<balance[log]<<endl<<endl;
		
}

void WritetoFile(int acc, string number[], string name[], int pin[], int balance[]){
	ofstream file("Banking_data.txt");
	file<<left<<setw(20)<<"Acc_Number"<<setw(20)<<"Acc_Name"<<setw(15)<<"Balance"<<"Pin";
	for(int i=0; i<acc; i++){
		file<<endl;
		file<<left<<setw(20)<<number[i]<<setw(20)<<name[i]<<setw(15)<<balance[i]<<pin[i];
	}
	file.close();
}

void ReadFromFile(int& acc, string number[], string name[], int pin[], int balance[]){
	string line;
	
	ifstream file("Banking_data.txt");
	getline(file,line);
	while(getline(file,line)){
		string pinstr;
		string balstr;
		stringstream ss(line);
		ss>>number[acc]>>name[acc]>>balstr>>pinstr;
		pin[acc]=stoi(pinstr);
		balance[acc]=stoi(balstr);
		acc++;
	}
	file.close();
}

int main(){
	string name[m],number[m];
	int balance[m], pin[m];
	int acc=0;
	for(int i=0; i<m; i++){
		balance[i]=0;
	}
	int opt1, opt2; int log=-1;
	ReadFromFile(acc,number,name, pin, balance);
	
	do{
		DisplayMenu1();
		cin>>opt1;
		
		switch(opt1){
			
			case 1:{
				CreateAccount(acc,number,name,pin);
				break;
			}
			
			case 2:{
				LoginToAcc(acc,log,number,name,pin);
				if(log>=0){
				
				do{	
				DisplayMenu2();
				cin>>opt2;
				
				switch(opt2){
					
					case 1:{
						AccountInfo(acc,log,number,name,pin,balance);
						break;
					}
					
					case 2:{
						CheckBalance(log,balance);
						break;
					}
					
					case 3:{
						DepositMoney(log,number,name,pin,balance);
						break;
					}
					
					case 4:{
						WithdrawMoney(log,number,name,pin,balance);
						break;
					}
					
					case 5:{
						SendMoney(acc,log,number,name,pin,balance);
						break;
					}
					
					case 0:{
						cout<<"Logging Out...........\n\n";
						break;
					}
					
					default:{
						cout<<"Invalid Choice!!\n";
					}
				}
				}while(opt2!=0);
			}
				break;
			}
			
			case 3:{
				DeleteAcc(acc,number,name,pin,balance);
				break;
			}
			
			case 0:{
				cout<<"Exiting.........";
				break;
			}
			
			default:{
						cout<<"Invalid Choice!!\n";
					}
					
			
		}
		
	}while(opt1!=0);
	
	WritetoFile(acc,number,name,pin,balance);
}