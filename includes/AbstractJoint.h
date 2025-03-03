#ifndef ABSTRACTJOINT_H
#define ABSTRACTJOINT_H

#include <string>
#include <iostream>
#include <memory>

class SpatialEntity;

class AbstractJoint {
protected:
    double rotationLimit;
    double breakForce;
    bool unbreakable;
    bool isBroken;

    std::unique_ptr<AbstractJoint> brokenJointType;
    SpatialEntity* connectedA = nullptr;
    SpatialEntity* connectedB = nullptr;

public:
    AbstractJoint(double rotationLimit, double breakForce, bool unbreakable = false)
        : rotationLimit(rotationLimit), breakForce(breakForce), unbreakable(unbreakable), isBroken(false) {}

    virtual ~AbstractJoint() = default;

    virtual void applyForce(double force);
    virtual void update(double deltaTime);

    bool getIsBroken() const { return isBroken; }

    virtual std::string getType() const = 0;

    virtual void eventWhenBroken();
    virtual void setBrokenType(std::unique_ptr<AbstractJoint> brokenJoint);
    virtual AbstractJoint* getBrokenType() const;

    void setConnectedObjects(SpatialEntity* objA, SpatialEntity* objB) {
        connectedA = objA;
        connectedB = objB;
    }

    SpatialEntity* getConnectedObjectA() const { return connectedA; }
    SpatialEntity* getConnectedObjectB() const { return connectedB; }

    bool hasConnectedObjectA() const { return connectedA != nullptr; }
    bool hasConnectedObjectB() const { return connectedB != nullptr; }

    virtual void print() const;
};

#endif // ABSTRACTJOINT_H

