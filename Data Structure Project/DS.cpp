#include <iostream>
#include <conio.h>
#include <cstdlib>//system("cls");
#include <stdio.h>
#include <time.h> //clock,time,sleep
#include <stdlib.h> // Rand()
#include <Windows.h> // Sleep () 
#include <string> //strcpy
#include <fstream> //write,read file


using namespace std;

void TryAgain();

void DrawChart();
void chart1();

int search(int a[], int arraysize, int item)
{

	int beg, end, mid;
	beg = 0;
	end = arraysize - 1;

	while (beg <= end)
	{
		mid = (beg + end) / 2;
		if (item == a[mid])
		{
			return(mid);
		}
		else
			if (item > a[mid])
			{
				beg = mid + 1;
			}
			else
			{
				beg = mid - 1;
			}
	}
}

void BinarySearch()
{
	int search(int a[], int arraysize, int item);
	system("cls");
	cout << " \n Binary Search\n" << endl;
	int a[10000], i, beg, end, mid, item, temp, result;

	cout << "\n------------ BINARY SEARCH ------------ \n\n";

	for (i = 0; i <= 10000; i++) // random numbers fill the array 
	{
		//srand(time(NULL));
		a[i] = rand() % 10000;
	}
	int arraysize, n = 0;
	cout << " Enter size of array you want to search (1-10000) : "; // we use the numbers we want
	cin >> arraysize;
	cout << "\n Orginally random datas : " << endl;                //show random data
	for (int MB = 0; MB <= arraysize; MB++)
	{
		a[MB] = rand() % 10000;
		cout << a[MB] << "		";
	}


	for (int i = 0; i<arraysize; i++)        //sort
	{
		for (int j = 0; j<arraysize - 1; j++)
		{
			if (a[j + 1]>a[j])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	cout << "\nEnter Item you want to Search : ";
	cin >> item;


	float t;
	clock_t start = clock();
	Sleep(3000);
	result = search(a, arraysize, item);

	if (result != 0)
	{
		cout << "\nElement found at position " << result + 1;
	}
	else
	{
		cout << "\nElement is not found....!!!";
	}
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n Time Elapsed : " << t << " Second";

	cin.get();
	TryAgain();
}

void BubbleSort()
{
	system("cls");
	cout << "\n Bubble Sort \n" << endl;
	int hold;
	int array[10000];
	int n;
	cout << "Enter size of array : ";
	cin >> n;

	for (int i = 0; i<10000; i++) // fill array with numbers
	{
		array[i] = rand() % 10000;
	}

	cout << endl;
	system("cls");
	cout << "Orignally randoms data is: \n" << endl;
	cin.get();

	for (int j = 0; j<n; j++) // use numbers we want
	{
		array[j] = rand() % 10000;
		cout << array[j];
		cout << "		";
	}
	cout << endl;

	Sleep(300);
	float t;
	clock_t start = clock();
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (array[j]>array[j + 1])
			{
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
			}
		}
	}

	cout << "\n\n----------------------------------------------------------- \n\n";

	ofstream fout("BubbleSort.txt"); //opening an output stream for file BubbleSort.txt
									 /*checking whether file could be opened or not. If file does not exist or don't have write permissions, file
									 stream could not be opened.*/
	if (fout.is_open())
	{
		//file opened successfully so we are here
		cout << "\n\nFile Opened successfully!!!"
			<< " \nWriting data from array to file " << endl;

		Sleep(3000);
		cout << "Sorted Array is: \n\n" << endl;
		for (int i = 1; i < n; i++)
		{
			cout << array[i];
			cout << "		";
			fout << array[i] << endl;//writing ith character of array in the file
		}
		cout << "\nArray data successfully saved into the file BubbleSort.txt" << endl;
	}
	else //file could not be opened
	{
		cout << "\nFile could not be opened." << endl;
	}

	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n\n Time elapsed : " << t << "second" << endl;

	cin.get();
	TryAgain();
}

