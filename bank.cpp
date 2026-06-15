#include <iostream>
#include <fstream>
using namespace std;
struct accbalance{
    string accountHoldername;
    int accountnumber;
    int pin;
    double balance;
    string accounttype;
};
void saveinfo(const accbalance &acc){
    ofstream file("acount.txt");
    if(file){
        file <<   acc.accountHoldername << endl;
        file <<     acc.balance           << endl;
        file <<    acc.accounttype       << endl;
        file <<     acc.accountnumber     << endl;
    file.close();
        cout << "account info saved to file\n";
    }else{
        cout << "file not open";
    }
}
void view_accinfo(accbalance &acc){
    cout << " Account Holder:" <<    acc.accountHoldername << endl;
    cout << " Balance :"       <<    acc.balance           << endl;
    cout << " Account Type:"   <<    acc.accounttype       << endl;
    cout << " Account Number:" <<    acc.accountnumber     << endl;
}

void withdrawalAmount(accbalance &acc, int amount){
    if(amount < acc.balance){
         acc.balance -= amount;
    cout << "Withdrawal Successful !!" << endl;
    cout << "Your current Balance is:" << acc.balance << endl;
    }else{
        cout << "insufficient balance!!!" << endl;
    }

}
void depositAmount( accbalance &acc , int amount ){
    acc.balance += amount;
cout << "Your Current balance is:" << acc.balance << endl;
}
void view_accbalance(accbalance &acc){
    cout << "Your Current Balance is:" << acc.balance << endl;
}
int main(){
    accbalance acc;
cout << "Enter Your Pin:" << endl;
cin  >> acc.pin;
    int choice; 
    cout << "Enter this Information to proceed further ... " << endl;
    cout << "Enter Account Holder Name:" << endl;
    cin.ignore();
    getline(cin , acc.accountHoldername);
    cout << "Enter Account Number :" << endl;
    cin  >> acc.accountnumber;
    cout << "Enter Account Type (saving , Current):" << endl;
    cin.ignore();
    getline(cin , acc.accounttype);
    cout  << "Enter Balance:" << endl;
    cin    >> acc.balance;
    cout  << "Enter pin :"   << endl;
    cin   >> acc.pin;
       saveinfo(acc);
do{
    int amount;
  cout << "press 1 for view account information"   << endl;
  cout << "press 2 for withdrawal ammount"         << endl;
  cout << "press 3 for deposit amount"             << endl;
  cout << "press 4 for view acount balance"        << endl; 
  cout << "press 5 for exit"                       << endl;
  cout << "Enter your choice:"                     << endl;
  cin  >> choice;
  switch(choice){
    case 1:
      view_accinfo(acc);
    break;
    case 2:
    cout << "Enter withdrawal Amount:";
    cin  >> amount;
      withdrawalAmount(acc , amount);
    break;
    case 3:
    cout << "Enter your Deposite Amount:" << endl;
    cin  >> amount;
      depositAmount(acc , amount);
    break;
    case 4:
       view_accbalance(acc);
    break;
    case 5:
    cout << "Thankyou!!! ...... Exiting " << endl;
    break;
    default:
    cout << "Invalid input please try again!!";
  }
}while(choice!=5);
return 0;
}
