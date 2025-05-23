//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PoroMechanicsAction.h"

#include "Factory.h"
#include "FEProblem.h"
#include "Parser.h"
#include "Conversion.h"

registerMooseAction("SolidMechanicsApp", PoroMechanicsAction, "setup_mesh_complete");

registerMooseAction("SolidMechanicsApp", PoroMechanicsAction, "validate_coordinate_systems");

registerMooseAction("SolidMechanicsApp", PoroMechanicsAction, "add_kernel");

InputParameters
PoroMechanicsAction::validParams()
{
  InputParameters params = QuasiStaticSolidMechanicsPhysics::validParams();
  params.addRequiredParam<VariableName>("porepressure", "The pore pressure variable");
  params.addClassDescription("Adds the poro-mechanics coupling term");
  return params;
}

PoroMechanicsAction::PoroMechanicsAction(const InputParameters & params)
  : QuasiStaticSolidMechanicsPhysics(params)
{
  if (_use_ad)
    paramError("use_ad", "AD not setup for use with PoroMechanicsAction");
}

void
PoroMechanicsAction::act()
{
  QuasiStaticSolidMechanicsPhysics::act();

  if (_current_task == "add_kernel")
  {
    // Prepare displacements and set value for dim
    std::vector<VariableName> displacements = getParam<std::vector<VariableName>>("displacements");
    unsigned int dim = displacements.size();

    // all the kernels added below have pore pressure as a coupled variable
    // add this to the kernel's params
    std::string type("PoroMechanicsCoupling");
    InputParameters params = _factory.getValidParams(type);
    VariableName pp_var(getParam<VariableName>("porepressure"));
    params.addCoupledVar("porepressure", "");
    params.set<std::vector<VariableName>>("porepressure") = {pp_var};

    // now add the kernels
    for (unsigned int i = 0; i < dim; ++i)
    {
      std::string kernel_name = "PoroMechanics" + Moose::stringify(i);

      params.set<unsigned int>("component") = i;
      params.set<NonlinearVariableName>("variable") = displacements[i];

      _problem->addKernel(type, kernel_name, params);
    }
  }
}
