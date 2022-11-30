#include "inputManager.h"

/// <summary>
/// V�rifie si on a cliqu� sur le sprite de la fen�tre re�us en param�tre
/// </summary>
/// <param name="object"></param>
/// <param name="button"></param>
/// <param name="window"></param>
/// <returns></returns>
bool inputManager::isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window)
{
	if (Mouse::isButtonPressed(button))
	{
		IntRect tempRect(object.getPosition().x, object.getPosition().y,
			object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (tempRect.contains(Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

/// <summary>
/// Retourne la position de la souris de la fen�tre re�ue en param�tre
/// </summary>
/// <param name="window"></param>
/// <returns></returns>
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}