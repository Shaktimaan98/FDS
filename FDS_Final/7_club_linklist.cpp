#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class node {
    int prn;
    string name;
    node *link;
    friend class linkedlist;
};

class linkedlist {
    node *start;

public:
    linkedlist() : start(nullptr) {}

    void insert_President() {
        node *tmp = new node();
        int pr;
        string nm;
        cout << "Enter PRN and Name:\n";
        cin >> pr >> nm;

        tmp->prn = pr;
        tmp->name = nm;
        tmp->link = nullptr;

        if (start == nullptr) {
            start = tmp;
        } else {
            tmp->link = start;
            start = tmp;
        }
        display();
    }

    void insert_Secretary() {
        node *tmp = new node();
        int pr;
        string nm;
        cout << "Enter PRN and Name:\n";
        cin >> pr >> nm;

        tmp->prn = pr;
        tmp->name = nm;
        tmp->link = nullptr;

        if (start == nullptr) {
            start = tmp;
        } else {
            node *q = start;
            while (q->link != nullptr) {
                q = q->link;
            }
            q->link = tmp;
        }
        display();
    }

    void insert_Member() {
        display();
        int pr, index;
        string nm;
        node *tmp = new node();

        cout << "Enter PRN and Name:\n";
        cin >> pr >> nm;

        tmp->prn = pr;
        tmp->name = nm;
        tmp->link = nullptr;

        if (start == nullptr) {
            start = tmp;
        } else {
            cout << "\nEnter index after which element to be inserted:\n";
            cin >> index;
            node *q = start;
            for (int i = 0; i < index; i++) {
                q = q->link;
                if (q == nullptr) {
                    cout << "There are fewer elements\n";
                    return;
                }
            }
            tmp->link = q->link;
            q->link = tmp;
        }
        display();
    }

    void del_President() {
        if (start == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        node *tmp = start;
        start = start->link;
        free(tmp);
        display();
    }

    void del_Secretary() {
        if (start == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        node *q = start;
        node *tmp = start;
        while (tmp->link != nullptr) {
            q = tmp;
            tmp = tmp->link;
        }
        q->link = nullptr;
        free(tmp);
        display();
    }

    void del_Member() {
        int pr;
        cout << "Enter PRN to be deleted: ";
        cin >> pr;

        node *q = start;
        node *tmp = start;

        while (tmp != nullptr) {
            if (tmp->prn == pr) {
                q->link = tmp->link;
                free(tmp);
                break;
            }
            q = tmp;
            tmp = tmp->link;
        }
        display();
    }

    void display() {
        if (start == nullptr) {
            cout << "Club is empty!!\n";
        } else {
            cout << "**** Members in Club ****\n";
            node *q = start;
            while (q != nullptr) {
                cout << q->prn << "  " << q->name << endl;
                q = q->link;
            }
        }
    }

    void count() {
        int i = 0;
        node *q = start;
        while (q != nullptr) {
            i++;
            q = q->link;
        }
        cout << "Total no. of members in club: " << i << endl;
    }

    void reverse1() { reverse(start); }

    void reverse(node *ptr) {
        if (ptr == nullptr) return;
        reverse(ptr->link);
        cout << "\n" << ptr->prn << "\t" << ptr->name;
    }

    void concat(linkedlist &l1, linkedlist &l2) {
        if (l1.start == nullptr) {
            l1.start = l2.start;
        } else {
            node *ptr = l1.start;
            while (ptr->link != nullptr) {
                ptr = ptr->link;
            }
            ptr->link = l2.start;
        }
        l1.display();
    }
};

int main() {
    linkedlist l1, l2;
    int ch;

    cout << "\n**** Linked List *****\n";
    cout << "\n1. Insert President";
    cout << "\n2. Insert Secretary";
    cout << "\n3. Insert Member";
    cout << "\n4. Delete President";
    cout << "\n5. Delete Secretary";
    cout << "\n6. Delete Member";
    cout << "\n7. Display";
    cout << "\n8. Count";
    cout << "\n9. Reverse";
    cout << "\n10. Concat";
    cout << "\n11. Exit\n";

    while (true) {
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                l1.insert_President();
                break;
            case 2:
                l1.insert_Secretary();
                break;
            case 3:
                l1.insert_Member();
                break;
            case 4:
                l1.del_President();
                break;
            case 5:
                l1.del_Secretary();
                break;
            case 6:
                l1.del_Member();
                break;
            case 7:
                l1.display();
                break;
            case 8:
                l1.count();
                break;
            case 9:
                l1.reverse1();
                break;
            case 10:
                cout << "Enter details for second list:\n";
                l2.insert_President();
                l2.insert_Member();
                l2.insert_Secretary();
                l1.concat(l1, l2);
                break;
            case 11:
                exit(0);
            default:
                cout << "\nWrong Choice !!\n";
        }
    }
    return 0;
}
