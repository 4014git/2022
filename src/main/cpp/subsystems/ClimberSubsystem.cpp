#include "subsystems/ClimberSubsystem.h"

#include <iostream>

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem()
    : m_leftMotor{kLeftMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
      m_rightMotor{kRightMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless},
      m_leftEncoder{m_leftMotor.GetEncoder()}, m_rightEncoder{m_rightMotor.GetEncoder()}
{
    m_leftMotor.SetInverted(kInverted);
    m_rightMotor.SetInverted(kInverted);

    m_leftEncoder.SetPositionConversionFactor(kEncoderUnitsPerInch);
    m_leftEncoder.SetPositionConversionFactor(kEncoderUnitsPerInch);
}

// This method will be called once per scheduler run
void ClimberSubsystem::Periodic()
{
    std::cout << "Left Encoder: " << m_leftEncoder.GetPosition() << " Right Encoder: " << m_rightEncoder.GetPosition()
              << std::endl;
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

void ClimberSubsystem::ResetEncoders()
{
    m_leftEncoder.SetPosition(0);
    m_rightEncoder.SetPosition(0);
}

double ClimberSubsystem::getLeftEncoderDistance()
{
    return m_leftEncoder.GetPosition();
}

double ClimberSubsystem::getRightEncoderDistance()
{
    return m_rightEncoder.GetPosition();
}

double ClimberSubsystem::getAverageEncoderDistance()
{
    return (m_leftEncoder.GetPosition() + m_rightEncoder.GetPosition()) / 2.0;
}