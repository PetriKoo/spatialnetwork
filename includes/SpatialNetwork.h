#ifndef SPATIALNETWORK_H
#define SPATIALNETWORK_H

#include "SpatialEntity.h"
#include "Object.h"
#include "Road.h"

// Verkosto, joka sisältää objekteja.
class SpatialNetwork : public SpatialEntity {
private:
    std::unordered_map<std::string, std::unique_ptr<Object>> objects;
    SpatialRelation relations;
public:
    explicit SpatialNetwork(const std::string& n);
    // Lisää objekti verkostoon. Palauttaa osoittimen lisättyyn objektiin.
    Object* addObject(const std::string& objName);
    // Lisää tien verkostoon. Palauttaa osoittimen lisättyyn tienä.
    Road* addRoad(const std::string& roadName, double cost = 0.5);
    // Asettaa objektin ominaisuuden.
    void setProperty(const std::string& objName, const std::string& key, double value);
    // Asettaa etäisyyden kahden objektin välillä.
    void setDistance(const std::string& obj1, const std::string& obj2, double distance);
    // Asettaa kulman kahden objektin välillä.
    void setAngle(const std::string& obj1, const std::string& obj2, double angle);
    void print() const override;
    
    // Palauttaa objektien säilön, jotta reitinhaku voi käydä läpi verkoston solmut.
    const std::unordered_map<std::string, std::unique_ptr<Object>>& getObjects() const;
    // Palauttaa SpatialRelation-olion, jotta etäisyystiedot ovat saatavilla.
    const SpatialRelation& getRelations() const;
};

#endif
