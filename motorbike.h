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
    void set_mark();         ///люпйю лнрнжхйкю
    void get_mark();
    void set_model();         ///лндекэ лнрнжхйкю
    void get_model();
    void set_moto_engine();         ///назел дбхфйю лнрнжхйкю
    void get_moto_engine();
    void set_power();         ///лнымнярэ лнрнжхйкю
    void get_power();
    void set_terrain();         ///леярмнярэ дкъ лнрнжхйкю
    void get_terrain();
    ~motorbike();
};

#endif
