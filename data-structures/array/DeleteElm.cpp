#include <iostream>
#include <vector>
using namespace std;

// deleting element at the beginning of the array
void beginning(vector<int> arr)
{
    int n = arr.size() - 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    cout << "beginning ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// deleting elm at the given index of the array
void givenPoint(vector<int> arr, int p)
{
    int n = arr.size() - 1;
    for (int i = p; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    // if the point (index) higher than the n, increase the n to the normal array size
    if (p > n)
    {
        n++;
    }

    cout << "given point ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// deleting elm at the end of the array
void end(vector<int> arr)
{
    int n = arr.size() - 1;

    cout << "end ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// deleting elm that first occurrence based on parameter
void firstOccurrence(vector<int> arr, int elm)
{
    int n = arr.size() - 1;
    bool isElmFind = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == elm)
        {
            isElmFind = true;
        }
        if (isElmFind)
        {
            arr[i] = arr[i + 1];
        }
    }

    // if the element couldn't be find, increase the n to the normal array size
    if (!isElmFind)
    {
        n++;
    }

    cout << "first occurrence ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// deleting elm that all occurrence based on parameter
void allOccurrence(vector<int> arr, int elm)
{
    int n = arr.size();
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != elm)
        {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            k++;
        }
    }

    n -= n - k;

    cout << "all occurrence ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5, 5, 3, 6};

    beginning(arr);
    cout << endl;
    givenPoint(arr, 1);
    cout << endl;
    end(arr);
    cout << endl;
    firstOccurrence(arr, 4);
    cout << endl;
    allOccurrence(arr, 3);
    return 0;
}