#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int getRandom(int min, int max);
int getCapital(int *investments, int numberOfInvestors);
double getInvestorsProfit(int years, int typeOfProfit, int investedMoney, int companyPercent);
double getCompanyProfit(int years, int capital, int typeOfProfit, int companyPercent);

int main()
{
	int numberOfInvestors, numberOfYears, totalCapital;
	
	do
	{
		system("cls");
		cout << "Enter your number of investors (max: 240): ";
		cin >> numberOfInvestors;
	} while (numberOfInvestors > 240 || numberOfInvestors < 0);

	int* investors = new int[numberOfInvestors];

	for (int i = 0; i < numberOfInvestors; i++)
	{
		investors[i] = getRandom(50, 200);
	}


	for (int i = 0; i < numberOfInvestors; i++)
	{
		cout << "Investor #" << i + 1 << "\t invested \t" << investors[i] << '$' << endl;
	}

	totalCapital = getCapital(investors, numberOfInvestors);
	cout << endl << "Total company capital is: " << totalCapital << '$' << endl;
	cout << endl;

	do
	{
		cout << "Enter your number of working years: ";
		cin >> numberOfYears;
	} while (numberOfYears < 0);

	if (numberOfInvestors > 100)
	{
		int companyPercent = 30;

		cout << "For all years your company can gain: " << fixed << setprecision(2) << getCompanyProfit(numberOfYears, totalCapital, 3, companyPercent) << '$' << " of profit" << endl;
		cout << endl;

		for (int i = 0; i < numberOfInvestors; i++)
		{
			cout << "Investor #" << i + 1 << "\t cans gain \t" << fixed << setprecision(2) << getInvestorsProfit(numberOfYears, 3, investors[i], companyPercent) << '$' << endl;
		}

	}
	else if (numberOfInvestors > 50)
	{
		int companyPercent = 50;

		cout << "For all years your company can gain: " << fixed << setprecision(2) << getCompanyProfit(numberOfYears, totalCapital, 2, companyPercent) << '$' << " of profit" << endl;

		cout << endl;
		for (int i = 0; i < numberOfInvestors; i++)
		{
			cout <<  "Investor #" << i + 1 << "\t cans gain \t" << fixed << setprecision(2) << getInvestorsProfit(numberOfYears, 2, investors[i], companyPercent) << '$' << endl;
		}
	}
	else if (numberOfInvestors > 10)
	{
		int companyPercent = 60;

		cout << "For all years your company can gain: " << fixed << setprecision(2) << getCompanyProfit(numberOfYears, totalCapital, 1, companyPercent) << '$' << " of profit" << endl;
		cout << endl;

		for (int i = 0; i < numberOfInvestors; i++)
		{
			cout << "Investor #" << i + 1 << "\t cans gain \t" << fixed << setprecision(2) <<  getInvestorsProfit(numberOfYears, 1, investors[i], companyPercent) << '$' << endl;
		}
	}
	else 
	{
		cout << "Company couldn`t starting :(";
		return 101;
	}

	system("pause");
	return 0;
}

int getCapital(int* investments, int numberOfInvestors)
{
	int capital{};

	for (int i = 0; i < numberOfInvestors; i++)
	{
		capital += investments[i];
	}

	return capital;
}

double getInvestorsProfit(int years, int typeOfProfit, int investedMoney, int companyPercent)
{
	double totalProfit = (double)investedMoney - (double)investedMoney / 100.00 * (double)companyPercent;

	switch (typeOfProfit)
	{
		case 1:
		{
			int percentOfProfit = 12;

			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * percentOfProfit;
			}

			break;
		}
		case 2:
		{
			int percentOfProfit = 14;

			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * percentOfProfit;
			}

			break;
		}
		case 3:
		{
			int percentOfProfit = 17;

			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * percentOfProfit;
			}

			break;
		}
		default:
		{
			return 1;
			break;
		}
	}

	return totalProfit - investedMoney;
}

double getCompanyProfit(int years, int capital, int typeOfProfit, int companyPercent)
{
	int averageCompanyProfit = 5;
	double totalProfit = (double)capital / 100.00 * (double)companyPercent;

	switch (typeOfProfit)
	{
		case 1:
		{
			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * averageCompanyProfit;
			}

			break;
		}
		case 2:
		{
			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * averageCompanyProfit;
			}

			break;
		}
		case 3:
		{
			for (int i = 0; i < years; i++)
			{
				totalProfit += totalProfit / 100 * averageCompanyProfit;
			}

			break;
		}
		default:
		{

			break;
		}
	}

	return totalProfit;
}

int getRandom(int min, int max)
{
	return min + rand() % (max - min);
}