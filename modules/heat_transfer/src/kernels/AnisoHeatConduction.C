//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "AnisoHeatConduction.h"

registerMooseObject("HeatTransferApp", AnisoHeatConduction);

InputParameters
AnisoHeatConduction::validParams()
{
  InputParameters params = DerivativeMaterialInterface<Kernel>::validParams();
  params.addClassDescription("Anisotropic diffusive heat conduction term $\\nabla \\cdot "
                             "-\\mathbf{k} \\nabla T$ of the thermal energy conservation equation");
  params.addParam<MaterialPropertyName>(
      "thermal_conductivity",
      "thermal_conductivity",
      "Material property providing thermal conductivity of the material.");

  return params;
}

AnisoHeatConduction::AnisoHeatConduction(const InputParameters & parameters)
  : DerivativeMaterialInterface<Kernel>(parameters),
    _k(getMaterialProperty<RankTwoTensor>("thermal_conductivity")),
    _dk_dT(getMaterialPropertyDerivative<RankTwoTensor>("thermal_conductivity", _var.name()))
{
}

Real
AnisoHeatConduction::computeQpResidual()
{
  return _k[_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}

Real
AnisoHeatConduction::computeQpJacobian()
{
  return _k[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp] +
         _dk_dT[_qp] * _phi[_j][_qp] * _grad_u[_qp] * _grad_test[_i][_qp];
}
