//
// Created by Мария Ульянова on 27.09.2022.
//

#ifndef CPP_OPENCV_COLOR_HEADER_FILE_H
#define CPP_OPENCV_COLOR_HEADER_FILE_H

#endif //CPP_OPENCV_COLOR_HEADER_FILE_H

//struct color
//{
//    // описание красной, зеленой, и синей компоненты цвета. Диапазон значений - от 0 до 255
//    int red, green, blue;
//
//    // функция вычисления яркости
//    int luminance()
//    {
//        return int(0.212*red + 0.715*green + 0.072*blue);
//    }
//};

class Color
{
private:
    // описание красной, зеленой, и синей компоненты цвета. Диапазон значений - от 0 до 255
    int m_red, m_green, m_blue;
public:
    Color();
    Color(int red, int blue, int green);
    Color(const Color& other);
    ~Color();

    void SetRed(int red); // аналогично – для green и blue
    int GetRed() const; // аналогично – для green и blue
    void SetGreen(int green); // аналогично – для green и blue
    int GetGreen() const;
    void SetBlue(int blue); // аналогично – для green и blue
    int GetBlue() const;
    int luminance() const;

};

inline void Color::SetRed(int red)
{
    m_red  = red;
}
inline int Color:: GetRed() const
{
    return m_red;
}

inline void Color::SetGreen(int green)
{
    m_green  = green;
}
inline int Color:: GetGreen() const
{
    return m_green;
}

inline void Color::SetBlue(int blue)
{
    m_blue  = blue;
}
inline int Color:: GetBlue() const
{
    return m_blue;
}

inline int Color:: luminance() const
{
    return 0.212*m_red + 0.715*m_green + 0.072*m_blue;
}