// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimberSubsystem.h"

#include <iostream>

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem() : m_leftMotor{kLeftMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, m_rightMotor{kRightMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, m_leftEncoder{kLeftEncoderFront, kLeftEncoderFollower}, m_rightEncoder{kRightEncoderFront, kRightEncoderFollower}
{
    m_leftEncoder.SetDistancePerPulse(kEncoderUnitsPerInch);
    m_rightEncoder.SetDistancePerPulse(kEncoderUnitsPerInch);

    m_leftEncoder.SetDistancePerPulse(kEncoderUnitsPerInch);
    m_rightEncoder.SetDistancePerPulse(kEncoderUnitsPerInch);
}

// This method will be called once per scheduler run
void ClimberSubsystem::Periodic()
{
    std::cout << "Left Encoder: " << m_leftEncoder.GetDistance() << " Right Encoder: " << m_rightEncoder.GetDistance() << std::endl;
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
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
}

double ClimberSubsystem::getLeftEncoderDistance()
{
    return m_leftEncoder.GetDistance();
}

double ClimberSubsystem::getRightEncoderDistance()
{
    return m_rightEncoder.GetDistance();
}

double ClimberSubsystem::getAverageEncoderDistance()
{
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2;
}