#ifndef ABSTRACTSPATIALENTITYTYPE_H
#define ABSTRACTSPATIALENTITYTYPE_H

#include <string>
#include <unordered_map>

class AbstractSpatialEntityType {
protected:
    std::string typeName;
    std::unordered_map<std::string, double> defaultAttributes;

public:
    explicit AbstractSpatialEntityType(const std::string& name);
    virtual ~AbstractSpatialEntityType() = default;

    std::string getTypeName() const { return typeName; }
    
    void setDefaultAttribute(const std::string& key, double value);
    double getDefaultAttribute(const std::string& key) const;

    virtual void describe() const = 0;  // Jätetään aliluokkien toteutettavaksi
};

#endif // ABSTRACTSPATIALENTITYTYPE_H

