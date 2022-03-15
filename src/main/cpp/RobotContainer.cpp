#include "RobotContainer.h"


RobotContainer::RobotContainer() // : m_autonomousCommand(&m_drive) 
{
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        m_drive.ArcadeDrive(m_driverController.GetY(),
                            m_driverController.GetX());
      },
      {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return new frc2::InstantCommand([] {});
}
