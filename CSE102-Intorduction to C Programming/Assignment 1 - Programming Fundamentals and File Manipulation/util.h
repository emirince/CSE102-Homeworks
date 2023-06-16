#ifndef _UTIL_H_
#define _UTIL_H_

int find_divisible(int x,int y,int z);

int find_nth_divisible(int n,int f_i,int z);

int validate_identify_number(char identify_number[]);

int create_customer(char identify_number[],int password);

int check_login(char identify_number[],int password);	

int withdrawable_amount(float cash_amount);

#endif /* _UTIL_H_ */
