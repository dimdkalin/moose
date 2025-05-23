//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "NearestPointLayeredSideAverageFunctor.h"

registerMooseObject("MooseApp", NearestPointLayeredSideAverageFunctor);

InputParameters
NearestPointLayeredSideAverageFunctor::validParams()
{
  InputParameters params =
      NearestPointBase<LayeredSideAverageFunctor, SideIntegralFunctorUserObject>::validParams();
  params.addClassDescription(
      "Computes layered side averages of a functor nearest to a set of points.");
  return params;
}

NearestPointLayeredSideAverageFunctor::NearestPointLayeredSideAverageFunctor(
    const InputParameters & parameters)
  : NearestPointBase<LayeredSideAverageFunctor, SideIntegralFunctorUserObject>(parameters)
{
}
