/***************************************************************************
 *   Copyright (C) 2006 by Rene Horn   *
 *   the.rhorn@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "mouse.h"

namespace g2 {

Device& operator>> (Device &din, Mouse mouse)
{
    g2_query_pointer(din.m_device, &mouse.m_coord.x, &mouse.m_coord.y,
                     &mouse.m_button);
    return din;
}

Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}


}

/*!
    \fn g2::Mouse::X() const
 */
double g2::Mouse::X() const
{
    return m_coord.x;
}


/*!
    \fn g2::Mouse::Y() const
 */
double g2::Mouse::Y() const
{
    return m_coord.y;
}

/*!
    \fn g2::Mouse::Button
 */
unsigned int g2::Mouse::Button()
{
    return m_button;
}


/*!
    \fn g2::Mouse::Alt()
 */
bool g2::Mouse::Alt()
{
    return (ALT_KEY&m_button);
}


/*!
    \fn g2::Mouse::Ctrl()
 */
bool g2::Mouse::Ctrl()
{
    return (CTRL_KEY&m_button);
}


/*!
    \fn g2::Mouse::Shift()
 */
bool g2::Mouse::Shift()
{
    return (SHIFT_KEY&m_button);
}


/*!
    \fn g2::Mouse::WinKey()
 */
bool g2::Mouse::WinKey()
{
    return (WIN_KEY&m_button);
}


/*!
    \fn g2::Mouse::Left()
 */
bool g2::Mouse::Left()
{
    return (LEFT_BUTTON&m_button);
}


/*!
    \fn g2::Mouse::Middle()
 */
bool g2::Mouse::Middle()
{
    return (MIDDLE_BUTTON&m_button);
}


/*!
    \fn g2::Mouse::Right()
 */
bool g2::Mouse::Right()
{
    return (RIGHT_BUTTON&m_button);
}


/*!
    \fn g2::Mouse::Position()
 */
g2::Point g2::Mouse::Position()
{
    return m_coord;
}
