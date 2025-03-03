#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <string>
#include <iostream>

class AbstractState {
public:
    virtual ~AbstractState() = default;
    
    // Palauttaa olomuodon nimen, esim. "Solid", "Liquid" tai "Gas".
    virtual std::string getName() const = 0;
    
    // Päivittää tilaa ajan myötä (deltaTime voi kuvata ajankulua tai muita muuttujia).
    virtual void update(double deltaTime) = 0;
    
    // Tulostaa tilan tiedot.
    virtual void print() const = 0;
};

#endif // ABSTRACTSTATE_H

