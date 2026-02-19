#include "core/physics.h"

physics_t::physics_t(float mass, acceleration_t acceleration, velocity_t velocity, float drag)
    : mass(mass), acceleration(acceleration), velocity(velocity), drag(drag) {}

velocity_t physics_t::getSpeed() {
    return velocity;
}

momentum_t physics_t::getMomentum() {
    return {velocity.x_t * mass, velocity.y_t * mass};
}

void physics_t::applyForce(float forceX, float forceY) {
    acceleration.x_tt += forceX / mass;
    acceleration.y_tt += forceY / mass;
}

void physics_t::update(float deltaTime) {
    velocity.x_t += acceleration.x_tt * deltaTime;
    velocity.y_t += acceleration.y_tt * deltaTime;
    velocity.x_t *= (1.0f - drag);
    velocity.y_t *= (1.0f - drag);

    //
}
