#ifndef PERCEPTIONSENSOR_H
#define PERCEPTIONSENSOR_H

#include <vector>
#include "SpatialEntity.h"

class PerceptionSensor {
private:
    double fieldOfView;  // Näkökentän kulma (esim. 90 astetta)
    double viewDistance; // Kuinka pitkälle hahmo näkee

public:
    PerceptionSensor(double fov, double distance);
    
    // Suodattaa näkyvät objektit
    std::vector<const SpatialEntity*> getVisibleEntities(const std::vector<const SpatialEntity*>& worldEntities, const SpatialEntity& observer) const;

    void setFieldOfView(double fov);
    double getFieldOfView() const;
    
    void setViewDistance(double distance);
    double getViewDistance() const;
};

#endif // PERCEPTIONSENSOR_H

