#pragma once

#include <frc/Encoder.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class ClimberSubsystem : public frc2::SubsystemBase
{
  public:
    ClimberSubsystem();

    void setLeftSpeed(double speed);
    void setRightSpeed(double speed);
    void setSpeed(double speed);
    void ResetLeftEncoder();
    void ResetRightEncoder();
    void ResetEncoders();
    double getLeftEncoderDistance();
    double getRightEncoderDistance();
    double getAverageEncoderDistance();

  private:
    rev::CANSparkMax m_leftMotor;
    rev::CANSparkMax m_rightMotor;

    rev::SparkMaxRelativeEncoder m_leftEncoder;
    rev::SparkMaxRelativeEncoder m_rightEncoder;
};
