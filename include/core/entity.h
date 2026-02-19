#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "raylib.h"
#include "core/camera.h"
#include "core/physics.h"

typedef enum properties {
    NONE,
    CONTROL,
    COLLIDE,
    NOSHOW,
    PHYSICS,
    NOMOVE
} properties_t;

class image_t {
private:
    Texture2D *tex;
    Rectangle source;

    Vector2 origin;

    bool isAnimation;
    int numFrames;
public:
    image_t(Texture2D *ptex, Rectangle psource);
    image_t(Texture2D *ptex, Rectangle psource, int pnumFrames);
    //void nextFrame();
    void render(Rectangle dest, float rot, int frame);
    Rectangle getSource() { return source; }
    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(origin, source);
    }

};

class entity_t {
private:
    image_t *image;
    Rectangle hitbox;

public:
    float x;
    float y;
    float z;
    float rotation;

    int frame;

    physics_t physics;
    
    std::vector<properties_t> properties;

public:
    entity_t(image_t *image);
    entity_t(image_t *image, Rectangle phitbox);
    void setImage(image_t *pimage);
    Rectangle getHitbox();
    image_t* getImage() { return image; }
    void draw(camera_t *camera);

    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(x, y, z, rotation, properties);
    }

};

#endif
