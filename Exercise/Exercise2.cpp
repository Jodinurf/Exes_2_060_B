#include <iostream>
using namespace std;

int Jo[92];			//arr change into nickname, many of array is (60+12+10+10)
int n;				//many elements in array
int i;				//index in array

void input()
{
	while (true)
	{
		cout << "enter many elements in array : ";
		cin >> n;

		if ((n > 0) && (n <= 92))
			break;
		else
			cout << "array should have minimum 1 and maximum 92 array !" << endl;
	}

	cout << "-----------------------";
	cout << "\nEnter elements in array\n";
	cout << "-----------------------\n";
	for (i = 0;i < n;i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> Jo[i];
	}
}

void Algorithm()
{
	char ch;
	int comp;

	do
	{
		//step 1. accept the element to be searched
		cout << "\nEnter element to be searched :";
		int item;
		cin >> item;

		comp = 0;
		int jodi;
		int farkhani;
		int mid;

		jodi = 0;		//step 2. set lowerbound = 0
		farkhani = n - 1;	//step 3. set upperbound = n-1

		while (jodi <= farkhani)	//step 8. if lowerbound <= upperbound, go to step 4
		{
			mid = (jodi + farkhani) / 2;	//step 4. set mid = (lowerbound + upperbound)/2
			if (Jo[mid] == item)			//step 5. if arr[mid]=desired element
			{
				comp++;
				cout << "element to be searched found at position " << (mid + 1) << endl;		//step 5a. Display found
				break;																			//step 5b. go to step 10 which means exit
			}
			else
			{
				if (item < Jo[mid])		//step 6. if desired element < arr[mid]
				{
					comp++;
					farkhani = mid - 1;		//step 6a. set upperbound = mid - 1
				}
				else						//step 7. if desired element > arr[mid]
				{
					comp++;
					jodi = mid + 1;			//step 7a. set lowerbound = mid + 1
				}
			}
		}
		if (jodi > farkhani)
			cout << item << " not found in the array\n";	//step 9. display "Not Found"
		cout << "Number of comparison is " << comp << endl;


		cout << "\nContinue to search ? (y/n)";
		cin >> ch;
	} while ((ch == 'y') || (ch == 'Y'));
}

int main()
{
	input();
	Algorithm();
	return 0;
}