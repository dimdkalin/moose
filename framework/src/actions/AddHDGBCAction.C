//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "AddHDGBCAction.h"
#include "FEProblem.h"

registerMooseAction("MooseApp", AddHDGBCAction, "add_hybridized_integrated_bc");

InputParameters
AddHDGBCAction::validParams()
{
  InputParameters params = MooseObjectAction::validParams();
  params.addClassDescription(
      "Add a hybridized integrated boundary condition object to the simulation.");
  return params;
}

AddHDGBCAction::AddHDGBCAction(const InputParameters & params) : MooseObjectAction(params) {}

void
AddHDGBCAction::act()
{
  _problem->addHDGIntegratedBC(_type, _name, _moose_object_pars);
}
