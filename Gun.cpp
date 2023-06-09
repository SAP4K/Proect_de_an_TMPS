#include "Gun.h"
std::uint16_t Gun::nr_bullets = 0;
Bullet::Bullet(const Rectangle& position)
{
	this->property_bullet.x = position.x;
	this->property_bullet.y = position.y;
	this->property_bullet.width = 10;
	this->property_bullet.height = 10;
}
Bullet::Bullet(const Rectangle& position, Color color)
{
	this->property_bullet.x = position.x;
	this->property_bullet.y = position.y;
	this->property_bullet.width = 10;
	this->property_bullet.height = 10;
	DrawRectangle(this->property_bullet.x, this->property_bullet.y, this->property_bullet.width, this->property_bullet.height, color);
}
void Bullet::move_bullet_bot(Color color)
{
	this->property_bullet.y += 5;
	DrawRectangle(this->property_bullet.x, this->property_bullet.y, this->property_bullet.width, this->property_bullet.height, color);
}
void Bullet::draw_new_position()
{
	this->property_bullet.y -= 5;
	DrawRectangle(this->property_bullet.x, this->property_bullet.y, this->property_bullet.width, this->property_bullet.height, WHITE);
}

Gun::Gun(std::uint16_t damage){}


Simple_Gun::Simple_Gun(std::uint16_t damage, const Rectangle& position):Gun(damage)
{
	
	this->body_gun = new Rectangle;
	this->body_gun->x = position.x + position.width/2;
	this->body_gun->width = position.width/5;
	this->body_gun->x -= this->body_gun->width / 2;
	this->body_gun->height = position.height/2;
	this->body_gun->y = position.y - this->body_gun->height;
	this->damage = damage;
}
void Simple_Gun::atack()
{
	this->bullets[this->nr_bullets] = new Bullet(*this->body_gun);
	this->nr_bullets++;
}


void Gun::draw_bullet()
{
	if (!this->bullets.empty()) {
		std::map<uint16_t, Bullet*>::iterator show_bullet = this->bullets.begin();
		while (show_bullet != this->bullets.end())
		{
			show_bullet->second->draw_new_position();
			show_bullet++;
		}
	}
}

void Simple_Gun::draw_gun_body()
{
	DrawRectangle(this->body_gun->x, this->body_gun->y, this->body_gun->width, this->body_gun->height, WHITE);
}
void Simple_Gun::draw_new_position_gun_body(const Rectangle& position)
{
	this->body_gun->x = position.x + position.width / 2;
	this->body_gun->width = position.width / 5;
	this->body_gun->x -= this->body_gun->width / 2;
	this->body_gun->height = position.height / 2;
	this->body_gun->y = position.y - this->body_gun->height;
	this->draw_gun_body();
	this->draw_bullet();
}
Double_Gun::Double_Gun(std::uint16_t damage, const Rectangle& position):Gun(damage)
{
	this->body_gun = new Rectangle[2];
	this->body_gun[0].y = position.y+position.height/2;
	this->body_gun[0].x = position.x;
	this->body_gun[0].width = -position.width/5;
	this->body_gun[0].height = -position.height*1.2;

	this->body_gun[1].y = position.y + position.height / 2;
	this->body_gun[1].width = -position.width / 5;
	this->body_gun[1].height = -position.height * 1.2;
	this->body_gun[1].x = position.x + position.width - this->body_gun[1].width;
}
void Double_Gun::atack()
{
	this->bullets[this->nr_bullets] = new Bullet(this->body_gun[0]);
	this->nr_bullets++;
	this->bullets[this->nr_bullets] = new Bullet(this->body_gun[1]);
	this->nr_bullets++;
}
void Double_Gun::draw_gun_body()
{
	DrawRectangle(this->body_gun[0].x, this->body_gun[0].y, this->body_gun[0].width, this->body_gun[0].height, WHITE);
	DrawRectangle(this->body_gun[1].x, this->body_gun[1].y, this->body_gun[1].width, this->body_gun[1].height, WHITE);
}
void Double_Gun::draw_new_position_gun_body(const Rectangle& position)
{
	this->body_gun[0].y = position.y + position.height / 2;
	this->body_gun[0].x = position.x;
	this->body_gun[0].width = -position.width / 5;
	this->body_gun[0].height = -position.height * 1.2;

	this->body_gun[1].y = position.y + position.height / 2;
	this->body_gun[1].width = -position.width / 5;
	this->body_gun[1].height = -position.height * 1.2;
	this->body_gun[1].x = position.x + position.width - this->body_gun[1].width;
	this->draw_gun_body();
	this->draw_bullet();
}
Gun* Factory_Gun::Create_Gun(std::uint16_t id,const Rectangle& main_body) 
{
	if(id==1)
	{
		return new Simple_Gun(8, main_body);
	}
	if(id==2)
	{
		return new Double_Gun(3, main_body);
	}
	return nullptr;
};