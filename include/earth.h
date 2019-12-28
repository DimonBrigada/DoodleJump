#ifndef EARTH_H_
#define EARTH_H_

#include <memory>

#include "platform.h"

class Player;

class Earth : public Platform {
 public:
    static std::shared_ptr<Platform> create();
    ~Earth();
    void update(Player* player);
    void fallen(Player* player);

 private:
    Earth();
};

#endif  // EARTH_H_