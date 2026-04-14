#include "banking.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

/*
 * Default constructor to set all values to zero.
 */
Banking::Banking()
{
    InitialInvestment = 0;
    MonthlyDeposit = 0;
    InterestRate = 0;
    NumYears = 0;
}

/*
 * Sets the initial investment amount from the user.
 */
void Banking::setInitialInvestment(double initialInvestment)
{
    this->InitialInvestment = initialInvestment;
}

/*
 * Sets the monthly deposit amount.
 */
void Banking::setMonthlyDeposit(double monthlyDeposit)
{
    this->MonthlyDeposit = monthlyDeposit;
}

/*
 * Sets the annual interest rate.
 */
void Banking::setInterestRate(double interestRate)
{
    this->InterestRate = interestRate;
}

/*
 * Sets the number of years for the investment.
 */
void Banking::setNumYears(int numYears)
{
    this->NumYears = numYears;
}

/*
 * Displays the investment growth without additional monthly deposits.
 */
void Banking::displayWithoutDeposits() const
{
    cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Start with initial investment
    double currentBalance = InitialInvestment;

    for (int year = 1; year <= NumYears; ++year)
    {
        double yearlyInterest = 0;

        // Apply monthly compound interest (12 times per year)
        for (int month = 1; month <= 12; ++month)
        {
            double interest = currentBalance * (InterestRate / 12);

            currentBalance += interest;
            yearlyInterest += interest;
        }

        // printing and formatting
        ostringstream balance;
        ostringstream interest;

        balance << fixed << setprecision(2) << "$" << currentBalance;
        interest << fixed << setprecision(2) << "$" << yearlyInterest;

        cout << left << setw(6) << year << "  ";

        cout << setw(20) << left << balance.str();
        cout << setw(27) << right << interest.str();

        cout << endl;
    }
}

/*
 * Displays the investment growth with additional monthly deposits.
 */
void Banking::displayWithDeposits() const
{
    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "--------------------------------------------------------" << endl;

    // Start with initial investment
    double currentBalance = InitialInvestment;

    for (int year = 1; year <= NumYears; ++year)
    {
        double yearlyInterest = 0;

        // Apply monthly deposits + compound interest
        for (int month = 1; month <= 12; ++month)
        {
            currentBalance += MonthlyDeposit;

            double interest = currentBalance * (InterestRate / 12);

            currentBalance += interest;
            yearlyInterest += interest;
        }

        // printing and formatting
        ostringstream balance;
        ostringstream interest;

        balance << fixed << setprecision(2) << "$" << currentBalance;
        interest << fixed << setprecision(2) << "$" << yearlyInterest;

        cout << left << setw(6) << year << "  ";
        cout << setw(20) << left << balance.str();
        cout << setw(27) << right << interest.str();

        cout << endl;
    }
}