#include "commands/DriveCmd.h"

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

    // Check which controllers are connected.
    bool arcadeConnected = frc::DriverStation::IsJoystickConnected(0);
    bool tankConnected = frc::DriverStation::IsJoystickConnected(1);

    // Tank takes priority if both controllers are connected.
    if (tankConnected && m_pTankController != nullptr)
    {
        double left = -m_pTankController->GetLeftY();
        double right = -m_pTankController->GetRightY();

        m_pDriveSub->DriveTank(left, right);
    }

    // Otherwise, use Arcade.
    else if (arcadeConnected && m_pArcadeController != nullptr)
    {
        double forward = -m_pArcadeController->GetLeftY();
        double turn = m_pArcadeController->GetRightX();

        m_pDriveSub->DriveRC(forward, turn);
    }

    // No controller connected.
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