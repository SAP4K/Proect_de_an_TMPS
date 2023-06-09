#pragma once
#include<raylib.h>
#include<raymath.h>
#include<rlgl.h>
#include<iostream>
class Hp 
{
public:
	Hp();
 
	virtual void decrease_hp(std::uint16_t) = 0;
protected:
	std::int16_t hp;
};

class Move_Body
{
public:
	virtual void draw_new_position() = 0;
};

class Body: public Hp, public Move_Body
{
public:
	Body(Rectangle);
	void decrease_hp(std::uint16_t) override;
	void draw_new_position() override;
	void init();
	void lef(float);
	void right(float);
	void set_hp(std::int16_t);
	Rectangle get_rec();
private:
	Rectangle body_rectangle;
};

