#ifndef TRAINS_H
#define TRAINS_H


class Trains
{
public:
    Trains();

    int getRailway_number() const;
    void setRailway_number(int value);

private:
    int railway_number;
};

#endif // TRAINS_H
