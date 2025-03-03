#ifndef SPATIALENTITY_H
#define SPATIALENTITY_H

#include <memory>
#include <vector>
#include <string>
#include "AbstractSpatialEntityType.h"
#include "CompositeObject.h"

class SpatialEntity {
private:
    std::string id;
    std::string name;
    std::unique_ptr<AbstractSpatialEntityType> entityType;
    std::vector<std::unique_ptr<CompositeObject>> components;

public:
    SpatialEntity(const std::string& id, const std::string& name, std::unique_ptr<AbstractSpatialEntityType> type)
        : id(id), name(name), entityType(std::move(type)) {}

    void addComponent(std::unique_ptr<CompositeObject> component) {
        if (!component) return;
        components.push_back(std::move(component));
    }

    void removeComponent(size_t index) {
        if (index < components.size()) {
            components.erase(components.begin() + index);
        }
    }

    const std::vector<std::unique_ptr<CompositeObject>>& getComponents() const { return components; }

    void update(double deltaTime) {
        for (auto& component : components) {
            component->update();
        }
    }

    virtual void print() const;
};

#endif // SPATIALENTITY_H

