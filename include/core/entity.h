#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "raylib.h"
#include "core/properties.h"

class image_t {
private:
    Texture2D *tex;
    Rectangle source;

    Vector2 origin;

public:
    image_t(Texture2D *ptex, Rectangle psource);
    void render(Rectangle dest, float rot);
    Rectangle getSource() { return source; }
    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(origin, source);
    }

};


class properties_t {
private:
    std::vector<base_prop_t> props;
};

class entity_t {
private:
    image_t *image;

public:
    float x;
    float y;
    float z;
    float rotation;

    properties_t properties;

public:
    entity_t(image_t *image);
    void setImage(image_t *pimage);
    void draw();

    template<class Archive>
    void serialize(Archive& archive)
    {
        archive(x, y, z, rotation, properties);
    }

};

#endif
