#pragma once

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
private:
	float speed;
	float distance;
	float size;
};