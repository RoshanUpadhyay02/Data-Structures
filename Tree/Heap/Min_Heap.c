#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heapify(int arr[], int size, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<size && arr[l] < arr[smallest])
        smallest = l;
    if(r<size && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(&arr[i],&arr[smallest]);
        Heapify(arr,size,smallest);
    }
}

void insert(int array[], int value)
{
    int i;
    if(size == 0)
    {
        array[size] = value;
        size++;
    }
    else
    {
        array[size] = value;
        size++;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            Heapify(array, size, i);
        }
    }
}

void print(int array[])
{
    int i;
    for (i=0;i<size;i++)
        printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    int n,i,x;
    printf("Enter the number of elements in the heap: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in the heap: ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(arr,x);
    }

    printf("\nThe Elements of the heap are: ");
    print(arr);
    return 0;
}

