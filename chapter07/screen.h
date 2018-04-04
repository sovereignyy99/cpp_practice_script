/*
 * @Author: MatthewPerry
 * @Date: 2018-04-05 00:38:32
 * @Last Modified by: MatthewPerry
 * @Last Modified time: 2018-04-05 01:26:11
 */

#include <iostream>
#include <string>

//
// ────────────────────────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: D E C E L A R E T I O N   A N D   D E F I N I T I O N : :  :   :    :     :        :          :
// ────────────────────────────────────────────────────────────────────────────────────────────────────────
//

class screen_cl
{
  public:
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
