#include "Identity.h"
Identity::Identity():body(nullptr), gun(nullptr),Move(0){};
Move::Move(std::uint16_t speed) :speed(speed) {};
void Identity::set_position(char position)
{
	if(position == '-')
	{
		this->body->lef(speed);
	}
	if(position == '+')
	{
		this->body->right(speed);
	}
}

BuilIdentity::BuilIdentity()
{
	this->reset();
}
BuilIdentity::~BuilIdentity()
{
	delete this->result;
}
void BuilIdentity::reset()
{
	this->result = new Identity;
}
Identity* BuilIdentity::GetIdentity()
{
	Identity* for_return = this->result;
	this->reset();
	return for_return;
}
void Identity::init()
{
	this->body->init();
}
void Identity::draw()
{
	this->body->draw_new_position();
	Rectangle rec = this->body->get_rec();
	this->gun->draw_new_position_gun_body(rec);
}
void Identity::shot()
{
	this->gun->atack();
}
void BuilIdentity::ProductBody(Rectangle rec, std::uint16_t hp){


	this->result->body = new Body(rec);
	if (rec.width >= 50 && rec.width < 60)
	{
		this->result->speed = 5;
		this->result->body->set_hp(10);
	}
	if (rec.width >= 60 && rec.width < 70)
	{
		this->result->speed = 3;
		this->result->body->set_hp(20);
	}
	if (rec.width >= 70 && rec.width < 80)
	{
		this->result->speed = 3;
		this->result->body->set_hp(30);
	}
	if (rec.width >= 80 && rec.width < 90)
	{
		this->result->speed = 2;
		this->result->body->set_hp(40);
	}
	if (rec.width >= 90 && rec.width <= 100)
	{
		this->result->speed = 1;
		this->result->body->set_hp(50);
	}
	this->main_body = rec;
	std::cout << "sa produs corpul\n";
};
void BuilIdentity::ProductGun(std::uint16_t id_gun) 
{
	Factory_Gun gun_factory;
	this->result->gun = gun_factory.Create_Gun(id_gun,this->main_body);
	std::cout << "sa produs arma\n";
};
