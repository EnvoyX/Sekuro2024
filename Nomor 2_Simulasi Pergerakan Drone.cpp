#include <iostream>
#include <iomanip>

using namespace std;

void lokasi(double &x , double &y);
void gerak(double &x, double &y);

int main ()
{
    double x;
    double y;

    cout << "X: " << '\n';
    cin >> x;

    cout << "Y: ";
    cin >> y;

    cout << "Cek lokasi awal" << "\n";
    lokasi(x,y);


    cout << "Bergerak dengan x dan y yang diinput: " << '\n';
    gerak(x,y);

    cout << "Setelah bergerak, sekarang ada di: " << '\n';
    lokasi(x,y);
    



    
}


void lokasi(double &x , double &y)
{
    cout << "Lokasi X dan Y sekarang adalah" << '\n';
    cout << "(" << fixed << std::setprecision(2) << x << "," << y  << ")" <<'\n';  //Memberikan 2 angka decimal point di belakang koma
}

void gerak (double &x, double &y)
{
    double tempX;
    double tempY;
    cout << "input X: " << '\n';
    cin >> tempX;

    cout << "input y: " << '\n';
    cin >> tempY;

    x += (tempX);
    y += (tempY);
}