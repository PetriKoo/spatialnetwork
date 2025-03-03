#ifndef OBJECT_H
#define OBJECT_H

#include "SpatialEntity.h"
#include "Material.h"
#include <unordered_map>
#include <memory>

class Object : public SpatialEntity {
protected:
    std::unordered_map<std::string, double> properties;
    std::unique_ptr<Material> material;

public:
    explicit Object(const std::string& n);
    virtual ~Object() = default;

    void setProperty(const std::string& key, double value);
    double getProperty(const std::string& key) const;

    void setMaterial(std::unique_ptr<Material> mat);
    void updateMaterial(double deltaTime);

    virtual void print() const override;
};

#endif // OBJECT_H

