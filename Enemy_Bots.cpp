#include "Enemy_Bots.h"
Bot_Hp_Implementor::Bot_Hp_Implementor(std::int16_t hp, Color color):hp(hp), bullet_color(color) {}



Bot_Hp_ImplementorA::Bot_Hp_ImplementorA():Bot_Hp_Implementor(20, RED){}
void  Bot_Hp_ImplementorA::reduction_hp() {};

Bot_Hp_ImplementorB::Bot_Hp_ImplementorB(std::int16_t hp,Color color):Bot_Hp_Implementor(10, GREEN){}

void Bot_Hp_ImplementorB::reduction_hp() {};


Body_bot::Body_bot(Rectangle rec, Bot_Hp_Implementor& bot_hp, int16_t velocity)
{
	this->rec = rec;
	this->body_hp = &bot_hp;
	this->velocity = velocity;
}
std::uint16_t Atack_Bot::contur = 0;
void Body_bot::move()
{
	this->rec.x += this->velocity;
	DrawRectangle(this->rec.x, this->rec.y, this->rec.width, this->rec.height, this->body_hp->bullet_color);
	if(this->rec.x+rec.width>1000)
	{
		this->rec.x = 20;
	}
}
void Body_bot::atack()
{
	this->move();
	if(Timer >=1)
	{
		this->bullets[this->contur] = new Bullet(this->rec);
		std::map<std::int16_t, Bullet*>::iterator bullet_iterators = this->bullets.begin();
		while(bullet_iterators!= this->bullets.end())
		{
			bullet_iterators->second->move_bullet_bot(this->body_hp->bullet_color);
			bullet_iterators++;
		}
		Timer = 0;
		this->contur++;
	}
	std::cout << Timer << "\n";
	Timer += GetFrameTime();
}