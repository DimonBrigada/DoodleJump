#include "earth.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "resource_holder.h"
#include "player.h"

std::shared_ptr<Earth> Earth::create() {
    std::shared_ptr<Earth> earth(new Earth);
    earth->initialize();
    return earth;
}

Earth::Earth() : Platform(&TextureHolder::getInstance()->get(Textures::EARTH), 0) {
}

Earth::~Earth() {
}

void Earth::fallen(Player* player) {
    if ((player->getVelocity() > 0)
        && isOverlappedToBottom(player)) {
        setHidden(true);
    }
}
