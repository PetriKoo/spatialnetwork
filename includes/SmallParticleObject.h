#ifndef SMALLPARTICLEOBJECT_H
#define SMALLPARTICLEOBJECT_H

#include "PrimitiveShape.h"
#include "ParticleCluster.h"

class SmallParticleObject {
private:
    PrimitiveShape shape;  // Muoto, sisältää mitat ja tiheyden
    ParticleCluster* cluster;  // Partikkeliryhmä, luodaan tarvittaessa
    bool isBroken;  // Onko objekti muuttunut partikkeleiksi?

public:
    SmallParticleObject(const std::string& type, double w, double h, double d, double density, double hardness, double elasticity);
    ~SmallParticleObject();

    void applyForce(double force);
    void update();
    void print() const;

    // Laskee ja palauttaa massan käyttäen muodon tiheyttä ja tilavuutta
    double getMass() const {
        return shape.getDensity() * (shape.getWidth() * shape.getHeight() * shape.getDepth());
    }
};

#endif // SMALLPARTICLEOBJECT_H

