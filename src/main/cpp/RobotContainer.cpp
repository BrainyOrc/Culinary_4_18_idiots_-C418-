#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>
#include "commands/DriveCmd.h"

RobotContainer::RobotContainer()
{
    Init();
    ConfigureBindings();
}

void RobotContainer::ConfigureBindings()
{
    m_driveSub.SetDefaultCommand(
        DriveCmd(
            &m_driveSub,
            &m_arcadeController,
            &m_tankController
        )
    );
}

void RobotContainer::Init()
{
    m_driveSub.Init();
}

void RobotContainer::GetAutonomousCommand()
{
}