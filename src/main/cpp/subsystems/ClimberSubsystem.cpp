#include "subsystems/ClimberSubsystem.h"

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem()
    : m_leftMotor{kLeftMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
      m_rightMotor{kRightMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
      m_leftEncoder{m_leftMotor.GetEncoder()}, m_rightEncoder{m_rightMotor.GetEncoder()}
{
    m_leftMotor.SetInverted(kLeftnverted);
    m_rightMotor.SetInverted(kRightInverted);

    m_leftMotor.SetIdleMode(kNeutralMode);
    m_rightMotor.SetIdleMode(kNeutralMode);

    m_leftEncoder.SetPositionConversionFactor(kEncoderUnitsPerInch);
    m_rightEncoder.SetPositionConversionFactor(kEncoderUnitsPerInch);
}

void ClimberSubsystem::Periodic()
{
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

void ClimberSubsystem::ResetLeftEncoder()
{
    m_leftEncoder.SetPosition(0);
}

void ClimberSubsystem::ResetRightEncoder()
{
    m_rightEncoder.SetPosition(0);
}

void ClimberSubsystem::ResetEncoders()
{
    m_leftEncoder.SetPosition(0);
    m_rightEncoder.SetPosition(0);
}

double ClimberSubsystem::getLeftEncoderDistance()
{
    return m_leftEncoder.GetPosition() / kEncoderUnitsPerInch;
}

double ClimberSubsystem::getRightEncoderDistance()
{
    return m_rightEncoder.GetPosition() / kEncoderUnitsPerInch;
}

double ClimberSubsystem::getAverageEncoderDistance()
{
    return (m_leftEncoder.GetPosition() + m_rightEncoder.GetPosition()) / (2.0 * kEncoderUnitsPerInch);
}