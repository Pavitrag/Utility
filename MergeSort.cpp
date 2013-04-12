/*This Merge-Sort Algo does not create a seperate array on each call to sort() method.
This logic was picked from what is described by Robert Sedgewick in his coursera algorithm part I course on 
Merge-Sort*/


#include<iostream>

using namespace std;

class MergeSort
{
private:
  static bool less(int a, int b)
	{
		if(a < b) return true;
		return false;
	}

	static void merge(int a[], int aux[], int lo, int mid, int hi)
	{
		int i = lo, j = mid+1;
		for (int k = lo; k <= hi; k++)
		{
			if (i > mid)    		aux[k] = a[j++];
			else if (j > hi)		aux[k] = a[i++];
			else if (less(a[j], a[i])) 	aux[k] = a[j++];
			else 				aux[k] = a[i++];
		}
	}
	static void sort(int a[], int aux[], int lo, int hi)
	{
		if (hi <= lo) return;
		int mid = lo + (hi - lo) / 2;
		sort (aux, a, lo, mid);
		sort (aux, a, mid+1, hi);
		if (!less(aux[mid+1], aux[mid])) return;
		merge(aux, a, lo, mid, hi);
	}

public:

	static void sort(int a[], int len)
	{
		int *aux = new int[len];
		for(int i = 0; i< len; i++)
			aux[i] = a[i];
		sort(a, aux, 0, len - 1); //calls another version of sort() as above.
	}

	static void display(int A[], int len)
	{
		for(int i = 0; i< len; i++)
			cout << A[i] << " ";
		cout << endl;
	}

};

void mergeSortDriver()
{
	int A[] = {7, 2, 9, 6, 3, 8};

	cout << "Before Sorting..." << endl;
	MergeSort::display(A, 6);

	MergeSort::sort(A, 6);

	cout << "After Sorting..." << endl;
	MergeSort::display(A, 6);

	return;
}
