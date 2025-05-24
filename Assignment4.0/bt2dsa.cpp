#include<iostream>
using namespace std;


struct Node {
    int data1;
    int data2;
    Node* next;
    Node* prev;


    Node(int x, int p) {
        data1 = x;
        data2 = p;
        next = nullptr;
        prev = nullptr;
    }
};


class doublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // In danh sách theo định dạng (data1,data2);(data1,data2);...
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->data1 << "," << temp->data2 << ")";
            temp = temp->next;
            if (temp != nullptr) {
                cout << ";";
            }
        }
        cout << endl;
    }

    // Thêm phần tử mới vào hàng đợi theo thứ tự ưu tiên giảm dần (priority queue)
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);

        // TH1: danh sách rỗng
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        // TH2: độ ưu tiên lớn hơn head → chèn vào đầu
        else if (p > head->data2) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        // TH3: độ ưu tiên nhỏ hơn hoặc bằng tail → chèn vào cuối
        else if (p <= tail->data2) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        // TH4: chèn vào giữa danh sách
        else {
            Node* temp = head;
            // Duyệt đến node trước vị trí cần chèn
            while (temp->next && p <= temp->next->data2) {
                temp = temp->next;
            }
            // Chèn newNode vào sau temp
            newNode->next = temp->next;
            if (temp->next) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Loại bỏ phần tử có độ ưu tiên cao nhất (ở đầu danh sách)
    void dequeue() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next; // Cập nhật head
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; // Danh sách rỗng sau khi xóa
            }
            delete temp; // Giải phóng bộ nhớ node bị xóa
        }
    }
};

// Hàm main: xử lý các lệnh nhập vào và gọi các thao tác tương ứng
int main() {
    int n;
    cin >> n; // Nhập số lệnh

    int x, p;
    doublyLinkedList myList; // Tạo danh sách liên kết đôi
    string operat;

    for (int i = 0; i < n; i++) {
        cin >> operat;
        if (operat == "enqueue") {
            cin >> x >> p;
            myList.enqueue(x, p); // Thêm phần tử (x,p) vào hàng đợi
        } else if (operat == "dequeue") {
            myList.dequeue(); // Loại bỏ phần tử ưu tiên cao nhất
        } else {
            cout << " invalid"; // Lệnh không hợp lệ
        }
    }

    myList.print(); // In danh sách sau khi xử lý xong
    return 0;
}

