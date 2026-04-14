#ifndef BANKING_H
#define BANKING_H

// Banking class handles investment data and calculations
class Banking
{

private:
	// private member variables
	double InitialInvestment;
	double MonthlyDeposit;
	double InterestRate;
	int NumYears;

public:
	// Constructor and public methods
	Banking();

	void setInitialInvestment(double initialInvestment);
	void setMonthlyDeposit(double monthlyDeposit);
	void setInterestRate(double interestRate);
	void setNumYears(int numYears);

	void displayWithoutDeposits() const;
	void displayWithDeposits() const;
};

#endif