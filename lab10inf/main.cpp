#include <iostream>

using namespace std;

struct Tur
        {
        public:
            string country;
            double price;
            double april;
            double may;
            double june;
            double jule;
            double august;
            double september;
            struct Tur *before;
        };
int main() {

    return 0;
}
/*
struct Node {char *Name;
             int Value;
             Node *Next
            };
Node *PNode; //объявляется указатель

PNode = new Node; //выделяется память

PNode->Name = "STO"; //присваиваются значения
PNode->Value = 28;
PNode->Next = NULL;

delete PNode; // освобождение памяти
 */