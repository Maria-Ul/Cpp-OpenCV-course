//
// Created by Мария Ульянова on 27.09.2022.
//
#include "Color_header_file.h"
#include <iostream>
using namespace std;

// конструктор по умолчанию
Color:: Color()
        : m_red(0)
        , m_green(0)
        , m_blue(0)
{
    luminance();
}
// полный конструктор
Color:: Color(int red, int blue, int green)
        : m_red(red)
        , m_blue(blue)
        , m_green(green)
{
    luminance();
}
// конструктор копирования
Color::Color(const Color& other)
        : m_red(other.m_red)
        , m_blue(other.m_blue)
        , m_green(other.m_green)
{
    luminance();
}
//деструктор
Color:: ~Color()
{
}

int main()
{
    Color val_color = Color(5, 15, 3);
    cout << val_color.luminance() << endl;
    return 0;
}