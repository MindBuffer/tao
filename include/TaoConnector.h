/* Tao - A software package for sound synthesis with physical models
 * Copyright (C) 1993-1999 Mark Pearson
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "TaoDevice.h"
#include "TaoAccessPoint.h"

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

class DLLEXPORT TaoConnector : public TaoDevice
    {
public:
    TaoConnector(void);
    ~TaoConnector();
    TaoConnector(const char *connectorName);
    TaoConnector(const char *connectorName, TaoAccessPoint &ap1, TaoAccessPoint &ap2);
    TaoConnector(const char *connectorName, TaoAccessPoint &ap1, TaoAccessPoint &ap2,
		float connectionStrength);
    TaoConnector(const char *connectorName, TaoAccessPoint &ap, float anchor);
    TaoConnector(const char *connectorName, TaoAccessPoint &ap, float anchor,
		float connectionStrength);
    TaoConnector(const char *connectorName, float anchor, TaoAccessPoint &ap);
    TaoConnector(const char *connectorName, float anchor, TaoAccessPoint &ap,
		float connectionStrength);
    void operator()(TaoAccessPoint &ap1, TaoAccessPoint &ap2);
    void operator()(TaoAccessPoint &ap1, TaoAccessPoint &ap2, float connectionStrength);
    void operator()(TaoAccessPoint &ap, float anchor);
    void operator()(TaoAccessPoint &ap, float anchor, float connectionStrength);
    void operator()(float anchor, TaoAccessPoint &ap);
    void operator()(float anchor, TaoAccessPoint &ap, float connectionStrength);
    void update();
    
    void display();
        
private:
    TaoAccessPoint accessPoint1, accessPoint2;
    float anchorPoint1, anchorPoint2;		// If one or both ends of the connector 
						// are connected to constants rather
						// than real access points, these
						// variables store the z-coordinates
						// for the anchor points.
    float strength;				
    void updateAccessToAccess();
    void updateAccessToAnchor();
    void updateAnchorToAccess();
    };						
				
#endif
