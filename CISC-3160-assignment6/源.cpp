#include<iostream>
#include<cstdlib>
using namespace std;

void bubble(int a[], int n);
void swap(int* a, int* b);
int part(int a[], int l, int h);
void quick(int a[], int l, int h);
void merge(int a[], int l, int m, int h);
void msort(int a[], int l, int h);
int main() {
	int a[1000], i, n, choice, ch;
	cout << "Enter range to sort the elements " << endl;
	cin >> n;
	cout << "Enter a choice among 1.sorted 2.reverse or 3.random " << endl;
	cout << "Enter your choice ";
	cin >> ch;
	switch (ch) {
	case 1: for (i = 0;i < n;i++) {
		a[i] = i;
	}
		  cout << "current array is \n";
		  for (i = 0;i < n;i++) {
			  cout << a[i] << "\t";
		  }
		  cout << endl;
		  break;
	case 2: for (i = 0;i < n;i++) {
		a[i] = n - i;
	}
		  for (i = 0;i < n;i++) {
			  cout << a[i] << "\t";
		  }
		  cout << endl;
		  break;
	case 3: for (i = 0;i < n;i++) {
		a[i] = (rand() % 100 + i);
	}
		  for (i = 0;i < n;i++) {
			  cout << a[i] << "\t";
		  }
		  cout << endl;
		  break;
	default:cout << "You didn't enter a valid choice try again !" << endl;
		return 0;
	}
	cout << "Enter choice of sort 1.Bubble 2.Quick 3.Merge Sort " << endl;
	cout << "Enter 1 or 2 or 3" << endl;
	cin >> choice;
	switch (choice) {
	case 1: cout << "Sorting is done using Bubble Sort" << endl;
		bubble(a, n);
		break;
	case 2: cout << "Sorting is done using Quick Sort" << endl;
		quick(a, 0, n - 1);
		break;
	case 3: cout << "Sorting is done using Merge Sort" << endl;
		msort(a, 0, n - 1);
		break;
	default: cout << "you have entered an invalid choice " << endl;
	}
	cout << "Sorted array is \n";
	for (i = 0;i < n;i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

void bubble(int a[], int n) {
	int i, j, t;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (a[i] < a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int part(int a[], int l, int h) {
	int pi = a[h];
	int index = (l - 1);
	int j;
	for (j = l; j <= h - 1; j++) {
		if (a[j] <= pi) {
			index++;
			swap(&a[index], &a[j]);
		}
	}
	swap(&a[index + 1], &a[h]);
	return (index + 1);
}

void quick(int a[], int l, int h) {
	if (l < h) {
		int index = part(a, l, h);
		quick(a, l, index - 1);
		quick(a, index + 1, h);
	}
}

void msort(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		msort(a, low, mid);
		msort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}

void merge(int a[], int low, int mid, int high) {
	int h, i, j, b[50], k;
	h = low;
	i = low;
	j = mid + 1;
	while ((h <= mid) && (j <= high)) {
		if (a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		}
		else {
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > mid) {
		for (k = j;k <= high;k++) {
			b[i] = a[k];
			i++;
		}
	}
	else {
		for (k = h;k <= mid;k++) {
			b[i] = a[k];
			i++;
		}
	}
	for (k = low;k <= high;k++) {
		a[k] = b[k];
	}
}
