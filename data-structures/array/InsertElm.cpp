#include <iostream>
#include <vector>
using namespace std;

// insterting elm at the beginning of the array
void beginning(vector<int> arr, int elm)
{
    int n = arr.size() - 1;

    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = elm;

    cout << "beginning ";
    for (int elm : arr)
    {
        cout << elm << " ";
    }
}

// inserting elm at the given index
void givenPoint(vector<int> arr, int elm, int p)
{
    int n = arr.size() - 1;

    for (int i = n; i > p; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[p] = elm;

    cout << "given point ";
    for (int elm : arr)
    {
        cout << elm << " ";
    }
};

// inserting elm at the end of the array
void end(vector<int> arr, int elm)
{
    int n = arr.size() - 1;
    arr[n] = elm;

    cout << "end ";
    for (int elm : arr)
    {
        cout << elm << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 0};
    int elm = 6;

    beginning(arr, elm);
    cout << endl;
    givenPoint(arr, elm, 2);
    cout << endl;
    end(arr, elm);
    return 0;
}