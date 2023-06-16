#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Person {
  char name[50];
  char address[50];
  int phone;
};

union Loan {
  float amount;
  float interestRate;
  int period;
};

typedef struct BankAccount {
  union Person Customer;
  union Loan Loans[3];
}
bank;

float calculateLoan(float amount, float rate, int period);
int checkID(int customer, int customersID[], int i);
int whichLoan(int customer, bank * account);
int doesFileExists(char * filename);

void listCustomers(bank * account, int i) {             //It prints the customer menu
  int a;
  for (a = 0; a < i; a++) {
    printf("Customer ID = %d\n", a + 1);
    printf("Customer Name = %s\n\n", account[a].Customer.name);
  }
}

void addCustomer(bank * account, int i, int customersID[], int customerNumber) {

  char customerAdress[50];
  int phoneNumber;
  FILE * txt;

  txt = fopen("customer.txt", "a");             //It prints the customer menu to the customer.txt
  fprintf(txt, "%d ", customerNumber);
  fflush(stdin);
  printf("Customer Name = ");
  scanf(" %[^\n]%*c", account[i].Customer.name);
  fprintf(txt, "%s ", account[i].Customer.name);
  printf("Customer Address = ");
  scanf(" %[^\n]%*c", customerAdress);
  fprintf(txt, "%s ", customerAdress);
  printf("Customer Phone = ");
  scanf("%d", & phoneNumber);
  fprintf(txt, "%d\n", phoneNumber);
  fclose(txt);

}

void newLoan(bank * account, int i, int customersID[]) {

  int customer, period, a, check = 0, idCheck;          
  float amount, rate, loan;

  if (i != 0) {

    for (a = 0; a < i; a++) {
      printf("Customer ID = %d\n", customersID[a]);
      printf("Customer Name = %s\n", account[a].Customer.name);
    }

    printf("Please enter the customers's id that you want to make application = ");
    scanf("%d", & customer);

    idCheck = checkID(customer, customersID, i);        //It sends to the function if customer exits or not

    while (idCheck == 0) {
      printf("Invalid customer id. Try again = ");
      scanf("%d", & customer);
      idCheck = checkID(customer, customersID, i);

    }

    int returnValue = whichLoan(customer, account);

    if (returnValue == -1) {
      printf("A customer can have max 3 loans\n");
    } else {

      printf("Please enter the loan amount = ");
      scanf("%f", & amount);
      while (amount <= 0) {                                 //This part doesn't allow you to input some unvalid inputs
        printf("Please enter a positive number = ");
        scanf("%f", & amount);
      }

      printf("Please enter the interest rate = ");
      scanf("%f", & rate);
      while (rate <= 0) {
        printf("Please enter a positive number = ");
        scanf("%f", & rate);
      }

      rate = rate / 100;

      printf("Please enter period of payment = ");
      scanf("%d", & account[customer - 1].Loans[returnValue].period);
      while (account[customer - 1].Loans[returnValue].period <= 0) {
        printf("Please enter a positive number = ");
        scanf("%d", & account[customer - 1].Loans[returnValue].period);
      }

      loan = calculateLoan(amount, rate, account[customer - 1].Loans[returnValue].period);

      FILE * txt;
      txt = fopen("loan.txt", "a");
      fprintf(txt, "%d ", customersID[customer - 1]);       //It prints the loan details to the loan.txt
      fprintf(txt, "%f\n", loan);
      fclose(txt);
      printf("\nloan = %f\n", loan);
    }

  } else {
    printf("You must add mew customer to make new loan application!\n\n\n");
  }

}

int whichLoan(int customer, bank * account) {

  int i;

  for (i = 0; i < 3; i++) { 
    if (account[customer - 1].Loans[i].amount > 0) {}       //This function detects which loan should used
    else {
      return i;
    }
  }
  return -1;
}

int checkID(int customer, int customersID[], int i) {
  int a;

  for (a = 0; a < i; a++) {
    if (customersID[a] == customer) {
      return 1;
    }
  }
  return 0;
}

float calculateLoan(float amount, float rate, int period) {        //This calculates the loan 
  int a = 0;
  static float x = 1;
  float loan;
  if (a != period) {
    x = x * (1 + rate);
    calculateLoan(amount, rate, period - 1);
  } else {
    loan = amount * x;
    return loan;
  }
}

