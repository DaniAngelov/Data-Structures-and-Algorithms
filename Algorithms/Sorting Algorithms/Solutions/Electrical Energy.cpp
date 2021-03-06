// github.com/DaniAngelov

#include <iostream>
using namespace std;

long long int count2 = 0;
int temp;

void merge(int* arr, int start, int mid, int end)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int* arr1 = new int[length1];
    int* arr2 = new int[length2];


    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[start + i];
    }

    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;



    while (i < length1 && j < length2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            count2 = count2 + length1 - i;
        }
        k++;
    }

    while (i < length1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < length2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
void mergeSort(int* arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}


int main()
{

    long long int N;
    cin >> N;
    if (N == 0)
    {
        cout << "0";
        return 0;
    }

    int* arr = new  int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }


    mergeSort(arr, 0, N - 1);

    cout << count2;



    int _;
    cin >> _;
    return 0;
}
