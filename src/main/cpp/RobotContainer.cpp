#include "RobotContainer.h"


RobotContainer::RobotContainer()
{
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] { m_drive.ArcadeDrive(m_driverController.GetY(), m_driverController.GetX());},
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return &m_Auto;
}
