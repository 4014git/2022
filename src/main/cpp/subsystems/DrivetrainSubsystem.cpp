#include "subsystems/DrivetrainSubsystem.h"

using namespace DriveConstants;

DrivetrainSubsystem::DrivetrainSubsystem() : m_left1{LeftMotor1ID}, m_left2{LeftMotor2ID}, m_right1{RightMotor1ID}, m_right2{RightMotor2ID} {
  m_left.SetInverted(LeftDriveReversed);
  m_right.SetInverted(RightDriveReversed);
}

void DrivetrainSubsystem::ArcadeDrive(double y, double x) {
  m_drive.ArcadeDrive(y, x);
}