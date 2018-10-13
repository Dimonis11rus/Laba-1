#include "head.h"

using namespace std;

class keeper;
class bus : public garage
{
private:
    char *bus_mark;
    char *bus_model;
    char *bus_seats;
    char *bus_all_passengers;
    char *final_destination;
public:
    friend keeper;
	bus()
	{
	    cout<<"Вызов конструктора без параметров\n";
        bus_mark=new char[20];
        bus_model=new char[20];
        bus_seats=new char[5];
        bus_all_passengers=new char[5];
        final_destination=new char[20];
	}
	bus(char a, char b, char c, char d, char e)
	{
        cout<<"Вызов конструктора с параметрами\n";
        *bus_mark=a;    *bus_model=b;    *bus_seats=c;   *bus_all_passengers=d; *final_destination=e;
	}
	bus(const bus & arg)
    {
        cout<<"Вызов конструктора копирования\n";
		bus_mark=new char[20];
        bus_model=new char[20];
        bus_seats=new char[5];
        bus_all_passengers=new char[5];
        final_destination=new char[20];
		for(int q=0; q<20; q++)
            bus_mark[q]=arg.bus_mark[q];
        for(int q=0; q<20; q++)
            bus_model[q]=arg.bus_model[q];
        for(int q=0; q<5; q++)
            bus_seats[q]=arg.bus_seats[q];
        for(int q=0; q<5; q++)
            bus_all_passengers[q]=arg.bus_all_passengers[q];
        for(int q=0; q<20; q++)
            final_destination[q]=arg.final_destination[q];
    }
    void set_mark()         ///МАРКА АВТОБУСА
    {
        cout<<"Введите марку автобуса: ";       gets(bus_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(bus_mark); i++)
            cout<<bus_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ АВТОБУСА
    {
        cout<<"Введите модель автобуса: ";      gets(bus_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(bus_model); i++)
            cout<<bus_model[i];
        cout<<". ";
    }
    void set_seats()         ///СИДЯЧИЕ МЕСТА В АВТОБУСЕ
    {
        while(1)
        {
            cout<<"Введите количество сидячих мест в автобусе: ";
            try
            {
                gets(bus_seats);
                for(int m=0; m<strlen(bus_seats); m++)
                {
                    if (isalpha(bus_seats[m]))
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
    void get_seats()
    {
        cout<<"Сидячих мест - ";
        for(int i=0; i<strlen(bus_seats); i++)
            cout<<bus_seats[i];
        cout<<". ";
    }
    void set_all_passengers()         ///ОБЩЕЕ КОЛ-ВО МЕСТ В АВТОБУСЕ
    {
        while(1)
        {
            cout<<"Введите общее кол-во мест в автобусе: ";
            try
            {
                gets(bus_all_passengers);
                for(int m=0; m<strlen(bus_all_passengers); m++)
                {
                    if (isalpha(bus_all_passengers[m]))
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
    void get_all_passengers()
    {
        cout<<"Всего мест - ";
        for(int i=0; i<strlen(bus_all_passengers); i++)
            cout<<bus_all_passengers[i];
        cout<<". ";
    }
    void set_destination()         ///КОНЕЧНЫЙ ПУНКТ
    {
        cout<<"Введите название конечного пункта: ";    gets(final_destination);
    }
    void get_destination()
    {
        cout<<"Конечная остановка - ";
        for(int i=0; i<strlen(final_destination); i++)
            cout<<final_destination[i];
        cout<<". ";
    }

    ~bus()
    {
    delete [] bus_mark;
    delete [] bus_model;
    delete [] bus_seats;
    delete [] bus_all_passengers;
    delete [] final_destination;
    }
};
