#include "camera.h"

int Camera::getScreenX(int x) const
{
	return x;
}

int Camera::getScreenY(int y) const
{
	return y;
}

double Camera::getScale() const
{
	return scales[selectedScale];
}

void Camera::zoomIn()
{
	if (selectedScale < scales.size() - 1)
		selectedScale++;
}

void Camera::zoomOut()
{
	if (selectedScale > 0)
		selectedScale--;
}

void Camera::resetZoom()
{
	selectedScale = scales.size() / 2;
}
