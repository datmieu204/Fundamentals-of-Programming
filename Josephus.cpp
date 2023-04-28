/*
Bài toán Josephus có N sinh viên đứng thành vòng tròn ( đánh số thứ tự liên tiếp từ 1 tới N) và được trao thưởng là người thứ M quanh vòng tròn, sau đó người đó bước ra khỏi vòng tròn và vòng tròn được thu hẹp lại. Yêu cầu tìm ra thứ tự từng người được trao thưởng. Hãy viết chương trình giải quyết bài toán Josephus. 

Input: Dòng đầu tiên ghi giá trị N Dòng thứ hai ghi giá trị M 

Output: Dòng đầu tiên ghi danh sách thứ tự lĩnh thưởng cách nhau bởi dấu cách.

*/

#include<iostream>
#include<vector>

using namespace std;

void josephus(int n, int m) {
    vector<int> circle(n);
    //Đánh số thứ tự cho vòng tròn bắt đầu từ 1 
    for (int i = 0; i < n; i++)   circle[i] = i + 1;
    
    int index = 0;
    
    while (n != 1) {
        index = (index + m - 1) % n;
        cout << circle[index] << " ";
        circle.erase(circle.begin() + index);
        n--;
    }
    cout << circle[0] << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    josephus(n,m);
}


/*  KHI DÙNG DSLK 
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    Node* get_list_head(){return head;}

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* current = head;
            do {
                cout << current->value << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }

    void josePhus(int n, int m){
    Node* temp;
        while (n != 1)
        {
            temp = head;
            for (int i = 0; i < m - 2; i++)
            {
                temp = temp->next;
            }
            Node* old = temp->next;
            temp->next = temp->next->next;
            head = temp->next;

            cout << old->value << " ";
            delete old;
            n--;
        }
    }
};


int main() {
    CircularLinkedList myList;
    int n,m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        myList.append(1);
    }
    myList.josePhus(n, m);
    cout << myList.get_list_head()->value;
}
*/
