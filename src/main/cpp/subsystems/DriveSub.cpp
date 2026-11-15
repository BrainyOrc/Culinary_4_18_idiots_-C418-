// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


#include "subsystems/DriveSub.h"

#include "Constants.h"

DriveSub::DriveSub()
{

}

void DriveSub::Periodic()
{
  
}

void DriveSub::Init() 
{
  m_leftMotor1.SetInverted(false);
  m_leftMotor2.SetInverted(false);
  m_rightMotor1.SetInverted(true);
  m_rightMotor2.SetInverted(true);

  m_leftMotor2.Follow(m_leftMotor1);
  m_rightMotor2.Follow(m_rightMotor1);
}

void DriveSub::DriveTank(double left, double right) 
{
//  m_leftMotor1.Set(left);
//  m_leftMotor2.Set(left);
//  m_rightMotor1.Set(right);
//  m_rightMotor2.Set(right);

m_leftMotor1.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, left);
m_leftMotor2.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, left);
m_rightMotor1.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, right);
m_rightMotor2.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, right);
}

void DriveSub::DriveRC(double vertical, double horizontal) 
{
double dampFactor = 0.8;
double dampedHoriz = horizontal * dampFactor;

DriveTank(vertical+dampedHoriz, vertical-dampedHoriz);
}
