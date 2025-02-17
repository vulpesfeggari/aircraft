// Copyright (c) 2023 FlyByWire Simulations
// SPDX-License-Identifier: GPL-3.0

#ifndef FLYBYWIRE_AIRCRAFTPRESETS_H
#define FLYBYWIRE_AIRCRAFTPRESETS_H

#include <cstdint>

#include "DataManager.h"
#include "Module.h"
#include "PresetProcedures.h"
#include "PresetProceduresDefinition.h"
#include "ProcedureStep.h"

class MsfsHandler;

/**
 * This module is responsible for loading aircraft presets.
 * It uses the AircraftProcedures.h definition of procedures to load the presets.
 */
class AircraftPresets : public Module {
 private:
  // Convenience pointer to the data manager
  DataManager* dataManager = nullptr;

  // LVARs
  NamedVariablePtr aircraftPresetVerbose{};
  NamedVariablePtr loadAircraftPresetRequest{};
  NamedVariablePtr progressAircraftPreset{};
  NamedVariablePtr progressAircraftPresetId{};

  // Sim-vars
  AircraftVariablePtr simOnGround{};

  // Procedures
  const PresetProcedures presetProcedures;

  // current procedure ID
  int currentProcedureID = 0;
  // current procedure
  const std::vector<const ProcedureStep*>* currentProcedure = nullptr;
  // flag to signal that a loading process is ongoing
  bool loadingIsActive = false;
  // in ms
  double currentLoadingTime = 0.0;
  // time for next action in respect to currentLoadingTime
  double currentDelay = 0;
  // step number in the array of steps
  std::size_t currentStep = 0;

 public:
  AircraftPresets() = delete;

  /**
   * Creates a new AircraftPresets instance and takes a reference to the MsfsHandler instance.
   * @param msfsHandler The MsfsHandler instance that is used to communicate with the simulator.
   * @param aircraftProceduresDefinitions The AircraftProceduresDefinition instance that is used to define the procedures.
   */
  explicit AircraftPresets(MsfsHandler& msfsHandler, const PresetProceduresDefinition& aircraftProceduresDefinitions)
      : Module(msfsHandler), presetProcedures(PresetProcedures(aircraftProceduresDefinitions)) {}

  bool initialize() override;
  bool preUpdate(sGaugeDrawData*) override { return true; }; // not required for this module
  bool update(sGaugeDrawData* pData) override;
  bool postUpdate(sGaugeDrawData*) override { return true; }; // not required for this module
  bool shutdown() override;
};

#endif  // FLYBYWIRE_AIRCRAFTPRESETS_H
