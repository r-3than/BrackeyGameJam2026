#include "core/entity_defs.h"
#include "gameplay/gameManager.h"

void entity_defs_t::init() {
    Texture2D *tex = &GameManager::instance().tilesheet;
    image_t* image = new image_t(tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f});
    entity_t* entity = new entity_t(image);



    image = new image_t(tex, (Rectangle){0.0f, 0.0f, 32.0f, 32.0f});
    images.push_back(image);
    entity = new entity_t(images[0]);
    entities.push_back(entity);
    entity_name.push_back("Example Entity 1");

    image = new image_t(tex, (Rectangle){32.0f, 0.0f, 32.0f, 32.0f});
    images.push_back(image);
    entity = new entity_t(images[1]);
    entities.push_back(entity);
    entity_name.push_back("Example Entity 2");

    image = new image_t(tex, (Rectangle){64.0f, 0.0f, 32.0f, 32.0f});
    images.push_back(image);
    entity = new entity_t(images[2]);
    entities.push_back(entity);
    entity_name.push_back("Example Entity 3");
}