void LinearSearch()
{
	system("cls");
	cout << "\n Linear Search\n" << endl;
	int arr[100000], i, num, n, c = 0, pos;
	cout << "\n Enter the size of array : ";
	cin >> n;

	for (i = 0; i<n; i++)
	{
		arr[i] = rand() % 100000 + 1;
		cout << arr[i] << "		";
	}

	cout << "\n Enter the number to be search : ";
	cin >> num;
	float t;
	clock_t start = clock();
	Sleep(3000);
	for (i = 0; i<n; i++)
	{
		if (arr[i] == num)
		{
			c = 1;
			pos = i + 1;
			break;
		}
	}
	if (c == 0)
	{
		cout << "\nNumber not found..!!";
	}
	else
	{
		cout << num << "\n Found at position : " << pos;
	}
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n Time Elapsed : " << t << " Second";
	cin.get();
	TryAgain();
}

void quicksort(int x[10000], int first, int last)
{
	int pivot, j, temp, i;

	if (first<last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i<j)
		{
			while (x[i] <= x[pivot] && i<last)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j)
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort(x, first, j - 1);
		quicksort(x, j + 1, last);

	}
}

void QuickSort()
{
	system("cls");
	cout << "\n Quick Sort \n" << endl;
	int x[10000], size, i, Arraysize;
	float t;

	cout << " Enter size of the array: ";
	cin >> Arraysize;

	clock_t start = clock();

	cout << "Orignally randoms data is: \n" << endl;
	cin.get();

	for (i = 1; i <= Arraysize; i++) // creat random numbers
	{
		x[i] = rand() % 10000;
		cout << x[i] << "		";
	}

	quicksort(x, 0, Arraysize - 1);  // call quicksort function
	cout << " \n ======================================================================= \n" << endl;
	cout << " Sorted Elements" << endl;
	for (i = 1; i <= Arraysize; i++)
	{
		cout << x[i] << "		";
	}

	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n Time Elapsed : " << t << " Second";

	cin.get();
	TryAgain();
}

void T1(int topN, char src, char aux, char dest)
{
	if (topN == 1)
	{
		cout << "\n Disk 1 from " << src << " to " << dest;
	}
	else
	{
		T1(topN - 1, src, dest, aux); //src to aux
		cout << "\n Disk " << topN << " from " << src << " to " << dest;
		T1(topN - 1, aux, src, dest); //aux to dest

	}
}

void HanoiTower()
{
	system("cls");
	cout << "\n Hanoi Tower \n" << endl;
	// src = Source | aux = Auxiliry | dest = Destination
	float t;
	clock_t start = clock();
	int ndisk;
	system("cls");
	cout << "\n Enter number of disks : ";
	cin >> ndisk;
	T1(ndisk, 'A', 'B', 'C');  /*Calling Function*/
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n Time elapsed : " << t << "second";

	cin.get();
	TryAgain();
}

void merge(int *, int, int, int);

void mergesort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
	return;
}

