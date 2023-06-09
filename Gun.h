#pragma once
#include<raylib.h>
#include<raymath.h>
#include<rlgl.h>
#include<map>
#include<iostream>
class Bullet
{
public:
	Bullet(const Rectangle&);
	Bullet(const Rectangle&, Color);
	void move_bullet_bot(Color);
private:
	Rectangle property_bullet;
	void draw_new_position();
	friend class Gun;
};

class Gun
{
public:
	Gun(std::uint16_t);
	virtual void atack() = 0;
	void draw_bullet();
	virtual void draw_gun_body() = 0;
	virtual void draw_new_position_gun_body(const Rectangle& position) = 0;
protected:
	std::uint16_t damage;
	Rectangle* body_gun;
	std::map<uint16_t, Bullet*> bullets;
	static std::uint16_t nr_bullets;
};
class Simple_Gun: public Gun
{
public:
	Simple_Gun(std::uint16_t, const Rectangle&);
	void atack() override;
	void draw_gun_body() override;
	void draw_new_position_gun_body(const Rectangle& ) override;
};
class Double_Gun: public Gun
{
public:
	void atack() override;
	void draw_gun_body() override;
	void draw_new_position_gun_body(const Rectangle& ) override;
	Double_Gun(std::uint16_t, const Rectangle&);
};

class Factory_Gun
{
public:
	Gun* Create_Gun(std::uint16_t,const Rectangle&);
};