#ifndef ROAD_H
#define ROAD_H

#include "Object.h"

class Road : public Object {
private:
    double travelCost; // Matalampi arvo tekee tien käytöstä edullisempaa.
public:
    Road(const std::string& name, double cost = 0.5); // Oletusarvo, esim. 0.5, pienempi kuin normaali 1.0.
    double getTravelCost() const;
    void print() const override;
};

#endif
