#include "collision.h"

/// <summary>
/// Où le sprite 1 sera le bird et le sprite 2 soit un land ou un pipe
/// </summary>
/// <param name="sprite1"></param>
/// <param name="sprite2"></param>
/// <returns></returns>
bool collision::checkSpriteCollision(Sprite sprite1, Sprite sprite2) const
{
	Rect<float> rect1 = sprite1.getGlobalBounds();	// On crée un rectangle des
	Rect<float> rect2 = sprite2.getGlobalBounds();	// Dimensions des sprites reçus
	return rect1.intersects(rect2);					// True, ils entrent en contact, false sinon
}

/// <summary>
/// 
/// </summary>
/// <param name="sprite1"></param>
/// <param name="scale1"></param>
/// <param name="sprite2"></param>
/// <param name="scale2"></param>
/// <returns></returns>
bool collision::checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const
{
	sprite1.setScale(scale1, scale1);
	sprite2.setScale(scale2, scale2);
	Rect<float> rect1 = sprite1.getGlobalBounds();
	Rect<float> rect2 = sprite2.getGlobalBounds();
	return rect1.intersects(rect2);
}

/// <summary>
/// 
/// </summary>
/// <param name="sprite1"></param>
/// <param name="scale1X"></param>
/// <param name="scale1Y"></param>
/// <param name="sprite2"></param>
/// <param name="scale2X"></param>
/// <param name="scale2Y"></param>
/// <returns></returns>
bool collision::checkSpriteCollision(Sprite sprite1, float scale1X, float scale1Y, Sprite sprite2, float scale2X, float scale2Y) const
{
	sprite1.setScale(scale1X, scale1Y);
	sprite2.setScale(scale2X, scale2Y);
	Rect<float> rect1 = sprite1.getGlobalBounds();
	Rect<float> rect2 = sprite2.getGlobalBounds();
	return rect1.intersects(rect2);
}

/// <summary>
/// 
/// </summary>
/// <param name="sprite1"></param>
/// <param name="sprite2"></param>
/// <returns></returns>
Vector2f collision::getDistance(Sprite sprite1, Sprite sprite2) const
{
	int distanceX = (sprite1.getPosition().x+ sprite1.getGlobalBounds().width) - (sprite2.getPosition().x + sprite2.getGlobalBounds().width);
	int distanceY = (sprite1.getPosition().y + sprite1.getGlobalBounds().height) - (sprite2.getPosition().y + sprite2.getGlobalBounds().height);

	return Vector2f(distanceX, distanceY);
}

/// <summary>
/// 
/// </summary>
/// <param name="sprite1"></param>
/// <param name="scale1X"></param>
/// <param name="scale1Y"></param>
/// <param name="sprite2"></param>
/// <param name="scale2X"></param>
/// <param name="scale2Y"></param>
/// <returns></returns>
bool collision::isPast(Sprite sprite1, Sprite sprite2) const
{
	//sprite1.setScale(scale1X, scale1Y);
	//sprite2.setScale(scale2X, scale2Y);

	return sprite1.getPosition().y + sprite1.getGlobalBounds().height >= sprite2.getPosition().y + sprite2.getGlobalBounds().height;
}
}

 float DistanceToEntity(const Vector2f& LocalPlayer, const Vector2f& Enemy)
{
	return sqrt(pow(LocalPlayer.x - Enemy.x, 2) + pow(LocalPlayer.y - Enemy.y, 2) );
}