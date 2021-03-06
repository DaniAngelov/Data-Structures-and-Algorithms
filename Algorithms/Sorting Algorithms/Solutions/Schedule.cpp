// github.com/DaniAngelov

#include <iostream>
using namespace std;


void merge(int* arr, int* arr3, int start, int mid, int end)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int* arr1 = new int[length1];
    int* arr3_left = new int[length1];
    int* arr2 = new int[length2];
    int* arr3_right = new int[length2];



    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[start + i];
        arr3_left[i] = arr3[start + i];
    }

    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
        arr3_right[i] = arr3[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;



    while (i < length1 && j < length2)
    {
        if (arr1[i] == arr2[j])
        {
            arr[k] = arr1[i];
            if (arr1[i] < arr2[j])
            {
                arr[k] == arr1[i];
            }
            else
            {
                arr[k] == arr2[j];
            }
        }

        if (arr3_left[i] < arr3_right[j])
        {
            arr3[k] = arr3_left[i];
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr3_right[j];
            arr[k] = arr2[j];
            j++;

        }
        k++;


    }


    while (i < length1)
    {
        arr3[k] = arr3_left[i];
        arr[k] = arr1[i];
        i++;
        k++;

    }

    while (j < length2)
    {

        arr3[k] = arr3_right[j];
        arr[k] = arr2[j];
        j++;
        k++;

    }



}
void mergeSort(int * arr, int* arr2, int start, int end)
{


    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, arr2, start, mid);
        mergeSort(arr, arr2, mid + 1, end);


        merge(arr, arr2, start, mid, end);
    }
}

int main()
{
    int N;
    cin >> N;
    if (N == 0)
    {
        cout << "0";
        return 0;
    }

    int* arr = new int[N];
    int* arr2 = new int[N];


    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        cin >> arr2[i];
        arr2[i] += arr[i];

    }


    mergeSort(arr, arr2, 0, N - 1);
 
    int ends = arr2[0];
    long long cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (ends <= arr[i])
        {
            cnt++;
            ends = arr2[i];
        }
    }

    cout << cnt;

    int _;
    cin >> _;
    return 0;
}
