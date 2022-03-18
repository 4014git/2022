#include "subsystems/DrivetrainSubsystem.h"

using namespace DriveConstants;

DrivetrainSubsystem::DrivetrainSubsystem()
    : m_leftFront{kLeftMotorFront}, m_leftFollower{kLeftMotorFollower}, m_rightFront{kRightMotorFront},
      m_rightFollower{kRightMotorFollower}, squareInputs{kSquareInputs}
{
    m_leftFront.ConfigFactoryDefault();
    m_leftFollower.ConfigFactoryDefault();
    m_rightFront.ConfigFactoryDefault();
    m_rightFollower.ConfigFactoryDefault();

    m_leftFollower.Follow(m_leftFront);
    m_rightFollower.Follow(m_rightFront);

    m_rightFront.SetInverted(kLeftMotorInvert);
    m_rightFollower.SetInverted(kLeftMotorInvert);
    m_leftFront.SetInverted(kRightMotorInvert);
    m_leftFollower.SetInverted(kRightMotorInvert);

    m_rightFront.SetNeutralMode(kNeutralMode);
    m_rightFollower.SetNeutralMode(kNeutralMode);
    m_leftFront.SetNeutralMode(kNeutralMode);
    m_leftFollower.SetNeutralMode(kNeutralMode);
}

void DrivetrainSubsystem::ArcadeDrive(double y, double x)
{
    m_drive.ArcadeDrive(y, x, squareInputs);
}

void DrivetrainSubsystem::ResetEncoders()
{
    m_leftFront.SetSelectedSensorPosition(0);
    m_rightFront.SetSelectedSensorPosition(0);
}

double DrivetrainSubsystem::GetLeftEncoder()
{
    return m_leftFront.GetSelectedSensorPosition() / kEncoderUnitsPerInch;
}

double DrivetrainSubsystem::GetRightEncoder()
{
    return m_rightFront.GetSelectedSensorPosition() / kEncoderUnitsPerInch;
}

double DrivetrainSubsystem::GetAverageEncoderDistanceInches()
{
    return (m_leftFront.GetSelectedSensorPosition() + m_rightFront.GetSelectedSensorPosition()) /
           (2.0 * kEncoderUnitsPerInch);
}

void DrivetrainSubsystem::SetSquareInputs(bool setSquareInputs){
    squareInputs = setSquareInputs;
}