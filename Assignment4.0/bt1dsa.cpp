#include <iostream>
using namespace std;


    int data;
    Node* next;

    // Hàm khởi tạo node với giá trị val
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;     // Con trỏ đầu danh sách
    Node* tail;     // Con trỏ cuối danh sách

public:
    // Hàm khởi tạo danh sách rỗng
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Thêm phần tử vào cuối danh sách
    void append(int x) {
        Node* newNode = new Node(x); // Tạo node mới
        if (head == nullptr) {       // Nếu danh sách rỗng
            head = tail = newNode;   // Node mới là cả head và tail
        } else {
            tail->next = newNode;    // Gắn node mới vào cuối danh sách
            tail = newNode;          // Cập nhật tail
        }
        printList();                 // In danh sách sau khi thêm
    }

    // Tìm kiếm phần tử trong danh sách
    void search(int x) {
        Node* current = head;
        int position = 1;
        bool found = false;

        while (current != nullptr) {
            if (current->data == x) {
                found = true;
                cout << position << endl; // In vị trí nếu tìm thấy
                break;
            }
            current = current->next;
            position++;
        }

        if (!found) {
            cout << "NO" << endl; // In "NO" nếu không tìm thấy
        }
    }

    // Đảo ngược danh sách liên kết
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        tail = head; // Cập nhật tail là head ban đầu

        while (current != nullptr) {
            next = current->next;    // Lưu node tiếp theo
            current->next = prev;    // Đảo chiều liên kết
            prev = current;          // Di chuyển prev lên
            current = next;          // Di chuyển current lên
        }

        head = prev; // Cập nhật head mới
    }

    // In toàn bộ danh sách
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) cout << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Hàm hủy: giải phóng bộ nhớ
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current; // Giải phóng node hiện tại
            current = next;
        }
    }
};

// Hàm main: đọc lệnh và xử lý danh sách
int main() {
    LinkedList list;
    int n;
    cin >> n; // Nhập số lượng lệnh

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "append") {
            int x;
            cin >> x;
            list.append(x); // Thêm x vào danh sách
        } else if (command == "search") {
            int x;
            cin >> x;
            list.search(x); // Tìm kiếm x trong danh sách
        } else if (command == "reverse") {
            list.reverse(); // Đảo ngược danh sách
        }
    }

    return 0;
}
