#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class DrivetrainSubsystem : public frc2::SubsystemBase {
  public:
    DrivetrainSubsystem();
    void ArcadeDrive(double fwd, double rot);

  private:
    WPI_TalonFX m_left1;
    WPI_TalonFX m_left2;
    WPI_TalonFX m_right1;
    WPI_TalonFX m_right2;

    frc::MotorControllerGroup m_left{m_left1, m_left2};
    frc::MotorControllerGroup m_right{m_right1, m_right2};

    frc::DifferentialDrive m_drive{m_left, m_right};
};
