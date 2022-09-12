#pragma once

#include "camera.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
class UICamera : public Camera
#pragma clang diagnostic pop
{
public:
	[[nodiscard]] int getScreenX(int gameX) const override;
	[[nodiscard]] int getScreenY(int gameY) const override;
	[[nodiscard]] double getScale() const override;
};
