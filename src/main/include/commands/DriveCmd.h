// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/controller/PIDController.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/DriveSub.h"

#include "frc/Timer.h"

class DriveCmd : public frc2::CommandHelper<frc2::Command, DriveCmd> {
 public:
  DriveCmd(DriveSub* subsystem, frc2::CommandXboxController* pController);

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  DriveSub* m_pDriveSub = nullptr;
  frc2::CommandXboxController* m_pController;
  bool m_isFinished = false;

  frc::Timer m_timer;
};