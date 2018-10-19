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
    void set_mark();
    void get_mark();
    void set_model();
    void get_model();
    void set_seats();
    void get_seats();
    void set_all_passengers();
    void get_all_passengers();
    void set_destination();
    void get_destination();
    ~bus();
};

#endif
