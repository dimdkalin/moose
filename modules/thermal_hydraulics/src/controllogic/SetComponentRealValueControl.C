//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "SetComponentRealValueControl.h"
#include "Function.h"

registerMooseObject("ThermalHydraulicsApp", SetComponentRealValueControl);

InputParameters
SetComponentRealValueControl::validParams()
{
  InputParameters params = THMControl::validParams();
  params.addRequiredParam<std::string>("component", "The name of the component to be controlled.");
  params.addRequiredParam<std::string>(
      "parameter", "The name of the parameter in the component to be controlled.");
  params.addRequiredParam<std::string>("value",
                                       "The name of control data to be set in the component.");
  params.addClassDescription("Control to set a floating point (Real) value of a component "
                             "parameter with control data boolean");
  return params;
}

SetComponentRealValueControl::SetComponentRealValueControl(const InputParameters & parameters)
  : THMControl(parameters),
    _component_name(getParam<std::string>("component")),
    _param_name(getParam<std::string>("parameter")),
    _ctrl_param_name("component", _component_name, _param_name),
    _value(getControlData<Real>("value"))
{
}

void
SetComponentRealValueControl::execute()
{
  setControllableValueByName<Real>(_ctrl_param_name, _value);
}
