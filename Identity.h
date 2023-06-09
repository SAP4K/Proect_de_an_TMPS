#pragma once
#include<raylib.h>
#include<raymath.h>
#include<rlgl.h>
#include"Gun.h"
#include"Body.h"
class Move
{
public:
	Move(std::uint16_t);
	virtual void set_position(char) = 0;
protected:
	float speed;
};
class Identity:public Move
{
public:
	Identity();
	void set_position(char) override;
	void draw();
	void init();
	void shot();
private:
	Body* body;
	Gun* gun;
	friend class BuilIdentity;
};
class Builder
{
public:
	virtual void ProductBody(Rectangle, std::uint16_t) = 0;
	virtual void ProductGun(std::uint16_t) = 0;
};

class BuilIdentity: public Builder
{
public:
	BuilIdentity();
	~BuilIdentity();
	Identity* GetIdentity();
	void reset();
	void ProductBody(Rectangle,std::uint16_t) override;
	void ProductGun(std::uint16_t) override;
private:
	Identity* result;
	Rectangle main_body;
};