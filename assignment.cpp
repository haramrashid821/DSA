#include<iostream>
#include<string>
using namespace std;
//structure to store expense entries
struct Expense{
    string date; 
	string category;
	float amount;
    Expense* next;   
//parametrized constructor to initialize variables
Expense(string d,float a,string c){
    date=d;
    amount=a;
    category=c;
    next=NULL;
    }
};
//class named expense tracker for tracking expenses using a linked list
class Expense_tracker{
//private data member 
private:
//pointer named expense pointing towards first node of the list
    Expense* head; 
//public
public:
//constructor to initialize head as NULL (empty list)
Expense_tracker(){
    head=NULL;
    }
//----------------------------------------------------------------------
//function of the class to add new expense at the end of the linked list
void add_expense(string date,float amount,string category){
//creating a new expense node
    Expense* new_expense=new Expense(date,amount,category);
//set head to the new node if the list is empty
    if(head==NULL){
        head=new_expense;
    } else {
//find the last node and attach the new one if the list is not empty
    Expense* last=head;
//keep moving to the next node until we reach the end
    while(last->next!=NULL){
        last=last->next;
    }
//attach the new node at the end
    last->next=new_expense;
    }
//confirm to user
    cout<<"expense added successfully"<<endl;
}
//-------------------------------------------------------------
//function to show all the expenses added by the user
void display_expenses(){
//if no expenses is entered 
    if(head== NULL){
        cout<<"no expense is entered"<<endl;
        return;
        }
//if expenses are entered
	cout<<"all expenses"<<endl;
        Expense* temp=head;
        while(temp!=NULL){
            cout<<"date="<<temp->date<<endl;
            cout<<"amount="<<temp->amount<<endl;
            cout<<"category="<<temp->category<<endl;
            temp=temp->next;
        }
    }
//function to display monthly report
void monthly_report(string month_year){
    cout<<"monthly report for"<<month_year<<endl;
    //start from the head of the list
	Expense* current=head;
	//to store total monthly expenses of the month  
    float total_monthly_expenses=0;
	//to check if we found any expense   
    bool found=false;
//loop to go through each expense
    while(current!=NULL){
		string date_month_year=current->date.substr(3,7);
//if the expense matches the required month
    if(date_month_year==month_year){
        cout<<"date="<<current->date<<endl;
        cout<<"amount="<<current->amount<<endl;
        cout<<"category="<<current->category<<endl;
        total_monthly_expenses=total_monthly_expenses+current->amount;
        found=true;
        }
//move to the next expense
        current=current->next;
    }
//f no expenses were found for the month
    if(!found){
        cout<<"no monthly expenses are found"<<endl;
    }
//final output if expense found
    cout<<"total amount spent in "<<month_year<<total_monthly_expenses<<endl;
}
//function to display weekly report
void weekly_report(string start_date,string end_date) {
        // startDate and endDate in dd-mm-yyyy format
        cout<<"weekly Report from "<<start_date<<" to "<<end_date<<endl;
        Expense* temp=head;
        float total_weekly_expenses=0;
        while(temp!=NULL){
            if(temp->date >=start_date&&temp->date<=end_date){
                cout<<"date="<<temp->date<<endl;
                cout<<"amount="<<temp->amount<<endl;
                cout<<"category= "<<temp->category<<endl;
                total_weekly_expenses=total_weekly_expenses+temp->amount;
            }
            temp=temp->next;
        }
        cout<<"total weekly expenses are"<<total_weekly_expenses<<endl;
    }
};

// ---------------- Main function ----------------
int main() {
    Expense_tracker tracker;
    int choice;
    string date;
	string category;
	string month_year;
	string start_date;
	string end_date;
    float amount;
do{
    cout<<"====== Expense Tracker Menu ======"<<endl;
    cout<<"1.Add expense"<<endl;
    cout<<"2.Show all expenses"<<endl;
    cout<<"3.Monthly report"<<endl;
    cout<<"4.Weekly report"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"enter your choice:"<<endl;
    cin>>choice;
    //to clear input buffer
	cin.ignore(); 
switch(choice){
    case 1:
        cout<<"enter date="<<endl;
        getline(cin,date);
        cout<<"enter amount="<<endl;
        cin>>amount;
        cin.ignore();
        cout<<"enter category="<<endl;
        getline(cin,category);
        tracker.add_expense(date,amount,category);
            break;
	case 2:
        tracker.display_expenses();
            break;
	case 3:
        cout<<"enter month and year="<<endl;
        getline(cin,month_year);
        tracker.monthly_report(month_year);
            break;
	case 4:
        cout<<"enter start date="<<endl;
        getline(cin,start_date);
        cout<<"enter end date="<<endl;
        getline(cin,end_date);
        tracker.weekly_report(start_date,end_date);
            break;

    case 0:
        cout<<"exiting......";
            break;
//default case
    default:
        cout<<"invalid choice==try again please=="<<endl;
        }

    } while(choice!=0);

    return 0;
}
