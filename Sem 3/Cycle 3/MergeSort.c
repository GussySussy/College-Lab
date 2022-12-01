#include <stdio.h>

int a[100], b[100], l, r;

void merge(int a[], int low, int mid, int high)
{
    int l, r, k;

    for (l = low, r = mid + 1; l <= mid && r <= high; k++)
    {
        if (a[l] <= a[r])
        {
            b[k] = a[l++];
        }
        else
        {
            b[k] = a[r++];
        }
    }

    while (l <= mid)
        b[k++] = a[l++];

    while (r <= high)
    {
        b[k++] = b[r++];
    }

    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void sort(int low, int high)
{
    int mid = (low + high) / 2;
    sort(low, mid);
    sort(mid + 1, high);
    merge(a, low, mid, high);
}

void display(int a[], int length)
{
    int i = 0;
    while (i < length)
    {
        printf("%d\t", a[i++]);
    }
}

void main()
{
    int i = 0, element;
    char ch;

    do
    {
        printf("What element do you wish to add : ");
        scanf("%d", &element);
        a[i++] = element;
        printf("Do you wish to add another element to the list?(y/n) : \n");
        scanf(" %c", &ch);
    } while (ch == 'y');

    printf("The unsorted list is : \n");
    display(a, i);
    sort(0, i - 1);
    printf("The sorted list is : \n");
    display(a, i);
}