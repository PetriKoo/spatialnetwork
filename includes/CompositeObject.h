#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "SmallParticleObject.h"
#include <vector>
#include <memory>
#include <iostream>

class CompositeObject {
private:
    std::vector<std::unique_ptr<SmallParticleObject>> components;

public:
    CompositeObject() = default;
    
    void addComponent(std::unique_ptr<SmallParticleObject> component) {
        if (!component) return;
        components.push_back(std::move(component));
    }
    
    void applyForce(double force);
    void update();
    
    void print() const {
        if (components.empty()) {
            std::cout << "CompositeObject: (Ei komponentteja)" << std::endl;
            return;
        }
        for (const auto& component : components) {
            component->print();
        }
    }

    // Laskee ja palauttaa kaikkien komponenttien yhteenlasketun massan
    double getTotalMass() const {
        double totalMass = 0.0;
        for (const auto& component : components) {
            totalMass += component->getMass();
        }
        return totalMass;
    }
};

#endif // COMPOSITEOBJECT_H

