// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/smartdashboard/SmartDashboard.h>
#include <units/length.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/PWMTalonSRX.h>
#include "Constants.h" 
#include <frc2/command/CommandPtr.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/Drive/DifferentialDrive.h>
#include <frc2/command/RunCommand.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

class DriveSub : public frc2::SubsystemBase 
{
 public:
  DriveSub();

  void Init();

  void Periodic() override;

  void DriveTank(double left, double right);

  void DriveRC(double vertical, double horizontal);


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix::motorcontrol::can::TalonSRX m_leftMotor1{OperatorConstants::kC418DriveLM1};
  ctre::phoenix::motorcontrol::can::TalonSRX m_leftMotor2{OperatorConstants::kC418DriveLM2};
  ctre::phoenix::motorcontrol::can::TalonSRX m_rightMotor1{OperatorConstants::kC418DriveRM1};
  ctre::phoenix::motorcontrol::can::TalonSRX m_rightMotor2{OperatorConstants::kC418DriveRM2};

};
