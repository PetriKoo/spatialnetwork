#ifndef WORLDREACTIONSYSTEM_H
#define WORLDREACTIONSYSTEM_H

#include "SpatialEntity.h"
#include "AbstractEffect.h"
#include "AbstractReaction.h"
#include <vector>
#include <memory>

class WorldReactionSystem {
private:
    std::vector<std::unique_ptr<AbstractEffect>> appliedEffects;
    std::vector<std::unique_ptr<AbstractReaction>> registeredReactions;

public:
    WorldReactionSystem() = default;

    // Lisää uusi efekti järjestelmään
    void addEffect(std::unique_ptr<AbstractEffect> effect);

    // Lisää uusi reaktio järjestelmään
    void addReaction(std::unique_ptr<AbstractReaction> reaction);

    // Päivittää maailman tilan
    void updateWorldState(std::vector<SpatialEntity*>& entities, double deltaTime);
};

#endif // WORLDREACTIONSYSTEM_H

