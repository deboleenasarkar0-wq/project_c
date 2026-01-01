# project_c
Automated Teller Machine (ATM) Simulation System 
The Automated Teller Machine (ATM) Simulation is a C based application designed to replicate the core functionalities of a modern banking terminal. The primary goal of this project is to provide a secure and efficient platform for users to perform essential financial transactions such as balance inquiries, deposits, and withdrawals.
Beyond basic operations, this simulation prioritizes system integrity and user protection through advanced logic implementation. A key feature is the Security Lockout mechanism, which safeguards accounts against unauthorized access by limiting login attempts. Furthermore, the system enforces a Maximum Transaction Limit to ensure that all withdrawals remain within safe parameters. By utilizing file handling for data persistence, the application ensures that user records are accurately maintained and updated across sessions.

Key Features:

1.Secure Authentication Logic: The system implements a robust access control mechanism requiring a valid account number and PIN for every session.

2.Security Lockout Mechanism: To prevent brute-force attacks, the system includes a login attempt counter that automatically terminates the session after three unsuccessful PIN entries.

3.Transaction Limit Validation: A mandatory validation layer ensures that every withdrawal request is checked against a predefined Maximum Transaction Limit before processing.

4.Overdraft Protection: The system performs a real-time balance check to prevent withdrawals that exceed the available funds, ensuring accounts do not go into a negative balance.

5.Persistent Data Storage: By utilizing C File I/O, all account information, including updated balances and PINs, is permanently saved and can be reloaded across different program sessions.

6.User-Friendly Command Line Interface (CLI): The application offers an intuitive menu-based interface, providing clear prompts and error messages for a seamless user experience.

The Automated Teller Machine (ATM) Simulation system project aims to protect user accounts with a security lockout mechanism and maintain financial integrity by validating transaction limits.

Tools Used: 

 Programming Language: C Language (ANSI C standard)
 
 Compiler: GNU Compiler Collection (GCC) 
 
 IDE / Editor: Code::Blocks 
 
 Operating System: Windows
 
 Version Control: GitHub 


### NOTE: The project was completed collaboratively. The GitHub repository was maintained by one member as another member is new to GitHub and version control systems.


### Project Contribution & Role Assignment:

### Deboleena Sarkar​​

1. Core Logic Implementation : Structure and Array of Structures Design. ​

2. File I/O (Data Persistence) : Implementation of load data() and save data() functions.​

3. Main Control Flow : Designing the main() function and the main menu loop.

### ​Musfika Rahman​​

1. ATM Functionality : Implementation of Deposit, Withdraw, and Check Balance functions. ​

2. User Interface : Designing the Menu and input validation logic.​

3. Testing & Debugging : Comprehensive testing of all transaction scenarios.​

​
