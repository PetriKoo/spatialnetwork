#ifndef ABSTRACTSHADER_H
#define ABSTRACTSHADER_H

#include <string>
#include <iostream>

class AbstractShader {
public:
    virtual ~AbstractShader() = default;
    
    // Palauttaa shaderin nimen, esim. "PhongShader"
    virtual std::string getName() const = 0;
    
    // Päivittää shaderin tilaa ajan myötä
    virtual void update(float deltaTime) = 0;
    
    // Tulostaa shaderin tiedot
    virtual void print() const = 0;
    
    // Simuloidaan shaderin aktivointia (esimerkiksi renderöintiin)
    virtual void apply() const = 0;
};

#endif // ABSTRACTSHADER_H

