#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase
{
  public:
    IntakeSubsystem();

    void setLeftRotationSpeed(double speed);
    void setRightRotationSpeed(double speed);
    void setRotationSpeed(double speed);
    void setIntakeSpeed(double speed);

  private:
    TalonSRX m_leftRotation;
    TalonSRX m_rightRotation;
    TalonSRX m_intake;
};
