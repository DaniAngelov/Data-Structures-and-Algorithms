// github.com/DaniAngelov

#include <iostream>
using namespace std; 
  
/
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid;
       
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
            
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 
  
int main() 
{ 
    int N;
    cin >> N;
    int* arr = new int[N]; 
    
    for(int i = 0; i < N;i++)
    {
      cin >> arr[i];
    }
    int x;
    cin >> x;
    
    int res = binarySearch(arr, 0, N - 1, x); 
    if(res != -1)
      {
        cout << "found" << endl;
      }
    else
      cout << "not found" << endl;
      
      int _;
      cin >> _;
     return 0; 
} 
