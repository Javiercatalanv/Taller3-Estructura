#include <bits/stdc++.h>
#include <queue>
#include "Product.h"
#include "TreeAbb.h"
#include "TreeAvl.h"
using namespace std;
queue<Product*> transactions;
TreeAvl transactionsTree;
//TreeAbb transactionsTreeAbb;
int amountCriteria, maxTransCriteria;

void userInterface();


void writeTransactionToFile(ofstream& file, Product* trans) { //This method saves all the transaction information in a string
    string transactionRecord = to_string(trans->getId()) + "," + to_string(trans->getSourceAccount()) + "," + to_string(trans->getDestinationAccount()) + "," + to_string(trans->getAmount()) + "," + trans->getDate() + "," + trans->getHour();
    file << transactionRecord << endl;
}

void newFile() { //This method works to create a .txt file that saves the data
    ofstream file("transactions.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    while (!transactions.empty()) {
        Product* trans = transactions.front();
        writeTransactionToFile(file, trans);
        transactions.pop();
        delete trans;
    }

    file.close();
}


void enterTransaction(){ // This method is used to enter transaction data into the system
    int id, amount = 0, sourceAccount = 0, destinationAccount = 0, option;
    string date, hour;

    id = transactions.size()+1;
    cout << "In order to enter a new transaction, please enter the required information:\n";
    cout << "Enter the source account number:\n";
    cout << "> ";
    cin >> sourceAccount;
    cout << "Now, enter the destination account you want to create the transaction for:\n";
    cout << "> ";
    cin >> destinationAccount;
    cout << "Now, Enter the date on which you make this transaction (dd/mm/aaaa):\n";
    cout << "> ";
    cin >> date;
    cout << "Now, Enter the Hour on which you make this transaction (hh:mm):\n";
    cout << "> ";
    cin >> hour;
    cout << "Now, Enter the amount to transfer:\n";
    cout << ">";
    cin >> amount;

    Product* transact = new Product(id, sourceAccount, destinationAccount, amount, date, hour);
    transactions.push(transact);
    transactionsTree.insert(transact);
    //transactionsTreeAbb.insert(transact);

    cout << "Do you want to make another transaction?\n";
    cout << "Choose an option:\n";
    cout << "1.- Yes\n";
    cout << "2.- No\n";
    cout << "> ";
    cin >> option;

while(option < 1 || option > 2) {
    cout << "You entered an invalid option, please try again.\n";
    cout << "Do you want to make another transaction?\n";
    cout << "1.- Yes\n";
    cout << "2.- No\n";
    cout << "> ";
    cin >> option;
}
    if(option == 1){enterTransaction();}
    else if(option == 2){userInterface();}
}

void searchTransaction(){ // This method is used to search for a transaction by its id
    int id;
    cout << "Enter the ID of the transaction you want to search for:\n";
    cout << "> ";
    cin >> id;
    Product* sought = transactionsTree.search(id);
    if (sought != nullptr) {
        cout << "Transaction found ID: " << sought->getId() << ", Amount: " << sought->getAmount() << ", Source Account: " << sought->getSourceAccount() << ", Destination Account: " << sought->getDestinationAccount() << "\n";
    } else {
        cout << "Transaction not found.\n";
    }
}

void searchSuspiciousTransactions(){
    //I have to make this with ABB Tree
}

void suspiciousTransactionsCriteria(){ // This method is used to determine the criteria for which it is considered suspicious
    cout << "In order to select suspicious transaction criteria, please select a maximum amount to transfer in one day:\n";
    cout << "> ";
    cin >> amountCriteria;
    cout << "now declares the maximum number of transfers before they are considered suspicious.\n";
    cout << "> ";
    cin >> maxTransCriteria;
}

void generateReports() {

}

void close(){ // This method is used to terminate the program
    cout << "Good Bye!\n";
    newFile();
    //generateReports();
}

void userInterface(){ // This method is used to display the menu on the screen and access the corresponding method
    int x ;

    while(x < 1 || x > 5 ){
        cout << "To continue, please choose an option:\n";
        cout << "1. Enter Transaction.\n";
        cout << "2. Search Transaction.\n";
        cout << "3. Search Suspicious Transaction History.\n";
        cout << "4. Define Criteria For Suspicious Transactions.\n";
        cout << "5. Close.\n";
        cout << "> ";
        cin >> x;
    }

    if( x == 1){enterTransaction();}
    else if(x == 2){searchTransaction();userInterface();}
    else if(x == 3){searchSuspiciousTransactions();userInterface();}
    else if(x == 4){suspiciousTransactionsCriteria();userInterface();}
    else if(x == 5){close();}
}

int main(){ //This method is the main one, which basically allows you to call the method selection menu.
    cout << "Welcome to the Bank" << endl;
    userInterface();
}