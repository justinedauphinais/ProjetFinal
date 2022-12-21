#include "torch.h"

/// <summary>
/// Constructeur
/// </summary>
/// <param name="data"></param>
/// <param name="posX"></param>
/// <param name="posY"></param>
torch::torch(gameDataRef data, float posX, float posY, int animationIterator)
{
	_data = data;
	_animationIterator = animationIterator;

	_animation.push_back(_data->assets.getTexture("torch frame 1"));
	_animation.push_back(_data->assets.getTexture("torch frame 2"));
	_animation.push_back(_data->assets.getTexture("torch frame 3"));
	_animation.push_back(_data->assets.getTexture("torch frame 4"));

	_sprite.setTexture(_animation[_animationIterator]);
	_sprite.setScale(2.2f, 2.2f);

	setPosition(posX, posY);
}

/// <summary>
/// Mets à jour le sprite
/// </summary>
/// <param name="dt"></param>
void torch::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > TORCH_ANIMATION_TIME / _animation.size()) {
		_animationIterator++;

		if (_animationIterator >= _animation.size())	// Si fin vecteur
			_animationIterator = 0;

		_sprite.setTexture(_animation[_animationIterator]);

		_clock.restart();
	}
}
