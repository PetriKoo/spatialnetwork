#ifndef ABSTRACTFORCE_H
#define ABSTRACTFORCE_H

#include "SpatialEntity.h"

class AbstractForce {
public:
    virtual ~AbstractForce() = default;

    // Soveltaa voiman entiteettiin
    virtual void applyForce(SpatialEntity& entity, double deltaTime) = 0;

    // Palauttaa voiman nimen
    virtual std::string getForceName() const = 0;
};

#endif // ABSTRACTFORCE_H

