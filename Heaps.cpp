#include <bits/stdc++.h> 
using namespace std; 
  
void insert(int* arr, int n, int &last){
		if(last == 100){
			cout << "Heap Full" << endl;
			return;
		}
		else{
			arr[++last] = n;
			int i = last;
			while(i>1){
				if(arr[i] > arr[i/2]){
					swap(arr[i],arr[i/2]);
					i = i/2;
				}
				else{
					return;
				}
			}
		}
}

void deleteElement(int* arr, int& last){
	arr[1] = arr[last];
	last --;
	bool check = true;
	int i = 1;
	while(check == true){
		int maxno;
		int tempdig;
		if(arr[2*i] > arr[2*i + 1]){
			tempdig = 2*i;
		}
		else{
			tempdig = 2*i + 1;
		}

		if(arr[i] < arr[tempdig]){
			swap(arr[i],arr[tempdig]);
			i = tempdig;
			check = true;
		}
		else{
			check = false;
		}
	}
}

void printArray(int *arr, int last){
	for(int i = 1; i <=last;i++){
		cout << arr[i] << " | ";
	}
}

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    {  
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 

void printArrayHeapSort(int *arr, int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << endl;
	}
}  
  
int main() 
{ 
	int* arr = new int[101];
	int c = 1;
	int elem;
	int last = 0;
	cout << "HEAPS:" << endl;
	while(c!=0){
		cout << "Enter your choice:" << endl;
		cout << "1.INSERT\n2.DELETE\n3.PRINT THE HEAP AS IN ARRAY\n4.HEAP SORT\n0.QUIT PROGRAM" << endl;
		cin >> c;
		switch(c){
			case 1:
			cout << "Enter an element" << endl;
			cin >> elem;
			insert(arr,elem,last);
			break;

			case 2:
			deleteElement(arr,last);
			break;

			case 3:
			printArray(arr,last);
			break;
			case 4:
			int size;
			cout << "Enter the size of array" << endl;
			cin >> size;
			int harr[size];
			for(int x = 0; x < size; x++){
				cout << "Enter Elements" << endl;
				cin >> harr[x];
			}
			heapSort(harr,size);
			cout << "The sorted array" << endl;
			printArrayHeapSort(harr,size);
			break;
		}
	}

} 