#include "commands/DriveCmd.h"

#include <cmath>

DriveCmd::DriveCmd(DriveSub * pDriveSub, frc2::CommandXboxController * pController)
{
    m_pDriveSub = pDriveSub;
    m_pController = pController;

    AddRequirements(m_pDriveSub);
}

void DriveCmd::Initialize()
{
}

void DriveCmd::Execute()
{
    if (m_pDriveSub != nullptr && m_pController != nullptr)
    {
        double deadzone = 0.05;
        double leftY = m_pController->GetLeftY();
        double rightX = m_pController->GetRightY();

        if (leftY < deadzone && leftY > -deadzone)
        {
            leftY = 0.0;
            m_timer.Stop();
            m_timer.Reset();
        }
        else
        {
            m_timer.Start();
        }

        if (rightX < deadzone && rightX > -deadzone)
        {
            rightX = 0.0;
        }

        double responseFactor = 1.25;
        double leftFactor = std::lerp(0.0, 1.0, (double)m_timer.Get() * responseFactor);
        double rightFactor = 1.0;
        
        m_pDriveSub->DriveRC(-(leftY * leftFactor), rightX * rightFactor);

    }
}

void DriveCmd::End(bool interrupted) {}

bool DriveCmd::IsFinished()
{
    return m_isFinished;
}