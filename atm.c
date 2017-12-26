#include <stdio.h>	// This defines the standard IO functions
#include <stdlib.h>	// atoi
#include "atm.h"	// This defines the account structure

struct	account accounts[MAXACCTS];	// Array of account structures

/*
 * Declare functions used in the program.
 * This is REQUIRED for functions which return non-integer values.
 */
int	load_account_data();
int	print_account_data();
struct account *verify_account_data(struct account *acct, int acct_in, int pin_in);

char clear_cmd[] = "cls";				// Screen clear, Windows=cls, Mac/Linux=clear

// This is the entry point for the atm program.
int main()
{
	// Declare local variables
	char	input[20];			// data from the keyboard
	int		acct_in;			// account number from user
	int		pin_in;				// pin from user
	struct	account *my_acct;	// acct row from accounts structure
	int		keep_going;			// flag - keep the loops going

	// 1) Call load_account_data with the structure to load
	load_account_data(accounts);
	for (;;) {		// people loop
		printf("Welcome to the ATM machine\n");
		for (keep_going = 1; keep_going;) {	// account/pin loop
			printf("Please enter your account number: ");
			fgets(input, sizeof(input), stdin);
			acct_in = atoi(input);
			// If you want to exit, do it
			if (input[0] == 'e')	return 1;
			printf("Please enter your PIN: ");
			fgets(input, sizeof(input), stdin);
			pin_in = atoi(input);
			// If you want to exit, do it
			if (input[0] == 'e')	return 1;
			// Does the imput account and pin match the bank data?
			my_acct = verify_account_data(accounts, acct_in, pin_in);
			if (my_acct == NULL) {
				printf("Invalid account or PIN\n");
			} else {
				for (;keep_going;) {	// transaction loop
					printf("Welcome %s %s\n", my_acct->first_name, my_acct->last_name);
					printf("The following transactions are available:\n");
					printf("\tB = show Balance\n");
					printf("\tD = Deposit funds\n");
					printf("\tW = Withdraw funds\n");
					printf("\tE = Exit the ATM machine\n");
					printf("Your choice: ");
					fgets(input, sizeof(input), stdin);
					switch(input[0]) {
					case 'b':	// show balance
								printf("Your balance is $%.2f\n", my_acct->balance);
								break;
					case 'd':	// deposit funds
								printf("deposit funds\n");
								break;
					case 'w':	// withdraw funds
								printf("withdraw funds\n");
								break;
					case 'e':	// Exit
								printf("Exit the ATM machine\n");
								keep_going = 0;
								break;
					default:	printf("Invalid transaction '%c'\n", input[0]);
					}	// switch
				}	// transaction loop
			}	// else clause
		}	// account/pin loop
	}	// people loop
}	// main()

/*
 * Read in the accounts.data file into a structure
 * which is passed in as an argument.
 */
int load_account_data(struct account *acct)
{
	// Declare local variables
	int		fields;
	FILE	*file_in;

	// Open the data file
	file_in = fopen("accounts.data", "r");
	// loop through all the records
	for (;;acct++) 	{
		// Read one record into variables
		fields = fscanf(file_in, "%s %s %d %d %f",
				acct->last_name, acct->first_name,
				&acct->acct_number, &acct->pin, &acct->balance);
		// When we find EOF, break out of the loop
		if (fields == EOF)	break;
	}	// for
	// mark End of Data
	acct->pin = 0;
	// Close the data file
	fclose(file_in);
	// Return to the calling function
	return 0;
}	// load_account_data()

/*
 * Print all the data in the account structure
 * which is passed in as an argument.
 */
int print_account_data(struct account *acct)
{
	// loop through all the records
	for (;acct->pin != 0; acct++) {
		// Read one record into variables
		fprintf(stdout, "%s %s %d %d %.2f\n",
				acct->last_name, acct->first_name,
				acct->acct_number, acct->pin, acct->balance);
	}	// for
	// Return to the calling function
	return 0;
}	// print_account_data()

/*
 * Verify that the input account and PIN are in the bank data.
 * For a match return the record pointer
 * For an error return NULL
 */
struct account *verify_account_data(struct account *acct, int acct_in, int pin_in)
{
	// loop through all the records
	for (;acct->pin != 0; acct++) {
		// If the account and pin match the bank data,
		if (acct->acct_number == acct_in &&
			acct->pin == pin_in)	return acct;
	}	// for
	// Return an error to the calling function
	return NULL;
}	// verify_account_data()
