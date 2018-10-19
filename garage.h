#include "head.h"
#ifndef GARAGE_H
#define GARAGE_H

class garage
{
public:
    garage() {}
    virtual void set_mark()=0;       ///Установка марки транспорта
    virtual void get_mark()=0;       ///Получение марки транспорта
    virtual void set_model()=0;      ///Установка модели транспорта
    virtual void get_model()=0;      ///Получение модели транспорта
    virtual ~garage() {cout<<"Гараж удалён!\n";}
};
#endif
