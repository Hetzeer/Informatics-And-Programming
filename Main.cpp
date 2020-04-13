#include "Hex.h"


int main() {
    setlocale(LC_ALL, "RUS");
    
    unsigned char* tmp = new unsigned char[4];
    int size_ = 4;
    for (int i = 0; i < size_; i++) 
        tmp[i] = '4'; 
    Hex obj1, obj2(tmp, size_), obj3(obj2), 
        obj4(4);

    cout<<"Объект 1"<<endl;
    obj1.out();
    cout << endl;
    cout << "Объект 2" << endl;
    obj2.out();
    cout << endl;
    cout << "Объект 3" << endl;
    obj3.out();
    cout << endl;
    cout << "Объект 4" << endl;
    obj4.out();
    cout << endl;
    Hex test;

    cout << "Тест метода ввода" << endl;

    test.in();
    cout << "Вывода" << endl;
    test.out();
    cout << endl;
    cout << "Тест генерации случайного числа" << endl;
    obj1.generate();
    cout << "Вывод" << endl;
    obj1.out();
    cout << endl;
    cout << "Тест перевода из 16 в 10" << endl;
    int a = obj3.convert();
    cout << a<<endl;
    cout << "Тест ввода в файл" << endl;
    obj3.inf();
    cout << "Тест вывода в файл" << endl;
    obj3.outf();

    obj2 = test + obj1;
    cout << "Результат сложения" << endl;
    obj2.outp();


    cout << "\nРезультат вычитания" << endl;
    obj2 = test - obj1;
    obj2.outp();

    Hex obj(obj2);

    if (obj2 == obj)
    {
        cout << "\nОбъект1" << endl;
        obj3.out();
        cout << "\nОбъект2" << endl;
        obj2.out();
        cout << "\nОбъекты равны"<<endl;
    }
    else
        cout << "\nОбъекты не равны" << endl;

    cout << "\nОбъект1" << endl;
    obj1.out();
    cout << "\nОбъект2" << endl;
    obj2.out();

    if (obj2 != obj1)
    {
       
        cout << "\nОбъекты не равны"<<endl;
    }

    cin >> obj1;
    cout << obj2;    
}
