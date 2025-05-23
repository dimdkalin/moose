//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "NSFVEnergyAmbientConvection.h"
#include "NS.h"

registerMooseObject("NavierStokesApp", NSFVEnergyAmbientConvection);

InputParameters
NSFVEnergyAmbientConvection::validParams()
{
  InputParameters params = FVElementalKernel::validParams();
  params.addClassDescription(
      "Implements a solid-fluid ambient convection volumetric term "
      "proportional to the difference between the fluid and ambient temperatures : "
      "$q''' = \\alpha (T_{fluid} - T_{ambient})$.");
  params.addRequiredParam<MaterialPropertyName>(NS::alpha,
                                                "Name of the convective heat transfer coefficient");
  params.addRequiredParam<MooseFunctorName>("T_ambient", "The ambient temperature");
  return params;
}

NSFVEnergyAmbientConvection::NSFVEnergyAmbientConvection(const InputParameters & parameters)
  : FVElementalKernel(parameters),
    _alpha(getFunctor<ADReal>(NS::alpha)),
    _temp_ambient(getFunctor<ADReal>("T_ambient"))
{
}

ADReal
NSFVEnergyAmbientConvection::computeQpResidual()
{
  auto elem_arg = makeElemArg(_current_elem);
  const auto state = determineState();
  return _alpha(elem_arg, state) * (_var(elem_arg, state) - _temp_ambient(elem_arg, state));
}
