// File name: program4.cpp
// Author: Tommy Ong
// Student ID: M726Z836
// Assignment Number: 4
// Description: Vending machine
// Last Changed: February 23rd, 2016

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

int menu(void)
{
	char snack;
	int value = 0;

	cout << "Available snacks to select from:" << endl;
	cout << "P - Potato Chips  " << setw(10) << "$1.25" << endl;
	cout << "S - Snickers Bar  " << setw(10) << "$1.35" << endl;
	cout << "T - Pop Tart      " << setw(10) << "$0.95" << endl;
	cout << "C - Cookies       " << setw(10) << "$1.50" << endl;
	cout << "B - Brownie       " << setw(10) << "$1.75" << endl;
	cout << "N - Nuts          " << setw(10) << "$1.40" << endl;

	// TODO: Fix this. Inf loop rn
	do{
		cout << "Please enter the letter labeling your snack selection: ";
		cin >> snack;

		switch (snack){
			case 'p':	value = 125;	break;
			case 's':	value = 135;	break;
			case 't':	value = 95;		break;
			case 'c':	value = 150;	break;
			case 'b':	value = 175;	break;
			case 'n':	value = 140;	break;		
			default: cout << "Invalid selection!" << endl; value = 0; break;
		}
	} while ( value == 0 );

	return value;
}

int accept_money(int price){
	int current = 0;
	char c;
	while(current < price){
		cout << endl << "You selected snack item cost: " << price << " CENTS" << endl 
			 << "Your total inserted         : " <<  current << " CENTS" << endl
			 << "Enter amount (enter letter of choice): ";
		cin >> c;

		switch (c){
			case 'n': case 'N':	current += 5;	break;
			case 'q': case 'Q':	current += 25;	break;
			case 'd': case 'D': current += 100;	break;
			default: cout << endl << c << " is not recognized as a coin." << endl;
		}
	}
	return current;
}

int compute_change(int total_paid, int total_price){
	return total_paid - total_price;
}



int main(void)
{
	int price, change, total_paid = 0;
	char c;

	do{
		price = menu();

		cout << endl << "Money accepted by the machine:" << endl
			<< "   N - Nickel" << endl
			<< "   Q - Quarter" << endl
			<< "   D - The D" << endl;

		total_paid = accept_money(price);
		change = compute_change(total_paid, price);
		
		cout << endl << "Your total inserted: " << total_paid << " CENTS" << endl
			 << "Dispensing change:   " << change << " CENTS" << endl;

		cout << endl << "Would you like to make another purchase (Y/N): ";
		cin >> c;
		cout << endl;
		switch(c){
			case 'y': case 'Y': price = -1; break;
			default: price = -2; cout << "Thank you and enjoy your purchase!" << endl; break;
		}
	} while ( price == -1 );
	return (0);
}
