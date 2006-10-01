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
#include "polygon.h"

#include <cstdlib>

namespace g2 {

    double *Polygon::m_pointsBuffer=NULL;
    size_t Polygon::m_refCount=0;
    
Polygon::Polygon(Point *pt_list, size_t num_points, PolygonType poly_type, 
                    bool deletePoints)
 : Shape()
{
    m_points=pt_list;
    m_pointCount=num_points;
    m_deletePoints=deletePoints;
    m_polyType=poly_type;
    m_refCount++;
}


Polygon::~Polygon()
{
    if(m_deletePoints)
        delete [] m_points;
    m_refCount--;
    if(0==m_refCount)
        free(m_pointsBuffer);
}


void Polygon::DrawToDevice(int dev) const
{
    if(NULL==m_pointsBuffer)
        m_pointsBuffer = (double*)malloc(m_pointCount*2*sizeof(double));
    else
        realloc(m_pointsBuffer, m_pointCount*2*sizeof(double));
    
    for( size_t i=0, j=0; i<m_pointCount; i++){
        m_pointsBuffer[j++]=m_points[i].x;
        m_pointsBuffer[j++]=m_points[i].y;
    }
    
    switch(m_polyType) {
        case NormalPoly:
            g2_polygon(dev, m_pointCount, m_pointsBuffer);
            break;
        case PolyLine:
            g2_poly_line(dev, m_pointCount, m_pointsBuffer);
            break;
        case FilledPoly:
            g2_poly_line(dev, m_pointCount, m_pointsBuffer);
            break;
    }
}

}
