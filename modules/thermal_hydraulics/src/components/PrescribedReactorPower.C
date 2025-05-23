//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PrescribedReactorPower.h"

registerMooseObject("ThermalHydraulicsApp", PrescribedReactorPower);

InputParameters
PrescribedReactorPower::validParams()
{
  InputParameters params = TotalPowerBase::validParams();
  params.addClassDescription(
      "Specifies the total power of a component. This component is deprecated");
  params.addRequiredParam<Real>("power", "Total power [W]");
  return params;
}

PrescribedReactorPower::PrescribedReactorPower(const InputParameters & parameters)
  : TotalPowerBase(parameters)
{
  logError("Deprecated component, use 'type = TotalPower' instead.");
}
