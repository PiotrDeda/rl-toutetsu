#pragma once

#include "camera.h"

class UICamera : public Camera
{
public:
	[[nodiscard]] int getScreenX(int gameX) const override;
	[[nodiscard]] int getScreenY(int gameY) const override;
	[[nodiscard]] double getScale() const override;
};
