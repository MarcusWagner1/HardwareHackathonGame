#pragma once
#include "misc.hpp"

class Data
{
public:
	Data()
	{

	}
	Data(float speed, float distance, float size)
	{
		
	}
	void SetSpeed(float speed)
	{
		this->speed = speed;
	}
	void SetDistance(float distance)
	{
		this->distance = distance;
	}
	void SetSize(float size)
	{
		this->size = size;
	}
	float GetSize()
	{
		return size;
	}
	float GetDistance()
	{
		return distance;
	}
	float GetSpeed()
	{
		return speed;
	}
	void SetFinalPos(Vector2f newPos)
	{
		finalPos = newPos;
	}
	Vector2f GetFinalPos()
	{
		return finalPos;
	}
	Vector2f GetInitialPos()
	{
		return initialPos;
	}
	void SetInitialPos(Vector2f newPos)
	{
		initialPos = newPos;
	}
	Vector2f GetCurrentPos()
	{
		return currentPos;
	}
	void SetCurrentPos(Vector2f newPos)
	{
		currentPos = newPos;
	}
	
private:
	float speed;
	float distance;
	float size;
	Vector2f finalPos;
	Vector2f initialPos;
	Vector2f currentPos;
	float timeActive;
};