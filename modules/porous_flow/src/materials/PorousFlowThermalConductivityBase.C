//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "PorousFlowThermalConductivityBase.h"

template <bool is_ad>
InputParameters
PorousFlowThermalConductivityBaseTempl<is_ad>::validParams()
{
  InputParameters params = PorousFlowMaterialVectorBase::validParams();
  params.set<bool>("at_nodes") = false;
  params.set<std::string>("pf_material_type") = "thermal_conductivity";
  params.addClassDescription("Base class Material for thermal conductivity");
  return params;
}

template <bool is_ad>
PorousFlowThermalConductivityBaseTempl<is_ad>::PorousFlowThermalConductivityBaseTempl(
    const InputParameters & parameters)
  : PorousFlowMaterialVectorBase(parameters),
    _la_qp(declareGenericProperty<RealTensorValue, is_ad>("PorousFlow_thermal_conductivity_qp")),
    _dla_qp_dvar(is_ad ? nullptr
                       : &declareProperty<std::vector<RealTensorValue>>(
                             "dPorousFlow_thermal_conductivity_qp_dvar"))
{
  if (_nodal_material == true)
    mooseError("PorousFlowThermalConductivity classes are only defined for at_nodes = false");
}

template class PorousFlowThermalConductivityBaseTempl<false>;
template class PorousFlowThermalConductivityBaseTempl<true>;