void merge(int *a, int low, int high, int mid)
{
	int i, j, k, c[10000];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

void MERGE()
{
	float t;
	clock_t start = clock();
	system("cls");
	int a[1000], i, b[1000];
	int n;
	cout << "Enter size of array a: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10000;
		cout << a[i] << "		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";
	mergesort(a, 0, n);
	cout << "Sorted Array A : \n";
	for (i = 1; i < n; i++)
	{
		cout << a[i] <<"		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";
	int sizeofarray;
	cout << "Enter size of array b: ";
	cin >> sizeofarray;
	for (i = 0; i < sizeofarray; i++)
	{
		b[i] = rand() % 10000;
		cout << b[i] << "		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";

	mergesort(b, 0, sizeofarray);
	cout << "Sorted Array B : \n";
	for (i = 1; i < sizeofarray; i++)
	{
		cout << b[i]<< "		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";
	
	cin.get();
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n\n Time elapsed : " << t << "second" << endl;
	TryAgain();
}

void InsertionSort()
{
	system("cls");
	cout << "\n Insertion Sort \n" << endl;
	int a[10000], i, j, k, temp;
	for (i = 0; i < 10000; i++)
	{
		a[i] = rand() % 10000;  // fill array with numbers
	}

	int sizeofarray;
	cout << "Enter size of array : ";
	cin >> sizeofarray;
	cout << endl;
	cout << "Orignally randoms data is: \n" << endl;
	cin.get();

	for (int j = 0; j<sizeofarray; j++) // use numbers we want
	{
		a[j] = rand() % 10000;
		cout << a[j] << "		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";
	float t;
	clock_t start = clock();
	Sleep(3000);
	for (i = 1; i < sizeofarray; i++)
	{
		for (j = i; j >= 1; j--)
		{
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
				break;
		}
	}
	cout << "Sorted array\n" << endl;
	for (k = 0; k < sizeofarray; k++)
	{
		cout << a[k] << "		";
	}
	cout << "\n\n----------------------------------------------------------- \n\n";
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n\n Time elapsed : " << t << "second" << endl;

	cin.get();
	TryAgain();
}

void counting_sort(int a[], int n, int max)
{
	int count[10000] = { 0 }, i, j;

	for (i = 0; i<n; ++i)
		count[a[i]] = count[a[i]] + 1;

	cout << "\n Sorted Elements : \n" << endl ;
	cin.get();
	for (i = 0; i <= max; ++i)
		for (j = 1; j <= count[i]; ++j)
			cout << i << "		";
}

void CountingSort()
{
	system("cls");
	cout << " \n Counting Sort\n" << endl;
	int a[10000], n, i, max = 0;
	for (int i = 0; i<10000; i++) // fill array with numbers
	{
		a[i] = rand() % 10000;
	}
	cout << endl;
	system("cls");
	cout << "Enter size of random elements: " ;
	cin >> n;
	cout << "Orignally randoms data is: \n\n";
	cin.get();
	for (int j = 0; j<n; j++) // use numbers we want
	{
		a[j] = rand() % 10000;
		cout << a[j] << "		";
		if (a[j]>max)
			max = a[j];
	}
	cin.get();
	cout << "\n ==================================================================";

	float t;
	clock_t start = clock();
	Sleep(500);
	counting_sort(a, n, max);
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n\n Time Elapsed : " << t << "second" << endl;
	cin.get();
	TryAgain();
}

void max_heapify(int *a, int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}

void heapsort(int *a, int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		max_heapify(a, 1, i - 1);
	}
}

void build_maxheap(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(a, i, n);
	}
}

void HeapSort()
{
	system("cls");
	cout << " \n Heap Sort\n" << endl;
	int n, i, x;
	int a[10000];
	for (i = 1; i <= 10000; i++)
	{
		a[i] = rand() % 10000; // fill array with numbers
	}

	cout << "Enter size of array : ";
	cin >> n;
	cout << "\n Orignally randoms data is: \n";
	for (int j = 0; j < n; j++)  // use numbers we want
	{
		a[j] = rand() % 10000;
		cout << a[j] << "		";
	}

	cin.get();
	cout << "\n ================================================================== \n";
	float t;
	clock_t start = clock();
	cout << "Please wait ... " << endl;
	Sleep(5000);
	build_maxheap(a, n);
	heapsort(a, n);

	cout << "\nSorted Array \n\n";
	for (i = 1; i <= n; i++)
	{
		cout << a[i] << "		";
	}
	t = ((double)clock() - start) / CLOCKS_PER_SEC;
	cout << "\n Time Elapsed : " << t << "second" << endl;
	cin.get();
	TryAgain();
}

void chart()
{
	char result;
	cout << "\n\n Would You Like import These Data's To EXCEL With Chart ?(y/N): \a" << endl;
	result = getch();
	if (result == 'y' || result == 'Y')
	{
		int i;
		cout << "\n Runing Macro ....";
		_sleep(2000);
		cout << "\n Putting Numbers and Pulling Chart ....";
		_sleep(5000);
		cout << "\n Saving ....";
		_sleep(1500);
		cout << "\n Runing EXCEL ....";
		_sleep(2000);
		i = system("D:\Project.xlsx");
		cout << "\n EXCEL is Opened";
		cin.get();
		TryAgain();
	}
}

void default()
{
	ofstream MyExcelFile;
	MyExcelFile.open("d:\Project.xlsx");

	MyExcelFile << " , Binary Search , Linear Search , Quick Sort , Bubble Sort , Hanoi Tower ";
	MyExcelFile << " 0 , 0 , 0 , 0 , 0 , 0 ";

	void All();
	{
		MyExcelFile << "void Binary_Search() << = SERIES(Sheet1!$B$1?Sheet1!$A$2:$A$22?Sheet1!$B$2 : $B$22?1)";

		MyExcelFile << "void Quick_Sort() << = SERIES(Sheet1!$D$1?Sheet1!$A$2:$A$22?Sheet1!$D$2 : $D$22?3)";

		MyExcelFile << "void Linear_Search() << = SERIES(Sheet1!$C$1?Sheet1!$A$2:$A$22?Sheet1!$C$2 : $C$22?2)";

		MyExcelFile << "void Bubble_Sort() << = SERIES(Sheet1!$E$1?Sheet1!$A$2:$A$22?Sheet1!$E$2 : $E$22?4)";

		MyExcelFile << "void Hanoi_Tower() << = SERIES(Sheet1!$F$1?Sheet1!$A$2:$A$22?Sheet1!$F$2 : $F$22?5)";

		MyExcelFile.close();
	}
}

void chart1()
{
	system("cls");
	cout << " \n\n   ** Hanoi Tower algorithm is little different from the other algorithms **" << endl;
	_sleep(500);

}


void Menu()
{
	cout << "\n\n\n\n\n                   #***#***#    MAIN MENU    #***#***#"
		<< "\n\n		========================================="
		<< endl << "		1-  Binary Search		   "
		<< endl << "		2-  Bubble Sort			   "
		<< endl << "		3-  Linear Search		   "
		<< endl << "		4-  Quick  Sort			   "
		<< endl << "		5-  Hanoi  Tower		   "
		<< endl << "		6-  Merge  Sort            "
		<< endl << "		7-  Insertion Sort         "
		<< endl << "		8-  Heap Sort              "
		<< endl << "		9-  Counting Sort          "
		<< endl << "		10- Draw Graph             "
		<< endl << "		11- Exit			       "
		<< endl << "		Please choose an item : ";

	//int choose;
	//choose = 1, choose = 2, choose = 3, choose = 4, choose = 5,choose=6;
	int  choice;
	cin >> choice;
	if (true)
	{
		switch (choice)
		{
		case 1: BinarySearch();
			break;
		case 2: BubbleSort();
			break;
		case 3: LinearSearch();
			break;
		case 4: QuickSort();
			break;
		case 5: HanoiTower();
			break;
		case 6: MERGE();
			break;
		case 7: InsertionSort();
			break;
		case 8: HeapSort();
			break;
		case 9: CountingSort();
			break;
		case 10: {
			chart1();
			chart();
		}
			break;
		case 11: {
			cin.get();
			cout << endl << endl << "   Glad to use our application ;) \a" << endl << endl << endl << endl;
			cin.get();
			exit(0);
		}
				break;
		default:
			true;
			break;
		}
	}

	else
	{
		system("cls");
		cout << "\n\n\n\n\n\n			Please Enter 1 to 6 !" << endl;
		Menu();
	}
}

void Menu2()
{
	system("cls");
		cout << endl << "		1- Draw Chart		   "
		     << endl << "		2- exit			   "
		     << endl;

	int mhb;
	cin >> mhb;
	switch (mhb)
	{
	case 1: {
		chart();
		chart1();
	}
		break;
	case 2:
		cout << endl << endl << "   Glad to use our application ;) \a" << endl << endl << endl << endl;
		exit(0);
		break;

	}
}

void TryAgain()
{

	char result;
	cout << "\n Would you like to Try Again?(y/N): \a" << endl;
	result = getch();

	switch (result) {

	case 121: // "Y"
	case 89: // "y"
		cout << "yes";

		system("CLS");

		Menu();
		break;

	case 78: // "N"
	case 110: // "n"

		cout << endl << "  no  " << endl << endl;
		Menu2();


	default:

		TryAgain();

		break;
		cin.get();
	}
}

int main()
{
	system("color 75");
	cout << "\n\n\n\n\n		   Welcome to data structure application \n\n\n\n\n";
	cin.get();
	system("cls");
	cout << "\n\n\n\n\n\n			This application made by \n\n			Pouya Mehrbabak \n\n			Danial Saleh\n\n			Mehrdad Heidari \n ";
	cin.get();
	system("cls");
	cout << "Copyright (c) 2016 MHB\n\n Permission is here by granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files(the Software), to deal\nin the Software without restriction, including without limitation the rights\nto use, copy, modify, merge, publish, distribute, sublicense, and / or sell\ncopies of the Software, and to permit persons to whom the Software is\nfurnished to do so, subject to the following conditions :\n The above copyright notice and this permission notice shall be included in all\ncopies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED (AS IS), WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE\nAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\nOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\nSOFTWARE.";
	cin.get();
	system("cls");
	Menu();
	cin.get();

	return 0;
}

