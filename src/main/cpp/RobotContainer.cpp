#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
    ConfigureButtonBindings();

    m_drive.SetDefaultCommand(frc2::RunCommand(
        [this] { m_drive.ArcadeDrive(-m_driverController.GetY(), -m_driverController.GetZ()); }, {&m_drive}));
}

void RobotContainer::ConfigureButtonBindings()
{
    frc2::JoystickButton(&m_driverController, OIConstants::driverControllerChangeSquareInputs).WhenPressed(m_changeSquareInputPressed).WhenReleased(m_changeSquareInputReleased);
    
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerLeftClimberUpButton)
        .WhenPressed(m_LeftClimberUp)
        .WhenReleased(m_LeftClimberStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerLeftClimberDownButton)
        .WhenPressed(m_LeftClimberDown)
        .WhenReleased(m_LeftClimberStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerRightClimberUpButton)
        .WhenPressed(m_RightClimberUp)
        .WhenReleased(m_RightClimberStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerRightClimberDownButton)
        .WhenPressed(m_RightClimberDown)
        .WhenReleased(m_RightClimberStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerBothClimberUpButton).WhenPressed(m_BothClimbersAutoUp).WhenReleased(m_BothClimbersStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerBothClimberDownButton).WhenPressed(m_BothClimbersAutoDown).WhenReleased(m_BothClimbersStop);
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
    return &m_Auto;
}
