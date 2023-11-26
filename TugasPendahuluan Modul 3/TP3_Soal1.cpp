#include <iostream>

using namespace std;

//Masih belum ngerti :(

class LinearLine
{
    private:
        // empat float data type, yaitu x1, y1, x2, dan y2
        float x1;
        float x2;
        float y1;
        float y2;

    public:
    LinearLine (float x1, float y1, float x2, float y2) 
    {
        // Isilah definisi constructor ini dengan tujuan untuk
        // menginisialisasi data member
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    float gradient() 
    {
        // hitunglah gradient berdasarkan 4 titik tersebut
        
        float y;
        float m;
        float c;
        m = (y2-y1)/(x2-x1);

        return m;
    }
    float y_intercept() 
    {
        // hitunglah nilai y ketika x = 0
        float y;
        float m;
        float c;
        y = (0*m) + c;

        c = y;

        return c;


    }
    void operator + (float a)
    {
        // Buatlah operator overloading untuk menggeser garis linear
        // sejauh a pada arah sumbu x
    }
    void printEquation(float m, float c) 
    {
        // print equation dengan format y = mx+c
        cout << "y = " << m << " x + " << c << '\n';
        // perhatikan m = gradient dan c = y_intercept
    }




};


int main()
{
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); // inisialisasi objek line
    int a = 3; // nilai banyaknya penggeseran pada persamaan linear



    cout << "Gradient = " << line.gradient() << '\n';
    cout << "Persamaan: " << line.printEquation() << '\n';
    cout << "y_intercept = " << line.y_intercept() << '\n';
    


    /*
    lengkapilah fungsi main sehingga output program seperti pada contoh di bawah

    (x1, y1) = (1, 8)
    (x2, y2) = (2, 3)
    Sehingga didapatkan
    gradient = -5
    y_intercept = 13
    y = -5 x + 13

    Setelah digeser sejauh a, didapatkan persamaan baru:
    y = -5 x + 28
    */
}