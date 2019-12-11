#include <iostream>
#include <string>

using namespace std;
template<class T>
void sorting(T arr[], int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        T x = arr[i];
        for (j = i - 1; j >= 0 && x < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
}template<class T>void print(T arr[], int size){    for (int i = 0; i < size; i++)    {        cout << arr[i] << " ";    }}template<class T>T average(T arr[], int size){    double sum=0;    for (int i = 0; i < size; i++)    {        sum += arr[i];    }    return sum / size;}int main()
{
    int arr[] = { 9,3,17,6,5,4,31,2,12 };
    int k1 = sizeof(arr) / sizeof(arr[0]);
    sorting(arr, k1);
    for (int i = 0; i < k1; i++)
    {
        cout << arr[i] << ";";
    }
    cout << endl;
    int arr1[] = { 9,3,17,6,5,4,31,2,12 };
    double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
    char arrc[] = "Hello, word";
    k1 = sizeof(arr1) / sizeof(arr1[0]);
    int k2 = sizeof(arrd) / sizeof(arrd[0]);
    int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
    sorting(arr1, k1);
    //for (int i = 0; i < k1; i++) cout << arr1[i] << ";";
    print(arr1, k1);
    cout << endl;
    sorting(arrd, k2);
    print(arrd, k2);
    //for (int i = 0; i < k2; i++) cout << arrd[i] << ";";
    cout << endl;
    sorting(arrc, k3);
    print(arrc, k3);
    //for (int i = 0; i < k3; i++) cout << arrc[i] << ";";
    cout << endl;
    cout << average(arr1, k1) << endl;
    cout << average(arrd, k2) << endl;
    cout << average(arrc, k3) << endl;
    return 0;
}
