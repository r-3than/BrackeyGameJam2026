#include "core/entity.h"

image_t::image_t(Texture2D *ptex, Rectangle psource)
{
    tex = ptex; source = psource;
    origin = {0.0f, 0.0f};

    isAnimation = false;
}

// animations are stored as consecutive images (of the same size) horizontally
image_t::image_t(Texture2D *ptex, Rectangle psource, int pnumFrames)
{
    tex = ptex; source = psource;
    origin = {0.0f, 0.0f};

    isAnimation = true;
    numFrames = pnumFrames;
}

void image_t::render(Rectangle dest, float rot, int frame)
{
    if (isAnimation)
    {
        frame %= numFrames;
        source = (Rectangle){source.width*frame, source.y, source.width, source.height};
    }
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
    frame = 0;
    physics = physics_t();
    physics.drag = 0.1f;

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
    frame = 0;
    
    properties = std::vector<properties_t>();
    properties.push_back(COLLIDE);
}

void entity_t::setImage(image_t *pimage)
{
    image = pimage;
}

Rectangle entity_t::getHitbox()
{
    return (Rectangle){hitbox.x+x, hitbox.y+y, hitbox.width, hitbox.height};
}

void entity_t::draw(camera_t *camera)
{
    // TODO: calculate size based on screensize && camera zoom

    // camera->zoom.w/h in pixels(based off spritesheet pixels) -> scale that to fit the screen.

    float w = 32.0f, h = 32.0f;
    //w=32.0f/camera->zoom.w; h=32.0f/camera->zoom.h;
    if (image)
        image->render((Rectangle){x-camera->position.x, y-camera->position.y, w, h}, rotation, frame);
}
