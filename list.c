#include "list.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int length;
    unsigned char num[];
} List;

int len(List *arr)
{
    return arr->length;
};

void clear(List *arr)
{
    int length = arr->length;
    for(int i = 0; i < length; i++)
    {
        arr->num[i] = 0;
        (arr->length)--; 
    }
};

void push(List *arr, long long value)
{
    arr->num[arr->length] = value;
    (arr->length)++;
};

int pop(List *arr)
{   
    int item = arr->num[arr->length-1];
    arr->num[arr->length - 1] = 0;
    (arr->length)--;
    return item;
};

int count(List *arr, int num)
{
    int c = 0;
    for(int i = 0; i < arr->length; i++) if(arr->num[i] == num) c++;;
    return c;
};

int ind(List *arr, int num) 
{
    for(int i = 0; i< arr->length; i++) if(arr->num[i] == num) return i;
    return -1;
};

int max(List *arr)
{
    int max = 0;
    for(int i = 0; i< arr->length; i++) if(arr->num[i] > max) max = arr->num[i];
    return max;
};

int min(List *arr)
{
    int min = 10000;
    for(int i = 0; i< arr->length; i++) if(arr->num[i] < min) min = arr->num[i];
    return min;
};

void reverse(List *arr)
{
    unsigned char newarr[arr->length] = {};
    int c = 0;
    for(int i = arr->length - 1; i > -1; i--){
        newarr[c] = arr->num[i];
        c++;
    }
    for(int i = 0; i < arr->length; i++){
        arr->num[i] = newarr[i];
    }
};

void extend(List *arr1, List *arr2 )
{
    for (int i = 0; i < arr2->length; i++) push(arr1, arr2->num[i]);
};

void extend3(List *arr1, List *arr2, List *arr3)
{
    for (int i = 0; i < arr2->length; i++) push(arr1, arr2->num[i]);
    for (int i = 0; i < arr3->length; i++) push(arr1, arr3->num[i]);
};

void rem(List *arr, int num)
{
    int i = 0;
    for(i = 0; i < arr->length; i++) if(arr->num[i] == num) break;
    for(int c = 0; c < arr->length - i; c++){
        if(c == arr->length - i){
            arr->num[i+c] = 0; 
            break;
        }
        arr->num[i+c] = arr->num[i+c+1];
    }
    arr->length--;
}

void insert(List *arr, int num, int value)
{
    int tmp = arr->num[num];
    arr->num[num] = value;
    int i = num;
    while(i < arr->length + 1){
        int sec = arr->num[i+1];
        arr->num[i+1] = tmp;
        tmp = sec;
        i++;
    }
    arr->length++;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}