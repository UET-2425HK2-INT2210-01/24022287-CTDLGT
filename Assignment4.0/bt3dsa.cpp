#include <iostream>
using namespace std;


struct Node {
    char data;
    Node* prev;


    Node(char c) {
        data = c;
        prev = nullptr;
    }
};


class Stack {
public:
    Node* head = nullptr;


    void push(char c) {
        Node* newNode = new Node(c);  // Tạo node mới
        newNode->prev = head;         // Liên kết node mới với đỉnh cũ
        head = newNode;               // Cập nhật đỉnh mới
    }

    // Trả về phần tử ở đỉnh stack
    char top() {
        if (head == nullptr) return '\0'; // Nếu stack rỗng, trả về ký tự null
        return head->data;
    }

    // Loại bỏ phần tử ở đỉnh stack
    void pop() {
        if (head != nullptr) {
            Node* temp = head;        // Lưu node hiện tại
            head = head->prev;        // Lùi đỉnh xuống node trước
            delete temp;              // Xóa node cũ
        }
    }

    // Kiểm tra stack có rỗng không
    bool isEmpty() {
        return head == nullptr;
    }
};

// Hàm kiểm tra chuỗi s có dấu ngoặc hợp lệ không
bool isValid(string s) {
    Stack myStack;

    // Duyệt từng ký tự trong chuỗi
    for (char c : s) {
        // Nếu là dấu ngoặc mở → đưa vào stack
        if (c == '(' || c == '[' || c == '{') {
            myStack.push(c);
        } else {
            // Nếu stack rỗng → không hợp lệ
            if (myStack.isEmpty()) return false;

            char top = myStack.top(); // Lấy phần tử ở đỉnh stack

            // Kiểm tra cặp dấu ngoặc khớp nhau
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                myStack.pop(); // Xóa dấu ngoặc mở khớp
            } else {
                return false;  // Cặp không hợp lệ
            }
        }
    }

    // Nếu sau cùng stack rỗng → hợp lệ
    return myStack.isEmpty();
}

// Hàm main: nhập chuỗi và kiểm tra hợp lệ
int main() {
    string s;
    cin >> s; // Nhập chuỗi chứa các dấu ngoặc

    if (isValid(s)) {
        cout << "Valid";   // Hợp lệ
    } else {
        cout << "Invalid"; // Không hợp lệ
    }

    return 0;
}

