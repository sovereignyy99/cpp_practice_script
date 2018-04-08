/*
 * @Author: MatthewPerry
 * @Date: 2018-04-05 00:38:32
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-05 21:10:49
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

//
// ────────────────────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E C E L A R E T I O N   A N D   D E F I N I T I O N : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────────────────────
//
class screen_cl;
class window_mgr_cl
{
  public:
    //
    // ─── MEMBER DATA TYPE ───────────────────────────────────────────────────────────
    //
    using ScreenIndex = std::vector<screen_cl>::size_type;

    //
    // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
    //
    void Clear(ScreenIndex i);
    ScreenIndex AddScreen(const screen_cl &);

  private:
    //
    // ─── DATA MEMBER ────────────────────────────────────────────────────────────────
    //
    std::vector<screen_cl> Screens_cl_a;
    // std::vector<screen_cl> Screens_cl_a{screen_cl(24, 80, ' ')};
};

class screen_cl
{
  public:
    // friend class window_mgr_cl;
    friend void window_mgr_cl::Clear(ScreenIndex);
    //
    // ─── MEMBER DATA TYPE ───────────────────────────────────────────────────────────
    //
    typedef std::string::size_type pos;
    //
    // ─── CONSTRUCTOR ────────────────────────────────────────────────────────────────
    //
    screen_cl() = default;
    screen_cl(pos ht, pos wd) : Height(ht), Width(wd), strContents(ht * wd, ' ') {}
    screen_cl(pos ht, pos wd, char c) : Height(ht), Width(wd), strContents(ht * wd, c) {}

    //
    // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
    //
    char Get() const { return strContents[Cursor]; }
    char Get(pos r, pos c) const;
    screen_cl &Move(pos r, pos c);
    screen_cl &Set(char);
    screen_cl &Set(pos, pos, char);
    screen_cl &Display(std::ostream &os)
    {
        DoDisplay(os);
        return *this;
    }
    const screen_cl &Display(std::ostream &os) const
    {
        DoDisplay(os);
        return *this;
    }
    pos Size(void) const;

  private:
    //
    // ─── MEMBER FUNCTION ────────────────────────────────────────────────────────────
    //
    void DoDisplay(std::ostream &os) const { os << strContents; }

    //
    // ─── DATA MEMBER ────────────────────────────────────────────────────────────────
    //
    pos Cursor = 0;
    pos Height = 0, Width = 0;
    std::string strContents;
    mutable size_t AccessCtrl;
};

//
// ────────────────────────────────────────────────────────────────────── II ──────────
//   :::::: M E M B E R   F U N C T I O N : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────
//

/**
 * @brief clear index screen to blank screen
 *
 * @param i
 */
inline void window_mgr_cl::Clear(ScreenIndex i)
{
    if (i >= Screens_cl_a.size())
    {
        return;
    }
    screen_cl &s = Screens_cl_a[i];
    s.strContents = std::string(s.Height * s.Width, ' ');
}

/**
 * @brief add a new screen to vector
 *
 * @param s
 * @return window_mgr_cl::ScreenIndex
 */
window_mgr_cl::ScreenIndex window_mgr_cl::AddScreen(const screen_cl &s)
{
    Screens_cl_a.push_back(s);
    return Screens_cl_a.size() - 1;
}

/**
 * @brief get screen content at rXc
 *
 * @param r
 * @param c
 * @return char
 */
inline char screen_cl::Get(pos r, pos c) const
{
    ++AccessCtrl;
    pos row = r * Width;
    return strContents[row + c];
}

/**
 * @brief move cursor to rXc
 *
 * @param r
 * @param c
 * @return screen_cl&
 */
inline screen_cl &screen_cl::Move(pos r, pos c)
{
    ++AccessCtrl;
    pos row = r * Width;
    Cursor = row + c;
    return *this;
}

/**
 * @brief set char at cursor
 *
 * @param c
 * @return screen_cl&
 */
inline screen_cl &screen_cl::Set(char c)
{
    ++AccessCtrl;
    strContents[Cursor] = c;
    return *this;
}

/**
 * @brief set char at rXc
 *
 * @param r
 * @param c
 * @param c
 * @return screen_cl&
 */
inline screen_cl &screen_cl::Set(pos r, pos c, char ch)
{
    ++AccessCtrl;
    strContents[r * Width + c] = ch;
    return *this;
}

/**
 * @brief screen's size
 *
 * @return screen_cl::pos
 */
screen_cl::pos screen_cl::Size(void) const
{
    return Height * Width;
}

#endif