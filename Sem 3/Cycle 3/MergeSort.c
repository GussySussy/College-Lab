#include <stdio.h>

int a[100], b[100], l, r;

void merge(int low, int mid, int high)
{
    int l, r, k;

    for (l = low, r = mid + 1, k = low; l <= mid && r <= high; k++)
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
        b[k++] = a[r++];
    }

    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
}

void sort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid + 1, high);
        merge(low, mid, high);
    }
    else
    {
        return;
    }
}

void display(int a[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d\t", a[i]);
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
    printf("%d", i);
    printf("The unsorted list is : \n");
    display(a, i);
    sort(0, i - 1);
    printf("\nThe sorted list is : \n");
    display(a, i);
}