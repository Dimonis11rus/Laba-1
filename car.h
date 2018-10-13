#include "head.h"
#include "garage.h"

using namespace std;
char first[20], second[20], third[20], forth[20], fifth[20];
char del_mark[20], del_model[20];
int car_count=0, moto_count=0, bus_count=0;
HANDLE hConsoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
class keeper;
class car : public garage
{
private:
    char *car_mark;
    char *car_model;
    char *car_engine;
    char *car_color;
    char *car_kpp;
public:
    friend keeper;
	car()
	{
        cout<<"Вызов конструктора без параметров\n";
        car_mark=new char[20];
        car_model=new char[20];
        car_engine=new char[5];
        car_color=new char[15];
        car_kpp=new char[15];
	}
	car(char a, char b, char c, char d, char e)
	{
        cout<<"Вызов конструктора с параметрами\n";
        *car_mark=a;    *car_model=b;    *car_engine=c;   *car_color=d; *car_kpp=e;
	}
	car(const car & arg)
    {
        cout<<"Вызов конструктора копирования\n";
		car_mark=new char[20];
        car_model=new char[20];
        car_engine=new char[5];
        car_color=new char[15];
        car_kpp=new char[15];
		for(int q=0; q<20; q++)
            car_mark[q]=arg.car_mark[q];
        for(int q=0; q<20; q++)
            car_model[q]=arg.car_model[q];
        for(int q=0; q<5; q++)
            car_engine[q]=arg.car_engine[q];
        for(int q=0; q<15; q++)
            car_color[q]=arg.car_color[q];
        for(int q=0; q<15; q++)
            car_kpp[q]=arg.car_kpp[q];
    }
    void set_mark()         ///МАРКА АВТОМОБИЛЯ
    {
        cout<<"Введите марку автомобиля: ";     gets(car_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(car_mark); i++)
            cout<<car_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ АВТОМОБИЛЯ
    {
        cout<<"Введите модель автомобиля: ";    gets(car_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(car_model); i++)
            cout<<car_model[i];
        cout<<". ";
    }
    void set_car_engine()         ///ОБЪЕМ ДВИЖКА АВТОМОБИЛЯ
    {
        while(1)
        {
            cout<<"Введите объем двигателя автомобиля: ";
            try
            {
                gets(car_engine);
                for(int m=0; m<strlen(car_engine); m++)
                {
                    if (isalpha(car_engine[m]))
                    {
                        throw 404;
                    }
                }
                break;
            }
            catch(int i)
            {
                SetConsoleTextAttribute(hConsoleHandle, 13);
                cout<<"error "<<i<< " - вводить нужно цифры"<<endl;
                SetConsoleTextAttribute(hConsoleHandle, 15);
            }
        }
    }
    void get_car_engine()
    {
        cout<<"Объем двигателя - ";
        for(int i=0; i<strlen(car_engine); i++)
            cout<<car_engine[i];
        cout<<" л. ";
    }
    void set_color()         ///ЦВЕТ АВТОМОБИЛЯ
    {
        cout<<"Введите цвет автомобиля: ";      gets(car_color);
    }
    void get_color()
    {
        cout<<"Цвет - ";
        for(int i=0; i<strlen(car_color); i++)
            cout<<car_color[i];
        cout<<". ";
    }
    void set_kpp()         ///КОРОБКА ПЕРЕДАЧ АВТОМОБИЛЯ
    {
        cout<<"Введите тип КПП автомобиля: ";       gets(car_kpp);
    }
    void get_kpp()
    {
        cout<<"Коробка передач - ";
        for(int i=0; i<strlen(car_kpp); i++)
            cout<<car_kpp[i];
        cout<<". ";
    }

    ~car()
    {
    delete [] car_mark;
    delete [] car_model;
    delete [] car_engine;
    delete [] car_color;
    delete [] car_kpp;
    }
};
