//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ColumnMajorMatrix.h"
#include "ComputeMultipleInelasticStress.h"
#include "SmearedCrackSofteningBase.h"
#include "Function.h"

/**
 * ComputeSmearedCrackingStress computes the stress for a finite strain
 * material with smeared cracking
 */
class ComputeSmearedCrackingStress : public ComputeMultipleInelasticStress
{
public:
  static InputParameters validParams();

  ComputeSmearedCrackingStress(const InputParameters & parameters);

  virtual void initialSetup() override;
  virtual void initQpStatefulProperties() override;
  virtual void computeQpStress() override;

protected:
  /**
   * Update the local elasticity tensor (_local_elasticity_tensor)
   * due to the effects of cracking.
   */
  void updateLocalElasticityTensor();

  /**
   * Update all cracking-related state variables and the stress
   * tensor due to cracking in all directions.
   */
  virtual void updateCrackingStateAndStress();

  /**
   * Get the number of known crack directions. This includes cracks
   * in prescribed directions (even if not yet active) and active
   * cracks in other directions.
   * @return number of known crack directions
   */
  virtual unsigned int getNumKnownCrackDirs() const;

  /**
   * Compute the crack strain in the crack coordinate system. Also
   * computes the crack orientations, and stores in _crack_rotation.
   * @param strain_in_crack_dir Computed strains in crack directions
   */
  void computeCrackStrainAndOrientation(RealVectorValue & strain_in_crack_dir);

  /**
   * Updates the full stress tensor to account for the effect of cracking
   * using the provided stresses in the crack directions. The tensor is
   * rotated into the crack coordinates, modified, and rotated back.
   * @param tensor Stress tensor to be updated
   * @param sigma Vector of stresses in crack directions
   */
  void updateStressTensorForCracking(RankTwoTensor & tensor, const RealVectorValue & sigma);

  /**
   * Check to see whether there was cracking in any diretion in the previous
   * time step.
   * @return true if cracked, false if not cracked
   */
  bool previouslyCracked();

  ///@{ Input parameters for smeared crack models

  /// Threshold at which cracking initiates if tensile stress exceeds it
  const VariableValue & _cracking_stress;

  /// User-prescribed cracking directions
  std::vector<unsigned int> _prescribed_crack_directions;

  /// Maximum number of cracks permitted at a material point
  const unsigned int _max_cracks;

  /// Defines transition to changed stiffness during unloading
  const Real _cracking_neg_fraction;

  /// Controls the amount of shear retained
  const Real _shear_retention_factor;

  /// Controls the maximum amount that the damaged elastic stress is corrected
  /// to folow the release model during a time step
  const Real _max_stress_correction;
  ///@}

  /// Enum defining the method used to adjust the elasticity tensor for cracking
  const enum class CrackedElasticityType { DIAGONAL, FULL } _cracked_elasticity_type;

  //@{ Damage (goes from 0 to 1) in crack directions
  MaterialProperty<RealVectorValue> & _crack_damage;
  const MaterialProperty<RealVectorValue> & _crack_damage_old;
  ///@}

  /// Vector of values going from 1 to 0 as crack damage accumulates. Legacy
  /// property for backward compatibility -- remove in the future.
  MaterialProperty<RealVectorValue> & _crack_flags;

  //@{ Rotation tensor used to rotate tensors into crack local coordinates
  MaterialProperty<RankTwoTensor> & _crack_rotation;
  const MaterialProperty<RankTwoTensor> & _crack_rotation_old;
  ///@}

  //@{ Strain in direction of crack upon crack initiation
  MaterialProperty<RealVectorValue> & _crack_initiation_strain;
  const MaterialProperty<RealVectorValue> & _crack_initiation_strain_old;
  ///@}

  //@{ Maximum strain in direction of crack
  MaterialProperty<RealVectorValue> & _crack_max_strain;
  const MaterialProperty<RealVectorValue> & _crack_max_strain_old;
  ///@}

  //@{ Variables used by multiple methods within the calculation for a single material point
  RankFourTensor _local_elasticity_tensor;
  ///@}

  /// The user-supplied list of softening models to be used in the 3 crack directions
  std::vector<SmearedCrackSofteningBase *> _softening_models;

  /// Vector helper to update local elasticity tensor
  std::vector<Real> _local_elastic_vector;
};
