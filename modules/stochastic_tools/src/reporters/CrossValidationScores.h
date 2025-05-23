//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

// MOOSE includes
#include "GeneralReporter.h"
#include "SurrogateModelInterface.h"
#include "SurrogateModel.h"
/**
 * A tool to output CV scores
 */

class CrossValidationScores : public GeneralReporter, public SurrogateModelInterface
{
public:
  static InputParameters validParams();

  CrossValidationScores(const InputParameters & parameters);

  virtual void initialize() override {}
  virtual void execute() override;
  virtual void finalize() override {}

protected:
  /// Storage for cross-validation scores
  std::vector<std::vector<std::vector<Real>> *> _cv_scores;

  /// Model to extract CV values from.
  std::vector<const SurrogateModel *> _models;
};
