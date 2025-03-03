#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <iostream>
#include <memory>
#include "AbstractShader.h"


class Surface {
private:
    std::string texturePath; // Tekstuurin tiedostopolku
    std::unique_ptr<AbstractShader> shader; // Shader, abstrakti luokka
    float reflectivity;      // Heijastavuus (0.0 - 1.0)
    float roughness;         // Pinnan karkeus (0.0 = täysin sileä, 1.0 = erittäin karkea)

public:
    // Jos shader ei anneta, käytetään oletuksena PhongShaderia.
    Surface(const std::string& texture = "",
            std::unique_ptr<AbstractShader> shader = nullptr,
            float reflect = 0.0f,
            float rough = 0.5f);
    virtual ~Surface() = default;

    // Getterit ja setterit tekstuurille
    std::string getTexturePath() const;
    void setTexturePath(const std::string& path);
    
    // Getterit ja setterit shaderille
    AbstractShader* getShader() const;
    void setShader(std::unique_ptr<AbstractShader> shader);
    
    // Getterit ja setterit heijastavuudelle
    float getReflectivity() const;
    void setReflectivity(float reflect);
    
    // Getterit ja setterit pinnan karkeudelle
    float getRoughness() const;
    void setRoughness(float rough);
    
    // Päivittää pinnan ominaisuuksia ajan myötä
    virtual void update(float deltaTime);
    
    // Tulostaa pinnan tiedot
    virtual void print() const;
};

#endif // SURFACE_H

