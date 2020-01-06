#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;


void wrap()
{
	cout << endl;
}
int getRandom(int min, int max);
void convertToRime(int totalTime);

template <typename T>
void getTime(T racers[], int numberOfRacers, int numberOfCircles, int min, int max);

template <typename T>
void getFastestCircle(T racers[], int numberOfRacers, int numberOfCircles);

template <typename T>
void getWinner(T racers[], int numberOfRacers, int numberOfCircles);

int main()
{
	srand(time(NULL));

	int numberOfRacers{}, circles{};

	cout << "Welcome to \"Racing Simulator v0.2\"!\n\n";

	cout << "_______$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n______$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n_____$$$$________________________$$$$ \n____$$$$__________________________$$$$ \n___$$$$____________________________$$$$ \n__$$$$______________________________$$$$ \n_$$$$________________________________$$$$ \n_$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$$$___$$$$$ \n$$$$$___$$$$$$$$$$$$$$$$$$$$$$$$$$___$$$$$ \n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n_$$$$$$$$$$$$_______________$$$$$$$$$$$$$ \n__$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n___$$$$$$$$____________________$$$$$$$$ \n___$$$$$$$$____________________$$$$$$$$ \n___$$$$$$$$____________________$$$$$$$$ \n" << endl;

	do
	{
		cout << "Enter your number of racers (2 - 20): ";
		cin >> numberOfRacers;
	} while (numberOfRacers < 2 || numberOfRacers > 20);

	do
	{
		cout << "Enter your number of circles (1 - 10): ";
		cin >> circles;
	} while (circles < 1 || circles > 10);

	int** racers;

	racers = new int* [numberOfRacers];
	for (int i = 0; i < numberOfRacers; i++)
	{
		racers[i] = new int[circles];
	}

	getTime(racers, numberOfRacers, circles, 51, 132);

	cout << "Racer #" << "\t";
	for (int i = 0; i < circles; i++)
	{
		cout << "Circle " << i + 1 << "\t";
	}
	cout << endl;


	for (int i = 0; i < numberOfRacers; i++)
	{
		cout << i + 1 << "\t";
		for (int j = 0; j < circles; j++)
		{
			convertToRime(racers[i][j]);
			cout << "\t";
		}
		cout << endl;
	}

	getFastestCircle(racers, numberOfRacers, circles);
	getWinner(racers, numberOfRacers, circles);

	return 0;
}

int getRandom(int min, int max)
{
	return min + rand() % (max - min);
}

template <typename T>
void getTime(T racers[], int numberOfRacers, int numberOfCircles, int min, int max)
{
	for (int i = 0; i < numberOfRacers; i++)
	{
		for (int j = 0; j < numberOfCircles; j++)
		{
			racers[i][j] = getRandom(min, max);
		}
	}
}

void convertToRime(int totalTime)
{
	int seconds, minutes, hours{};

	seconds = totalTime % 60;
	minutes = totalTime / 60;

	if (hours < 10)
	{
		cout << '0' << hours << ':';
	}
	else
	{
		cout << hours << ':';
	}

	if (minutes < 10)
	{
		cout << '0' << minutes << ':';
	}
	else
	{
		cout << minutes << ':';
	}

	if (seconds < 10)
	{
		cout << '0' << seconds;
	}
	else
	{
		cout << seconds;
	}
}

template <typename T>
void getFastestCircle(T racers[], int numberOfRacers, int numberOfCircles)
{
	int fastestCircleTime	= racers[0][0];
	int fastestCircle		= 0;
	int fastestRacer		= 0;

	for (int i = 0; i < numberOfRacers; i++)
	{
		for (int j = 0; j < numberOfCircles; j++)
		{
			if (racers[i][j] < fastestCircleTime)
			{
				fastestCircleTime = racers[i][j];
				fastestRacer = i;
				fastestCircle = j;
			}
		}
	}

	wrap();
	cout << "The fastest circle was by Racer #" << fastestRacer + 1 << " with result: ";
	convertToRime(fastestCircleTime);
	cout << " on the circle #" << fastestCircle + 1 << endl;
}

template <typename T>
void getWinner(T racers[], int numberOfRacers, int numberOfCircles)
{
	const int MAX = 999999;

	int fastestRacer = 0;
	int fastestSumTime = MAX;

	for (int i = 0; i < numberOfRacers; i++)
	{
		int sumTime{};
		for (int j = 0; j < numberOfCircles; j++)
		{
			sumTime += racers[i][j];
		}

		if (sumTime < fastestSumTime)
		{
			fastestSumTime = sumTime;
			fastestRacer = i;
		}
	}

	wrap();
	cout << "The winner is Racer #" << fastestRacer + 1 << " with overall result: ";
	convertToRime(fastestSumTime);
	wrap();
}