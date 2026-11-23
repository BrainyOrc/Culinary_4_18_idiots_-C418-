#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>

#include "Constants.h"
#include "subsystems/DriveSub.h"

class RobotContainer {
 public:
  RobotContainer();

  void GetAutonomousCommand();

 private:
  // Controller 0: Arcade
  frc2::CommandXboxController m_arcadeController{0};

  // Controller 1: Tank
  frc2::CommandXboxController m_tankController{1};

  void ConfigureBindings();
  void Init();

  DriveSub m_driveSub;
};