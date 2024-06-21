// tabless.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"evil_tree.h"
#include"hash_table.h"
#include"linear_table.h"
#include"list.h"
#include"list_ordered_table.h"
#include"list_unordered_table.h"
#include"poly.h"

using namespace std;

void main()
{
    evil_tree<poly> AVL;
    hash_table<poly> ht;
    linear_table<string, poly> lt;
    list_ordered_table<string, poly> lot;
    list_unordered_table<string, poly> lut;
    string k;
    string value;
    poly pol;
    int choice;
    int c;

    while (true)
    {
        cout << "\nMenu\n 1. Add poly \n 2. Del poly\n 3. Print table\n 4. Find poly for a key\n 5.Mult poly to const\n 0. Exit \n\n Insert choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Insert key: ";
            cin >> k;
            cout << "Insert poly(such us 3x^2y^2z^2-5x^3y^3z^3): ";
            cin >> value;
            pol.str_to_poly(value);
            AVL.Insert_Elem(k, pol);
            ht.Insert(k, pol);
            lt.Insert(k, pol);
            lot.Insert(k, pol);
            lut.Insert(k, pol);
            cout << endl;
            break;
        case 2:
            cout << "Insert key: ";
            cin >> k;
            AVL.Delete_Node_With_Key(k);
            ht.Delete(k);
            lt.Delete(k);
            lot.Delete(k);
            lut.Delete(k);
            cout << endl;
            break; 
        case 3:
            AVL.print();
            ht.print();
            lt.print();
            lot.print();
            lut.print();
                break;
        case 4:
            cout << "Insert key: ";
            cin >> k;
            cout << *AVL.Find(k);
            cout << *ht.Find(k);
            cout << *lt.Find(k);
            cout << *lot.Find(k);
            cout << *lut.Find(k);
            cout << endl;
                break;
        case 5:
            cout << "Insert key: ";
            cin >> k;
            cout << "Insert const: ";
            cin >> c;
            pol = *AVL.Find(k) * c;
            cout << pol << endl;
            pol = *ht.Find(k) * c;
            cout << pol << endl;
            pol = *lt.Find(k) * c;
            cout << pol << endl;
            pol = *lot.Find(k) * c;
            cout << pol << endl;
            pol = *lut.Find(k) * c;
            cout << pol << endl;
            cout << endl;
                break;

        default:
            return;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
