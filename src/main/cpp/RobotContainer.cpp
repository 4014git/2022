#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
    ConfigureButtonBindings();

    m_drive.SetDefaultCommand(frc2::RunCommand(
        [this] { m_drive.ArcadeDrive(-m_driverController.GetY(), -m_driverController.GetX()); }, {&m_drive}));
    m_climber.SetDefaultCommand(frc2::RunCommand(
        [this] { m_climber.setSpeed(0); }, {&m_climber}));
}


void RobotContainer::ConfigureButtonBindings()
{
    frc2::JoystickButton(&m_driverController, OIConstants::driverControllerChangeSquareInputs).WhenPressed(m_changeSquareInputPressed).WhenReleased(m_changeSquareInputReleased);
    
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerLeftClimberUpButton)
        .WhileHeld(m_LeftClimberUp);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerLeftClimberDownButton)
        .WhileHeld(m_LeftClimberDown);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerRightClimberUpButton)
        .WhileHeld(m_RightClimberUp);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerRightClimberDownButton)
<<<<<<< HEAD
        .WhileHeld(m_RightClimberDown);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerClimberByJoystickButton).WhileHeld(m_ClimberByJoystick);
=======
        .WhenPressed(m_RightClimberDown)
        .WhenReleased(m_RightClimberStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerBothClimberUpButton).WhenPressed(m_BothClimbersAutoUp).WhenReleased(m_BothClimbersStop);
    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerBothClimberDownButton).WhenPressed(m_BothClimbersAutoDown).WhenReleased(m_BothClimbersStop);
>>>>>>> a4bbac5afa0635a2c84ab3ab709068f1e4232d46
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
    return &m_Auto;
}
