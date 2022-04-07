#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
    ConfigureButtonBindings();

    m_drive.SetDefaultCommand(frc2::RunCommand(
        [this] { m_drive.ArcadeDrive(-m_driverController.GetY(), -m_driverController.GetX(), false); }, {&m_drive}));
    m_climber.SetDefaultCommand(frc2::RunCommand(
        [this] {
            m_climber.setSpeed(m_operatorController.GetLeftY());
            m_climber.setRotationSpeed(m_operatorController.GetRightY());
        },
        {&m_climber}));
}

void RobotContainer::ConfigureButtonBindings()
{
    frc2::JoystickButton(&m_driverController, OIConstants::driverControllerSquareInputs)
        .WhileHeld(frc2::RunCommand(
            [this] { m_drive.ArcadeDrive(-m_driverController.GetY(), -m_driverController.GetX(), true); }, {&m_drive}));

    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerClimberLeftSide)
        .WhenPressed(frc2::InstantCommand([this] {
            m_climber.setRightSpeed(0);
            m_climber.setRightRotationSpeed(0);
        }))
        .WhileHeld(frc2::RunCommand(
            [this] {
                m_climber.setLeftSpeed(m_operatorController.GetLeftY());
                m_climber.setLeftRotationSpeed(m_operatorController.GetRightY());
            },
            {&m_climber}));

    frc2::JoystickButton(&m_operatorController, OIConstants::operatorControllerClimberRightSide)
        .WhenPressed(frc2::InstantCommand([this] {
            m_climber.setLeftSpeed(0);
            m_climber.setLeftRotationSpeed(0);
        }))
        .WhileHeld(frc2::RunCommand(
            [this] {
                m_climber.setRightSpeed(m_operatorController.GetLeftY());
                m_climber.setRightRotationSpeed(m_operatorController.GetRightY());
            },
            {&m_climber}));
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
    return &m_Auto;
}
