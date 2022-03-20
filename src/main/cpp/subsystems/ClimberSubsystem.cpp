#include "subsystems/ClimberSubsystem.h"

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem()
    : m_leftMotor{kLeftMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
      m_rightMotor{kRightMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless}
{
    m_leftMotor.SetInverted(kLeftnverted);
    m_rightMotor.SetInverted(kRightInverted);

    m_leftMotor.SetIdleMode(kNeutralMode);
    m_rightMotor.SetIdleMode(kNeutralMode);
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