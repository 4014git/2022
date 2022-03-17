#include "subsystems/DrivetrainSubsystem.h"

using namespace DriveConstants;

DrivetrainSubsystem::DrivetrainSubsystem() : m_leftFront{kLeftMotorFront}, m_leftFollower{kLeftMotorFollower}, m_rightFront{kRightMotorFront}, m_rightFollower{kRightMotorFollower}
{
  m_leftFront.ConfigFactoryDefault();
  m_leftFollower.ConfigFactoryDefault();
  m_rightFront.ConfigFactoryDefault();
  m_rightFollower.ConfigFactoryDefault();

  m_leftFollower.Follow(m_leftFront);
  m_rightFollower.Follow(m_rightFront);

  m_rightFront.SetInverted(TalonFXInvertType::CounterClockwise);
  m_rightFollower.SetInverted(TalonFXInvertType::FollowMaster);
  m_leftFront.SetInverted(TalonFXInvertType::Clockwise);
  m_leftFollower.SetInverted(TalonFXInvertType::FollowMaster);
}

void DrivetrainSubsystem::ArcadeDrive(double y, double x)
{
  m_drive.ArcadeDrive(y, x);
}

void DrivetrainSubsystem::ResetEncoders()
{
  m_leftFront.SetSelectedSensorPosition(0);
  m_rightFront.SetSelectedSensorPosition(0);
}

double DrivetrainSubsystem::GetAverageEncoderDistanceInches()
{
  return (m_leftFront.GetSelectedSensorPosition() + m_rightFront.GetSelectedSensorPosition()) / (2 * AutoConstants::kEncoderUnitsPerInch);
}