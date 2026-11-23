#include "commands/DriveCmd.h"
#include "Constants.h"
#include <cmath>

DriveCmd::DriveCmd(
    DriveSub* subsystem,
    frc2::CommandXboxController* arcadeController,
    frc2::CommandXboxController* tankController)
{
    m_pDriveSub = subsystem;
    m_pArcadeController = arcadeController;
    m_pTankController = tankController;

    AddRequirements(m_pDriveSub);
}

void DriveCmd::Initialize()
{
}

void DriveCmd::Execute()
{
    if (m_pDriveSub == nullptr)
        return;

// Check controller connections using Constants.h.
    bool arcadeConnected =
        frc::DriverStation::IsJoystickConnected(
            OperatorConstants::kDriverControllerPort);

    bool tankConnected =
        frc::DriverStation::IsJoystickConnected(
            OperatorConstants::kDriverControllerPortTank);

// PRIORITY 1: Controller 0 - Arcade
    if (arcadeConnected && m_pArcadeController != nullptr)
{
    double forward = -m_pArcadeController->GetLeftY();
    double turn = m_pArcadeController->GetRightX();

    // Apply joystick deadzone
    if (std::abs(forward) < 0.05)
        forward = 0.0;

    if (std::abs(turn) < 0.05)
        turn = 0.0;

    m_pDriveSub->DriveRC(forward, turn);
}
  
// PRIORITY 2: Controller 1 - Tank
    else if (tankConnected && m_pTankController != nullptr)
{
    double left = -m_pTankController->GetLeftY();
    double right = -m_pTankController->GetRightY();

    // Apply joystick deadzone
    if (std::abs(left) < 0.05)
        left = 0.0;

    if (std::abs(right) < 0.05)
        right = 0.0;

    m_pDriveSub->DriveTank(left, right);
}

    // Neither controller connected.
    else
    {
        m_pDriveSub->DriveTank(0.0, 0.0);
    }
}

void DriveCmd::End(bool interrupted)
{
    m_pDriveSub->DriveTank(0.0, 0.0);
}

bool DriveCmd::IsFinished()
{
    return false;
}