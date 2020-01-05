#include "life_board.h"

#include <life.h>
#include <resource_holder.h>
#include <config.h>

LifeBoard::LifeBoard(const int lives) : num_of_lives_(lives), life_index_(lives - 1) {
    int x = kScreenWidth, y = 10;
    sf::Texture& texture = TextureHolder::getInstance()->get(Textures::DOODLE);
    for (int i = 0; i < num_of_lives_; ++i) {
        x = x - texture.getSize().x / 2 - 5;
        lives_.push_back(std::make_shared<Life>(&texture, x, y));
    }
}

LifeBoard::~LifeBoard() {
}

void LifeBoard::initialize() {
    for (auto& life : lives_) {
        life->setHidden(false);
    }
}

void LifeBoard::update() {
    if (life_index_ < 0) return;
    lives_[life_index_--]->setHidden(true);
}

void LifeBoard::draw(sf::RenderWindow* app) {
    for (auto& life : lives_) {
        life->draw(app);
    }
}
