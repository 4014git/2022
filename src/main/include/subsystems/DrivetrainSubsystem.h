#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class DrivetrainSubsystem : public frc2::SubsystemBase
{
public:
  DrivetrainSubsystem();
  void ArcadeDrive(double fwd, double rot);
  void ResetEncoders();
  double GetAverageEncoderDistanceInches();

private:
  WPI_TalonFX m_leftFront;
  WPI_TalonFX m_leftFollower;
  WPI_TalonFX m_rightFront;
  WPI_TalonFX m_rightFollower;

  frc::DifferentialDrive m_drive{m_leftFront, m_rightFront};
};
