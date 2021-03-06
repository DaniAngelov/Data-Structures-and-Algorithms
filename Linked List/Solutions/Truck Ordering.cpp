// github.com/DaniAngelov

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;



string isPossible(stack<long long> st, long long * arr, long long  index, long long  length)
{
    long long i = index;
    if(st.empty())
    {
        st.push(arr[index + 1]);
        i++;
    }

    while (!st.empty())
    {
        if (st.top() - 1 == arr[index] )
        {

            arr[index] = st.top();
            st.pop();
        }
        else
        {
            if (i < length)
            {
                st.push(arr[i + 1]);
                i++;
            }
            else
            {
                return "no";
            }
        }
    }
    return "yes";
}

int main()
{


    long long  T;
    cin >> T;

    vector<string> v;

    for (int i = 0; i < T; i++)
    {
        long long  N;
        cin >> N;


        stack<long long > st;

        long long * arr = new long long[N];

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        if(N == 1 && arr[0] == 1)
        {
            v.push_back("yes");
            continue;
        }

        if(N == 1 && arr[0] != 1)
        {
            v.push_back("no");
            continue;
        }


        long long  index = 0;

        for (int i = 0; i < N; i++)
        {

            if (arr[i] != 1)
            {


                st.push(arr[i]);

            }
            else
            {
                
                index = i;
                break;


            }

        }


        v.push_back(isPossible(st, arr, index, N));

    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    int _;
    cin >> _;
    return 0;
}

/*
5
5 1 2 4 3

*/
