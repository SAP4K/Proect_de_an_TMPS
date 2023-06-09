#include<iostream>
#include<raylib.h>
#include<raymath.h>
#include<rlgl.h>
#include"Identity.h"
#include"Gun.h"
#include"Enemy_Bots.h"
#include<string>

BuilIdentity ident;
bool menu = true;
Rectangle* body_rectangle = new Rectangle{ 450,275,50,50 };
Identity* maint_object = nullptr;
Gun* temporar_gun=nullptr;
int x = 0;
std::uint16_t chose_gun = 1;
Factory_Gun guns;
void set_gun_rectangle()
{
    
    if (chose_gun == 1)
    {
        temporar_gun = guns.Create_Gun(1, *body_rectangle);
    }
    if(chose_gun == 2)
    {
        temporar_gun = guns.Create_Gun(2, *body_rectangle);
    }
    
}
void begin()
{
    char temporar[100] = "Creaza Entitatea";
    DrawText(temporar, 400, 100, 20, WHITE);
    if (x == 0) {
        if (IsKeyPressed(KEY_LEFT))
        {
            if (body_rectangle->height > 50) {
                body_rectangle->width -= 10;
                body_rectangle->height -= 10;
            }
        }
        if (IsKeyPressed(KEY_RIGHT))
        {
            if (body_rectangle->height < 100) {
                body_rectangle->width += 10;
                body_rectangle->height += 10;
            }
        }
    }
    if(x==1)
    {
        if(IsKeyPressed(KEY_LEFT))
        {
            if(chose_gun >1)
            {
                chose_gun--;
                std::cout << chose_gun << "\n";
            }
        }
        if(IsKeyPressed(KEY_RIGHT))
        {
            if(chose_gun<2)
            {
                chose_gun++;
                std::cout << chose_gun << "\n";
            }
        }
        set_gun_rectangle();
    }
    if(x==2)
    {
        maint_object = ident.GetIdentity();
        menu = false;

    }
    if(IsKeyPressed(KEY_ENTER))
    {
        if(x==0)
        {
            ident.ProductBody(*body_rectangle, 3);
        }
        if(x==1)
        {
            ident.ProductGun(chose_gun);
        }
        x++;
        std::cout << x << "\n";
    }
    DrawRectangle(body_rectangle->x,body_rectangle->y,body_rectangle->width,body_rectangle->height,WHITE);
    if(temporar_gun !=nullptr)
    {
        temporar_gun->draw_gun_body();

    }
    delete temporar_gun;
    temporar_gun = nullptr;
}
void run()
{
    if(IsKeyDown(KEY_LEFT))
    {
        maint_object->set_position('-');
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        maint_object->set_position('+');
    }
    if(IsKeyPressed(KEY_SPACE))
    {
        maint_object->shot();
    }
}
double timing = 3;
int main()
{
    Bot_Hp_Implementor* bot_hp = new Bot_Hp_ImplementorA();
    Rectangle rectangle_for_strong_bot = { 20,20,50,50 };
    Atack_Bot* bot = new Body_bot(rectangle_for_strong_bot, *bot_hp, 3);
    InitWindow(1000, 800, "Game");
    SetTargetFPS(120);
    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);
        if (menu) 
        {
            begin();
        }
        else
        {
            if (timing >= 0) {
                std::string temporar = "Jocul Incepe in " + std::to_string(int(timing));
                DrawText(temporar.c_str(), 400, 200, 20, WHITE);
                timing -= GetFrameTime();
            }
            if (timing <= 0) {
                if (x == 2)
                {
                    maint_object->init();
                    x++;
                }
                run();
                maint_object->draw();
                bot->atack();
            }
        }
        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
}