#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include "Robot.h"

void Robot::RobotInit()
{
    // frc::CameraServer::StartAutomaticCapture();
}

void Robot::RobotPeriodic()
{
    frc2::CommandScheduler::GetInstance().Run();
}

void Robot::DisabledInit()
{
}

void Robot::DisabledPeriodic()
{
}

void Robot::AutonomousInit()
{
    m_autonomousCommand = m_container.GetAutonomousCommand();

    if (m_autonomousCommand != nullptr)
    {
        m_autonomousCommand->Schedule();
    }
}

void Robot::AutonomousPeriodic()
{
}

void Robot::TeleopInit()
{
    if (m_autonomousCommand != nullptr)
    {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}

void Robot::TeleopPeriodic()
{
}

#ifndef RUNNING_FRC_TESTS
int main()
{
    return frc::StartRobot<Robot>();
}
#endif
