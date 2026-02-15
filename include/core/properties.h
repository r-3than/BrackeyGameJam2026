#ifndef PROPERTIES_H
#define PROPERTIES_H

class base_prop_t {};

class gravity_prop_t : public base_prop_t {
public:
    bool gravityEffected;
    Vector2 gravity;
};

class laser_prop_t : public base_prop_t {
public:
    Vector2 laserDir;
    float laserSpeed;
};

#endif
