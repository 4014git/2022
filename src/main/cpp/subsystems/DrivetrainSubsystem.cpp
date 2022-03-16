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