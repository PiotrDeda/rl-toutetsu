#pragma once

#include "../../engine/app/app.h"
#include "item_data.h"

class BlankItem : public ItemData
{
public:
	BlankItem()
	{
		this->sprite = App::get().getSprite("blank_item");
		this->type = Blank;
	};
};
