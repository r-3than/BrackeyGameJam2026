#include "core/entity.h"

image_t::image_t(Texture2D *ptex, Rectangle psource)
{
    tex = ptex; source = psource;
    origin = {0.0f, 0.0f};
}

void image_t::render(Rectangle dest, float rot)
{
    DrawTexturePro(*tex, source, dest, origin, rot, WHITE);
}

entity_t::entity_t(image_t *image)
{
    hitbox = (Rectangle){0.0f, 0.0f, 64.0f, 64.0f};
    setImage(image);
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    rotation = 0.0f;

    properties = std::vector<properties_t>();
    properties.push_back(COLLIDE);
}

entity_t::entity_t(image_t *image, Rectangle phitbox)
{
    hitbox = phitbox;
    setImage(image);
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    rotation = 0.0f;

    properties = std::vector<properties_t>();
}

void entity_t::setImage(image_t *pimage)
{
    image = pimage;
}

Rectangle entity_t::getHitbox()
{
    return (Rectangle){hitbox.x+x, hitbox.y+y, hitbox.width, hitbox.height};
}

void entity_t::draw()
{
    float w = 32.0f, h = 32.0f;
    const float scale = 2.0f;
    w*=scale; h*=scale;
    if (image)
        image->render((Rectangle){x, y, w, h}, rotation);
}
