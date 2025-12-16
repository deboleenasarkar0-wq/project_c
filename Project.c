#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Constant
#define MAX_ACCOUNTS 100 // Maximum number of accounts
#define FILENAME "account_data.txt" // FILE Name
#define MAX_WITHDRAWAL 20000.00 // Maximum limit per transaction
// ----------------------------

//Creating Structure for Account Data
typedef struct {
    int account_number;
    int pin;
    char name[50];
    double balance;
} Account;

// Array of Structures: Array for storing all account data
Account accounts[MAX_ACCOUNTS];

// Variable for tracking the current number of accounts
int account_count = 0;

// Index of the currently logged-in account
int logged_in_index = -1;

// Function to load data from the file
void load_data() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("\n=> No data file found. New data is being created.\n");
        return; // No need to create if file does not exist
    }

    account_count = 0;
    while (fscanf(file, "%d %d %lf %s",
                  &accounts[account_count].account_number,
                  &accounts[account_count].pin,
                  &accounts[account_count].balance ,
                  accounts[account_count].name) == 4) {
                // If 4 items are successfully read
        account_count++;
        if (account_count >= MAX_ACCOUNTS)
            break;

    }
    fclose(file);

printf("\n=> %d account data loaded\n", account_count);
}

void save_data() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("\nError: File could not be saved\n"); // My translation
        return;
    }

    for (int i = 0; i < account_count;i++) {
        fprintf(file, "%d %d %.2lf%s\n",
        accounts[i].account_number,
        accounts[i].pin,
        accounts[i].balance,
        accounts[i].name);
    }
    fclose(file);
    printf("\n=> Data has been saved successfully\n");
}

// Login Function
int login() {
    int acc_no, pin;
    printf("\n--- Login ---");
    printf("\n**Enter account number:** ");
    scanf("%d", &acc_no);
    printf("*Enter PIN number:* ");
    scanf("%d", &pin);

    for (int i = 0; i < account_count; i++) {
        // Check if the entered account number AND PIN match an existing account
        if (accounts[i].account_number == acc_no && accounts[i].pin == pin) {
            logged_in_index = i; // Save index if login is successful

            // Login Successful Output
            printf("\n=> *Login Successful!*");
            printf("\n**Welcome, %s!**\n", accounts[i].name);
            return 1; // Success
        }
    }

    // Failure Output
    printf("\n**Error: Account number or PIN is wrong!**\n");
    return 0; // Failure
}

// Balance Check
void check_balance() {
    if (logged_in_index == -1)
    return;
    printf("\n--- Check Balance ---\n");
    printf("\nCurrent Balance: %.2lf Taka\n", accounts[logged_in_index].balance);
}

// Deposit Money
void deposit() {
    if (logged_in_index == -1)
    return;
    double amount;
    printf("\n--- Deposit Money ---\n");
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    if (amount > 0) {
        accounts[logged_in_index].balance += amount;
        printf("\n=> Successfully deposited %.2lf Taka. New balance: %.2lf Taka\n",
               amount, accounts[logged_in_index].balance);
        save_data(); // Save data
    } else {
        printf("\nError: The deposit amount must be positive!\n");
    }
}

void withdraw() {
    if (logged_in_index == -1)
    return;
    double amount;
    printf("\n--- Withdraw Money ---\n");
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    // Check if amount is positive AND balance is sufficient
    if (amount > 0 && amount <= accounts[logged_in_index].balance && amount <= MAX_WITHDRAWAL) {
    // ----------------------------
        accounts[logged_in_index].balance -= amount;
        printf("\n=> Successfully withdrawn %.2lf Taka. New balance: %.2lf Taka\n",amount, accounts[logged_in_index].balance);
        save_data(); // Save data
    } else if (amount > accounts[logged_in_index].balance) {
        printf("\nError: Insufficient balance!\n");
    } else if (amount > MAX_WITHDRAWAL) {
        printf("\nError: The withdrawal amount exceeds the maximum limit of %.2lf Taka.\n", MAX_WITHDRAWAL);
    // -----------------------------
    } else {
        printf("\nError: The withdrawal amount must be positive!\n");
    }
}

// Function to create a dummy account (for project startup convenience)
void create_dummy_account() {
    if (account_count == 0) {
        accounts[0].account_number = 123456;
        accounts[0].pin = 1234;
        strcpy(accounts[0].name, "Rahman");
        accounts[0].balance = 5000.00;
        account_count++;
        save_data();
        printf("\n=> A dummy account has been created (Acc: 123456, PIN: 1234)\n");
    }
}

void atm_menu() {
    int choice;
    do {
        printf("\n\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Logout / Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: check_balance();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: printf("\nLogged out.\n"); logged_in_index = -1;
                    break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    load_data();
    create_dummy_account(); // A dummy account will be created when run for the first time


    int login_attempt = 0; // Starts attempt count at 0

    // Loop continues until login is successful OR attempts reach 3
    while (login_attempt < 3) {
        if (login()) {
            // Login successful
            atm_menu();

          // --- 1. MOVED: Check for logout only AFTER atm_menu finishes ---
            if (logged_in_index == -1)
                break; // Break loop if the user logged out from the menu
            // -----------------------------------------------------------------------

        } else {
            login_attempt++;
            if (login_attempt < 3) {
                printf("\n[ALERT] Invalid PIN or Account No. You have %d attempts left.\n", 3 - login_attempt);
            }
        }

        // --- 2. REMOVED: Delete the old, misplaced break logic here ---
        // if (logged_in_index == -1) break; // <-- DELETE THIS LINE
    }

    if (login_attempt == 3) {
        printf("\n\n*** SECURITY LOCKOUT ***\n");
        printf("Too many failed attempts. Your account has been temporarily locked.\n");
    }

    printf("\nProgram terminated.\n");
    return 0;
}









