#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void lokasi(double &x , double &y);
void gerak(double &x, double &y);
void gerak_2_input(double &x, double &y, double v, double t, double angle);
void gerak_2(double &x, double &y, double v , double t, double angle);


int main ()
{
    double x;
    double y;
    double v;
    double t;
    double angle;
    string comm;

    cout << "X: ";
    cin >> x;

    cout << "Y: ";
    cin >> y;

    while(comm != "done")
    {
        

        cout << "Pilih perintah yang dinginkan: ";
        cin >> comm;
        if (comm == "lokasi")
        {
            lokasi(x,y);
        }
        else if (comm == "gerak")
        {
            gerak_2_input(x,y,v,t,angle);
        }
        else if (comm == "done")
        {
            cout << "Program is terminated and finished!" << '\n';
        }
        else
        {
            cout << "Input salah!" << '\n';
        }

    }
    
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

void gerak_2_input(double &x, double &y, double v, double t, double angle)
{
    double tempX;
    double tempY;
    double theta;

    cout << "input Velocity(v): ";
    cin >> v;

    cout << "input Time(t): ";
    cin >> t;

    cout << "input theta angle: ";
    cin >> angle;

    theta = angle*(3.14159/180); //Mengubah derajat jadi radian

    cout << "Hasil Sin: "<< sin(theta) << '\n';
    cout << "Hasil Cos: "<< cos(theta) << '\n';

    tempX = (v*t) *cos(theta);
    tempY=  (v*t) *sin(theta);


    x += tempX;
    y += tempY;
}

void gerak_2(double &x, double &y, double v, double t, double angle)
{
    double tempX;
    double tempY;
    double theta;

    theta = angle*(3.14159/180); //Mengubah derajat jadi radian

    cout << "Hasil Sin: "<< sin(theta) << '\n';
    cout << "Hasil Cos: "<< cos(theta) << '\n';

    tempX = (v*t) *cos(theta);
    tempY=  (v*t) *sin(theta);


    x += tempX;
    y += tempY;
}