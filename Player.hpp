#pragma once
#include "GameObject.hpp"


class Player : GameObject
{
public:
	Player(const std::string& textureFile) : GameObject(textureFile)
	{
		// Additional player initialization
	}
	double GetLTurn()
	{
		return lTurn;
	}
	double GetRTurn()
	{
		return rTurn;
	}
	void SetLTurn(float lTurn)
	{
		lTurn = lTurn;
	}
	void SetRTurn(float rTurn)
	{
		rTurn = rTurn;
	}
	Sprite& GetSprite()
	{
		return *this->sprite;
	}
	void MovePlayer()
	{
		data.SetSize(1.0f);
		data.SetSpeed(1.0f);
		data.SetDistance(1.0f);

	}
	void TurnLeft()
	{
		//SetSprite("Left");
	}
	void TurnRight()
	{
		//SetSprite("Right");
	}
	void CenterOut()
	{
		///SetSprite("Center");
	}
	Data& FetchData()
	{
		return data;
	}
	void SpeedUp()
	{
		SetSpeed(0.2);
		if (aerial == true)
		{
			SetSprite("CarJumpBoost");
		}
		else
		{
			SetSprite("CarBoost");
		}
	}
	void SlowDown()
	{
		SetSpeed(0.01);
		if (aerial == true)
		{
			
		}
	}
private:
	int lTurn;
	int rTurn;
	bool aerial;
	
};