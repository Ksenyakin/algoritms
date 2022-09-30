#include <iostream>
#include <fstream>
using namespace std;

int counter = 0;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];
    int count = 0;
    counter += 2;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
            counter += 2;
        }
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    counter += 4;
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
    counter += 2;
    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
            counter++;
        }

        while (arr[j] > pivot) {
            j--;
            counter++;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
            counter += 3;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}


int main()
{
    const int n = 1000;
    int a[n];
    srand(time(0));
    ofstream f("Output.txt");

    int K = 10000; // Количество итераций


    // Для среднего случая:
    f << "Tmean(N):\n";
    for (int N = 100; N <= 1000; N += 100)
    {
        int sredn = 0;
        for (int k = 0; k < K; k++)
        {
            counter = 0;
            //cout << "\n Before sort: \n";
            for (int i = 0; i < N; i++)
            {
                a[i] = rand() % 100;
                //cout << a[i] << " ";
            }
            quickSort(a, 0, N - 1);
            sredn += counter;

            //cout << "\n Sorted: \n";
            //for (int i = 0; i < N; i++)
            //    cout << a[i] << " ";
        }
        f << sredn / K << endl;
    }

    // Для худшего случая:
    f << "\nTmax(N):\n";
    for (int N = 100; N <= 1000; N += 100)
    {
        counter = 0;

        //cout << "\n Before sort: \n";
        for (int i = 0; i < N; i++)
        {
            a[i] = N - i;
            //cout << a[i] << " ";
        }

        quickSort(a, 0, N - 1);

        //cout << "\n Sorted: \n";
        //for (int i = 0; i < N; i++)
        //    cout << a[i] << " ";


   
        f << counter << endl;
    }

    // Для лучшего случая:
    f << "\nTmin(N):\n";
    for (int N = 100; N <= 1000; N += 100)
    {
        counter = 0;

        //cout << "\n Before sort: \n";
        for (int i = 0; i < N; i++)
        {
            a[i] = i;
            //cout << a[i] << " ";
        }

        quickSort(a, 0, N - 1);

        //cout << "\n Sorted: \n";
        //for (int i = 0; i < N; i++)
        //    cout << a[i] << " ";

        f << counter << endl;
    }


}
