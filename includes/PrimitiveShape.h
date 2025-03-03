#ifndef PRIMITIVESHAPE_H
#define PRIMITIVESHAPE_H

#include <string>

class PrimitiveShape {
protected:
    std::string type;  // "box", "sphere", "polygon"
    double width, height, depth;
    double density, hardness, elasticity;

public:
    PrimitiveShape(const std::string& t, double w, double h, double d, double dens, double hard, double elas);
    virtual ~PrimitiveShape() = default;
    
    virtual void applyForce(double force);
    virtual bool shouldBreak(double force) const;
    
    std::string getType() const;
    void print() const;
};

#endif // PRIMITIVESHAPE_H

