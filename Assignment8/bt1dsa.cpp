
#include <iostream>
using namespace std;

// Hàm hoán đổi 2 phần tử
void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch mảng
int partition(double arr[], int low, int high) {
    double pivot = arr[high]; // chọn phần tử cuối làm pivot
    int i = low - 1;          // chỉ số phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // hoán đổi phần tử nhỏ hơn về bên trái
        }
    }
    swap(arr[i + 1], arr[high]); // đặt pivot vào đúng vị trí
    return i + 1;
}

// Hàm sắp xếp Quick Sort
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // phân hoạch mảng

        quickSort(arr, low, pi - 1);  // sắp xếp phần bên trái
        quickSort(arr, pi + 1, high); // sắp xếp phần bên phải
    }
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử

    double arr[1000]; // Giả sử tối đa 1000 phần tử

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Nhập từng số thực
    }

    quickSort(arr, 0, n - 1); // Gọi Quick Sort

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << " "; // In dấu cách giữa các số
    }
    cout << endl;

    return 0;
}
