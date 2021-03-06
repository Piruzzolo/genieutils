/*
    genie/dat - A library for reading and writing data files of genie
               engine games.
    Copyright (C) 2011 - 2013  Armin Preiml
    Copyright (C) 2011 - 2017  Mikko "Tapsa" P

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "genie/dat/unit/Moving.h"

namespace genie {

namespace unit {

    Moving::Moving() //: Unit()
    {
    }

    Moving::~Moving()
    {
    }

    //------------------------------------------------------------------------------
    void Moving::setGameVersion(GameVersion gv)
    {
        ISerializable::setGameVersion(gv);
    }

    void Moving::serializeObject(void)
    {
        serialize<int16_t>(WalkingGraphic);
        serialize<int16_t>(RunningGraphic);
        serialize<float>(RotationSpeed);
        serialize<int8_t>(OldSizeClass);
        serialize<int16_t>(TrackingUnit);
        serialize<int8_t>(TrackingUnitMode);
        serialize<float>(TrackingUnitDensity);
        serialize<int8_t>(OldMoveAlgorithm);

        if (getGameVersion() >= GV_AoKB) // 10.28
        {
            serialize<float>(TurnRadius);
            serialize<float>(TurnRadiusSpeed);
            serialize<float>(MaxYawPerSecondMoving);
            serialize<float>(StationaryYawRevolutionTime);
            serialize<float>(MaxYawPerSecondStationary);
        }
    }
}
}
