#pragma once

#include <array>

class Camera
{
public:
	[[nodiscard]] virtual int getScreenX(int gameX) const;
	[[nodiscard]] virtual int getScreenY(int gameY) const;
	[[nodiscard]] virtual double getScale() const;
	void move(int x, int y);
	void centerOn(int newX, int newY);
	void setBoundaries(int minX, int minY, int maxX, int maxY);
	void zoomIn();
	void zoomOut();
	void resetCamera();

private:
	void updateBoundaries();

	double x = 0, minX = 0, maxX = 0, curMinX = 0, curMaxX = 0;
	double y = 0, minY = 0, maxY = 0, curMinY = 0, curMaxY = 0;
	std::array<double, 5> scales = {0.5, 0.75, 1.0, 1.25, 1.5};
	unsigned long long selectedScale = scales.size() / 2;
};
