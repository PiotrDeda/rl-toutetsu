#pragma once

#include "../../engine/app/app.h"

class BlankItem : public Item
{
public:
	BlankItem()
	{
		this->sprite = App::get().getSprite("blank_item");
		this->type = Blank;
	};
};
