#ifndef ABSTRACTREACTION_H
#define ABSTRACTREACTION_H

#include "AbstractEffect.h"

class AbstractReaction {
public:
    virtual ~AbstractReaction() = default;

    // Tarkistaa, täyttyvätkö reaktion ehdot
    virtual bool checkCondition(const SpatialEntity& entity) const = 0;

    // Suorittaa reaktion, jos ehdot täyttyvät
    virtual void executeReaction(SpatialEntity& entity) = 0;

    // Palauttaa reaktion nimen
    virtual std::string getReactionName() const = 0;
};

#endif // ABSTRACTREACTION_H

