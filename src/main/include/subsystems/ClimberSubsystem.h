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
    void setLeftRotationSpeed(double speed);
    void setRightRotationSpeed(double speed);
    void setRotationSpeed(double speed);

  private:
    rev::CANSparkMax m_leftMotor;
    rev::CANSparkMax m_rightMotor;
    rev::CANSparkMax m_leftRotationMotor;
    rev::CANSparkMax m_rightRotationMotor;
};
