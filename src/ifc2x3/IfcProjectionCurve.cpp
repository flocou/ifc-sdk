// IFC SDK : IFC2X3 C++ Early Classes  
// Copyright (C) 2009 CSTB
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full license is in Licence.txt file included with this 
// distribution or is available at :
//     http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

#ifdef ENABLE_MSVC_PRECOMPILED_HEADER
#include "precompiled.h"
#endif

#include "ifc2x3/IfcProjectionCurve.h"

#include "ifc2x3/CopyOp.h"
#include "ifc2x3/IfcAnnotationCurveOccurrence.h"
#include "ifc2x3/Visitor.h"
#include <Step/ClassType.h>
#include <Step/logger.h>


#include <string>

using namespace ifc2x3;

IfcProjectionCurve::IfcProjectionCurve(Step::Id id, Step::SPFData *args) : IfcAnnotationCurveOccurrence(id, args) {
}

IfcProjectionCurve::~IfcProjectionCurve() {
}

bool IfcProjectionCurve::acceptVisitor(Step::BaseVisitor *visitor) {
    return static_cast< Visitor * > (visitor)->visitIfcProjectionCurve(this);
}

const std::string &IfcProjectionCurve::type() const {
    return IfcProjectionCurve::s_type.getName();
}

const Step::ClassType &IfcProjectionCurve::getClassType() {
    return IfcProjectionCurve::s_type;
}

const Step::ClassType &IfcProjectionCurve::getType() const {
    return IfcProjectionCurve::s_type;
}

bool IfcProjectionCurve::isOfType(const Step::ClassType &t) const {
    return IfcProjectionCurve::s_type == t ? true : IfcAnnotationCurveOccurrence::isOfType(t);
}

bool IfcProjectionCurve::init() {
    bool status = IfcAnnotationCurveOccurrence::init();
    std::string arg;
    if (!status) {
        return false;
    }
    return true;
}

void IfcProjectionCurve::copy(const IfcProjectionCurve &obj, const CopyOp &copyop) {
    IfcAnnotationCurveOccurrence::copy(obj, copyop);
    return;
}

IFC2X3_DLL_DEF Step::ClassType IfcProjectionCurve::s_type("IfcProjectionCurve");
