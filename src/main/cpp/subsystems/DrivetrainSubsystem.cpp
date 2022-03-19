#include "subsystems/DrivetrainSubsystem.h"

using namespace DriveConstants;

DrivetrainSubsystem::DrivetrainSubsystem()
    : m_leftFront{kLeftMotorFront}, m_leftFollower{kLeftMotorFollower}, m_rightFront{kRightMotorFront},
      m_rightFollower{kRightMotorFollower}, squareInputs{kDefualtSquareInputs}
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

double DrivetrainSubsystem::GetLeftEncoderDistance()
{
    return m_leftFront.GetSelectedSensorPosition() / kEncoderUnitsPerInch;
}

double DrivetrainSubsystem::GetRightEncoderDistance()
{
    return m_rightFront.GetSelectedSensorPosition() / kEncoderUnitsPerInch;
}

double DrivetrainSubsystem::GetAverageEncoderDistance()
{
    return (m_leftFront.GetSelectedSensorPosition() + m_rightFront.GetSelectedSensorPosition()) /
           (2.0 * kEncoderUnitsPerInch);
}

double DrivetrainSubsystem::GetLeftEncoderVelocity(){
    return m_leftFront.GetSelectedSensorVelocity();
}

double DrivetrainSubsystem::GetRightEncoderVelocity(){
    return m_rightFront.GetSelectedSensorVelocity();
}

double DrivetrainSubsystem::GetAverageEncoderVelocity(){
    return (m_leftFront.GetSelectedSensorVelocity()+m_rightFront.GetSelectedSensorVelocity())/2.0;
}

void DrivetrainSubsystem::SetSquareInputs(bool setSquareInputs){
    squareInputs = setSquareInputs;
}