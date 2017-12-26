/* atm.h
 * 
 * Header file for the ATM program
 */

/*
 * Define some constants to use below in our comparisons and assignments
 */
#define MAXACCTS	50

/*
 * Define the basic information about a bank account
 */
struct account {
	char	first_name[16];
	char	last_name[21];
	int		acct_number;
	int		pin;
	float	balance;
};
