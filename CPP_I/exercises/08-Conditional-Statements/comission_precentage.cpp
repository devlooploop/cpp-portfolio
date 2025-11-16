
// Problem - Comission Precentage

/*
Write a program to ask the user to enter:
• TotalSales
The commission is calculated as one percentage * the total sales amount, 
all you need is to decide which percentage
to use of the following:

• > 1000,000 --> Percentage is 1%
• > 500K to 1M --> Percentage is 2%
• > 100K – 500K --> Percentage is 3%
• > 50K to 100K --> Percentage is 5%
• Otherwise --> Percentage is 0%
Example Inputs:
110,000
Outputs:
3,300
*/

#include <iostream>
using namespace std;

double RadTotalSales(double &TotalSales)
{
	cin >> TotalSales;
	return TotalSales;
}

double CalculateComission(double TotalSales)
{
	double Comission;

	if (TotalSales >= 1000000)
	{
		Comission = TotalSales * 0.01;
		return Comission;
	}
	else if (TotalSales >= 500000 )
	{
		Comission = TotalSales * 0.02;
		return Comission;
	}
	else if (TotalSales >= 100000 )
	{
		Comission = TotalSales * 0.03;
		return Comission;
	}
	else if (TotalSales >= 50000 )
	{
		Comission = TotalSales * 0.05;
		return Comission;
	}
	else
	{
		Comission = TotalSales * 0.0;
		return Comission;
	}
}


int main()
{
	double sale_total ;
	cout << "Enter the Total Sales\n";

	cout <<"Total Comission is: " << CalculateComission(RadTotalSales(sale_total));

	return 0;
}