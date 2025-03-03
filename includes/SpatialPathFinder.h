#ifndef SPATIALPATHFINDER_H
#define SPATIALPATHFINDER_H

#include <vector>
#include <string>
#include "SpatialEntity.h"
#include "SpatialNetwork.h"

class SpatialPathFinder {
public:
    // Laskee optimaalisen reitin annetun SpatialNetwork:n sisällä kahden objektin välillä.
    // Palauttaa reitin vektorina, jossa ensimmäisenä on lähtöpiste ja viimeisenä maali.
    std::vector<const SpatialEntity*> findOptimalPath(const SpatialNetwork* network,
                                                        const std::string& startName,
                                                        const std::string& goalName);
};

#endif // SPATIALPATHFINDER_H