void getReport(bank * account, int i, int customersID[]) {

  int a, id, loan = 0, customerID, phone, selectLoan, reportMenu, fileExits, loanExists, userId, x;
  char address[100], array[200], name[100];
  float number, loan1, loan2, loan3, selectedLoan;
  FILE * customerTxt;
  FILE * loanTxt;

  printf("1. Customer Details\n");
  printf("2. Loan Details\n");
  printf("Please select from the menu = ");
  scanf("%d", & reportMenu);

  while (reportMenu != 1 && reportMenu != 2) {
    printf("Invalid entry. Please try again = ");
    scanf("%d", & reportMenu);
  }

  if (reportMenu == 1) {

    for (a = 0; a < i; a++) {
      printf("Customer ID = %d\n", customersID[a]);
      printf("Customer Name = %s\n", account[a].Customer.name);
    }

    printf("Please enter the customers id that you want to get report = ");
    scanf("%d", & userId);

    loanExists = account[userId - 1].Loans[0].period;   //By this value, we check if the loan.txt is created or not

    if (loanExists == 0) {

      customerTxt = fopen("customer.txt", "r");

      while (!feof(customerTxt)) {
        fscanf(customerTxt, "%d %s %s %d", & id, name, address, & phone);
        if (userId == id) {
          printf("Customer ID = %d\n", userId);
          printf("Customer Name = %s\n", name);
          printf("Customer Adress = %s\n", address);
          printf("Customer Phone = %d\n", phone);
          break;
        }
      }
      fclose(customerTxt);
    } else {

      loanTxt = fopen("loan.txt", "r");
      customerTxt = fopen("customer.txt", "r");

      while (!feof(customerTxt)) {
        fscanf(customerTxt, "%d %s %s %d", & id, name, address, & phone);
        if (userId == id) {

          printf("Customer ID = %d\n", userId);         //we print the scanned values from customer.txt
          printf("Customer Name = %s\n", name);
          printf("Customer Adress = %s\n", address);
          printf("Customer Phone = %d\n", phone);
        }

        while (!feof(loanTxt)) {
          fscanf(loanTxt, " %f", & number);
          if (number == id) {
            fscanf(loanTxt, " %f", & number);

            if (number != 0) {
              loan++;
            }
            if (loan == 1) {
              loan1 = number;
            } else if (loan == 2) {
              loan2 = number;
            } else if (loan == 3) {
              loan3 = number;
            }
          }
        }
        fclose(loanTxt);
        fclose(customerTxt);
      }

      if (loan != 0) {          //we print the loans like requested in the pdf
        if (loan == 1) {
          printf("[%f] => %f\n", loan1, loan1);
        }
        if (loan == 2) {
          printf("[%f + %f] => %f\n", loan1, loan2, loan1 + loan2);
        }
        if (loan == 3) {
          printf("[%f + %f + %f] => %f\n", loan1, loan2, loan3, loan1 + loan2 + loan3);
        }
      }
    }
  }

  if (reportMenu == 2) {

    for (a = 0; a < i; a++) {
      printf("Customer ID = %d\n", customersID[a]);
      printf("Customer Name = %s\n", account[a].Customer.name);
    }

    printf("Please enter the customers id that you want to get report = ");
    scanf("%d", & userId);

    loanExists = account[userId - 1].Loans[0].period;

    if (loanExists != 0) {

      loanTxt = fopen("loan.txt", "r");

      while (!feof(loanTxt)) {
        fscanf(loanTxt, " %f", & number);
        if (number == id) {
          fscanf(loanTxt, " %f", & number);

          if (number != 0) {
            loan++;
          }

          if (loan == 1) {
            loan1 = number;
          } else if (loan == 2) {
            loan2 = number;
          } else if (loan == 3) {
            loan3 = number;
          }
        }

      }

      fclose(loanTxt);

      if (loan != 0) {

        if (loan == 1) {
          printf("Loans\nLoan 1 = %f\n", loan1);
        } else if (loan == 2) {
          printf("Loans\nLoan 1 = %f\nLoan 2 = %f\n", loan1, loan2);
        } else if (loan == 3) {
          printf("Loans\nLoan 1 = %f\nLoan 2 = %f\nLoans 3 = %f\n", loan1, loan2, loan3);
        }

        printf("Please enter the loan you want to see details = ");
        scanf("%d", & selectLoan);

        if (selectLoan == 1) {
          selectedLoan = loan1;
        } else if (selectLoan == 2) {
          selectedLoan = loan2;
        } else if (selectLoan == 3) {
          selectedLoan = loan3;
        }

        int loanLength = account[id - 1].Loans[selectLoan - 1].period;

        printf("Total Credit Value = %f\n", selectedLoan);
        float montlyPayment = selectedLoan / loanLength;
                                                                    //we print the montly payment and total loan value
        for (i = 1; i <= loanLength; i++) {

          printf("%d. Montly Installment = %f\n", i, montlyPayment);
        }
      }
    } else {
      printf("You haven't applied for a loan yet.\n");
    }
  }

}
int main() {

  bank * account = (bank * ) malloc(50 * sizeof(bank));
  int userCount, customer;
  int menu, i = 0, a;
  int period;
  float amount, rate;
  int phoneNumber;
  char customerAdress[100];
  int customersID[50];
  int customerNumber = 0;

  FILE * txt;
  do {
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");
    printf("Welcome to the Bank Management System\n");
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");
    printf("    1. List All Customers\n");
    printf("    2. Add New Customers\n");
    printf("    3. New Loan Application\n");
    printf("    4. Report Menu\n");
    printf("    5. Exit System\n");

    scanf("%d", & menu);

    switch (menu) {

    case 1:

      listCustomers(account, i);

      break;

    case 2:

      customerNumber++;
      customersID[i] = customerNumber;
      addCustomer(account, i, customersID, customerNumber);
      i++;

      break;

    case 3:

      if (i != 0) {
        newLoan(account, i, customersID);
      } else {
        printf("You must add mew customer to make new loan application!\n\n\n");
      }
      break;

    case 4:

      getReport(account, i, customersID);

      break;

    case 5:

      break;

    default:
      printf("Wrong entry\n");
      break;
    }
  } while (menu != 5);

}