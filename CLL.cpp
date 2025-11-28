#include <iostream>
#include <string>
using namespace std;

template<typename T = string>
class CLL {
public:  // REPLACED private: with public: for Node visibility!
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(NULL) {}
    };
private:
    Node* last;

public:
    CLL() : last(NULL) {}

    ~CLL() {
        if (!last) return;
        Node* cur = last->next;
        last->next = NULL;
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    void insert_begin(const T& x) {
        Node* n = new Node(x);
        if (!last) {
            n->next = n;
            last = n;
        } else {
            n->next = last->next;
            last->next = n;
        }
    }

    void insert_end(const T& x) {
        Node* n = new Node(x);
        if (!last) {
            n->next = n;
            last = n;
        } else {
            n->next = last->next;
            last->next = n;
            last = n;
        }
    }

    void insert_at_pos(const T& x, int pos) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (!last || pos == 1) {
            insert_begin(x);
            return;
        }
        Node* p = last->next;
        int c = 1;
        while (p != last && c < pos - 1) {
            p = p->next;
            c++;
        }
        if (c != pos - 1) {
            cout << "Position out of bounds, inserting at end.\n";
            insert_end(x);
            return;
        }
        Node* n = new Node(x);
        n->next = p->next;
        p->next = n;
        if (p == last)
            last = n;
    }

    void delete_begin() {
        if (!last) {
            cout << "List is empty\n";
            return;
        }
        Node* head = last->next;
        if (last == head) {
            delete head;
            last = NULL;
        } else {
            last->next = head->next;
            delete head;
        }
    }

    void delete_end() {
        if (!last) {
            cout << "List is empty\n";
            return;
        }
        Node* head = last->next;
        if (last == head) {
            delete head;
            last = NULL;
        } else {
            Node* prev = head;
            while (prev->next != last)
                prev = prev->next;
            prev->next = last->next;
            delete last;
            last = prev;
        }
    }

    void delete_at_pos(int pos) {
        if (!last || pos <= 0) {
            cout << "Invalid operation\n";
            return;
        }
        Node* head = last->next;
        if (pos == 1) {
            delete_begin();
            return;
        }
        Node* prev = head;
        int c = 1;
        while (prev->next != last->next && c < pos - 1) {
            prev = prev->next;
            c++;
        }
        if (prev->next == last->next || c != pos - 1) {
            cout << "Position out of bounds.\n";
            return;
        }
        Node* del = prev->next;
        prev->next = del->next;
        if (del == last)
            last = prev;
        delete del;
    }

	int search(const T& x) {
	    if (!last) return -1;
	    Node* cur = last->next;
	    int index = 1;
	    do {
	        if (cur->data == x)
	            return index;
	        cur = cur->next;
	        index++;
	    } while (cur != last->next);
	    return -1;
	}

    void traverse_forward() const {
        if (!last) {
            cout << "(empty)\n";
            return;
        }
        Node* cur = last->next;
        cout << "CLL (forward): ";
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != last->next);
        cout << "\n";
    }

    void traverse_reverse() const {
        if (!last) {
            cout << "(empty)\n";
            return;
        }
        cout << "CLL (reverse): ";
        traverse_reverse_helper(last->next, last);
        cout << "\n";
    }
private:
    void traverse_reverse_helper(Node* cur, Node* stop) const {
        if (cur == stop) {
            cout << cur->data << " ";
            return;
        }
        traverse_reverse_helper(cur->next, stop);
        cout << cur->data << " ";
    }
};

int main() {
    CLL<> list; // Can change to CLL<int> list; to use integer-only CLL
    int choice, pos;
    string x;
    cout << "Enter initial CLL elements (end with 'end'): ";
    while (cin >> x && x != "end")
        list.insert_end(x);
    list.traverse_forward();

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at position\n";
        cout << "7. Search\n";
        cout << "8. Traverse forward\n";
        cout << "9. Traverse reverse\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter element: "; cin >> x;
            list.insert_begin(x);
            list.traverse_forward();
            break;
        case 2:
            cout << "Enter element: "; cin >> x;
            list.insert_end(x);
            list.traverse_forward();
            break;
        case 3:
            cout << "Enter element: "; cin >> x;
            cout << "Enter position: "; cin >> pos;
            list.insert_at_pos(x, pos);
            list.traverse_forward();
            break;
        case 4:
            list.delete_begin();
            list.traverse_forward();
            break;
        case 5:
            list.delete_end();
            list.traverse_forward();
            break;
        case 6:
            cout << "Enter position: "; cin >> pos;
            list.delete_at_pos(pos);
            list.traverse_forward();
            break;
        case 7:
            cout << "Enter element to search: "; cin >> x;
            {
			int idx = list.search(x);
			if (idx != -1)
			    cout << "Element found at position: " << idx << "\n";
			else
			    cout << "Element not found\n";
            }
            break;
        case 8:
            list.traverse_forward();
            break;
        case 9:
            list.traverse_reverse();
            break;
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
