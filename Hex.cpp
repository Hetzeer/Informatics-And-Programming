#include <time.h>
#include <locale.h>
#include "Hex.h"

Hex::Hex() {
    size = 4;
    num = new unsigned char[size+1];
    for (int i = 0; i < size; i++) {
        num[i] = '0';
    }
}

Hex::Hex(unsigned char* _num, int _size) {
    size = _size;
    num = new unsigned char[size+1];
    for (int i = 0; i < size; i++)
    {
        num[i] = _num[i];
    }

}

Hex::Hex(const Hex& c) {

    size = c.size;
    num = new unsigned char[size+1];
    for (int i = 0; i < size; i++)
    {
        num[i] = c.num[i];
    }

}

Hex::Hex(int _size) {
    num = new unsigned char[_size];
    cout << "Ввудите Шестнадцатеричное число\n";
    cout << "В размере " << _size<< " символов"<<endl; 
    for (int i = 0; i < _size; i++)
    {
        cin >> num[i];
        while (num[i] < '0' || num[i] > 'F')
        { 
            cout << "Введено неверное значение"<<endl; 
            cin >> num[i];
        }
    }
    size = _size;

}

Hex::~Hex() {
    size = 0;
    delete []num;
}

void Hex::generate() {
    int vib;

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        vib = rand() % 2;
        if (vib == 1)
            num[size - i - 1] = char('0' + rand() % ('9' - '0'));
        else 
            num[size - i - 1] = char('A' + rand() % ('F' - 'A'));
    }
}

int Hex::convert() {
    int* res = new int[size];
    unsigned long long int sum = 0;

    for (int i = 0; i < size; i++)
    {
        res[i] = static_cast<int>(num[i]) - 48;
        if (res[i] > 9) { res[i] = res[i] - 7; }
    }

    for (int i = 0; i < size; i++)
    {
        res[i] *= (int)pow(16, i);
        sum += res[i];
    }
   
    delete[]res;
    return sum;
}

void Hex::in() {
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
}

void Hex::out() {
    for (int i = 0; i < size; i++)
    {
        cout << num[i];
    }
}

void Hex::outp()
{
    for (int i = 0; i < size; i++)
    {
        cout << num[size -i-1];
    }
}

int Hex::inf() {
    FILE* file = fopen("C:\\in.txt", "r");
    char* str = new char[32];
    *str = { 0 };
    if (file == NULL)
    {
        cout << "Нет доступа к файлу\n";
        return 0;
    }
    else {
        while (!feof(file))
        {
            fgets(str, 32, file);
        }
    }
    int size = 0;
    size = strlen(str);
    for (int i = 0; i < size; i++) { num[i] = str[i]; }
    fclose(file);
    this->size = size;
    delete[]str;
    return 1;
}

int Hex::outf() {
    FILE* file = fopen("C:\\out.txt", "w");
    if (file == NULL)
    {
        cout << "Нет доступа к файлу\n";
        return 0;
    }
    for (int i = 0; i < size; i++) { fputc(num[i], file); }
    fclose(file);
    return 1;
}

Hex Hex::operator+(const Hex& tmp) const {
    Hex res,test;
    int* a = new int[size + 1];
    int* b = new int[tmp.size + 1];
    int bigerSize = (size > tmp.size) ? size : tmp.size;
    for (int i = 0; i < bigerSize; i++) {                           
        a[i] = 0;
        b[i] = 0;
    }
    bool five = false;
    for (int i = 0; i < size; i++)
    {
        a[i] = static_cast<int>(num[size - i - 1]) - 48;
        if (a[i] > 9) { a[i] = a[i] - 7; }
    }

    for (int i = 0; i < tmp.size; i++)
    {
        b[i] = static_cast<int>(tmp.num[tmp.size - i - 1]) - 48;
        if (b[i] > 9) { b[i] = b[i] - 7; }
    }
    for (int i = 0; i < size; i++)
    {
        res.num[i] = a[i] + b[i];
        if (res.num[i] > 15) { res.num[i] = res.num[i] - 16; a[i + 1] += 1; }
    }
    for (int i = 0; i < size; i++) {
        if ((int)res.num[i] > 9) { res.num[i] = res.num[i] + 55; }
        else { res.num[i] = res.num[i] + 48; }
        if (i + 1 == size && (int)a[i] + (int)b[i] > 15)
        {
            five = 1;
        }
    }
    cout << endl;
    if (five == 1) 
    { 
        cout << ""; 
        res.size = res.size++; 
        res.num[4] = '1';
        five = false; 
    }

    return res;
}

