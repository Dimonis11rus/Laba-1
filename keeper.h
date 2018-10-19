#ifndef KEEPER_H
#define KEEPER_H

class keeper
{
public:
	void save_car(car &obj);
    void save_motorbike(motorbike &obj);
    void save_bus(bus &obj);
    void read_file(car &obj_c, motorbike &obj_m, bus &obj_b, int &ii, int &car_count, int &moto_count, int &bus_count, char *str);

};

#endif
