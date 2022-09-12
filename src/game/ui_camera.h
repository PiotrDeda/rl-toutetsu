#pragma once

#include "camera.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
class UICamera : public Camera
#pragma clang diagnostic pop
{
public:
	[[nodiscard]] int getScreenX(int x) const override;
	[[nodiscard]] int getScreenY(int y) const override;
	[[nodiscard]] double getScale() const override;
};
