#include <iostream>
using namespace std;

#define ALEN 10

void print_array(int x[], int n) {
	for (int i = 0; i < n; i++)
		cout << x[i] << ";";	
	cout << endl;
}

void merge(int a[], int p, int q, int r)
{	
	int i;
	int n = (r - p) + 1;
	int b[n];
	
	for (i = 0; i < n; i++)
		b[i] = 0;
	
	i = 0;
	int tmp_p = p;
	int tmp_q = q + 1;
	
	while( tmp_p <= q && tmp_q <= r ) {
		if ( a[tmp_p] <= a[tmp_q]) {
			b[i++] = a[tmp_p++];
		}
		else {
			b[i++] = a[tmp_q++];
		}
	}
	
	while ( tmp_p <= q ) {
		b[i++] = a[tmp_p++];
	}
	
	while ( tmp_q <= r ) {
		b[i++] = a[tmp_q++];
	}
	
	cout << "pqr = " << p << q << r << endl;
	cout << "Array b: ";
	print_array(b, n);
	
	for (i = 0; i < n;) {
		a[p++] = b[i++];
	}
	cout << "Array A: ";
	print_array(a, ALEN);
}

void merge_sort(int a[], int p, int r)
{
	int q;
	if ( p < r ) {
		q = (p + r)/2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main(void)
{
	int a[ALEN] = {4,1,4,5,6,4,6,7,2,3};
	
	cout << "Before:" << endl;
	print_array(a, ALEN);
	
	merge_sort(a, 0, ALEN - 1);
	
	cout << "After:" << endl;
	print_array(a, ALEN);

	return 0;
}
