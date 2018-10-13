#include "head.h"

class keeper
{
public:
	void save_car(car &obj)
	{
    if(!strcmp(obj.car_mark, del_mark) && !strcmp(obj.car_model, del_model))
        return;
    ofstream outfile("BD.txt", ios::app);
        for(int i=0; i<strlen(obj.car_mark); i++)
            outfile<<obj.car_mark[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.car_model); i++)
            outfile<<obj.car_model[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.car_engine); i++)
            outfile<<obj.car_engine[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.car_color); i++)
            outfile<<obj.car_color[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.car_kpp); i++)
            outfile<<obj.car_kpp[i];
        outfile<<"*\n";
    outfile.close();
    }
    void save_motorbike(motorbike &obj)
    {
    if(!strcmp(obj.motorbike_mark, del_mark) && !strcmp(obj.motorbike_model, del_model))
        return;
    ofstream outfile("BD.txt", ios::app);
        for(int i=0; i<strlen(obj.motorbike_mark); i++)
            outfile<<obj.motorbike_mark[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.motorbike_model); i++)
            outfile<<obj.motorbike_model[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.motorbike_engine); i++)
            outfile<<obj.motorbike_engine[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.motorbike_power); i++)
            outfile<<obj.motorbike_power[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.motorbike_terrain); i++)
            outfile<<obj.motorbike_terrain[i];
        outfile<<"#\n";
    outfile.close();
    }
    void save_bus(bus &obj)
    {
    if(!strcmp(obj.bus_mark, del_mark) && !strcmp(obj.bus_model, del_model))
        return;
    ofstream outfile("BD.txt", ios::app);
        for(int i=0; i<strlen(obj.bus_mark); i++)
            outfile<<obj.bus_mark[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.bus_model); i++)
            outfile<<obj.bus_model[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.bus_seats); i++)
            outfile<<obj.bus_seats[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.bus_all_passengers); i++)
            outfile<<obj.bus_all_passengers[i];
        outfile<<'$';
        for(int i=0; i<strlen(obj.final_destination); i++)
            outfile<<obj.final_destination[i];
        outfile<<"@\n";
    outfile.close();
    }

    void read_file(car &obj_c, motorbike &obj_m, bus &obj_b, int &ii, int &car_count, int &moto_count, int &bus_count, char *str)
    {
        //infile.getline(str, 1024);
        ///                     СЧИТЫВАНИЕ ИЗ ФАЙЛА В БАЗУ
        char type;      ///Чтобы понять какой вид транспорта считываем  * - машина      #- мотоцикл      @ - автобус
            int jj=0;
            while(str[ii]!='$')
            {
                first[jj]=str[ii];
                ii++;    jj++;
            }
            ii++;    jj=0;
            while(str[ii]!='$')
            {
                second[jj]=str[ii];
                ii++;    jj++;
            }
            ii++;    jj=0;
            while(str[ii]!='$')
            {
                third[jj]=str[ii];
                ii++;    jj++;
            }
            ii++;    jj=0;
            while(str[ii]!='$')
            {
                forth[jj]=str[ii];
                ii++;    jj++;
            }
            ii++;    jj=0;
            while(str[ii]!='*' && str[ii]!='#'  && str[ii]!='@')
            {
                fifth[jj]=str[ii];
                ii++;    jj++;
            }
            type=str[ii];
            //cout<<type<<endl;
            switch(type)
            {
            case '*':
                strcpy(obj_c.car_mark, first);
                strcpy(obj_c.car_model, second);
                strcpy(obj_c.car_engine, third);
                strcpy(obj_c.car_color, forth);
                strcpy(obj_c.car_kpp, fifth);
                car_count++;
                break;
            case '#':
                strcpy(obj_m.motorbike_mark, first);
                strcpy(obj_m.motorbike_model, second);
                strcpy(obj_m.motorbike_engine, third);
                strcpy(obj_m.motorbike_power, forth);
                strcpy(obj_m.motorbike_terrain, fifth);
                moto_count++;
                break;
            case '@':
                strcpy(obj_b.bus_mark, first);
                strcpy(obj_b.bus_model, second);
                strcpy(obj_b.bus_seats, third);
                strcpy(obj_b.bus_all_passengers, forth);
                strcpy(obj_b.final_destination, fifth);
                bus_count++;
                break;
            }
            ii++;
            memset(first,'\0',20);   memset(second,'\0',20);    memset(third,'\0',20);    memset(forth,'\0',20);    memset(fifth,'\0',20);
    }

};
