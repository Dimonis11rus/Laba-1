#ifndef CAR_H
#define CAR_H

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
	car();
	car(char *a, char *b, char *c, char *d, char *e);
	car(const car & arg);
    void set_mark();
    void get_mark();
    void set_model();
    void get_model();
    void set_car_engine();
    void get_car_engine();
    void set_color();
    void get_color();
    void set_kpp();
    void get_kpp();
    ~car();
};

#endif
