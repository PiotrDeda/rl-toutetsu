#include "map_object.h"

MapObject::MapObject(const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<Camera>& camera) : GameObject(sprite,
																												camera) {}
