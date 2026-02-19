#ifndef PHYSICS_H
#define PHYSICS_H

static const float GRAVITY = -9.81f/10.0f;

struct momentum_t {
    float x_tm;
    float y_tm;
};

struct acceleration_t {
    float x_tt;
    float y_tt;
};

struct velocity_t
{
    float x_t;
    float y_t;
    velocity_t operator-() const {
        return {-x_t, -y_t};
    }
};


struct physics_t {
    acceleration_t acceleration;
    velocity_t velocity;
    float mass;
    float drag;

    physics_t(float mass = 1.0f, acceleration_t acceleration = {0.0f, -GRAVITY}, velocity_t velocity = {0.0f, 0.0f}, float drag = 0.0f);
    void applyForce(float forceX, float forceY);
    void setMass(float newMass) { mass = newMass; }
    void setAcceleration(float ax, float ay) { acceleration.x_tt = ax; acceleration.y_tt = ay; }
    void resetAcceleration() { acceleration.x_tt = 0.0f; acceleration.y_tt = -GRAVITY; }

    void operator^(physics_t& other) {

        momentum_t total_momentum = {
            velocity.x_t * mass + other.velocity.x_t * other.mass,
            velocity.y_t * mass + other.velocity.y_t * other.mass
        };
        velocity_t new_velocity = {
            total_momentum.x_tm / (mass + other.mass),
            total_momentum.y_tm / (mass + other.mass)
        };
        velocity = -new_velocity;
        other.velocity = new_velocity;
    }

    velocity_t getSpeed();
    momentum_t getMomentum();
    void update(float deltaTime);
};

#endif