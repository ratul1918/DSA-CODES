#include <iostream>
using namespace std; 
 
struct Date 
{ 
	int day, month, year; 
}; 

bool compare(const Date &d1, const Date &d2) 
{ 

	if (d1.year < d2.year) 
		return true; 
	if (d1.year == d2.year && d1.month < d2.month) 
		return true; 
	if (d1.year == d2.year && d1.month == d2.month && 
							d1.day < d2.day) 
		return true; 

	return false; 
}  
void sortDates(Date arr[], int n) 
{ 
	 
	sort(arr, arr+n, compare); 
} 

int main() 
{ 
	Date arr[] = {{20, 1, 2014}, 
				{25, 3, 2010}, 
				{ 3, 12, 1676}, 
				{18, 11, 1982}, 
				{19, 4, 2015}, 
				{ 9, 7, 2015}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	sortDates(arr, n); 

	cout << "Sorted dates are\n"; 
	for (int i=0; i<n; i++) 
	{ 
		cout << arr[i].day << " " << arr[i].month 
			<< " " << arr[i].year; 
		cout << endl; 
	} 
} 
