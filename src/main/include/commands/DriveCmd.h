#pragma once

#include <frc/DriverStation.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandXboxController.h>

#include "subsystems/DriveSub.h"

class DriveCmd : public frc2::CommandHelper<frc2::Command, DriveCmd> {
 public:
  DriveCmd(
      DriveSub* subsystem,
      frc2::CommandXboxController* arcadeController,
      frc2::CommandXboxController* tankController
  );

  void Initialize() override;
  void Execute() override;
  void End(bool interrupted) override;
  bool IsFinished() override;

 private:
  DriveSub* m_pDriveSub = nullptr;

  frc2::CommandXboxController* m_pArcadeController = nullptr;
  frc2::CommandXboxController* m_pTankController = nullptr;
};