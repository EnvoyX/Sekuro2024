#include <iostream>

using namespace std;


double area_square(double length);
double area_circle(double radius);
double area_rectangle(double length, double width);
double area_triangle(double heigth, double length);

int main()
{
    string choose;
    double radius;
    double length;
    double heigth;
    double width;
    double result;

    while(choose != "Done")
    {
        cout << "======================\n";
        cout << "Choose your shape: " << '\n';
        cout << "======================\n";
        cin >> choose;

        std::cin.clear(); //reset error flag
        fflush(stdin); //clear input buffer

        if (choose == "Circle" || choose == "circle")
        {
            cout << "======================\n";
            cout << "Choose your radius: " << '\n';
            cout << "======================\n";

            cin >> radius;

            double result = area_circle(radius);

            cout << "The result is: " << result << '\n';
        }
        else if(choose == "Rectangle" || choose == "rectangle")
        {
            cout << "======================\n";
            cout << "Choose your length: " << '\n'; 
            cout << "======================\n";

            cin >> length;

            cout << "======================\n";
            cout << "Choose your width: " << '\n';
            cout << "======================\n";

            cin >> width;

            double result = area_rectangle(length, width);

            cout << "The result is: " << result << '\n';

        }
        else if (choose == "Square" || choose == "square")
        {
            cout << "======================\n";
            cout << "Choose your length: " << '\n';
            cout << "======================\n";

            cin >> length;

            double result = area_square(length);

            cout << "The result is: " << result << '\n';
        }

        else if(choose == "Triangle" || choose == "triangle")
        {

            cout << "======================\n";
            cout << "Choose your length: " << '\n';
            cout << "======================\n";
            cin >> length;

            cout << "======================\n";
            cout << "Choose your heigth: " << '\n';
            cout << "======================\n";
            cin >> heigth;

            double result = area_triangle(heigth , length);

            cout << "The result is: " << result << '\n';
        }

        else if(choose == "Done")
        {
            cout << "Selesai!";
        }

        else
        {
            cout << "Wrong Input!" << '\n';
        }
            
    }

}

double area_square(double length)
{
    return length * length;
}
double area_circle(double radius)
{   
    return (3.14) * (radius * radius);
}
double area_rectangle(double length, double width)
{
    return length * width;
}
double area_triangle(double height, double length)
{
    return (0.5)*(height)*(length);
}