Hex Hex::operator-(const Hex& tmp) const {
    Hex res,tis(*this),tmpsh(tmp);
    int* a = new int[size + 1];
    int* b = new int[tmp.size + 1];
    
    int c = tis.convert();
    int d = tmpsh.convert();
    

    int bigerSize = (size > tmp.size) ? size : tmp.size;
    if (d > c)
    {
        cout << "\nError\n";
        cout << "\nПервое меньше второго\n";
        return 0;
    }
    else {
        bool five = false;
        for (int i = 0; i < bigerSize; i++) {                           
            a[i] = 0;
            b[i] = 0;
        }

        for (int i = 0; i < size; i++)                                  
        {
            a[i] = static_cast<int>(num[size - i - 1]) - 48;
            if (a[i] > 9) { a[i] = a[i] - 7; }
        }
     
        for (int i = 0; i < tmp.size; i++)                                
        {
            b[i] = static_cast<int>(tmp.num[tmp.size - i - 1]) - 48;
            if (b[i] > 9) { b[i] = b[i] - 7; }
        }

        for (int i = 0; i < size; i++)
        {
            res.num[i] = a[i] - b[i];                                                  
            if (res.num[i] < 0)                                         
            {
                res.num[i] = (a[i] - b[i]) - 16;
                a[i + 1] -= 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < size; i++) {                                
            sum += res.num[i];
        }
        if (sum == 0) { res.num[0] = 0; res.size = 1; }
        for (int i = 0; i < size; i++)                                  
        {
            if ((int)res.num[i] > 9)
            {
                res.num[i] = res.num[i] + 55;
            }
            else { res.num[i] = res.num[i] + 48; }
        }
        cout << std::endl;
    }
    return res;
}

Hex& Hex::operator=(const Hex& tmp) {
    int bigSize;
    bigSize = (size > tmp.size) ? size : tmp.size;
    size = tmp.size;
    for (int i = 0; i < bigSize; i++)
    {
        num[i] = tmp.num[i];
    }
    return *this;
}

bool Hex::operator==(const Hex& tmp) {
    bool res = true;
    Hex tis(*this), tmpsh(tmp);
    int D = tis.convert();
    int B = tmpsh.convert();
    if (size != tmp.size) 
    {
        res = false;
        return res;
    }
    else if (B != D)
    {
        res = false;
        return res;
    }
    return res;
}

bool Hex::operator!=(const Hex& tmp) {
    bool res = true;
    Hex tis(*this), tmpsh(tmp);
    int D = tis.convert();
    int B = tmpsh.convert();
    if (size != tmp.size)
    {
        return res;
    }
    else if (B == D)
    {
        res = false;
        return res;
    }
    return res;
}

std::ostream& operator << (std::ostream& stream, const Hex& tmp) {
    FILE* file = fopen("C:\\out.txt", "w");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл для записи\n";
    }
    else
        for (int i = 0; i < tmp.size; i++)
            fputc(tmp.num[tmp.size - i - 1], file);
    fclose(file); 
    stream << "Данные успешно записанны в файл\n";
    return stream;
}

std::istream& operator >> (std::istream& stream, Hex& tmp) {
 
   
    FILE * file = fopen("C:\\in.txt", "r+");
    char* str = new char[32];
    *str = { 0 };
    if (file == NULL)
    {
        cout << "Не удалось прочитать данные с файла\n";
        return stream;
    }
    else {
        while (!feof(file))
        {
            fgets(str, 32, file);
        }
    }
    int size = 0;
    size = strlen(str);
    for (int i = 0; i < size; i++) { tmp.num[i] = str[i]; }
    fclose(file);
    tmp.size = size;
    delete[]str;
    return stream;
}