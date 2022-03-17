#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
  ConfigureButtonBindings();

  m_drive.SetDefaultCommand(
      frc2::RunCommand(
          [this]
          { m_drive.ArcadeDrive(-m_driverController.GetY(), -m_driverController.GetX()); },
          {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings() {
  frc2::JoystickButton(&m_driverController, OIConstants::driverControllerLeftClimberUpButton).WhenPressed(m_LeftClimberUp).WhenReleased(m_LeftClimberStop);
  frc2::JoystickButton(&m_driverController, OIConstants::driverControllerLeftClimberDownButton).WhenPressed(m_LeftClimberDown).WhenReleased(m_LeftClimberStop);
  frc2::JoystickButton(&m_driverController, OIConstants::driverControllerRightClimberUpButton).WhenPressed(m_RightClimberUp).WhenReleased(m_RightClimberStop);
  frc2::JoystickButton(&m_driverController, OIConstants::driverControllerRightClimberDownButton).WhenPressed(m_RightClimberDown).WhenReleased(m_RightClimberStop);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  return &m_Auto;
}
