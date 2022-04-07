#include "subsystems/ClimberSubsystem.h"

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem()
    : m_leftMotor{kLeftMotor, rev::CANSparkMax::MotorType::kBrushless},
      m_rightMotor{kRightMotor, rev::CANSparkMax::MotorType::kBrushless},
      m_rightRotationMotor{kRightRotationMotor, rev::CANSparkMax::MotorType::kBrushless},
      m_leftRotationMotor{kLeftRotationMotor, rev::CANSparkMax::MotorType::kBrushless}

{
    m_leftMotor.SetInverted(kLeftInverted);
    m_rightMotor.SetInverted(kRightInverted);
    m_leftRotationMotor.SetInverted(kLeftTransversalInverted);
    m_rightRotationMotor.SetInverted(kRightTransversalInverted);

    m_leftMotor.SetIdleMode(kNeutralMode);
    m_rightMotor.SetIdleMode(kNeutralMode);
    m_leftRotationMotor.SetIdleMode(kNeutralMode);
    m_rightRotationMotor.SetIdleMode(kNeutralMode);
}

void ClimberSubsystem::setLeftSpeed(double speed)
{
    m_leftMotor.Set(speed);
}

void ClimberSubsystem::setRightSpeed(double speed)
{
    m_rightMotor.Set(speed);
}

void ClimberSubsystem::setSpeed(double speed)
{
    m_leftMotor.Set(speed);
    m_rightMotor.Set(speed);
}

void ClimberSubsystem::setLeftRotationSpeed(double speed)
{
    m_leftRotationMotor.Set(speed);
}

void ClimberSubsystem::setRightRotationSpeed(double speed)
{
    m_rightRotationMotor.Set(speed);
}

void ClimberSubsystem::setRotationSpeed(double speed)
{
    m_leftRotationMotor.Set(speed);
    m_rightRotationMotor.Set(speed);
}