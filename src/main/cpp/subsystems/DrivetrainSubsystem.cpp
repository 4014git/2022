#include "subsystems/DrivetrainSubsystem.h"

using namespace DriveConstants;

DrivetrainSubsystem::DrivetrainSubsystem() : m_leftFront{LeftMotorFront}, m_leftFollower{LeftMotorFollower}, m_rightFront{RightMotorFront}, m_rightFollower{RightMotorFollower} {
  m_leftFront.ConfigFactoryDefault();
  m_leftFollower.ConfigFactoryDefault();
  m_rightFront.ConfigFactoryDefault();
  m_rightFollower.ConfigFactoryDefault();

  m_leftFollower.Follow(m_leftFront);
  m_rightFollower.Follow(m_rightFront);

  m_rightFront.SetInverted(TalonFXInvertType::Clockwise);
  m_rightFollower.SetInverted(TalonFXInvertType::Clockwise);
  m_leftFront.SetInverted(TalonFXInvertType::CounterClockwise);
  m_leftFollower.SetInverted(TalonFXInvertType::CounterClockwise);
}

void DrivetrainSubsystem::ArcadeDrive(double y, double x) {
  m_drive.ArcadeDrive(y, x);
}

void DrivetrainSubsystem::ResetEncoders() {
  m_leftFront.SetSelectedSensorPosition(0, 0, 10);
  m_leftFollower.SetSelectedSensorPosition(0, 0, 10);
  m_rightFront.SetSelectedSensorPosition(0, 0, 10);
  m_rightFollower.SetSelectedSensorPosition(0, 0, 10);
}

double DrivetrainSubsystem::GetAverageEncoderDistance() {
  // the gorgeous one-liner
  return (m_leftFront.GetSelectedSensorPosition() + m_leftFollower.GetSelectedSensorPosition() + m_rightFront.GetSelectedSensorPosition() + m_rightFollower.GetSelectedSensorPosition())/4;
}