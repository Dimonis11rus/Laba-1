#include "head.h"

using namespace std;
class keeper;
class motorbike : public garage
{
private:
    char *motorbike_mark;
    char *motorbike_model;
    char *motorbike_engine;
    char *motorbike_power;
    char *motorbike_terrain;
public:
    friend keeper;
	motorbike()
	{
	    cout<<"Вызов конструктора без параметров\n";
        motorbike_mark=new char[20];
        motorbike_model=new char[20];
        motorbike_engine=new char[5];
        motorbike_power=new char[5];
        motorbike_terrain=new char[20];
	}
	motorbike(char a, char b, char c, char d, char e)
	{
        cout<<"Вызов конструктора с параметрами\n";
        *motorbike_mark=a;    *motorbike_model=b;    *motorbike_engine=c;   *motorbike_power=d; *motorbike_terrain=e;
	}
	motorbike(const motorbike & arg)
    {
        cout<<"Вызов конструктора копирования\n";
		motorbike_mark=new char[20];
        motorbike_model=new char[20];
        motorbike_engine=new char[5];
        motorbike_power=new char[5];
        motorbike_terrain=new char[20];
		for(int q=0; q<20; q++)
            motorbike_mark[q]=arg.motorbike_mark[q];
        for(int q=0; q<20; q++)
            motorbike_model[q]=arg.motorbike_model[q];
        for(int q=0; q<5; q++)
            motorbike_engine[q]=arg.motorbike_engine[q];
        for(int q=0; q<5; q++)
            motorbike_power[q]=arg.motorbike_power[q];
        for(int q=0; q<20; q++)
            motorbike_terrain[q]=arg.motorbike_terrain[q];
    }
    void set_mark()         ///МАРКА МОТОЦИКЛА
    {
        cout<<"Введите марку мотоцикла: ";          gets(motorbike_mark);
    }
    void get_mark()
    {
        for(int i=0; i<strlen(motorbike_mark); i++)
            cout<<motorbike_mark[i];
        cout<<" ";
    }
    void set_model()         ///МОДЕЛЬ МОТОЦИКЛА
    {
        cout<<"Введите модель мотоцикла: ";         gets(motorbike_model);
    }
    void get_model()
    {
        for(int i=0; i<strlen(motorbike_model); i++)
            cout<<motorbike_model[i];
        cout<<". ";
    }
    void set_moto_engine()         ///ОБЪЕМ ДВИЖКА МОТОЦИКЛА
    {
        while(1)
        {
            cout<<"Введите объем двигателя мотоцикла: ";
            try
            {
                gets(motorbike_engine);
                for(int m=0; m<strlen(motorbike_engine); m++)
                {
                    if (isalpha(motorbike_engine[m]))
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
    void get_moto_engine()
    {
        cout<<"Объем двигателя - ";
        for(int i=0; i<strlen(motorbike_engine); i++)
            cout<<motorbike_engine[i];
        cout<<" л. ";
    }
    void set_power()         ///МОЩНОСТЬ МОТОЦИКЛА
    {
        while(1)
        {
            cout<<"Введите мощность двигателя мотоцикла: ";
            try
            {
                gets(motorbike_power);
                for(int m=0; m<strlen(motorbike_power); m++)
                {
                    if (isalpha(motorbike_power[m]) )
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
    void get_power()
    {
        cout<<"Мощность - ";
        for(int i=0; i<strlen(motorbike_power); i++)
            cout<<motorbike_power[i];
        cout<<" л.c. ";
    }
    void set_terrain()         ///МЕСТНОСТЬ ДЛЯ МОТОЦИКЛА
    {
        cout<<"Введите для какой местности мотоцикл: ";
        gets(motorbike_terrain);
    }
    void get_terrain()
    {
        cout<<"Для ";
        for(int i=0; i<strlen(motorbike_terrain); i++)
            cout<<motorbike_terrain[i];
        cout<<" местности.";
    }

    ~motorbike()
    {
    delete [] motorbike_mark;
    delete [] motorbike_model;
    delete [] motorbike_engine;
    delete [] motorbike_power;
    delete [] motorbike_terrain;
    }
};
