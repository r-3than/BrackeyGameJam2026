#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "raylib.h"
//#include "core/properties.h"

typedef enum properties {
    NONE,
    CONTROL
} properties_t;

class image_t {
private:
    Texture2D *tex;
    Rectangle source;

    Vector2 origin;

public:
    image_t(Texture2D *ptex, Rectangle psource);
    void render(Rectangle dest, float rot);

};

class entity_t {
private:
    image_t *image;

public:
    float x;
    float y;
    float z;
    float rotation;

    std::vector<properties_t> properties;

public:
    entity_t(image_t *image);
    void setImage(image_t *pimage);
    void draw();

};

#endif
