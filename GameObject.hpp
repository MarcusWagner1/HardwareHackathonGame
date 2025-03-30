#pragma once
#include "Data.hpp"
#include "misc.hpp"
#include "TextureHandler.hpp"
class GameObject
{
public:
	
	GameObject(const string& textureName)
	{
		if (textureName == "Banana")
		{
			Texture& text = TextureHandler::getInstance().GetTexture(textureName);
			sprite = new Sprite(text);
			sprite->setTexture(texture);
			sprite->setScale(Vector2f(1.0f, 1.0f));
			sprite->setOrigin({ 0.5f, 0.5f });
			sprite->setPosition(Vector2f(500.0f, 0.f));
		}
		if (textureName == "Center")
		{
			
			Texture& text = TextureHandler::getInstance().GetTexture(textureName);
			sprite = new Sprite(text);
			sprite->setTexture(texture);
			sprite->setScale(Vector2f(0.1f, 0.1f));
			sprite->setOrigin(Vector2f(0.5f, 0.5f));
			sprite->setPosition(Vector2f(800.0f, 500.0f));
		}
		
	}
	~GameObject()
	{
		delete sprite;
	}
	
	void SetSprite(const string& textName)
	{
		Texture& texture = TextureHandler::getInstance().GetTexture(textName);
		sprite->setTexture(texture);
		sprite->setTextureRect(IntRect({ 0, 0 }, { static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y) }));
	}
	void MoveObject(float speed)
	{
		//sprite->move({ 0.f, speed });
		sprite->setPosition({ sprite->getPosition().x, sprite->getPosition().y + speed });
		//cout << sprite->getPosition().x << " " << sprite->getPosition().y << "\n";
		float distance = sprite->getPosition().y;
		if (distance > 0)
		{
			UpdateScale(0.0, 750.0f, 5.0f, 0.05f, 1.0f);
			//sprite->setTextureRect(IntRect({ 0, 0 },
			//	{ static_cast<int>(sprite->getTexture().getSize().x * sprite->getScale().x),
			//	static_cast<int>(sprite->getTexture().getSize().y * sprite->getScale().y) }
			//));

		}
	}
	void UpdateScale(float playerY, float horizonY, float baseScale, float minScale, float maxScale)
	{
		float distance = sprite->getPosition().y;

		float safeDistance = std::max(1.0f, distance);

		float newScale = baseScale * (1.0f / safeDistance);

		newScale = std::clamp(newScale, minScale, maxScale);

		sprite->setScale({ newScale, newScale });
	}
	Sprite& GetSprite()
	{
		return *sprite;
	}
protected:
	
	void SetSpeed(float speed)
	{
		data.SetSpeed(speed);
	}
	void SetDistance(float distance)
	{
		data.SetDistance(distance);
	}
	void SetSize(float size)
	{
		data.SetSize(size);
	}
	float GetSize()
	{
		return data.GetSize();
	}
	float GetDistance()
	{
		return data.GetDistance();
	}
	float GetSpeed()
	{
		return data.GetSpeed();
	}
	Data data;
	Texture texture;
	Sprite* sprite;
private:
	
};

