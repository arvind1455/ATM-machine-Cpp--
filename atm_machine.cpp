/*
INSTRUCTIONS:

1) Run the command  g++ -std=c++11 -O1 atm_machine.cpp -o atm to build and compile the cpp file. 
2) Once compiled run ./atm
3) ENTER C or c to denote that the card is entered.
4) Enter "1415" as pin.
5) Choose the appropriate options you want to choose.

Author : Kamesh Arvind Sarangan (M.Engg. Robotics)
*/

#include <iostream>
#include <string>

using namespace std;

//MAIN FUNCTIONS
void menu();
void acc(int choice);

string acc_type[] = {" ", " Checking Account", " Savings Account"};
string response;

int acc_details[] = {
    1415,                           // PIN NUMBER
    25,                             // CHECKING ACCOUNT
    50                              // SAVING ACCOUNT
};

//CHECK PIN ENTERED CORRECT OR NOT
bool pinValidate(int pin){
    if (pin == acc_details[0]){
        return true;
    } 
    else
    {
        return false;
    }
}

//EXIT THE ATM
bool act(string response){
    if( response == "y" || response == "Y"){
        return true;
    }
    else if( response == "n" || response =="N"){
        string exit;
        cout<<"Thank you for using the ATM. See you soon later.\n";
        return false;
    }
}

//EXIT FROM MENU AND ATM
bool card(string response){
    if( response == "c" || response == "C"){
        return true;
    }
    else if( response != "c" || response !="C"){
        string a;
        cout<<"Thank you for using the ATM. See you soon later.\n";
        cin>>a;
        return false;
    }
}

//CLASS OF ACCOUNT SETTINGS
class acc_settings{

    private:
        int choice;
        int balance;
    public:
        acc_settings(int choice){
            this->choice = choice;
            this->balance = acc_details[this->choice];
        }

    int withdraw(){
        int amountW;
        cout<<"Enter the amount to be withdrawn: \n"<<endl;
        cin>>amountW;

        if (amountW <= this->balance)
        {
            int acc_balance = this->balance -= amountW;
            cout<<"Withdrawing "<<"$"<<amountW<<endl;
            //ACCOUNT UPDATE

            acc_details[this->choice] = acc_balance;
            bal();
        } else
        {
            cout<<"Insufficient amount"<<endl;
            bal();
        }
        return 0;
    }

    int deposit(){
        int amountD;
        cout<<"Enter the amount to Deposit: \n"<<endl;
        cin>>amountD;

        int acc_balance = this->balance += amountD;
       
        //ACCOUNT UPDATE
        acc_details[this->choice] = acc_balance;
        bal();
        return 0;
    }    

    int transfer(){
        int amountt;
        int transfer = this->choice == 1 ? 2 : 1;
        cout<<"Enter the amount to transfer to your "<<acc_type[transfer]<<endl;
        cin>>amountt;

        if (amountt <= acc_details[this->choice])
        {
            int new_balance = this->balance -= amountt;
            acc_details[this->choice] = new_balance; 

            int transferto = acc_details[transfer] += amountt;
            acc_details[transfer] = transferto;

            cout<<"\n\tAmount transaction successful!!!"<<endl;
            bal();
        } else
        {
            cout<<"Insufficient amount"<<endl;
            bal();
        }
        return 0;
    }

    int bal(){
        string ba;
        cout<<"Do you want to check your balance "<<acc_type[this->choice]<<" account balance ? (Y/N)\n"<<endl;
        cin>>ba;
        if(ba == "y" || ba == "Y"){
            cout<<"Your account balance is: $" <<this->balance<<endl;
        }
        cout<<"Would you like to continue ? (Y/N)\n";
        cin>>response;
        if (act(response)){
            acc(this->choice);
        }
        return 0;
    }
};

//ACCOUNT OPTIONS
void acc(int opt){
    cout<<"\n\n\t"<<acc_type[opt]<<"\n\t1. Check Balance "<<"\n\t2. Withdraw from "<<acc_type[opt]
    <<"\n\t3. Deposit to " <<acc_type[opt]<<"\n\t4. Transfer "<<"\n\t5. --Go Back to Menu"<<endl;

    acc_settings account(opt);
    int select;
    cin>>select;

    switch (select)
    {
    case 1:
        account.bal();
        break;
    
    case 2:
        account.withdraw();
        break;    
    
    case 3:
        account.deposit();
        break;        
    
    case 4:
        account.transfer();
        break;  

    case 5:
        menu();
        break;

    default:
        cout<<"Would you like to continue (Y/N)\n";
        cin>>response;
        act(response);
        if (act(response)){
            menu();
        }
        break;
    }
}

//MENU OPTIONS
void menu(){
    int opt;
    cout <<"\tMain Menu --"<<endl;
    cout <<"\tPlease select an option to continue. "<<endl;
    cout <<"\t1. Checking Account \t2. Saving Account \t3. Exit"<<endl;
    cin >> opt;
    switch (opt)
    {
    case 1:
        acc(opt);
        break;
    
    case 2:
        acc(opt);
        break;
    
    default:
        cout<<"Would you like to continue (Y/N)\n";
        cin>>response;
        act(response);
        if (act(response)){
            menu();
        }
        break;
    }
}

int main()
{
    int pin;
    cout<<"\n\t******************Welcome to Arvind's Bank****************** \n"<<endl;
    cout<<"Please ENTER your card"<<endl;
    cin >> response;
    card(response);
    if(card(response))
    {
        do
        {
            cout<<"Enter your Pin to proceed\n";
            cin>>pin;
            if (pinValidate(pin)){
                cout<<"Hello There"<<endl;
                menu();
            }else
            {
                cout<<"Wrong Pin ENTERED. PLEASE TRY AGAIN FROM THE BEGINNING"<<endl;
                break;
            }
        } while (!pinValidate(pin));
    }
    return 0;     
}
