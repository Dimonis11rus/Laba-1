#ifndef BUS_H
#define BUS_H

class keeper;
class bus
{
private:
    char *bus_mark;
    char *bus_model;
    char *bus_seats;
    char *bus_all_passengers;
    char *final_destination;
public:
    friend keeper;
	bus();
	bus(char *a, char *b, char *c, char *d, char *e);
	bus(const bus & arg);
    void set_mark();         ///люпйю юбрнасяю
    void get_mark();
    void set_model();         ///лндекэ юбрнасяю
    void get_model();
    void set_seats();         ///яхдъвхе леярю б юбрнасяе
    void get_seats();
    void set_all_passengers();         ///наыее йнк-бн леяр б юбрнасяе
    void get_all_passengers();
    void set_destination();         ///йнмевмши осмйр
    void get_destination();
    ~bus();
};

#endif
