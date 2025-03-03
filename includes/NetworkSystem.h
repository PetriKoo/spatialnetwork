#ifndef NETWORKSYSTEM_H
#define NETWORKSYSTEM_H

#include <string>
#include "SpatialRelation.h"
#include "SpatialNetwork.h"
#include <unordered_map>

// Verkostojen hallinta. Myös verkostot säilytetään älykkäillä osoittimilla.
class NetworkSystem {
private:
    std::unordered_map<std::string, std::unique_ptr<SpatialNetwork>> networks;
    SpatialRelation networkRelations;
public:
    // Lisää uusi verkosto ja palauttaa sen osoittimen.
    SpatialNetwork* addNetwork(const std::string& netName);
    // Lisää objekti olemassa olevaan verkostoon.
    void addObjectToNetwork(const std::string& netName, const std::string& objName);
    // Asettaa etäisyyden kahden verkoston välillä.
    void setNetworkDistance(const std::string& net1, const std::string& net2, double distance);
    // Asettaa kulman kahden verkoston välillä.
    void setNetworkAngle(const std::string& net1, const std::string& net2, double angle);
    void print() const;
};

#endif
