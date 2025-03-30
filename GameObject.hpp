#pragma once
#include "Data.hpp"
#include "misc.hpp"
#include "TextureHandler.hpp"
class GameObject
{
public:
	
	GameObject(const string& textureName)
	{
		Texture& text = TextureHandler::getInstance().GetTexture(textureName);
		sprite = new Sprite(text);
		sprite->setTexture(texture);
		if (textureName == "Banana")
		{
			
			sprite->setScale(Vector2f(1.0f, 1.0f));
			sprite->setOrigin({ 0.5f, 0.5f });
			sprite->setPosition(Vector2f(500.0f, 0.f));
		}
		if (textureName == "Car")
		{
			
			
			sprite->setScale(Vector2f(0.1f, 0.1f));
			sprite->setOrigin(Vector2f(0.5f, 0.5f));
			sprite->setPosition(Vector2f(699, 900-140.9));
		}
		if (textureName == "Sky")
		{
			sprite->setScale({ 1.f, 1.f });
			sprite->setOrigin({ 0.5f,0.5f });
			sprite->setPosition({ 0, 0 });
		}
		if (textureName == "Ground")
		{
			sprite->setScale({ 1.f,1.f });
			sprite->setOrigin({ 0.5f,0.5f });
			sprite->setPosition({ 0,524 });
		}
		if (textureName == "Boulder")
		{
			sprite->setScale({ 1.f/FINALSCALE, 1.f/FINALSCALE });
			sprite->setOrigin({ 0.5f,0.5f });
			/*Vector2f initialPos = { 802, 524-19.96};
			Vector2f finalPos = { 242, 900 - 174.27 };*/
			Vector2f initialPos = { 839.07, 524 - 19.96 };
			Vector2f finalPos = { 1111, 900 - 174.27 };
			data.SetInitialPos(initialPos);
			data.SetCurrentPos(initialPos);
			sprite->setPosition({initialPos});
			data.SetFinalPos(finalPos);
			
		}
		if (textureName == "Road")
		{
			sprite->setScale({ 1.f,1.f });
			sprite->setOrigin({ 0.5f,0.5f });
			sprite->setPosition({ 192,524 });
		}
		if (textureName == "Sun")
		{
			sprite->setScale({ 0.5f,0.5f });
			sprite->setOrigin({ 0.5f,0.5f });
			sprite->setPosition({ 100,100 });
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
		
		float dx = ((data.GetFinalPos().x - data.GetInitialPos().x));
		float dy = ((data.GetFinalPos().y - data.GetInitialPos().y));
		Vector2f hyp{ dx,dy };
		//sprite->move(hyp.normalized()*speed);
		data.SetCurrentPos({ sprite->getPosition().x, sprite->getPosition().y });
		Vector2f distance{ static_cast<float>(data.GetFinalPos().x - data.GetCurrentPos().x), static_cast<float>(data.GetFinalPos().y - data.GetCurrentPos().y) };
		//Vector2f totalDistance = { dx,dy };
		//float traveledLength = sqrtf((distance.x * distance.x) + (distance.y * distance.y));
		float remainingLength = sqrtf(distance.x * distance.x + distance.y * distance.y);
		float totalLength = sqrtf(dx * dx + dy * dy);
		if (timetobye != true)
		{
			cout << sprite->getPosition().x << endl;
			progress = 1.0f - (remainingLength / totalLength);
			progress = clamp(progress, 0.0f, 1.0f);
			float dynamicSpeed = speed * (1.0f + progress * progress * EXPONENTFACTOR) * 1.5;
			sprite->move(hyp.normalized() * dynamicSpeed);
			float newScaleFactor = (1.0f / FINALSCALE) + (1.0f - 1.0f / FINALSCALE) * pow(progress, EXPONENTFACTOR);
			newScaleFactor = clamp(newScaleFactor, static_cast<float>(1.0f / FINALSCALE), 1.0f);
			sprite->setScale({ newScaleFactor, newScaleFactor });
		}
		
		
		if (progress > 0.98)
		{
			timetobye = true;
			cout << "moving in this function!";
			float exitSpeed = speed * 10.0f;
			Vector2f newhyp = { hyp };
			sprite->move(newhyp.normalized() * exitSpeed);
			FloatRect bounds = sprite->getGlobalBounds();
			Vector2f pos = sprite->getPosition();
			cout << pos.y;
			
			float right = pos.x + bounds.size.x;
			float bottom = pos.y + bounds.size.y;
			if (right < 0 || pos.x > 1690 || bottom < 0 || pos.y > 900)
			{
				cout << "object is off the screen so we shall delete the sprite\n";
				delete sprite;
			}
		}
		
			
		
	
		
		
		////cout << sprite->getScale().x << " " << sprite->getScale().y << "\n";
		//Vector2f scale({ static_cast<float>((1 / FINALSCALE + (1 - 1 / FINALSCALE) * (traveledLength / totalLength))), static_cast<float>((1 / FINALSCALE + (1 - 1 / FINALSCALE) * (traveledLength / totalLength)) )});
		//sprite->setScale(scale);
		

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
	bool timetobye;
	float progress;
private:
	
};

