#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cstdlib"
#include <time.h>
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

    #include <windows.h>
    void delay(int n)
    {
        Sleep(n*1000);
    }

#else

    #include <unistd.h>

    void delay(int n)
    {
        usleep(n);
    }

#endif

using namespace std;

const int n=20; //высота поля
const int m=20; //ширина поля
const int s1=10; //время падения в мс
const int n1=1; //высота нажатия
const int sec=5000;
unsigned a[n][5],dl[5];

void gotoxy(int xpos, int ypos)
{
  COORD scrn;

  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);
}

void fon()
{
    //здесь рисуешь фон
}

void nov(int q)
{
    int x=q*m/6;
    int y=n/10;
    dl[q]++;
    a[dl[q]][q]=y;

    // рисуешь круг с координатами (х;у)
}

void sm(int q)
{
    int i;

    for (i=1;i<dl[q];i++) //смещаем все элементы массива на 1 назад
    {
        a[i-1][q]=a[i][q];

    }
    a[dl[q]][q]=0;
    dl[q]--;

    //удаляешь фигуру
}

void vniz()
{
    int i,k;

    for (i=0;i<5;i++)
    {
        for (k=0;k<a[dl[i]][i];k++)
        {
            int x1=i*n/6;
            int y1=a[k][i];  //координаты фигуры сейчас (если нужны)
            int x2=x1;
            int y2=a[k][i]+(n-n1)/s1; //координаты фигур после перемещения
            a[k][i]=y2;
            if (y1>n-10)
            {
                sm(i);
            }
            else
            {
                //переместить фигуру с координат х1;у1 в х2;у2
            }
        }
    }
}

int main(void)
{
    //setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    fon(); //создаем фон

    unsigned i,k,result,e,m1,s=0;
    char ch;
    bool fl=true;

    for (i=0;i<5;i++) // зануляем все длины
        dl[i]=-1;

   // cin>>sec;sec=sec*1000+100000;  //длительность песни

    int c[sec];         //здесь должна быть нормальная музыка
    {
        for (i=0;i<sec;i++)
        {
            c[i]=rand()%5;
        }
    }

    int b[sec+s1];      //здесь мы должны считвать ноты
    {
        for (i=0;i<sec;i++)
        {
            m1=rand()%51;
            if (m1>45) b[i]=m1-45;
            else b[i]=0;
        }
    }

    for (i=0;i<n;i++)
        {
            cout<<"\n";
            for (k=0;k<5;k++)
            {
                cout<<a[i][k]<<" ";
            }
        }

    system("cls");
    while (sec!=(s+100000))
    {
        ch=0;

        s++; // увеличиваем кол-во мс

        Beep(c[s]*1000,1); // воспроизводим мелодию

        if (b[s+s1]!=0) { gotoxy(20,20);cout<<b[s+s1]; nov(b[s+s1]-1);  } // если есть нота то создаем ее

        result=_kbhit();cout<<result<<"\n"; //если была нажат клавша
        if (result!=0) { ch=_getch(); gotoxy(20,25); cout<<ch; }   //то мы считываем ее в ch

        e=0;
        switch (ch)  //определение колонки которая нажата
        {
            case 'z': { e=1;cout<<e;break; }
            case 'x': { e=2;cout<<e;break; }
            case 'c': { e=3;cout<<e;break; }
            case 'v': { e=4;cout<<e;break; }
            case 'b': { e=5;cout<<e;break; }
            case 'я': { e=1;cout<<e;break; }
            case 'ч': { e=2;cout<<e;break; }
            case 'с': { e=3;cout<<e;break; }
            case 'м': { e=4;cout<<e;break; }
            case 'и': { e=5;cout<<e;break; }
            case 27 : { fl=false;break; }
            case 'q':{ cout<<"programma priostanovlena";_getch();break; }
        }

        if (e!=0) { /*if ((a[0][e-1]>n1-20) && (a[0][e-1]<n1+20))*/ { cout<<"asd";sm(e-1); } }
        // если была нажата клавиша то удаляем элемент

        vniz(); // опускаем все круги вниз

        for (i=0;i<n;i++)
        {
            cout<<"\n";
            for (k=0;k<5;k++)
            {
                cout<<a[i][k]<<" ";
            }
        }

        delay(1);

        system("cls");

        if (fl==false) break;
    }
    cout<<"igra bila zakonchena";
    return 0;
}
