#include <iostream>
#include <string.h>
using namespace std;

class child;
class schoolchild {
private:
    char name[20];
    char surname[20];
    int group;
public:
    schoolchild(char *n, char *s, int c) {
        strcpy(name, n);
        strcpy(surname, s);
        group = c;
    }
    void getData() {
        cout << name << " " << surname << "\t" << group << "-� ����" << endl;
    }
    friend child;
};

class child {
public:
    void changeClass(schoolchild &obj, int newCl) {
        obj.group = newCl;
    }

    void getChangeData(schoolchild obj) {
        cout << obj.name << " " << obj.surname << "\t �����������(�) �� " << obj.group << "-� ����" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    schoolchild arsen("Arsen", "Stotskyi", 3);
    schoolchild marian("Marian", "Dolynskyi", 3);
    schoolchild nazar("Nazar", "Slobodyanyk", 3);

    cout << "�� 3 ����i: " << endl;
    arsen.getData();
    marian.getData();
    nazar.getData();

    child transfer;
    transfer.changeClass(arsen, 4);
    transfer.changeClass(marian, 4);

    cout << endl;
    cout << "�� 4 ����i: " << endl;
    transfer.getChangeData(arsen);
    transfer .getChangeData(marian);

    cout << endl;
    cout << "�� 3 ����i: " << endl;
    nazar.getData();



    return 0;
}
