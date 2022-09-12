#include "camera.h"

int Camera::getScreenX(int gameX) const
{
	return static_cast<int>((gameX - x) * getScale());
}

int Camera::getScreenY(int gameY) const
{
	return static_cast<int>((gameY - y) * getScale());
}

double Camera::getScale() const
{
	return scales[selectedScale];
}

void Camera::move(int dx, int dy)
{
	this->x += dx / getScale();
	this->y += dy / getScale();
	if (x < curMinX)
		x = curMinX;
	if (x > curMaxX)
		x = curMaxX;
	if (y < curMinY)
		y = curMinY;
	if (y > curMaxY)
		y = curMaxY;
}

void Camera::setBoundaries(int newMinX, int newMinY, int newMaxX, int newMaxY)
{
	this->minX = newMinX;
	this->minY = newMinY;
	this->maxX = newMaxX;
	this->maxY = newMaxY;
	updateBoundaries();
}

void Camera::zoomIn()
{
	if (selectedScale < scales.size() - 1)
	{
		selectedScale++;
		updateBoundaries();
	}
}

void Camera::zoomOut()
{
	if (selectedScale > 0)
	{
		selectedScale--;
		updateBoundaries();
	}
}

void Camera::resetCamera()
{
	this->x = 0;
	this->y = 0;
	selectedScale = scales.size() / 2;
	updateBoundaries();
}

void Camera::updateBoundaries()
{
	curMinX = static_cast<int>(minX * scales[selectedScale]);
	curMinY = static_cast<int>(minY * scales[selectedScale]);
	curMaxX = static_cast<int>(maxX * scales[selectedScale]);
	curMaxY = static_cast<int>(maxY * scales[selectedScale]);
	move(0, 0);
}
