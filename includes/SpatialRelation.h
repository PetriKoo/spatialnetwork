#ifndef SPATIALRELATION_H
#define SPATIALRELATION_H

#include "SpatialEntity.h"

class SpatialRelation {
private:
    // Tallennetaan symmetrisesti etäisyydet ja kulmat.
    std::unordered_map<const SpatialEntity*, std::unordered_map<const SpatialEntity*, double>> distances;
    std::unordered_map<const SpatialEntity*, std::unordered_map<const SpatialEntity*, double>> angles;
public:
    void setDistance(const SpatialEntity* obj1, const SpatialEntity* obj2, double distance);
    void setAngle(const SpatialEntity* obj1, const SpatialEntity* obj2, double angle);
    void printRelations() const;

    // Palauttaa kaikki naapurit ja niiden etäisyydet annetulle objektilla.
    const std::unordered_map<const SpatialEntity*, double>& getNeighbors(const SpatialEntity* entity) const;
};

#endif
