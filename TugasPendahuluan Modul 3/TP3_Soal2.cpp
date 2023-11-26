#include <iostream>

using namespace std;

//Masih belum ngerti :(


class Shape
{
    private:
        float area;
        float keliling;
    public:
        // gunakan virtual function
        virtual float calculateArea() 
        { 
            return 0; 
        }
        float calculateKeliling() 
        { 

        return 0; 

        }
};

class Rectangle : private Shape{
    // deklarasikan member data, (float) width dan (float) length
    public:
        float width;
        float length;

    // Buatlah constructor untuk menginisialisasi member!
    Rectangle(float width, float length)
    {
        this->width = width;
        this->length = length;
    }
     // Buatlah calculateArea()
    // Buatlah calculateKeliling()
    float calculateArea()
    {

    }

    float calculateKeliling()
    {

    }

};


int main()
{
    Rectangle rect (5.0, 4.0);
    Shape* shape1 = &rect;

    // dengan menggunakan pointer shape1, panggillah

    // function calculateArea() dan calculateKeliling() pada class Rectangle
    
    // PERIKSA HASILNYA BENAR ATAU SALAH? Jika salah maka perbaikilah base class-nya
}