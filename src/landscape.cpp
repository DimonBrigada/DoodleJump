#include "landscape.h"

#include <SFML/Graphics.hpp>

#include "plat.h"

void Subject::addObserver(std::shared_ptr<Observer> observer) {
    observers_.push_back(observer);
}

void Subject::removeObserver(std::shared_ptr<Observer> observer) {
    observers_.remove(observer);
}

void Subject::update(int dy) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->update(dy);
    }
}

void Subject::calculate(int player_x, int player_y, float* dy) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->calculate(player_x, player_y, dy);
    }
}

void Subject::draw(sf::RenderWindow* app, sf::Sprite* sprite) {
    for (auto observer = observers_.begin(); observer != observers_.end(); ++observer) {
        (*observer)->draw(app, sprite);
    }
}

void Landscape::onUpdate(int dy) {
    update(dy);
}

void Landscape::onCalculate(int x, int y, float* dy) {
    calculate(x, y, dy);
}

void Landscape::onDraw(sf::RenderWindow* app, sf::Sprite* sprite) {
    draw(app, sprite);
}
