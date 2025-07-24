#include <iostream>
#include <algorithm> // Needed for sort()
using namespace std;

// Define a structure for Date
struct Date 
{ 
	int day, month, year; 
}; 

// Comparison function for sorting two dates
bool compare(const Date &d1, const Date &d2) 
{ 
	// First compare years
	if (d1.year < d2.year) 
		return true;

	// If years are equal, compare months
	if (d1.year == d2.year && d1.month < d2.month) 
		return true;

	// If years and months are equal, compare days
	if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) 
		return true;

	// Otherwise, d1 is not earlier than d2
	return false; 
}  

// Function to sort an array of dates
void sortDates(Date arr[], int n) 
{ 
	// Use STL sort with custom comparator
	sort(arr, arr + n, compare); 
} 

int main() 
{ 
	// Array of unsorted dates
	Date arr[] = {
		{20, 1, 2014}, 
		{25, 3, 2010}, 
		{ 3, 12, 1676}, 
		{18, 11, 1982}, 
		{19, 4, 2015}, 
		{ 9, 7, 2015}
	}; 
	
	int n = sizeof(arr) / sizeof(arr[0]); // Number of elements

	// Sort the array
	sortDates(arr, n); 

	// Print the sorted dates
	cout << "Sorted dates are:\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << arr[i].day << " " << arr[i].month << " " << arr[i].year << endl; 
	} 

	return 0;
}
