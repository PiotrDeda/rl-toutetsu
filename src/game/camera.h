#pragma once

#include <array>

class Camera
{
public:
	[[nodiscard]] virtual int getScreenX(int x) const;
	[[nodiscard]] virtual int getScreenY(int y) const;
	[[nodiscard]] virtual double getScale() const;
	void zoomIn();
	void zoomOut();
	void resetZoom();

private:
	std::array<double, 5> scales = {0.5, 0.75, 1.0, 1.25, 1.5};
	unsigned long long selectedScale = scales.size() / 2;
};
