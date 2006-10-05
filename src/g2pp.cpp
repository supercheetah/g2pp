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

// This is the sample program.

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef G2_USE_X11
#define G2_USE_X11
#endif

#include <g2++.h>
using namespace g2;

int main(int argc, char *argv[])
{
    Device xdev(1024,1024);
    xdev.SetOrigin( 512, 512, 1, 1);
    Point neck, ear_left, ear_right, body_center;
    neck.x=neck.y=0;
    ear_left.x=-20;
    ear_right.x=20;
    ear_left.y=ear_right.y=40;
    body_center.x=0;
    body_center.y=-50;
    
    Triangle head(neck, ear_left, ear_right, true);
    Circle body(body_center, neck, true);
    Circle arm_right(48, -8, 15, true), arm_left(-48, -8, 15, true);
    Circle leg_right(15, -100, 20, true), leg_left(-15, -100, 20, true);
    
    xdev << head << body << arm_left << arm_right << leg_left << leg_right;
    
    Mouse mouse;
    while(true) {
        xdev >> mouse;
        if(mouse.Left())
            break;
    }
    
    return EXIT_SUCCESS;
}
