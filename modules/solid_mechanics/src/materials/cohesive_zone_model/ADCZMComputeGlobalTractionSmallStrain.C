//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ADCZMComputeGlobalTractionSmallStrain.h"
#include "CZMComputeGlobalTractionSmallStrain.h"

registerMooseObject("SolidMechanicsApp", ADCZMComputeGlobalTractionSmallStrain);

InputParameters
ADCZMComputeGlobalTractionSmallStrain::validParams()
{
  InputParameters params = CZMComputeGlobalTractionSmallStrain::validParams();
  return params;
}

ADCZMComputeGlobalTractionSmallStrain::ADCZMComputeGlobalTractionSmallStrain(
    const InputParameters & parameters)
  : ADCZMComputeGlobalTractionBase(parameters)
{
}

void
ADCZMComputeGlobalTractionSmallStrain::computeEquilibriumTracion()
{
  _traction_global[_qp] = _czm_total_rotation[_qp] * _interface_traction[_qp];
}
