#include "Body.h"
Hp::Hp() {};
Body::Body(Rectangle rec) : body_rectangle(rec) 
{

};
void Body::decrease_hp(std::uint16_t damage) 
{
	this->hp -= damage;
};
void Body::draw_new_position()
{
	DrawRectangle(this->body_rectangle.x, this->body_rectangle.y, this->body_rectangle.width, this->body_rectangle.height, WHITE);
}
void Body::init()
{
	this->body_rectangle.x = 20;
	this->body_rectangle.y = 600;
}
void Body::right(float speed)
{
	if(this->body_rectangle.x+this->body_rectangle.width<980)
	{
		this->body_rectangle.x += speed;
	}
}
void Body::lef(float speed)
{
	if (this->body_rectangle.x > 20)
	{
		this->body_rectangle.x -= speed;
	}
}
void Body::set_hp(std::int16_t hp)
{
	this->hp = hp;
}

Rectangle Body::get_rec()
{
	return this->body_rectangle;
}
