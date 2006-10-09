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
#include "g2exception.h"

#include <cstring>

namespace g2 {

g2exception::g2exception(const char *message, ExceptionValues exc_type)
    :m_message(new char[strlen(message)]), m_type(exc_type)
{
    strcpy(m_message, message);
}


g2exception::~g2exception()
{
    delete [] m_message;
}


}


/*!
    \fn g2::g2exception::type()
 */
int g2::g2exception::Type()
{
    return m_type;
}


/*!
    \fn g2::g2exception::what()
 */
const char* g2::g2exception::what()
{
    return m_message;
}
