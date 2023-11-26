#include <iostream>
#include <iomanip>

using namespace std;


void location(int &x, int &y);
void peta(int size, int map[][15]);
void gerak(int &x, int &y, int map[][15], int &deltaX, int &deltaY);
void showMap(int size, int map[][15]);
void history(int &x, int &y, int map[][15], int &deltaX, int &deltaY);
void redo(int &x, int &y, int &deltaX, int &deltaY, int map[][15]);
void undo(int &x, int &y, int &deltaX, int &deltaY, int map[][15]);

int main ()
{

    int x;
    int y;
    int deltaX = 0;
    int deltaY = 0;
    int size = 15;
    int map[15][15];
    string comm;
    

    peta(size,map);



    cout << "Masukkan X awal: ";
    cin >> x;

    cout << "Masukkan Y awal: ";
    cin >> y;

    history(x,y,map,deltaX,deltaY);

    while(comm != "done")
    {   
        cout << "Pilih perintah: ";
        cin >> comm;
        if(comm == "gerak")
        {
            gerak(x,y,map,deltaX,deltaY);
        }
        else if (comm == "lokasi")
        {
            location(x,y); 
        }
        else if (comm == "history")
        {
            showMap(size,map);
        }
        else if (comm == "undo")
        {
            undo(x,y,deltaX,deltaY,map);
        }
        else if (comm == "redo")
        {
            redo(x,y,deltaX,deltaY,map);
        }

        else if(comm == "done")
        {
            break;
        }
        else if(comm == "delta")
        {
            cout << "Delta X: " << deltaX << '\n';
            cout << "Delta Y: " << deltaY << '\n';
        }
        else
        {
            cout << "Salah input" << '\n';
        }
    }


}


void location(int &x, int &y)
{
    cout << "Lokasi X dan Y sekarang ada di titik: " << '\n';
    cout << "(" << x << "," << y  << ")" <<'\n';
}

void gerak(int &x,int &y, int map[][15], int &deltaX, int &deltaY)
{
    int tempX;
    int tempY;

    cout << "input gerak X: " << '\n';
    cin >> tempX;

    cout << "input gerak Y: " << '\n';
    cin >> tempY;

    if(x + tempX <= (15-1) && y + tempY <= (15-1) )
    {
        deltaX = tempX;
        deltaY = tempY;
        
        x += (tempX);
        y += (tempY);

        map[x][y] = 7;
    }

    else
    {
        cout << "Gerak tidak bisa dilakukkan karena diluar batas map" << '\n';
    }

    
}

void peta(int size, int map[][15])
{
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0 ; j < size ; j++)
        {
            map[i][j] = 0;
        }
    }
}

void showMap(int size, int map[][15])
{
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0 ; j < size ; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

void history(int &x, int &y, int map[][15], int &deltaX, int &deltaY)
{
    map[x][y] = 7;
    deltaX = 0;
    deltaY = 0;
}

void undo(int &x, int &y, int &deltaX, int &deltaY, int map[][15])
{
    if(map[x-deltaX][y-deltaY] == 7)
    {
        cout << "Undo Berhasil" << '\n';
        x -= deltaX;
        y -= deltaY;
    }
    else
    {
        cout << "Undo tidak berhasil" << '\n';
    }
}

void redo(int &x, int &y, int &deltaX, int &deltaY, int map[][15])
{
    if(map[x+deltaX][y+deltaY] == 7)
    {
        cout << "Redo Berhasil" << '\n';
        x += deltaX;
        y += deltaY;
    }
    else
    {
        cout << "Redo tidak berhasil" << '\n';
    }
}







