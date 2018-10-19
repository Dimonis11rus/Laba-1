#ifndef MOTORBIKE_H
#define MOTORBIKE_H

class keeper;
class motorbike
{
private:
    char *motorbike_mark;
    char *motorbike_model;
    char *motorbike_engine;
    char *motorbike_power;
    char *motorbike_terrain;
public:
    friend keeper;
	motorbike();
	motorbike(char *a, char *b, char *c, char *d, char *e);
	motorbike(const motorbike & arg);
    void set_mark();
    void get_mark();
    void set_model();
    void get_model();
    void set_moto_engine();
    void get_moto_engine();
    void set_power();
    void get_power();
    void set_terrain();
    void get_terrain();
    ~motorbike();
};

#endif
