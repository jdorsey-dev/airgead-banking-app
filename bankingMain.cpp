#include <iostream>
#include <string>
#include "banking.h"

using namespace std;

/*
 * Gets a double value greater than or equal to the minimum value.
 */
double getDouble(double lowest, string prompt)
{
    double number = 0;
    bool needData = true;

    do
    {
        cout << prompt << " Must be greater than or equal to " << lowest << ": ";
        cin >> number;

        needData = (number < lowest);

        if (needData)
        {
            cout << "Invalid number - must be greater than or equal to " << lowest << endl;
        }

    } while (needData);

    return number;
}

/*
 * Gets an integer value greater than or equal to the minimum value.
 */
int getInteger(int lowest, string prompt)
{
    int number = 0;
    bool needData = true;

    do
    {
        cout << prompt << " Must be greater than or equal to " << lowest << ": ";
        cin >> number;

        needData = (number < lowest);

        if (needData)
        {
            cout << "Invalid number - must be greater than or equal to " << lowest << endl;
        }

    } while (needData);

    return number;
}

int main() {
    Banking airBanking;
    char choice;

    do
    {
        // input header
        cout << "**********************************" << endl;
        cout << "********** Data Input ************" << endl;

        // input selection
        double initialInvestment = getDouble(1, "Initial Investment Amount: ");
        airBanking.setInitialInvestment(initialInvestment);

        double monthlyDeposit = getDouble(0, "Monthly Deposit: ");
        airBanking.setMonthlyDeposit(monthlyDeposit);

        double interestRate = getDouble(1, "Annual Interest (%): ");
        interestRate *= 0.01;
        airBanking.setInterestRate(interestRate);

        int years = getInteger(1, "Number of years: ");
        airBanking.setNumYears(years);

        // displays entered values
        cout << "**********************************" << endl;
        cout << "********** Data Input ************" << endl;

        cout << "Initial Investment Amount: $" << initialInvestment << endl;
        cout << "Monthly Deposit: $" << monthlyDeposit << endl;
        cout << "Annual Interest: %" << interestRate * 100 << endl;
        cout << "Number of years: " << years << endl;
        
        //ask user to continue
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();


        //display reports
        airBanking.displayWithoutDeposits();
        airBanking.displayWithDeposits();

        // continue confirmation
        cout << endl;
        cout << "Would you like to continue? (y/n): ";

        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}