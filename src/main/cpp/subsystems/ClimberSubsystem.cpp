// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimberSubsystem.h"

#include <iostream>

using namespace ClimberConstants;

ClimberSubsystem::ClimberSubsystem() : m_leftMotor{kLeftMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless}, m_rightMotor{kRightMotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless}
{
    m_leftMotor.SetInverted(kInverted);
    m_rightMotor.SetInverted(kInverted);

    // m_leftMotor.GetEncoder().SetPositionConversionFactor(kEncoderUnitsPerInch);
    // m_rightMotor.GetEncoder().SetPositionConversionFactor(kEncoderUnitsPerInch);
}

// This method will be called once per scheduler run
void ClimberSubsystem::Periodic()
{
    // std::cout << "Left Encoder: " << m_leftMotor.GetEncoder().GetPosition() << " Right Encoder: " << m_rightMotor.GetEncoder().GetPosition() << std::endl;
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
    m_leftMotor.GetEncoder().SetPosition(0);
    m_rightMotor.GetEncoder().SetPosition(0);
}

double ClimberSubsystem::getLeftEncoderDistance()
{
    return m_leftMotor.GetEncoder().GetPosition();
}

double ClimberSubsystem::getRightEncoderDistance()
{
    return m_rightMotor.GetEncoder().GetPosition();
}

double ClimberSubsystem::getAverageEncoderDistance()
{
    return (m_leftMotor.GetEncoder().GetPosition() + m_rightMotor.GetEncoder().GetPosition()) / 2;
}