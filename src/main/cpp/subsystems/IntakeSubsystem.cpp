#include "subsystems/IntakeSubsystem.h"

using namespace IntakeConstants;

IntakeSubsystem::IntakeSubsystem() : m_leftRotation{kLeftMotorRotation}, m_rightRotation{kRightMotorRotation}, m_intake{kMotorIntake}{
    m_leftRotation.ConfigFactoryDefault();
    m_rightRotation.ConfigFactoryDefault();
    m_intake.ConfigFactoryDefault();

    m_leftRotation.SetInverted(kLeftMotorInvert);
    m_rightRotation.SetInverted(kRightMotorInvert);
    m_intake.SetInverted(kMotorIntakeInvert);

    m_leftRotation.SetNeutralMode(kRotationNeutralMode);
    m_rightRotation.SetNeutralMode(kRotationNeutralMode);
    m_intake.SetNeutralMode(kIntakeNeutralMode);
}


void IntakeSubsystem::setLeftRotationSpeed(double speed) {
    m_leftRotation.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::setRightRotationSpeed(double speed) {
    m_rightRotation.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::setRotationSpeed(double speed) {
    m_leftRotation.Set(ControlMode::PercentOutput, speed);
    m_rightRotation.Set(ControlMode::PercentOutput, speed);
}

void IntakeSubsystem::setIntakeSpeed(double speed) {
    m_intake.Set(ControlMode::PercentOutput, speed);
}