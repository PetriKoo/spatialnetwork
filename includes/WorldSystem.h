#ifndef WORLDSYSTEM_H
#define WORLDSYSTEM_H

#include "PhysicsSystem.h"
#include "NetworkSystem.h"
#include "WorldReactionSystem.h"
#include "AbstractForce.h"
#include <vector>

class WorldSystem {
private:
    PhysicsSystem physicsSystem;
    WorldReactionSystem reactionSystem;
    NetworkSystem networkSystem;  // Nyt ainoa etäisyyksien hallitsija

    std::vector<SpatialEntity*> entities;

public:
    WorldSystem() = default;

    // Lisää uusi entiteetti maailmaan ja verkostoon
    void addEntity(SpatialEntity* entity);

    // Poistaa entiteetin
    void removeEntity(SpatialEntity* entity);

    // Lisää uusi voima fysiikkajärjestelmään
    void addForce(std::unique_ptr<AbstractForce> force);

    // Hallinnoi verkostoja ja etäisyyksiä
    void addNetwork(const std::string& name);
    void addObjectToNetwork(const std::string& netName, const std::string& objName);
    void setNetworkDistance(const std::string& net1, const std::string& net2, double distance);
    double getNetworkDistance(const std::string& net1, const std::string& net2) const;
    void setNetworkAngle(const std::string& net1, const std::string& net2, double angle);

    void update(double deltaTime);
};

#endif // WORLDSYSTEM_H

