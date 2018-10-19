#include "head.h"
#include "motorbike.h"

motorbike::motorbike()
{
    cout<<"Вызов конструктора без параметров\n";
    motorbike_mark=new char[20];
    motorbike_model=new char[20];
    motorbike_engine=new char[5];
    motorbike_power=new char[5];
    motorbike_terrain=new char[20];
}

motorbike::motorbike(char *a, char *b, char *c, char *d, char *e)
{
    cout<<"Вызов конструктора с параметрами\n";
    motorbike_mark=new char[20];
    motorbike_model=new char[20];
    motorbike_engine=new char[5];
    motorbike_power=new char[5];
    motorbike_terrain=new char[20];
    strcpy(motorbike_mark, a);
    strcpy(motorbike_model, b);
    strcpy(motorbike_engine, c);
    strcpy(motorbike_power, d);
    strcpy(motorbike_terrain, e);
}

motorbike::motorbike(const motorbike & arg)
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
void motorbike::set_mark()         ///МАРКА МОТОЦИКЛА
{
    cout<<"Введите марку мотоцикла: ";          gets(motorbike_mark);
}
void motorbike::motorbike::get_mark()
{
    for(int i=0; i<strlen(motorbike_mark); i++)
        cout<<motorbike_mark[i];
    cout<<" ";
}
void motorbike::set_model()         ///МОДЕЛЬ МОТОЦИКЛА
{
    cout<<"Введите модель мотоцикла: ";         gets(motorbike_model);
}
void motorbike::get_model()
{
    for(int i=0; i<strlen(motorbike_model); i++)
        cout<<motorbike_model[i];
    cout<<". ";
}
void motorbike::set_moto_engine()         ///ОБЪЕМ ДВИЖКА МОТОЦИКЛА
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
void motorbike::get_moto_engine()
{
    cout<<"Объем двигателя - ";
    for(int i=0; i<strlen(motorbike_engine); i++)
        cout<<motorbike_engine[i];
    cout<<" л. ";
}
void motorbike::set_power()         ///МОЩНОСТЬ МОТОЦИКЛА
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
void motorbike::get_power()
{
    cout<<"Мощность - ";
    for(int i=0; i<strlen(motorbike_power); i++)
        cout<<motorbike_power[i];
    cout<<" л.c. ";
}
void motorbike::set_terrain()         ///МЕСТНОСТЬ ДЛЯ МОТОЦИКЛА
{
    cout<<"Введите для какой местности мотоцикл: ";
    gets(motorbike_terrain);
}
void motorbike::get_terrain()
{
    cout<<"Для ";
    for(int i=0; i<strlen(motorbike_terrain); i++)
        cout<<motorbike_terrain[i];
    cout<<" местности.";
}

motorbike::~motorbike()
{
    cout<<"Мотоцикл удалена!\n";
    delete [] motorbike_mark;
    delete [] motorbike_model;
    delete [] motorbike_engine;
    delete [] motorbike_power;
    delete [] motorbike_terrain;
}

