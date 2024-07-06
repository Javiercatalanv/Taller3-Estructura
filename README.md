# Taller3-Estructura

Javier Alonso Catalán Vargas ; 21.445.807-1 ; javier.catalan01@alumnos.ucn.cl

# Objetos Creados en el Main:

Product : {id : (se genera automaticamente) , sourceAccount: "214820", destinationAccount: "216540", amount: "50000", date:"11/10/2023", hour: "22:10"}

Product : {id : (se genera automaticamente) , sourceAccount: "225681", destinationAccount: "185203", amount: "2500", date:"20/05/2015", hour: "05:05"}

Product : {id : (se genera automaticamente) , sourceAccount: "204785", destinationAccount: "356801", amount: "30000", date:"03/12/2003", hour: "12:30"}

# Objetos Creados en el Main:

void writeTransactionToFile(ofstream& file, Product* trans) : This method saves all the transaction information in a string

void newFile() : This method works to create a .txt file that saves the data

void enterTransaction() : This method is used to enter transaction data into the system

void searchTransaction() : This method is used to search for a transaction by its id

void suspiciousTransactionsCriteria() : This method is used to determine the criteria for which it is considered suspicious

void close() : This method is used to terminate the program

void userInterface() : This method is used to display the menu on the screen and access the corresponding method

int main() : This method is the main one, which basically allows you to call the method selection menu.

void generateReports() : This method generates a report of the suspicious transactions that enter the filter that was filled out in the suspicious criteria capsule.

void searchSuspiciousTransactions() : This method searches for suspicious transactions that enter the filter that was filled out in the suspicious criteria capsule.
