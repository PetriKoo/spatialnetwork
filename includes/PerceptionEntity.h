#ifndef PERCEPTIONENTITY_H
#define PERCEPTIONENTITY_H

#include "SpatialEntity.h"
#include "PerceptionSensor.h"

class PerceptionEntity : public SpatialEntity {
private:
    PerceptionSensor sensor;

public:
    PerceptionEntity(const std::string& id, const std::string& name, std::unique_ptr<AbstractSpatialEntityType> type, double fov, double viewDistance);
    
    // Näkee ja päivittää pelaajan näkyvyyden perusteella
    void updateVision(const std::vector<const SpatialEntity*>& worldEntities);

    void print() const override;
};

#endif // PERCEPTIONENTITY_H

