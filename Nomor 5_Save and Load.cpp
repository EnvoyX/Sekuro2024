#include <iostream>
#include <iomanip>

using namespace std;

//Insialisasi Fungsi 
void location(int &x, int &y);
void peta(int size, int map[][15]);
void gerak(int &x, int &y, int map[][15], int &deltaX, int &deltaY);
void showMap(int size, int map[][15]);
void history(int &x, int &y, int map[][15], int &deltaX, int &deltaY);
void redo(int &x, int &y, int &deltaX, int &deltaY, int map[][15]);
void undo(int &x, int &y, int &deltaX, int &deltaY, int map[][15]);
void save(int &x, int &y, int size, int map[][15], int savedmap[][15], int &savedX,  int &savedY);
void load(int &x, int &y, int size, int map[][15], int savedmap[][15], int &savedX,  int &savedY);
void reset(int &x , int &y, int size, int map[][15]);

int main ()
{

    //inisialisasi variabel
    int x;
    int y;
    int deltaX = 0;
    int deltaY = 0;
    int size = 15;
    int map[15][15];
    int savedmap[15][15];
    int savedX = 0;
    int savedY = 0;
    string comm;
    

    peta(size,map); //Membuat map history


    //Menginput posisi awal X dan Y
    cout << "Masukkan X awal: ";
    cin >> x;

    cout << "Masukkan Y awal: ";
    cin >> y;

    history(x,y,map,deltaX,deltaY); //memasukkan X dan Y awal ke map

    while(comm != "done")  // membuat perintah yang bisa berulang2 sampai user memilih perinta "done"
    {   
        cout << "Pilih perintah: ";  //Memilih perintah
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

        else if (comm == "save")
        {
            save(x,y,size,map,savedmap,savedX,savedY);
            cout << "Save Berhasil!" << '\n';
        }

        else if (comm == "load")
        {
            load(x,y,size,map,savedmap,savedX,savedY);
            cout << "Load Berhasil!" << '\n';
        }
        else if (comm == "reset")
        {
            reset(x,y,size,map);
            cout << "Reset Berhasil!" << '\n';
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
    // Memberikan Informasi lokasi x dan y terbaru
    cout << "Lokasi X dan Y sekarang ada di titik: " << '\n';
    cout << "(" << x << "," << y  << ")" <<'\n';
}

void gerak(int &x,int &y, int map[][15], int &deltaX, int &deltaY)
{
    //inisialisasi variabel untuk mengubah posisi x dan y setelah bergerak
    int tempX; 
    int tempY;

    cout << "input gerak X: " << '\n';
    cin >> tempX;

    cout << "input gerak Y: " << '\n';
    cin >> tempY;

    if(x + tempX <= (15-1) && y + tempY <= (15-1) )  //jika masih dalam range maka drone bisa bergerak
    {
        deltaX = tempX; //menandai perubahan x untuk
        deltaY = tempY;
        
        x += (tempX);  //pertambahan koordinat x sebesar tempX
        y += (tempY); //pertambahan koordinat y sebesar tempY

        map[x][y] = 7; //menandai lokasi setelah bergerak
    }

    else
    {
        cout << "Gerak tidak bisa dilakukkan karena diluar batas map" << '\n';
    }

    
}

void peta(int size, int map[][15])
{

    //Membuat peta untuk history
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
    //melihat keadaan map atau history sekarang
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
    // memasukkan kondisi x dan y di awal
    map[x][y] = 7;
    deltaX = 0;
    deltaY = 0;
}

void undo(int &x, int &y, int &deltaX, int &deltaY, int map[][15])
{
    if(map[x-deltaX][y-deltaY] == 7)  //jika di posisi sebelumnya ada tanda 7 maka bisa diundo
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
    if(map[x+deltaX][y+deltaY] == 7) //jika di posisi setelahnya ada tanda 7 maka bisa diundo
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

void save(int &x, int &y, int size, int map[][15], int savedmap[][15], int &savedX,  int &savedY)
{
    //memasukkan data x dan y ke variabel simpanan
    savedX = x;
    savedY = y;

    //meyimpan semua history dari map ke variabel savedmap
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size ;j++)
        {
            savedmap[i][j] = map[i][j];
        }
    }
}

void load(int &x, int &y, int size, int map[][15], int savedmap[][15], int &savedX, int &savedY)
{

    //mengganti data x dan y sekarang dengan savedX dan savedY yang sudah tersimpan
    x = savedX;
    y = savedY;

    //mengganti map sekarang dengan savedmap yang sudah tersimpan
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size;j++)
        {
            map[i][j] = savedmap[i][j];
        }
    }
}

void reset(int &x , int &y, int size, int map[][15])
{
    //Mereset semua variabel x dan y serta map ke 0;
    x = 0;
    y = 0;
    for(int i = 0; i < size; i++ )
    {
        for(int j = 0 ; j < size ; j++)
        {
            map[i][j] = 0;
        }
    }
}







