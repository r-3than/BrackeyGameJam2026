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

void entity_t::draw()
{
    float w = 32.0f, h = 32.0f;
    if (image)
        image->render((Rectangle){x, y, w, h}, rotation);
}
