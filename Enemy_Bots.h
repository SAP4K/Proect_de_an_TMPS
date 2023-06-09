#pragma once
#include<raylib.h>
#include<raymath.h>
#include<rlgl.h>
#include<iostream>
#include<map>
#include"Gun.h"
class Bot_Hp_Implementor
{
public:
	virtual void reduction_hp() = 0;	
	Bot_Hp_Implementor(std::int16_t, Color);
protected:
	std::int16_t hp;
	Color bullet_color;
	friend class Body_bot;
};
class Bot_Hp_ImplementorA :public Bot_Hp_Implementor
{
public:
	Bot_Hp_ImplementorA();
	void reduction_hp() override;
};
class Bot_Hp_ImplementorB :public Bot_Hp_Implementor
{
public:
	Bot_Hp_ImplementorB(std::int16_t, Color);
	void reduction_hp() override;
};
class Atack_Bot
{
public:
	virtual void atack() = 0;
protected:
	std::uint16_t damage;
	static std::uint16_t contur;
};

class Move_Bot
{
public:
	virtual void move() = 0;
protected:
	std::int16_t velocity;
	std::map <std::int16_t, Bullet*> bullets;
};
class Body_bot: public Move_Bot, public Atack_Bot
{
public:
	Body_bot(Rectangle, Bot_Hp_Implementor&, int16_t);
	void move() override;
	void atack() override;
private:
	Rectangle rec;
	Bot_Hp_Implementor* body_hp;
	double Timer;
};