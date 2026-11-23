
#include "subsystems/DriveSub.h"
#include "Constants.h"

#include <frc/DriverStation.h>
#include <iostream>
#include <ctre/phoenix/motorcontrol/ControlMode.h>
#include <ctre/phoenix/motorcontrol/NeutralMode.h>
#include <ctre/phoenix/motorcontrol/InvertType.h>

DriveSub::DriveSub()
{
}

void DriveSub::Init()
{
    // Configure master controllers first.
    ConfigureMasters();

    // Establish follower relationships second.
    ConfigureFollowers();

    // Report communication problems.
    VerifyCAN();
}

void DriveSub::ConfigureMasters()
{
    // Reset configurations to known defaults.
    m_leftMotor1.ConfigFactoryDefault(100);
    m_rightMotor1.ConfigFactoryDefault(100);

    // Set motor inversion.
    m_leftMotor1.SetInverted(false);
    m_rightMotor1.SetInverted(true);

    // Set neutral behavior.
    m_leftMotor1.SetNeutralMode(
        ctre::phoenix::motorcontrol::NeutralMode::Brake);

    m_rightMotor1.SetNeutralMode(
        ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

void DriveSub::ConfigureFollowers()
{
    // Reset follower configurations.
    m_leftMotor2.ConfigFactoryDefault(100);
    m_rightMotor2.ConfigFactoryDefault(100);

    // Establish follower relationships.
    m_leftMotor2.Follow(m_leftMotor1);
    m_rightMotor2.Follow(m_rightMotor1);

    // Match master inversion.
    m_leftMotor2.SetInverted(
        ctre::phoenix::motorcontrol::InvertType::FollowMaster);

    m_rightMotor2.SetInverted(
        ctre::phoenix::motorcontrol::InvertType::FollowMaster);
}

void DriveSub::VerifyCAN()
{
    int leftMasterFirmware = m_leftMotor1.GetFirmwareVersion();
    int leftFollowerFirmware = m_leftMotor2.GetFirmwareVersion();

    int rightMasterFirmware = m_rightMotor1.GetFirmwareVersion();
    int rightFollowerFirmware = m_rightMotor2.GetFirmwareVersion();

   std::cout
    << "CAN firmware diagnostic: "
    << "LM1=" << leftMasterFirmware
    << ", LM2=" << leftFollowerFirmware
    << ", RM1=" << rightMasterFirmware
    << ", RM2=" << rightFollowerFirmware
    << std::endl;
}

void DriveSub::DriveTank(double left, double right)
{
    m_leftMotor1.Set(
        ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        left);

    m_rightMotor1.Set(
        ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        right);
}

void DriveSub::DriveRC(double vertical, double horizontal)
{
    double dampFactor = 0.8;
    double dampedHoriz = horizontal * dampFactor;

    DriveTank(
        vertical + dampedHoriz,
        vertical - dampedHoriz
    );
}

void DriveSub::Periodic()
{
}
