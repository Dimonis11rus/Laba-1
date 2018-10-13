#include "head.h"
#include "car.h"
#include "motorbike.h"
#include "bus.h"
#include "keeper.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    car *car_mas = new car[N];
    motorbike *moto_mas = new motorbike[N];
    bus *bus_mas = new bus[N];
    system("cls");
    keeper s;
    int choise1, choise2;
    char *str=new char[1024];
    ofstream outfile("BD.txt", ios::app);         outfile.close();    ///чтобы создался файл
    while(1)
    {
        int q=0, cnt=0;
        ifstream infile("BD.txt");
        while(!infile.eof())
        {
            infile>>str[q];
            if(str[q]=='*' || str[q]=='@' || str[q]=='#')
                cnt++;                                         ///      cnt - чтобы определить количество транспорта в базе
            q++;
        }
        infile.close();
        int ii=0;
        car_count=0;    moto_count=0;   bus_count=0;
        int w=0;            ///      w-счетчик для цикла
        while(w<cnt)
        {
            s.read_file(car_mas[car_count], moto_mas[moto_count], bus_mas[bus_count], ii, car_count, moto_count, bus_count, str);
            w++;
        }
        SetConsoleTextAttribute(hConsoleHandle, 10);
        cout<<"Вы в гараже, выберите транспорт:\n1)Машина\t"<<car_count<<"\n2)Мотоцикл\t"<<moto_count<<"\n3)Автобус\t"<<bus_count<<"\n4)Удалить транспорт\n0)Выйти\n>";
        SetConsoleTextAttribute(hConsoleHandle, 15);
        cin>>choise1;
        switch(choise1)
        {
        case 1:         ///МАШИНЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    car_mas[car_count].set_mark();
                    car_mas[car_count].set_model();
                    car_mas[car_count].set_car_engine();
                    car_mas[car_count].set_color();
                    car_mas[car_count].set_kpp();
                    s.save_car(car_mas[car_count]);
                    car_count++;
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsoleHandle, 4);
                    for(int j=0; j<car_count; j++)
                    {
                        cout<<" - ";
                        car_mas[j].get_mark();
                        car_mas[j].get_model();
                        car_mas[j].get_car_engine();
                        car_mas[j].get_color();
                        car_mas[j].get_kpp();
                        cout<<endl;
                    }
                    SetConsoleTextAttribute(hConsoleHandle, 15);
                    cout<<endl;
                    system("pause");
                    break;
                }
            }
            break;
        case 2:         ///МОТОЦИКЛЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    moto_mas[moto_count].set_mark();
                    moto_mas[moto_count].set_model();
                    moto_mas[moto_count].set_moto_engine();
                    moto_mas[moto_count].set_power();
                    moto_mas[moto_count].set_terrain();
                    s.save_motorbike(moto_mas[moto_count]);
                    moto_count++;
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsoleHandle, 4);
                    for(int j=0; j<moto_count; j++)
                    {
                        cout<<" - ";
                        moto_mas[j].get_mark();
                        moto_mas[j].get_model();
                        moto_mas[j].get_moto_engine();
                        moto_mas[j].get_power();
                        moto_mas[j].get_terrain();
                        cout<<endl;
                    }
                    SetConsoleTextAttribute(hConsoleHandle, 15);
                    cout<<endl;
                    system("pause");
                    break;
                }
            }
            break;
        case 3:         ///АВТОБУСЫ
            {
                cout<<"1)Записать в базу\n2)Вывести на экран\n>";
                cin>>choise2;
                getchar();
                switch(choise2)
                {
                case 1:
                    bus_mas[bus_count].set_mark();
                    bus_mas[bus_count].set_model();
                    bus_mas[bus_count].set_seats();
                    bus_mas[bus_count].set_all_passengers();
                    bus_mas[bus_count].set_destination();
                    s.save_bus(bus_mas[bus_count]);
                    bus_count++;
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsoleHandle, 4);
                    for(int j=0; j<bus_count; j++)
                    {
                        cout<<" - ";
                        bus_mas[j].get_mark();
                        bus_mas[j].get_model();
                        bus_mas[j].get_seats();
                        bus_mas[j].get_all_passengers();
                        bus_mas[j].get_destination();
                        cout<<endl;
                    }
                    SetConsoleTextAttribute(hConsoleHandle, 15);
                    cout<<endl;
                    system("pause");
                    break;
                }
            }
            break;
        case 4:
            {
                getchar();
                cout<<"Ведите марку транспорта: ";
                gets(del_mark);
                cout<<"Ведите модель транспорта: ";
                gets(del_model);
                ofstream del("BD.txt");         del.close();        ///Для очистки файла
                ofstream outfile("BD.txt", ios::app);
                for(int i=0; i<car_count; i++)
                    s.save_car(car_mas[i]);
                for(int i=0; i<moto_count; i++)
                    s.save_motorbike(moto_mas[i]);
                for(int i=0; i<bus_count; i++)
                    s.save_bus(bus_mas[i]);
                memset(del_mark,'\0',20);   memset(del_model,'\0',20);
                outfile.close();
            }
            break;
        case 0: {exit(1);}
        }
    system("cls");
    }
    delete [] str;
    delete [] car_mas;
    delete [] moto_mas;
    delete [] bus_mas;
    return 0;
}


