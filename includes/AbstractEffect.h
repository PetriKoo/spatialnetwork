#ifndef ABSTRACTEFFECT_H
#define ABSTRACTEFFECT_H

#include "SpatialEntity.h"

class AbstractEffect {
public:
    virtual ~AbstractEffect() = default;
    
    // Vaikutetaan entiteettiin
    virtual void applyEffect(SpatialEntity& entity, double deltaTime) = 0;

    // Palauttaa efektin nimen
    virtual std::string getEffectName() const = 0;
};

#endif // ABSTRACTEFFECT_H

