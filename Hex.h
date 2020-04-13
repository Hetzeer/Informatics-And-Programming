#include <iostream>
#include <locale>
using namespace std;
class Hex
{
private:
    unsigned char* num;
    int size;
public:
    Hex();
    Hex(unsigned char* _num, int _size);
    Hex(const Hex& tmp);
    Hex(int size);
    ~Hex();
    void in();                
    void out();
    void outp();
    void generate();                
    int convert();          
    int  inf();               
    int  outf();          
    Hex& operator = (const Hex& tmp);
    Hex  operator + (const Hex& tmp) const;
    Hex  operator - (const Hex& tmp) const;
    bool operator == (const Hex& tmp);
    bool operator != (const Hex& tmp);
    friend std::ostream& operator << (std::ostream& stream, const Hex& tmp);
    friend std::istream& operator >> (std::istream& stream, Hex& tmp);
                
};
