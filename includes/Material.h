#ifndef MATERIAL_H
#define MATERIAL_H

#include "AbstractState.h"
#include <memory>
#include <iostream>

class Material {
private:
    double temperature;
    double durability;
    double elasticity;
    double density;
    std::unique_ptr<AbstractState> state;

public:
    Material(double temp, double dur, double elas, double dens, std::unique_ptr<AbstractState> initState)
        : temperature(temp), durability(dur), elasticity(elas), density(dens), state(std::move(initState)) {}

    void update(double deltaTime) {
        if (state) state->update(deltaTime);
    }

    void print() const {
        std::cout << "Material: Temp: " << temperature
                  << ", Durability: " << durability
                  << ", Elasticity: " << elasticity
                  << ", Density: " << density << "\\n";
        if (state) state->print();
    }
};

#endif // MATERIAL_H

