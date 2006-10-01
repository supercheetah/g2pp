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
#ifndef G2MOUSE_H
#define G2MOUSE_H

#include <shape.h>
#include <device.h>

namespace g2 {

enum ButtonStates {
    ALT_KEY=0x8,
    CTRL_KEY=0x4,
    SHIFT_KEY=0x1,
    WIN_KEY=0x40,
    LEFT_BUTTON=0x100,
    MIDDLE_BUTTON=0x200,
    RIGHT_BUTTON=0x400
};

/**
	@author Rene Horn <the.rhorn@gmail.com>
*/
class Mouse{
    friend Device& operator>> (Device &din, Mouse mouse);
public:
    Mouse();

    ~Mouse();
    double X() const;
    double Y() const;
    bool Alt();
    bool Ctrl();
    bool Shift();
    bool WinKey();
    bool Left();
    bool Middle();
    bool Right();
    unsigned int Button();
    Point Position();

protected:
    Point m_coord;
    unsigned int m_button;
};

Device& operator>> (Device &din, Mouse mouse);

typedef Mouse Pointer;

}

#endif
