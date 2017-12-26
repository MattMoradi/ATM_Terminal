# ATM_Terminal
This is a basic Command Line ATM for your terminal. It is capable of performing ATM based operations and calculations and tracking account information. Please check the Account_PINS file for authentication access. This project was developed using the CodeBlocks IDE. Some of the ATM-IPO program logic is included below.

```xml
Input       Proccess        Output
=========   =============   =================
top_loop
                            Welcome message
acct_loop:
                            Please enter your account number
acct_num                    Please enter your PIN
pin         Verify that acct
            and PIN are in the
            bank data       F: Invalid account or PIN
            Go to acct_loop
                            T: Welcome name
                            display menu of commands
                                Balance
                                Deposit
                                Withdrawl
                                Exit
                                Your Choice?

txn_code    B:
            get balance         Your balance is $100

            D:                  How much?
amount      balance += amount   Your new balance is $200

            W:                  How much?
amount      balance -= amount   Your new balance is $100

            E:                  Thanks for using the ATM machine
            close the account
            go to top_loop
