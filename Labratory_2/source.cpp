#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <fstream>
#include<string>
using namespace std;
void Checkn(int n)
{
	if (n < 4)
	{
		throw "Input correct data";
	}
}
void calcRange(double a, double b, int t, int n)
{
	double seq, sum;
	seq = 1;
	if (a <= 0)
	{
		sum = 0;
		while (a <= b)
		{
			for (double i = 0; i <= (n - 1); i++)
			{

				for (double j = 0; j <= (n - 1); j++)
				{
					double y;
					y = 0;
					if ((a - i - j) != 0)
					{
						y = 1 / (a - i - j);
					}
					else
					{
						cout << "Incorrect input(Devision by zero)";
						system("pause");
					}

					sum += y;

					a = a + t;
				}
				cout << "Value of x" << seq << "=" << a - t << "          " << "Value of y" << seq << "=" << sum << endl;
				seq++;
			}
		}
	}

	else {

		while (a <= b)
		{
			sum = 1;

			for (double i = 1; i <= n; i++)
			{
				double y = 0;
				if (a != 0 && i != 0)
				{
					y = (1 / a) - (1 / i);
				}
				else
				{
					cout << "Incorrect input(Devision by zero)";
					system("pause");
				}
				sum = sum * y;
			}

			cout << "Value of x" << seq << "=" << a << "          " << "Value of y" << seq << "=" << sum << endl;
			a = a + t;
			seq++;
		}
	}

}
bool correctData(std::ifstream &file, std::string filename)
{
	size_t count = 0;
	char ch;
	while (file >> ch)
	{
		if (ch != '.')
		if (!isdigit(ch)) count++;
	}
	if (count) return false;
	else
		return true;

}
void input(const char * prompt, int& var)
{
	for (;;)
	{
		std::cout << prompt << std::flush;
		if ((std::cin >> var).good()) return;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Wrong input, try again\n";
		}
		std::cin.ignore(std::numeric_limits<std::size_t>::max(), '\n');
	}
}
double calc(double x, double n)
{
	double sum = 0;
	if (x <= 0)
	{

		for (double i = 0; i <= (n - 1); i++)
		{

			for (double j = 0; j <= (n - 1); j++)
			{
				double y;
				y = 0;
				if ((x - i - j) != 0)
				{


					y = 1 / (x - i - j);
					sum += y;
				}
				else{
					cout << "Incorrect input(Devision by zero)";
									}
			}


		}
	}

	else
	{
		sum++;
		double y = 0;
		for (double i = 1; i <= n; i++)
		{
			if (x != 0 && i != 0)
			{
				y = (1 / x) - (1 / i);
				sum *= y;
			}
			else {
				cout << "Incorrect input(Devision by zero)";
				system("pause");
			}
		}
	}
	return sum;
}

void main(){
	ifstream indata;
	int selection, selection2, a, b, x, n, t;
	x = 1;
	n = 1;
	input("Type of input:\n1-From keyboard\n2-From file\n", selection);
	switch (selection)
	{
	default:
		cout << "Incorret input, restart and try again\n";
		system("pause");
		exit(1);
	case 1:
		
		input("1-Calculate for one X\n2-Calculate for a range\n", selection2);
		switch (selection2)
		{
		default:
			cout << "Incorret input, restart and try again\n";
			system("pause");
			exit(1);
		case 1:
			input("Input X\n", x);
			input("Input limit\n", n);
			while (n <= 0)
			{
				cout << "Incorrect limit\n";
				input("Input limit\n", n);
			}
			cout << "Result" << calc(x, n) << endl;
			break;
		case 2:
			input("Input limits A\n", a);
			input("Input limits B\n", b);

			input("Input size of step\n", t);
			while (t <= 0)
			{
				cout << "Error input, Step must be > 0\n";
				input("Input size of step\n", t);
			}
			input("Input limit\n", n);
			while (n <= 0)
			{
				cout << "Incorrect limit\n";
				input("Input limit\n", n);
			}
			calcRange(a, b, t, n);
			break;

		}
		break;

	case 2:
		input("1-Calculate for one X\n2-Calculate for a range\n", selection2);
		switch (selection2)
		{
		default:
			cout << "Incorret input, restart and try again\n";
			system("pause");
			exit(1);
		case 1:

			indata.open("test.txt");
			if (!indata.is_open())
				cout << "CAN'T OPEN FILE, INCORRECT FILE NAME OR PATH/n";
			else
			{
				if (!correctData(indata, "test.txt"))
				{
					std::cout << "The file  contains invalid characters\n";
					system("pause");
					exit(1);
				}
				else
				{
					indata >> x;
					indata >> n;

				}

			}

			break;
		case 2:

			indata.open("test.txt");
			if (!indata.is_open())
				cout << "CAN'T OPEN FILE, INCORRECT FILE NAME OR PATH/n";
			else
			{
				if (!correctData(indata, "test.txt"))
				{
					std::cout << "The file  contains invalid characters\n";
					system("pause");
					exit(1);
				}
				else
				{
					indata >> a;
					indata >> b;
					indata >> t;
					indata >> n;

				}

			}

			break;

		}
		
	}
	system("pause");
}


	
	/* cout << "Save in a file?" << endl << "1 - No\n" << endl << "2 - Yes\n";
	cin >> selection1;
	switch (selection1)
	{
	default:
		cout << "Incorret input, restart and try again\n";
		system("pause");
		exit(1);
	case 1:
		break;
	case 2:
		ofstream outdata;
		outdata.open("test.txt");
		outdata << calc(x, n);
		outdata.close();
		break;
	}
	system("pause");

}*/